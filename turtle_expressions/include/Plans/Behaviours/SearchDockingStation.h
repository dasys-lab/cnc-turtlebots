#ifndef SearchDockingStation_H_
#define SearchDockingStation_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1414681429307) ENABLED START*/ //Add additional includes here
/*PROTECTED REGION END*/
namespace alica
{
class SearchDockingStation : public DomainBehaviour
{
public:
  SearchDockingStation();
  virtual ~SearchDockingStation();
  virtual void run(void* msg);
  /*PROTECTED REGION ID(pub1414681429307) ENABLED START*/ //Add additional public methods here
  /*PROTECTED REGION END*/
protected:
  virtual void initialiseParameters();
  /*PROTECTED REGION ID(pro1414681429307) ENABLED START*/ //Add additional protected methods here
  /*PROTECTED REGION END*/
private:
  /*PROTECTED REGION ID(prv1414681429307) ENABLED START*/ //Add additional private methods here
  /*PROTECTED REGION END*/};
} /* namespace alica */

#endif /* SearchDockingStation_H_ */
