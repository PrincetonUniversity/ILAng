/// \file
/// The source for IlaSim

#include <fstream>
#include <queue>
#include <string>

#include <fmt/format.h>

#include <ilang/target-sc/ila_sim.h>
#include <ilang/util/fs.h>
#include <ilang/util/log.h>

namespace ilang {

IlaSim::IlaSim() {}

IlaSim::IlaSim(const InstrLvlAbsPtr& model_ptr) { model_ptr_ = model_ptr; }

void IlaSim::set_instr_lvl_abs(const InstrLvlAbsPtr& model_ptr) {
  model_ptr_ = model_ptr;
}

void IlaSim::set_systemc_path(std::string systemc_path) {
  systemc_path_ = systemc_path;
}

void IlaSim::enable_cmake_support() { cmake_support_ = true; }

void IlaSim::sim_gen(std::string export_dir, bool external_mem, bool readable,
                     bool qemu_device) {

  if (cmake_support_) {
    auto res = os_portable_mkdir(export_dir);
    ILA_INFO_IF(res) << "Create new dir " << export_dir;

    auto source_dir = os_portable_append_dir(export_dir, "src");
    auto header_dir = os_portable_append_dir(export_dir, "include");
    auto extern_dir = os_portable_append_dir(export_dir, "extern");

    os_portable_mkdir(source_dir);
    os_portable_mkdir(header_dir);
    os_portable_mkdir(extern_dir);
  }

  sim_gen_init(export_dir, external_mem, readable, qemu_device);
  sim_gen_init_header();
  sim_gen_input();
  sim_gen_state();
  sim_gen_init();
  sim_gen_decode();
  sim_gen_state_update();
  sim_gen_execute_kernel();
  sim_gen_execute_invoke();
  sim_gen_export();
}

void IlaSim::sim_gen_init(std::string export_dir, bool external_mem,
                          bool readable, bool qemu_device) {
  header_.str("");
  mk_script_.str("");
  obj_list_.str("");
  header_indent_ = "";
  searched_id_set_.clear();
  store_ite_set_.clear();
  const_mem_set_.clear();
  declared_id_set_.clear();
  func_set_.clear();
  defined_store_ite_set_.clear();
  defined_state_set_.clear();
  dfs_ld_search_set_.clear();
  external_ld_set_.clear();
  external_st_set_.clear();
  ld_st_counter_ = 0;
  EXTERNAL_MEM_ = external_mem;
  export_dir_ = export_dir;
  readable_ = readable;
  qemu_device_ = qemu_device;

  source_file_list_.clear();
  header_file_list_.clear();
}

void IlaSim::sim_gen_init_header() {
  if (!qemu_device_) {
    header_ << header_indent_ << "#include \"systemc.h\"\n";
    header_ << header_indent_ << "#include <map>\n";
    header_ << header_indent_ << "#include <fstream>\n";
    header_ << header_indent_ << "#include <iostream>\n";
    header_ << header_indent_ << "#include <sstream>\n";

    header_ << header_indent_
            << fmt::format("SC_MODULE({}) {{\n", model_ptr_->name().str());

    increase_indent(header_indent_);

    header_ << header_indent_ << "std::stringstream instr_log_ss;\n";
    header_ << header_indent_ << "std::ofstream instr_log;\n";
  } else {
    header_ << header_indent_
            << "#include <boost/multiprecision/cpp_int.hpp>\n";
    header_ << header_indent_ << "using namespace boost::multiprecision;\n";
    int_var_width_scan();
    for (auto int_width = int_var_width_set_.begin();
         int_width != int_var_width_set_.end(); int_width++) {
      if ((*int_width == 8) || (*int_width == 16) || (*int_width == 32) ||
          (*int_width == 64) || (*int_width == 128) || (*int_width == 256) ||
          (*int_width == 512) || (*int_width == 1024))
        continue;
      header_ << header_indent_
              << fmt::format(
                     "typedef number<cpp_int_backend<{0}, {0}, "
                     "unsigned_magnitude, unchecked, void>> uint{0}_t;\n",
                     std::to_string(*int_width));
    }
    header_ << header_indent_ << "#include <map>\n";
    header_ << header_indent_
            << fmt::format("class {} {{\n", model_ptr_->name().str());
    header_ << "public:\n";
    increase_indent(header_indent_);
  }
}

void IlaSim::sim_gen_input() {
  for (unsigned int i = 0; i < model_ptr_->input_num(); i++) {
    create_input(model_ptr_->input(i));
  }
}

void IlaSim::sim_gen_state() {
  std::queue<InstrLvlAbsPtr> child_ila_queue;
  for (unsigned int i = 0; i < model_ptr_->state_num(); i++)
    create_state(model_ptr_->state(i));

  for (unsigned int i = 0; i < model_ptr_->child_num(); i++)
    child_ila_queue.push(model_ptr_->child(i));

  while (!child_ila_queue.empty()) {
    auto current_ila = child_ila_queue.front();
    child_ila_queue.pop();
    for (unsigned int i = 0; i < current_ila->state_num(); i++)
      create_child_state(current_ila->state(i));
    for (unsigned int i = 0; i < current_ila->child_num(); i++)
      child_ila_queue.push(current_ila->child(i));
  }
}

void IlaSim::sim_gen_init() {
  std::queue<InstrLvlAbsPtr> child_ila_queue;
  for (unsigned int i = 0; i < model_ptr_->child_num(); i++)
    child_ila_queue.push(model_ptr_->child(i));
  while (!child_ila_queue.empty()) {
    auto current_ila = child_ila_queue.front();
    child_ila_queue.pop();
    create_init(current_ila);
    for (unsigned int i = 0; i < current_ila->child_num(); i++) {
      child_ila_queue.push(current_ila->child(i));
    }
  }
}

void IlaSim::sim_gen_decode() {
  std::queue<InstrLvlAbsPtr> ila_queue;
  ila_queue.push(model_ptr_);
  DebugLog::Enable("ILA hierarchy");
  while (!ila_queue.empty()) {
    auto current_ila = ila_queue.front();
    ila_queue.pop();
    ILA_INFO << "current_ila_name:" << current_ila->name();
    for (unsigned int i = 0; i < current_ila->child_num(); i++) {
      ILA_INFO << "current_ila_child:" << current_ila->child(i)->name();
      ila_queue.push(current_ila->child(i));
    }
    for (unsigned int i = 0; i < current_ila->instr_num(); i++) {
      ILA_INFO << "current_ila_instr:" << current_ila->instr(i)->name();
      create_decode(current_ila->instr(i));
    }
    ILA_INFO << "\n";
  }
  DebugLog::Disable("ILA hierarchy");
}

void IlaSim::sim_gen_state_update() {
  std::queue<InstrLvlAbsPtr> ila_queue;
  ila_queue.push(model_ptr_);
  while (!ila_queue.empty()) {
    auto current_ila = ila_queue.front();
    ila_queue.pop();
    for (unsigned int i = 0; i < current_ila->child_num(); i++) {
      ila_queue.push(current_ila->child(i));
    }
    for (unsigned int i = 0; i < current_ila->instr_num(); i++) {
      auto info_instr_num = current_ila->instr_num();
      ILA_INFO << "(" << i << "/" << info_instr_num << ")";
      ILA_INFO << "Generating state update for instr "
               << current_ila->instr(i)->name();
      create_state_update(current_ila->instr(i));
    }
  }
}

void IlaSim::sim_gen_execute_kernel() {
  std::stringstream execute_kernel;
  std::string indent = "";
  if (!qemu_device_)
    execute_kernel << indent << "#include \"systemc.h\"\n";
  execute_kernel << indent << "#include \"" << model_ptr_->name() << ".h\"\n";
  execute_kernel << indent << "#include <iostream>\n";
  execute_kernel << indent << "#include <fstream>\n";
  execute_kernel << indent
                 << fmt::format("void {}::compute() {{\n",
                                model_ptr_->name().str());
  increase_indent(indent);
  execute_kernel << indent << "static int instr_cntr = 0;\n";
  if (EXTERNAL_MEM_) {
    execute_write_external_mem(execute_kernel, indent);
    execute_read_external_mem(execute_kernel, indent);
    execute_external_mem_before_input(execute_kernel, indent);
  }
  if (!qemu_device_)
    execute_read_input(execute_kernel, indent);
  if (EXTERNAL_MEM_)
    execute_external_mem_after_output(execute_kernel, indent);
  execute_parent_instructions(execute_kernel, indent);
  execute_init(execute_kernel, indent);
  execute_child_instructions(execute_kernel, indent);
  if (EXTERNAL_MEM_)
    execute_external_mem_return(execute_kernel, indent);
  if (!qemu_device_)
    execute_write_output(execute_kernel, indent);
  decrease_indent(indent);
  execute_kernel << indent << "};\n";
  execute_kernel_export(execute_kernel);
  execute_kernel_mk_file();
  execute_kernel_header();
}

void IlaSim::sim_gen_execute_invoke() {
  if (!qemu_device_) {
    header_ << header_indent_
            << fmt::format("SC_HAS_PROCESS({});\n", model_ptr_->name().str());
    header_ << header_indent_ << model_ptr_->name()
            << "(sc_module_name name_) : sc_module(name_) {\n";
    increase_indent(header_indent_);
    header_ << header_indent_ << "SC_METHOD(compute);\n";
    header_ << header_indent_ << "sensitive";
    for (unsigned int i = 0; i < model_ptr_->input_num(); i++) {
      header_ << fmt::format(" << {}_{}_in", model_ptr_->name().str(),
                             model_ptr_->input(i)->name().str());
    }
    header_ << ";\n";
    decrease_indent(header_indent_);
    header_ << header_indent_ << "}\n";
  }

  decrease_indent(header_indent_);
  header_ << header_indent_ << "};\n";
}

void IlaSim::sim_gen_export() {
  std::ofstream outFile;
  auto file_name = fmt::format("{}.h", model_ptr_->name().str());

  if (cmake_support_) {
    file_name = os_portable_append_dir("include", file_name);
  }

  outFile.open(os_portable_append_dir(export_dir_, file_name));
  outFile << header_.rdbuf();
  outFile.close();
  if (!qemu_device_) {
    mk_script_ << "g++ -I. -I " << systemc_path_ << "/include/ "
               << "-L. -L " << systemc_path_ << "/lib-linux64/ "
               << "-Wl,-rpath=" << systemc_path_ << "/lib-linux64/ -std=c++11 "
               << "-g -c -o "
               << "uninterpreted_func.o "
               << "../../uninterpreted_func/uninterpreted_func.cc "
               << "-lsystemc\n";
#if 0
    mk_script_ << "g++ -I. -I " << systemc_path_ << "/include/ "
               << "-L. -L " << systemc_path_ << "/lib-linux64/ "
               << "-Wl,-rpath=" << systemc_path_ << "/lib-linux64/ "
               << "-c -o "
               << "test_tb.o test_tb.cc "
               << "-lsystemc\n";
#endif

#if 0
    mk_script_ << "g++ -I. -I " << systemc_path_ << "/include/ "
               << "-L. -L " << systemc_path_ << "/lib-linux64/ "
               << "-Wl,-rpath=" << systemc_path_ << "/lib-linux64/ "
               << "-o "
               << "test_tb test_tb.o " << obj_list_.rdbuf() << "-lsystemc\n";
#endif
  }

  if (cmake_support_) {
    header_file_list_.push_back(file_name);
    generate_cmake_support();
  } else {
    outFile.open(os_portable_append_dir(export_dir_, "mk.sh"));
    outFile << mk_script_.rdbuf();
    outFile.close();
  }
}

void IlaSim::generate_cmake_support() {
  auto file = os_portable_append_dir(export_dir_, "CMakeLists.txt");
  auto proj = model_ptr_->name().str();
  auto source_dir = os_portable_append_dir(export_dir_, "src");
  auto header_dir = os_portable_append_dir(export_dir_, "include");
  auto extern_dir = os_portable_append_dir(export_dir_, "extern");

  // gen recipe
  std::stringstream fb;

  fb << fmt::format("# CMakeLists.txt for {0}\n"
                    "cmake_minimum_required(VERSION 3.9.6)\n"
                    "project({0} LANGUAGES CXX)\n\n",
                    proj);

  // system c lib searching
#if 0
  fb << "# Search for SystemC library\n"
     << "find_package(PkgConfig)\n"
     << "pkg_check_modules(PC_SysC QUIET SystemC)\n\n"
     << "find_path(SysC_INCLUDE_DIR\n"
     << "  NAMES systemc.h\n"
     << "  HINTS ${PC_SysC_INCLUDEDIR} ${PC_SysC_INCLUDE_DIRS}\n"
     << "  PATH_SUFFIXES systemc\n"
     << ")\n\n"
     << "find_library(SysC_LIBRARY\n"
     << "  NAMES systemc libsystemc\n"
     << "  HINTS ${PC_SysC_LIBDIR} ${PC_SysC_LIBRARY_DIRS}\n"
     << "  PATH_SUFFIXES lib lib-linux64\n"
     << ")\n\n"
     << "mark_as_advanced(SysC_FOUND SysC_INCLUDE_DIR SysC_LIBRARY)\n"
     << "include(FindPackageHandleStandardArgs)\n\n"
     << "find_package_handle_standard_args(SysC DEFAULT_MSG\n"
     << "  SysC_INCLUDE_DIR\n"
     << "  SysC_LIBRARY\n"
     << ")\n\n"
     << "message(STATUS \"SystemC lib dir: ${SysC_LIBRARY}\")\n"
     << "message(STATUS \"SystemC include dir: ${SysC_INCLUDE_DIR}\")\n\n"
     << "if(SysC_FOUND AND NOT TARGET systemc::systemc)\n"
     << "  add_library(systemc::systemc INTERFACE IMPORTED)\n"
     << "  set_target_properties(systemc::systemc PROPERTIES\n"
     << "    INTERFACE_INCLUDE_DIRECTORIES \"${SysC_INCLUDE_DIR}\")\n"
     << "  set_target_properties(systemc::systemc PROPERTIES\n"
     << "    INTERFACE_LINK_LIBRARIES \"${SysC_LIBRARY}\")\n"
     << "endif()\n\n";
#else
  fb << "find_package(SystemCLanguage CONFIG REQUIRED)\n"
     << "set(CMAKE_CXX_STANDARD ${SystemC_CXX_STANDARD})\n\n";
#endif

  fb << fmt::format("aux_source_directory(extern extern_src)\n"
                    "add_executable({}\n"
                    "  ${{CMAKE_CURRENT_SOURCE_DIR}}/app/main.cc\n",
                    proj);
  for (auto f : source_file_list_) {
    fb << fmt::format("  ${{CMAKE_CURRENT_SOURCE_DIR}}/src/{}\n", f);
  }
  fb << "  ${extern_src})\n";

  fb << fmt::format("target_include_directories({0} PRIVATE include)\n"
                    "target_link_libraries({0} SystemC::systemc)\n",
                    proj);

  std::ofstream fw(file);
  fw << fb.rdbuf();
  fw.close();
}

}; // namespace ilang
