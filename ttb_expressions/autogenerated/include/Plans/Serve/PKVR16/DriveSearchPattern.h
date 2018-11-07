#ifndef DriveSearchPattern_H_
#define DriveSearchPattern_H_

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1481545714198) ENABLED START*/ // Add additional includes here
#include <geometry_msgs/Point.h>
/*PROTECTED REGION END*/
namespace alica
{
class DriveSearchPattern : public DomainBehaviour
{
public:
    DriveSearchPattern();
    virtual ~DriveSearchPattern();
    virtual void run(void* msg);
    /*PROTECTED REGION ID(pub1481545714198) ENABLED START*/ // Add additional public methods here
    /*PROTECTED REGION END*/
protected:
    virtual void initialiseParameters();
    /*PROTECTED REGION ID(pro1481545714198) ENABLED START*/ // Add additional protected methods here
    double scanRange;
    /*PROTECTED REGION END*/
private:
    /*PROTECTED REGION ID(prv1481545714198) ENABLED START*/ // Add additional private methods here
    double mapHeight;
    double mapWidth;
    double resolution;
    int pointsWidth;
    int pointsHeight;
    int listPoint = 0;
    double mapCorrectX;
    double mapCorrectY;
    double distanceGoalX;
    double distanceGoalY;
    double distanceToGoal;

    vector<geometry_msgs::Point> list;
        /*PROTECTED REGION END*/};
        } /* namespace alica */

#endif /* DriveSearchPattern_H_ */
