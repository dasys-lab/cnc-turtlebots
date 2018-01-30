#pragma once

#include <string>
#include <memory>

namespace ttb
{
namespace wm
{
	class Room;
	class POI
	{
	public:
		POI(int id);
//		POI();

		int id;
		double x;
		double y;
		std::shared_ptr<Room> room;
	};
}
}/* namespace ttb */

