/*
 * Robots.cpp
 *
 *  Created on: Feb 23, 2015
 *      Author: Stefan Jakob
 */

#include <Robots.h>
#include "TTBWorldModel.h"

namespace ttb { namespace wm
{

	Robots::Robots(TTBWorldModel* wm, int ringBufferLength)
	{
		this->wm = wm;

	}

	Robots::~Robots()
	{
		// TODO Auto-generated destructor stub
	}

}} /* namespace ttb::wm */
