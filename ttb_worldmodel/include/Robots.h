/*
 * Robots.h
 *
 *  Created on: Feb 23, 2015
 *      Author: Stefan Jakob
 */

#ifndef CNC_MSL_MSL_WORLDMODEL_INCLUDE_ROBOTS_H_
#define CNC_MSL_MSL_WORLDMODEL_INCLUDE_ROBOTS_H_

#include <vector>
#include "RingBuffer.h"
#include "InformationElement.h"

using namespace std;

namespace ttb
{

	class TTBWorldModel;
	class Robots
	{
	public:
		Robots(TTBWorldModel* wm, int ringBufferLength);
		virtual ~Robots();

	private:
		TTBWorldModel* wm;
	};

} /* namespace alica */

#endif /* CNC_MSL_MSL_WORLDMODEL_INCLUDE_ROBOTS_H_ */
