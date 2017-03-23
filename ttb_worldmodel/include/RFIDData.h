/*
 * RIFDData.h
 *
 *  Created on: Mar 2, 2017
 *      Author: lab-user
 */

#ifndef INCLUDE_RFIDDATA_H_
#define INCLUDE_RFIDDATA_H_

#include "RingBuffer.h"
#include "InformationElement.h"
#include "ttb_msgs/RFIDSensor.h"

namespace ttb {
	class TTBWorldModel;
}

namespace ttb
{
namespace wm
{

class RFIDData
{
  public:
    RFIDData(TTBWorldModel* wm, int ringBufferLength);
    virtual ~RFIDData();

	void processRFIDData(ttb_msgs::RFIDSensorPtr rfidData);

	shared_ptr<ttb_msgs::RFIDSensor> getRFIDData(int index = 0);

  private:
	TTBWorldModel* wm;
	unsigned long maxInformationAge;
	int ringBufferLength;
	RingBuffer<InformationElement<ttb_msgs::RFIDSensor>> rfidSensorData;

};

} /* namespace wm */
} /* namespace ttb */

#endif /* INCLUDE_RFIDDATA_H_ */
