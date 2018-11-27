/// \file
/// Dummy file for testing JSON lib integration

#include "nlohmann/json.hpp"
#include <ilang/json-inout/json_parse.h>
#include <iostream>

namespace ila {

using json = nlohmann::json;

void TestJsonParse() {
  json j;
  j["pi"] = 3.141;
  j["happy"] = true;
  j["nothing"] = nullptr;
  j["answer"]["everything"] = 42;
  j["list"] = {1, 0, 2};
  j["object"] = {{"currency", "USD"}, {"value", 42.99}};
  json j2 = {{"pi", 3.141},
             {"happy", true},
             {"name", "Niels"},
             {"nothing", nullptr},
             {"answer", {{"everything", 42}}},
             {"list", {1, 0, 2}},
             {"object", {{"currency", "USD"}, {"value", 42.99}}}};

  auto j3 = R"(
    {
      "happy": true,
      "pi": 3.141
    }
  )"_json;

  auto j4 = json::parse("{ \"happy\": true, \"pi\": 3.141 }");

  auto s = j4.dump();
  std::cout << j.dump(4) << std::endl;
}

}; // namespace ila
