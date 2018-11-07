#pragma once

namespace ttb
{
namespace robot
{

enum MovementReturnState
{
    GoalReached,
    GoalFailed,
    GoalInProgress,
    OtherGoalAssigned,
    NoGoalAssigned
};

} /* namespace robot */
} /* namespace ttb */
