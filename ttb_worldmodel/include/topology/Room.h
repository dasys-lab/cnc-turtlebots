#pragma once

#include <unordered_set>
#include <memory>

namespace ttb
{
namespace wm
{

class Area;
class Door;
class Room
{

  public:
	Room(std::string name);
    Room(std::string name, std::shared_ptr<Area> area) ;
    virtual ~Room();
    std::size_t hash() const;
    std::string toString();
    const std::shared_ptr<Area> area;
    const std::string name;
    std::unordered_set<std::shared_ptr<TopologicalDoor>> doors;
};

struct RoomComperator
{
    bool operator()(const std::shared_ptr<Room> a, const std::shared_ptr<Room> b) const
    {
       return a->name == b->name;
    }
};

struct RoomHash
{
    std::size_t operator()(const std::shared_ptr<Room> obj) const
    {
    	return obj->hash();
    }
};

} /* namespace wm */
} /* namespace ttb */
