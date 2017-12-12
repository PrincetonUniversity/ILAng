/// \file
/// Unit test for class Object.

#include "ila/object.h"
#include "test_util.h"

namespace ila {

TEST(Object, Construct) {
  Object obj, obj2;
  ObjPtr ptr = std::make_shared<Object>("specify name");
  Object obj_copy = *ptr.get();

  EXPECT_GT(obj2.Name().ToInt(), obj.Name().ToInt());

  std::string msg = "";
  GET_STDOUT_MSG((std::cout << ptr->Name()), msg);
  EXPECT_EQ(obj_copy.Name().Str(), msg);
}

TEST(Object, GetType) {
  Object obj;
  EXPECT_EQ(obj.GetObjType(), ObjType::OBJ_NONE);
}

} // namespace ila
