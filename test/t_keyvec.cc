/// \file
/// Unit test for KeyVec

#include "util/container.h"
#include "util_test.h"
#include <string>

namespace ila {

TEST(TestKeyVec, StringString) {
  KeyVec<std::string, std::string> kv;

  EXPECT_EQ(0, kv.size());

  // k1 --> abc
  // k2 --> 123
  // k3 --> xyz
  kv.push_back("k1", "abc");
  kv.push_back("k2", "123");
  kv.push_back("k3", "xyz");

  EXPECT_DEATH(kv.push_back("k2", "#$%"), ".*");

  EXPECT_EQ(3, kv.size());

  EXPECT_EQ("abc", kv[0]);
  EXPECT_EQ("123", kv[1]);
  EXPECT_EQ("xyz", kv[2]);
  EXPECT_DEATH(kv[3], ".*");

  auto pos = kv.find("k1");
  EXPECT_NE(pos, kv.end());
  EXPECT_EQ("k1", pos.first);
  EXPECT_EQ("abc", pos.second);

  pos = kv.find("k2");
  EXPECT_NE(pos, kv.end());
  EXPECT_EQ("k2", pos.first);
  EXPECT_EQ("123", pos.second);
}

} // namespace ila

