#pragma once

#include <string>

namespace ttb
{
namespace wm
{
	class POI
	{
	public:
		POI(int id, std::string name, float x, float y);
		POI();

		int id;
		std::string name;
		float x;
		float y;
	};
}
}/* namespace ttb */

