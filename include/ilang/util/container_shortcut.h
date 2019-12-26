/// \file
/// Some short cut for set operations

#ifndef ILANG_UTIL_CONTAINER_SHORTCUT_H__
#define ILANG_UTIL_CONTAINER_SHORTCUT_H__

#include <algorithm>
#include <set>
#include <string>

#define UNION(a, b, r)                                                         \
  (std::set_union((a).begin(), (a).end(), (b).begin(), (b).end(),              \
                  std::inserter((r), (r).end())))
#define INTERSECT(a, b, r)                                                     \
  (std::set_intersection((a).begin(), (a).end(), (b).begin(), (b).end(),       \
                         std::inserter((r), (r).end())))
#define DIFFERENCE(a, b, r)                                                    \
  (std::set_difference((a).begin(), (a).end(), (b).begin(), (b).end(),         \
                       std::inserter((r), (r).end())))
#define SYMDIFF(a, b, r)                                                       \
  (std::set_symmetric_difference((a).begin(), (a).end(), (b).begin(),          \
                                 (b).end(), std::inserter((r), (r).end())))

#define IN(e, s) ((s).find(e) != (s).end())
#define IN_p(e, s) ((s)->find(e) != (s)->end())

#define S_IN(sub, s) ((s).find(sub) != (s).npos)

#endif // ILANG_UTIL_CONTAINER_SHORTCUT_H__
