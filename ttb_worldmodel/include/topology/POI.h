#pragma once

#include <string>
#include <memory>

namespace ttb
{
namespace wm
{
	class LogicalObject;
	class Room;
	class POI
	{
	public:
		POI(int id);

		int id;
		double x;
		double y;
		std::shared_ptr<Room> room;
		std::shared_ptr<LogicalObject> gazeboModel;
	};

	struct POIComperator
	{
	    bool operator()(const std::shared_ptr<POI> a, std::shared_ptr<POI> b) const
	    {
	       return a->id == b->id;
	    }
	};

	struct POIHash
	{
	    std::size_t operator()(const std::shared_ptr<POI> obj) const
	    {
	    	return obj->id;
	    }
	};
}
}/* namespace ttb */

