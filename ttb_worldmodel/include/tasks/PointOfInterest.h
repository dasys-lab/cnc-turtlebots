/*
 * PointOfInterest.h
 *
 *  Created on: Feb 1, 2016
 *      Author: lab-user
 */

#ifndef SRC_POI_H_
#define SRC_POI_H_

#include <string>

namespace ttb
{
namespace wm
{

	struct PointOfInterest
	{
		PointOfInterest(int id, std::string name, float x, float y);
		PointOfInterest();

		int id;
		std::string name;
		float x;
		float y;
	};

}
}/* namespace ttb */

inline ttb::wm::PointOfInterest::PointOfInterest(int id, std::string name, float x, float y) : id(id), name(name), x(x), y(y)
{
}

inline ttb::wm::PointOfInterest::PointOfInterest() : id(-1), name("none"), x(0), y(0)
{
}

#endif /* SRC_POI_H_ */
