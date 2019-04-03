{
  "id" : 1553186306469,
  "name" : "Search",
  "comment" : null,
  "relativeDirectory" : "ServiceRobots",
  "variables" : [ {
    "id" : 1553508638691,
    "name" : "entity",
    "comment" : "the thing that should be found",
    "variableType" : null
  } ],
  "masterPlan" : false,
  "utilityThreshold" : 0.0,
  "preCondition" : null,
  "runtimeCondition" : {
    "id" : 1553508629606,
    "name" : "1553508629606",
    "comment" : null,
    "enabled" : true,
    "conditionString" : null,
    "pluginName" : "DefaultPlugin",
    "variables" : [ 1553508638691 ],
    "quantifiers" : [ ]
  },
  "entryPoints" : [ {
    "id" : 1553508539549,
    "name" : "1553508539549",
    "comment" : null,
    "successRequired" : false,
    "minCardinality" : 0,
    "maxCardinality" : 0,
    "task" : "ServiceRobotsTasks.tsk#1553508529074",
    "state" : 1553508561976,
    "plan" : 1553186306469
  } ],
  "states" : [ {
    "type" : "State",
    "id" : 1553508561976,
    "name" : "DriveAround",
    "comment" : "",
    "entryPoint" : 1553508539549,
    "parentPlan" : 1553186306469,
    "abstractPlans" : [ "ServiceRobots/Behaviours/Sweep.beh#1553508619994" ],
    "variableBindings" : [ {
      "id" : 1554285376584,
      "name" : "1554285376584",
      "comment" : null,
      "variable" : 1553508638691,
      "subPlan" : "ServiceRobots/Behaviours/Sweep.beh#1553508619994",
      "subVariable" : "ServiceRobots/Behaviours/Sweep.beh#1554285365317"
    } ],
    "outTransitions" : [ 1553508681887 ],
    "inTransitions" : [ ]
  }, {
    "type" : "TerminalState",
    "id" : 1553508588008,
    "name" : "FoundEntity",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1553186306469,
    "abstractPlans" : [ ],
    "variableBindings" : [ ],
    "outTransitions" : [ ],
    "inTransitions" : [ 1553508681887 ],
    "success" : true,
    "postCondition" : null
  } ],
  "transitions" : [ {
    "id" : 1553508681887,
    "name" : "FromDriveAroundToFoundEntity",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553508561976,
    "outState" : 1553508588008,
    "preCondition" : {
      "id" : 1553508688960,
      "name" : "1553508688960",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "entity found",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  } ],
  "synchronisations" : [ ]
}