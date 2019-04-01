{
  "id" : 1553186313956,
  "name" : "PutDown",
  "comment" : null,
  "relativeDirectory" : "ServiceRobots",
  "variables" : [ {
    "id" : 1553506228672,
    "name" : "X",
    "comment" : "x coordinate to putdown the entity",
    "variableType" : null
  }, {
    "id" : 1553506233885,
    "name" : "Y",
    "comment" : "y coordinate to putdown the entity",
    "variableType" : null
  }, {
    "id" : 1553506237542,
    "name" : "Z",
    "comment" : "z coordinate to putdown the entity",
    "variableType" : null
  }, {
    "id" : 1553506241307,
    "name" : "entity",
    "comment" : "the thing that needs to be put down",
    "variableType" : null
  } ],
  "masterPlan" : false,
  "utilityThreshold" : 0.0,
  "preCondition" : null,
  "runtimeCondition" : {
    "id" : 1553506204186,
    "name" : "1553506204186",
    "comment" : null,
    "enabled" : true,
    "conditionString" : null,
    "pluginName" : "DefaultPlugin",
    "variables" : [ 1553506228672, 1553506233885, 1553506237542, 1553506241307 ],
    "quantifiers" : [ ]
  },
  "entryPoints" : [ {
    "id" : 1553251833164,
    "name" : "1553251833164",
    "comment" : null,
    "successRequired" : false,
    "minCardinality" : 0,
    "maxCardinality" : 0,
    "task" : "ServiceRobotsTasks.tsk#1528875085489",
    "state" : 1553251836208,
    "plan" : 1553186313956
  } ],
  "states" : [ {
    "type" : "State",
    "id" : 1553251836208,
    "name" : "DriveToPoint",
    "comment" : "",
    "entryPoint" : 1553251833164,
    "parentPlan" : 1553186313956,
    "abstractPlans" : [ "ServiceRobots/Behaviours/DriveToPoint.beh#1553508193766" ],
    "parametrisations" : [ ],
    "outTransitions" : [ 1553251878842, 1553503372591 ],
    "inTransitions" : [ 1553503358877 ]
  }, {
    "type" : "State",
    "id" : 1553251837742,
    "name" : "PutDown",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1553186313956,
    "abstractPlans" : [ "ServiceRobots/Behaviours/PutDown.beh#1553508167181" ],
    "parametrisations" : [ ],
    "outTransitions" : [ 1553503358877, 1553503376373, 1553503379375 ],
    "inTransitions" : [ 1553251878842 ]
  }, {
    "type" : "TerminalState",
    "id" : 1553251860992,
    "name" : "DriveToFailed",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1553186313956,
    "abstractPlans" : [ ],
    "parametrisations" : [ ],
    "outTransitions" : [ ],
    "inTransitions" : [ 1553503372591 ],
    "success" : false,
    "postCondition" : null
  }, {
    "type" : "TerminalState",
    "id" : 1553251862908,
    "name" : "FailedToPlaceObject",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1553186313956,
    "abstractPlans" : [ ],
    "parametrisations" : [ ],
    "outTransitions" : [ ],
    "inTransitions" : [ 1553503376373 ],
    "success" : false,
    "postCondition" : null
  }, {
    "type" : "TerminalState",
    "id" : 1553254969436,
    "name" : "ObjectPlaced",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1553186313956,
    "abstractPlans" : [ ],
    "parametrisations" : [ ],
    "outTransitions" : [ ],
    "inTransitions" : [ 1553503379375 ],
    "success" : true,
    "postCondition" : null
  } ],
  "transitions" : [ {
    "id" : 1553251878842,
    "name" : "FromDefault NameToDefault Name",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553251836208,
    "outState" : 1553251837742,
    "preCondition" : {
      "id" : 1553503395943,
      "name" : "1553503395943",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "Arrived at point",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1553503358877,
    "name" : "FromPutDownToDriveToPoint",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553251837742,
    "outState" : 1553251836208,
    "preCondition" : {
      "id" : 1553503411200,
      "name" : "1553503411200",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "PutDown to DriveToPoint",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1553503372591,
    "name" : "FromDriveToPointToDriveToFailed",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553251836208,
    "outState" : 1553251860992,
    "preCondition" : {
      "id" : 1553503428123,
      "name" : "1553503428123",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "failed to drive to point",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1553503376373,
    "name" : "FromPutDownToFailedToPlaceObject",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553251837742,
    "outState" : 1553251862908,
    "preCondition" : {
      "id" : 1553503439638,
      "name" : "1553503439638",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "Failed putting down",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1553503379375,
    "name" : "FromPutDownToObjectPlaced",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553251837742,
    "outState" : 1553254969436,
    "preCondition" : {
      "id" : 1553503451171,
      "name" : "1553503451171",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "Putting down Successful",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  } ],
  "synchronisations" : [ ]
}
