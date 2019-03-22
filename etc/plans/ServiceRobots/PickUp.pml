{
  "id" : 1553186320902,
  "name" : "PickUp",
  "comment" : null,
  "relativeDirectory" : "ServiceRobots",
  "variables" : [ {
    "id" : 1553251224214,
    "name" : "entity",
    "comment" : "the thing that should be picked up",
    "variableType" : null
  } ],
  "masterPlan" : false,
  "utilityThreshold" : 0.0,
  "preCondition" : null,
  "runtimeCondition" : {
    "id" : 1553251210748,
    "name" : "1553251210748",
    "comment" : null,
    "enabled" : true,
    "conditionString" : null,
    "pluginName" : "DefaultPlugin",
    "variables" : [ 1553251224214 ],
    "quantifiers" : [ ]
  },
  "entryPoints" : [ {
    "id" : 1553250907083,
    "name" : "1553250907083",
    "comment" : null,
    "successRequired" : false,
    "minCardinality" : 0,
    "maxCardinality" : 0,
    "task" : "ServiceRobotsTasks.tsk#1553250786927",
    "state" : 1553250909709,
    "plan" : 1553186320902
  } ],
  "states" : [ {
    "type" : "State",
    "id" : 1553250909207,
    "name" : "Grap",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1553186320902,
    "abstractPlans" : "ServiceRobots/Behaviours/PickUp.beh#1553251475582, ",
    "parametrisations" : [ ],
    "outTransitions" : [ 1553251064992, 1553251068088, 1553251090038 ],
    "inTransitions" : [ 1553251083850 ]
  }, {
    "type" : "State",
    "id" : 1553250909709,
    "name" : "DriveToPickUpPos",
    "comment" : "",
    "entryPoint" : 1553250907083,
    "parentPlan" : 1553186320902,
    "abstractPlans" : "ServiceRobots/Behaviours/DriveCloseToObject.beh#1553251534505, ",
    "parametrisations" : [ ],
    "outTransitions" : [ 1553251071386, 1553251083850 ],
    "inTransitions" : [ 1553251090038 ]
  }, {
    "type" : "TerminalState",
    "id" : 1553250911977,
    "name" : "PickUpFail",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1553186320902,
    "abstractPlans" : "",
    "parametrisations" : [ ],
    "outTransitions" : [ ],
    "inTransitions" : [ 1553251068088 ],
    "success" : false,
    "postCondition" : null
  }, {
    "type" : "TerminalState",
    "id" : 1553250912679,
    "name" : "DriveToObjectFail",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1553186320902,
    "abstractPlans" : "",
    "parametrisations" : [ ],
    "outTransitions" : [ ],
    "inTransitions" : [ 1553251071386 ],
    "success" : false,
    "postCondition" : null
  }, {
    "type" : "TerminalState",
    "id" : 1553250914917,
    "name" : "PickedUp",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1553186320902,
    "abstractPlans" : "",
    "parametrisations" : [ ],
    "outTransitions" : [ ],
    "inTransitions" : [ 1553251064992 ],
    "success" : true,
    "postCondition" : null
  } ],
  "transitions" : [ {
    "id" : 1553251064992,
    "name" : "FromGrapToPickedUp",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553250909207,
    "outState" : 1553250914917,
    "preCondition" : {
      "id" : 1553251380427,
      "name" : "1553251380427",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "successfully picked up object",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1553251068088,
    "name" : "FromGrapToPickUpFail",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553250909207,
    "outState" : 1553250911977,
    "preCondition" : {
      "id" : 1553251368286,
      "name" : "1553251368286",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "Failed to pick up object",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1553251071386,
    "name" : "FromDriveToPickUpPosToDriveToObjectFail",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553250909709,
    "outState" : 1553250912679,
    "preCondition" : {
      "id" : 1553251355730,
      "name" : "1553251355730",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "object position not available",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1553251083850,
    "name" : "FromDriveToPickUpPosToGrap",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553250909709,
    "outState" : 1553250909207,
    "preCondition" : {
      "id" : 1553251337135,
      "name" : "1553251337135",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "arrived at poi",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1553251090038,
    "name" : "FromGrapToDriveToPickUpPos",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553250909207,
    "outState" : 1553250909709,
    "preCondition" : {
      "id" : 1553251329784,
      "name" : "1553251329784",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "pos not reached",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  } ],
  "synchronisations" : [ ]
}