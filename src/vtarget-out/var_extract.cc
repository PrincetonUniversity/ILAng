/// \file Source of variable extractor
/// This is use to extract variable from expression (string)
/// See whether it is ila-state(I/O) / vlg-state and ...
/// and change their name if needed and generate a string
// --- Hongce Zhang

#include <ilang/vtarget-out/var_extract.h>

#include <cctype>

#include <ilang/util/log.h>
#include <ilang/util/str_util.h>

namespace ilang {

VarExtractor::VarExtractor(str_j is_ila_state, str_j is_ila_input,
                           str_j is_vlg_sig)
    : _is_ila_state(is_ila_state), _is_ila_input(is_ila_input),
      _is_vlg_sig(is_vlg_sig) {}

// mi == ila_inst_name / vlg_inst_name
bool VarExtractor::contains_mod_inst_name(const std::string& s,
                                          const std::string& mi) {
  ILA_ERROR_IF(mi == "")
      << "Implementation bug: set the module instances name first";
  return Split(s, ".").front() == mi;
}

std::string VarExtractor::GenString() const {
  std::string ret;
  for (auto&& t_s_pair : _tokens)
    ret += t_s_pair.second;
  return ret;
}

bool isStateBegin(unsigned char c) {
  return std::isalpha(c) || c == '#' || c == '_' || c == '$' ;
}

bool isStateCont(unsigned char c, size_t idx, const std::string& s) {
  if (std::isalpha(c) || std::isdigit(c) || c == '.' || c == '_' || c == ']' || c == '$')
    return true;
  if (!s.empty() && s.front() == '#' && c == '#')
    return true;
  else if (c == '[') {
    auto rp = s.find(']', idx);
    auto rc = s.find(':', idx);
    if (rc < rp)
      return false;
    // s[a:b], for this type, we make sure the whole of s is connected
    // basically, it assumes that the rf will not refer to multiple elements
    // but actually we need to check
    return true;
    // we are not sure of it actually
  }
  return false;
}

bool isNumBegin(unsigned char c) { return isdigit(c) || c == '\''; }

bool isNumCont(unsigned char c) {
  return isdigit(c) || isalpha(c) || c == '\'';
}

// [A-Za-z_][A-Za-z0-9\.]+ ==> state
// ['0-9][A-Za-z0-9']+ ==> num
void VarExtractor::ParseToExtract(const std::string& in,
                                  bool force_vlg_statename) {
  _tokens.clear();
  if (in.empty()) {
    ILA_ERROR << "Parsing an empty refinement string!";
    return;
  }

  auto l = in.length();

  bool is_num = isNumBegin(in.at(0));
  bool is_state = isStateBegin(in.at(0));
  ILA_CHECK(!(is_num && is_state)) << "Implementation bug";

  size_t left = 0;
  size_t idx = 1;

  for (; idx < l; ++idx) {
    bool is_num_new =
        (is_num && isNumCont(in.at(idx))) || isNumBegin(in.at(idx));
    bool is_state_new = (is_state && isStateCont(in.at(idx), idx, in)) ||
                        isStateBegin(in.at(idx));

    if (is_num && is_state) {
      ILA_CHECK(false) << "This should not be possible";
    } else if (is_num && !is_state) { // in the num matching
      if (!is_num_new) {              // leave matching
        is_num = false;
        _tokens.push_back({token_type::NUM, in.substr(left, idx - left)});
        left = idx;
        if (is_state_new)
          is_state = true;
      }
    } else if (is_state && !is_num) { // in the state matching
      if (!is_state_new) {            // leave matching
        is_state = false;
        auto subs = in.substr(left, idx - left);
        token_type tp;
        if (!subs.empty() && subs.front() == '#' &&
            subs.find('#', 1) != subs.npos) {
          _tokens.push_back({KEEP, ReplaceAll(subs, "#", "")});
          left = idx;
          if (is_num_new)
            is_num = true;
        }      // if # # [2:3] .. like this , will not convert at all
        else { // else normal ones
          // deal with []
          auto left_p = subs.find('[');
          auto check_s =
              subs.substr(0, left_p); // the string use to check no []

          if (_is_ila_state(check_s) && !force_vlg_statename)
            tp = ILA_S;
          else if (_is_ila_input(check_s) && !force_vlg_statename)
            tp = ILA_IN;
          else if (_is_vlg_sig(check_s))
            tp = VLG_S;
          else
            tp = UNKN_S;
          _tokens.push_back({tp, subs});
          left = idx;
          if (is_num_new)
            is_num = true;
        } // when no ##
      }
    } else if (!is_state && !is_num) { // not in the matching
      // see if we need to start matching
      ILA_CHECK(!(is_num_new && is_state_new))
          << "This should not be possible";
      if (is_num_new || is_state_new) {
        _tokens.push_back({token_type::KEEP, in.substr(left, idx - left)});
        left = idx;
      }
      if (is_num_new) {
        // copy [left, idx (not including) ] to KEEP
        is_num = true;
        is_state = false;
      } else if (is_state_new) {
        // copy [left, idx (not including) ] to KEEP
        is_num = false;
        is_state = true;
      }

    } else
      ILA_CHECK(false) << "Implementation bug, should not be reachable!";
  }
  ILA_CHECK(!(is_num && is_state)) << "Implementation bug";
  // copy the last if necessary
  if (left < idx) {
    auto subs = in.substr(left, idx - left);
    if (is_num)
      _tokens.push_back({token_type::NUM, subs});
    else if (is_state) {
      if (!subs.empty() && subs.front() == '#' &&
          subs.find('#', 1) != subs.npos)
        _tokens.push_back({KEEP, ReplaceAll(subs, "#", "")});
      else {
        token_type tp;
        auto left_p = subs.find('[');
        auto check_s = subs.substr(0, left_p); // the string use to check no []
        if (_is_ila_state(check_s) && !force_vlg_statename)
          tp = ILA_S;
        else if (_is_ila_input(check_s) && !force_vlg_statename)
          tp = ILA_IN;
        else if (_is_vlg_sig(check_s))
          tp = VLG_S;
        else
          tp = UNKN_S;
        _tokens.push_back({tp, subs});
      } // no #
    } else {
      _tokens.push_back({token_type::KEEP, subs});
    }
  }
}

void VarExtractor::ForEachTokenReplace(str_r replacer) {
  size_t idx = -1;
  for (auto&& p : _tokens) {
    idx++;
    auto rep = replacer(p);
    if (rep == p.second)
      continue;
    _tokens[idx] = std::make_pair(p.first, rep);
  }
}

// Find the strings like this :

}; // namespace ilang
