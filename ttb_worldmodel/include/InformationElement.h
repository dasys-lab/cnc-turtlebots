/*
 * InformationElement.h
 *
 *  Created on: May 13, 2014
 *      Author: sni
 */

#ifndef INFORMATIONELEMENT_H_
#define INFORMATIONELEMENT_H_

#include <memory>

namespace ttb
{

	typedef signed long long InfoTime;

//* InformationElement
/**
 * Information element stores one information and provides required meta
 * data. The information can not be changed.
 *
 */
template<typename T>
  class InformationElement
  {
  public:
    /*!
     * \brief Default constructor
     *
     * Default constructor
     *
     * \param information The information to store.
     * \param timeStamp time when information is received.
     */
    InformationElement(std::shared_ptr<T> information,unsigned long timeStamp) : information(information), timeStamp(timeStamp)
    {
    }

    /*!
     * \brief Default destructor
     *
     * Default destructor
     */
    virtual ~InformationElement()
    {
      //
    }

    /*!
     * \brief Returns the information stored in this container.
     *
     * Returns the information stored in this container.
     */
    std::shared_ptr<T> getInformation() const
    {
      return this->information;
    }
    unsigned long timeStamp; /**< validity time of the information */
    double certainty;

  private:
    std::shared_ptr<T> information; /**< the stored information */
  };

} /* namespace ice */

#endif /* INFORMATIONELEMENT_H_ */
