#include "topology/POI.h"

#include <sstream>

namespace ttb
{
namespace wm
{
POI::POI(int id)
    : id(id)
    , x(0)
    , y(0)
{
}
	std::string POI::toString()
	{
		std::stringstream ss;
		ss << "POI: ID: " << this->id << " x: " << this->x << " y: " << this->y << std::endl;
		return ss.str();
	}
}
}
