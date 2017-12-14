#pragma once

#include "Room.h"

#include <memory>

namespace ttb
{
namespace wm
{

class Door
{

  public:
    Door(std::shared_ptr<Room> from, std::shared_ptr<Room> to);
    virtual ~Door();
    std::size_t hash() const;
    std::string toString();
    bool open;
    const std::shared_ptr<Room> from;
    const std::shared_ptr<Room> to;
};

struct DoorComperator
{
    bool operator()(const std::shared_ptr<Door> a, std::shared_ptr<Door> b) const
    {
       return a->to->name == b->to->name && a->from->name == b->from->name;
    }
};

struct DoorHash
{
    std::size_t operator()(const std::shared_ptr<Door> obj) const
    {
    	return obj->hash();
    }
};

} /* namespace wm */
} /* namespace ttb */
