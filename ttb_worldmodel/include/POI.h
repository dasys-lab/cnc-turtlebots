/*
 * POI.h
 *
 *  Created on: Feb 1, 2016
 *      Author: lab-user
 */

#ifndef SRC_POI_H_
#define SRC_POI_H_

#include <string>

namespace ttb
{

	struct POI
	{
		POI(int id, std::string name, float x, float y);

		int id;
		std::string name;
		float x;
		float y;
	};

} /* namespace ttb */

inline ttb::POI::POI(int id, std::string name, float x, float y) : id(id), name(name), x(x), y(y)
{
}

#endif /* SRC_POI_H_ */
