///*
// * WumpusData.cpp
// *
// *  Created on: Mar 16, 2017
// *      Author: Lab User 5
// */
//
//#include <WumpusData.h>
//#include "TTBWorldModel.h"
//
//namespace ttb
//{
//
//	WumpusData::WumpusData(TTBWorldModel* wm, int ringBufferLength) : ringBufferLength(ringBufferLength),
//			actionsResponses(ringBufferLength), initialPoseResponses(ringBufferLength)
//	{
//		this->wm = wm;
//		this->fieldSize = -1;
//		this->ownID = wm->sc->getOwnRobotID();
//		maxInformationAge = 1000000000;
//		ownStartPos = nullptr;
//		this->heading = 0;
//	}
//
//	WumpusData::~WumpusData()
//	{
//		// TODO Auto-generated destructor stub
//	}
//
//	void WumpusData::processActionResponse(wumpus_simulator::ActionResponsePtr actionResponse)
//	{
//		InfoTime time = wm->getTime();
//		shared_ptr<wumpus_simulator::ActionResponse> actionResponsePtr = shared_ptr<wumpus_simulator::ActionResponse>(
//				actionResponse.get(), [actionResponse](wumpus_simulator::ActionResponse*) mutable
//				{	actionResponse.reset();});
//		shared_ptr<InformationElement<wumpus_simulator::ActionResponse>> ownactionResponse = make_shared<
//				InformationElement<wumpus_simulator::ActionResponse>>(actionResponsePtr, time);
//		actionsResponses.add(ownactionResponse);
//	}
//
//	void WumpusData::processInitialPoseResponse(wumpus_simulator::InitialPoseResponsePtr initialPoseResponse)
//	{
//		InfoTime time = wm->getTime();
//		shared_ptr<wumpus_simulator::InitialPoseResponse> initialPoseResponsePtr = shared_ptr<wumpus_simulator::InitialPoseResponse>(
//				initialPoseResponse.get(), [initialPoseResponse](wumpus_simulator::InitialPoseResponse*) mutable
//				{	initialPoseResponse.reset();});
//		shared_ptr<InformationElement<wumpus_simulator::InitialPoseResponse>> owninitialPoseResponse = make_shared<
//				InformationElement<wumpus_simulator::InitialPoseResponse>>(initialPoseResponsePtr, time);
//		initialPoseResponses.add(owninitialPoseResponse);
//		if(ownStartPos == nullptr && initialPoseResponsePtr->agentId == this->ownID)
//		{
//			this->ownStartPos = make_shared<geometry::CNPoint2D>(initialPoseResponsePtr->x, initialPoseResponsePtr->y );
//			this->fieldSize = initialPoseResponsePtr->fieldSize;
//			this->heading = initialPoseResponsePtr->heading;
//		}
//	}
//
//	shared_ptr<wumpus_simulator::ActionResponse> WumpusData::getActionResponse(int index)
//	{
//		auto x = actionsResponses.getLast(index);
//
//		if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
//		{
//			return nullptr;
//		}
//
//		return x->getInformation();
//	}
//
//	shared_ptr<wumpus_simulator::InitialPoseResponse> WumpusData::getInitialPoseResponse(int index)
//	{
//		auto x = initialPoseResponses.getLast(index);
//
//		if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
//		{
//			return nullptr;
//		}
//
//		return x->getInformation();
//	}
//
//	int WumpusData::getOwnId()
//	{
//		return ownID;
//	}
//
//} /* namespace ttb */
//
//
