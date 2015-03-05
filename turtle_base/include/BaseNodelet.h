/*
 * BaseNodelet.h
 *
 *  Created on: Feb 19, 2015
 *      Author: Jonas Scherbaum
 */

#ifndef CNC_TURTLEBOTS_TURTLE_BASE_INCLUDE_BASENODELET_H_
#define CNC_TURTLEBOTS_TURTLE_BASE_INCLUDE_BASENODELET_H_

#include <nodelet/nodelet.h>
#include <iostream>
#include "Base.h"

using namespace std;

namespace turtle {

  class BaseNodelet : public nodelet::Nodelet {
    public:
      //BaseNodelet();
      //~BaseNodelet();
      virtual void onInit();
      boost::shared_ptr<turtle::Base> inst_;
  };

}


#endif /* CNC_TURTLEBOTS_TURTLE_BASE_INCLUDE_BASENODELET_H_ */
