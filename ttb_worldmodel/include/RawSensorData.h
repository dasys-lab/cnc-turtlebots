/*
 * RawSensorData.h
 *
 *  Created on: May 27, 2015
 *      Author: Stephan Opfer
 */

#ifndef CNC_TTB_TTB_WORLDMODEL_RAWSENSORDATA_H_
#define CNC_TTB_TTB_WORLDMODEL_RAWSENSORDATA_H_

#include "RingBuffer.h"
#include "InformationElement.h"
#include <vector>


using namespace std;

namespace ttb
{

	class TTBWorldModel;
	class RawSensorData
	{
	public:
		RawSensorData(TTBWorldModel* wm, int ringBufferLength);
		virtual ~RawSensorData();
		void processWorldModelData();

	private:
		TTBWorldModel* wm;

		unsigned long maxInformationAge;
		int ownID;

	};

} /* namespace ttb */

#endif /* CNC_TTB_TTB_WORLDMODEL_RAWSENSORDATA_H_ */
