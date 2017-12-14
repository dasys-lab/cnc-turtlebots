#pragma once

#include <memory>
#include <unordered_set>

namespace ttb
{
namespace wm
{

class AreaDoor;
class Area
{

  public:
    Area(std::string name);
    virtual ~Area();
    std::size_t hash() const;
    const std::string name;
    std::unordered_set<std::shared_ptr<AreaDoor>> doors;
    std::string toString();
};

struct AreaComperator
{
    bool operator()(const std::shared_ptr<Area> a, const std::shared_ptr<Area> b) const
    {
        return a->name == b->name;
    }
};

struct AreaHash
{
    std::size_t operator()(const std::shared_ptr<Area> obj) const
    {
    	return obj->hash();
    }
};

} /* namespace wm */
} /* namespace ttb */
