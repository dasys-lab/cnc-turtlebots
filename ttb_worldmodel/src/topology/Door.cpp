#include "topology/Door.h"

namespace ttb
{
namespace wm
{

Door::Door(std::string name) : open(true), gazeboModel(nullptr)
{

}

Door::~Door()
{
}

std::size_t Door::hash() const
{
    return std::hash<std::string>()(this->name);
}

} /* namespace wm */
} /* namespace ttb */
