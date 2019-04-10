{
  "id" : 1553186299639,
  "name" : "DriveToPOI",
  "comment" : null,
  "relativeDirectory" : "ServiceRobots",
  "variables" : [ {
    "id" : 1553249844851,
    "name" : "door",
    "comment" : "the next door that needs to be opened",
    "variableType" : null
  }, {
    "id" : 1553249850610,
    "name" : "poi",
    "comment" : "the poi to drive to",
    "variableType" : null
  } ],
  "masterPlan" : false,
  "utilityThreshold" : 0.0,
  "preCondition" : null,
  "runtimeCondition" : {
    "id" : 1553249831272,
    "name" : "1553249831272",
    "comment" : null,
    "enabled" : true,
    "conditionString" : null,
    "pluginName" : "DefaultPlugin",
    "variables" : [ 1553249850610, 1553249844851 ],
    "quantifiers" : [ ]
  },
  "entryPoints" : [ {
    "id" : 1553246730787,
    "name" : "1553246730787",
    "comment" : null,
    "successRequired" : true,
    "minCardinality" : 0,
    "maxCardinality" : 100,
    "task" : "ServiceRobotsTasks.tsk#1528875085489",
    "state" : 1553246732403,
    "plan" : 1553186299639
  } ],
  "states" : [ {
    "type" : "State",
    "id" : 1553246732403,
    "name" : "DriveToPOI",
    "comment" : "",
    "entryPoint" : 1553246730787,
    "parentPlan" : 1553186299639,
    "abstractPlans" : [ "ServiceRobots/Behaviours/DriveToPOI.beh#1553249791474" ],
    "variableBindings" : [ {
      "id" : 1554282861783,
      "name" : "1554282861783",
      "comment" : null,
      "variable" : 1553249850610,
      "subPlan" : "ServiceRobots/Behaviours/DriveToPOI.beh#1553249791474",
      "subVariable" : "ServiceRobots/Behaviours/DriveToPOI.beh#1554282847422"
    } ],
    "outTransitions" : [ 1553247377749, 1553249685249, 1553249715180 ],
    "inTransitions" : [ 1553249723948 ]
  }, {
    "type" : "State",
    "id" : 1553246733927,
    "name" : "OpenDoor",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1553186299639,
    "abstractPlans" : [ "ServiceRobots/Behaviours/OpenDoor.beh#1553249804320" ],
    "variableBindings" : [ {
      "id" : 1554282973434,
      "name" : "1554282973434",
      "comment" : null,
      "variable" : 1553249844851,
      "subPlan" : "ServiceRobots/Behaviours/OpenDoor.beh#1553249804320",
      "subVariable" : "ServiceRobots/Behaviours/OpenDoor.beh#1554146721173"
    } ],
    "outTransitions" : [ 1553249711754, 1553249723948 ],
    "inTransitions" : [ 1553247377749 ]
  }, {
    "type" : "TerminalState",
    "id" : 1553246736188,
    "name" : "AtGoalPOI",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1553186299639,
    "abstractPlans" : [ ],
    "variableBindings" : [ ],
    "outTransitions" : [ ],
    "inTransitions" : [ 1553249685249 ],
    "success" : true,
    "postCondition" : null
  }, {
    "type" : "TerminalState",
    "id" : 1553246738057,
    "name" : "WasBlocked",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1553186299639,
    "abstractPlans" : [ ],
    "variableBindings" : [ ],
    "outTransitions" : [ ],
    "inTransitions" : [ 1553249711754, 1553249715180 ],
    "success" : false,
    "postCondition" : null
  } ],
  "transitions" : [ {
    "id" : 1553247377749,
    "name" : "FromDriveToPOIToOpenDoor",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553246732403,
    "outState" : 1553246733927,
    "preCondition" : {
      "id" : 1553249924824,
      "name" : "1553249924824",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "From POI to door: current POI should be reached.",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1553249685249,
    "name" : "FromDriveToPOIToAtGoalPOI",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553246732403,
    "outState" : 1553246736188,
    "preCondition" : {
      "id" : 1553249983248,
      "name" : "1553249983248",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "Goal POI reached",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1553249711754,
    "name" : "FromOpenDoorToWasBlocked",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553246733927,
    "outState" : 1553246738057,
    "preCondition" : {
      "id" : 1553250009834,
      "name" : "1553250009834",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "Unable to open some door!",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1553249715180,
    "name" : "FromDriveToPOIToWasBlocked",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553246732403,
    "outState" : 1553246738057,
    "preCondition" : {
      "id" : 1553249994733,
      "name" : "1553249994733",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "Unable to get to the goal POI",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1553249723948,
    "name" : "FromOpenDoorToDriveToPOI",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553246733927,
    "outState" : 1553246732403,
    "preCondition" : {
      "id" : 1553249888743,
      "name" : "1553249888743",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "From Door to POI state: Door should be open now.",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  } ],
  "synchronisations" : [ ]
}