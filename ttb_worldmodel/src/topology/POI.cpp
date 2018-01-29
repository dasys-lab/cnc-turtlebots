#include "POI.h"

namespace ttb
{
namespace wm
{
POI::POI(int id, std::string name, float x, float y)
    : id(id)
    , name(name)
    , x(x)
    , y(y)
{
}

POI::POI()
    : id(-1)
    , name("none")
    , x(0)
    , y(0)
{
}
}
}
