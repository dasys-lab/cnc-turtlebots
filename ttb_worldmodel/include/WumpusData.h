/*
 * WumpusData.h
 *
 *  Created on: Mar 16, 2017
 *      Author: Lab User 5
 */

#ifndef INCLUDE_WUMPUSDATA_H_
#define INCLUDE_WUMPUSDATA_H_

#include "RingBuffer.h"
#include "InformationElement.h"
#include <wumpus_simulator/ActionResponse.h>
#include <wumpus_simulator/InitialPoseResponse.h>

#include <map>
#include <memory>

using namespace std;

namespace ttb
{

	class TTBWorldModel;
	class WumpusData
	{
	public:
		WumpusData(TTBWorldModel* wm, int ringBufferLength);
		virtual ~WumpusData();
		int fieldSize;

		void processActionResponse(wumpus_simulator::ActionResponsePtr actionResponse);
		void processInitialPoseResponse(wumpus_simulator::InitialPoseResponsePtr initialPoseResponse);

		shared_ptr<wumpus_simulator::ActionResponse> getActionResponse(int index = 0);
		shared_ptr<wumpus_simulator::InitialPoseResponse> getInitialPoseResponse(int index = 0);

	private:
		int ownID;
		int ringBufferLength;
		unsigned long maxInformationAge;
		TTBWorldModel* wm;
		RingBuffer<InformationElement<wumpus_simulator::ActionResponse>> actionsResponses;
		RingBuffer<InformationElement<wumpus_simulator::InitialPoseResponse>> initialPoseResponses;
	};

} /* namespace ttb */

#endif /* INCLUDE_WUMPUSDATA_H_ */
