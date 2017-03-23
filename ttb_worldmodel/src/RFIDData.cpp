/*
 * RFIDData.cpp
 *
 *  Created on: Mar 2, 2017
 *      Author: lab-user
 */

#include <RFIDData.h>
#include <TTBWorldModel.h>

namespace ttb
{
namespace wm
{

RFIDData::RFIDData(TTBWorldModel *wm, int ringBufferLength) : rfidSensorData(ringBufferLength)
{
	this->ringBufferLength = ringBufferLength;
	this->wm = wm;
	maxInformationAge = 1000000000;
}

RFIDData::~RFIDData()
{
    // TODO Auto-generated destructor stub
}

void RFIDData::processRFIDData(ttb_msgs::RFIDSensorPtr rfidData)
{
    InfoTime time = wm->getTime();

    shared_ptr<ttb_msgs::RFIDSensor> serveTaskPtr =
        shared_ptr<ttb_msgs::RFIDSensor>(rfidData.get(), [rfidData](ttb_msgs::RFIDSensor *) mutable { rfidData.reset(); });
    shared_ptr<InformationElement<ttb_msgs::RFIDSensor>> ownRFIDData = make_shared<InformationElement<ttb_msgs::RFIDSensor>>(serveTaskPtr, time);
    rfidSensorData.add(ownRFIDData);
}



shared_ptr<ttb_msgs::RFIDSensor> RFIDData::getRFIDData(int index)
{
    auto x = rfidSensorData.getLast(index);

    if (x == nullptr || wm->getTime() - x->timeStamp > maxInformationAge)
    {
        return nullptr;
    }

    return x->getInformation();
}



} /* namespace wm */
} /* namespace ttb */
