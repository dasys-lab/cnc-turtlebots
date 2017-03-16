/*
 * WumpusData.cpp
 *
 *  Created on: Mar 16, 2017
 *      Author: Lab User 5
 */

#include <WumpusData.h>
#include "TTBWorldModel.h"

namespace ttb
{

	WumpusData::WumpusData(TTBWorldModel* wm, int ringBufferLength) :
			actionsResponses(ringBufferLength), initialPoseResponses(ringBufferLength)
	{
		this->wm = wm;
		this->ringBufferLength = ringBufferLength;
		this->fieldSize = -1;
		this->ownID = 0;
		maxInformationAge = 1000000000;
	}

	WumpusData::~WumpusData()
	{
		// TODO Auto-generated destructor stub
	}

	void WumpusData::processActionResponse(wumpus_simulator::ActionResponsePtr actionResponse)
	{
		InfoTime time = wm->getTime();
		shared_ptr<wumpus_simulator::ActionResponse> initialPoseResponsePtr = shared_ptr<wumpus_simulator::ActionResponse>(
				actionResponse.get(), [actionResponse](wumpus_simulator::ActionResponse*) mutable
				{	actionResponse.reset();});
		shared_ptr<InformationElement<wumpus_simulator::ActionResponse>> ownactionResponse = make_shared<
				InformationElement<wumpus_simulator::ActionResponse>>(initialPoseResponsePtr, time);
		actionsResponses.add(ownactionResponse);
	}

	void WumpusData::processInitialPoseResponse(wumpus_simulator::InitialPoseResponsePtr initialPoseResponse)
	{
		InfoTime time = wm->getTime();
		shared_ptr<wumpus_simulator::InitialPoseResponse> initialPoseResponsePtr = shared_ptr<wumpus_simulator::InitialPoseResponse>(
				initialPoseResponse.get(), [initialPoseResponse](wumpus_simulator::InitialPoseResponse*) mutable
				{	initialPoseResponse.reset();});
		shared_ptr<InformationElement<wumpus_simulator::InitialPoseResponse>> owninitialPoseResponse = make_shared<
				InformationElement<wumpus_simulator::InitialPoseResponse>>(initialPoseResponsePtr, time);
		initialPoseResponses.add(owninitialPoseResponse);
	}

	shared_ptr<wumpus_simulator::ActionResponse> WumpusData::getActionResponse(int index)
	{
		auto x = actionsResponses.getLast(index);

		if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
		{
			return nullptr;
		}

		return x->getInformation();
	}

	shared_ptr<wumpus_simulator::InitialPoseResponse> WumpusData::getInitialPoseResponse(int index)
	{
		auto x = initialPoseResponses.getLast(index);

		if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
		{
			return nullptr;
		}

		return x->getInformation();
	}

} /* namespace ttb */
