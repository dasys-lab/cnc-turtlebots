{
  "id" : 1553186270535,
  "name" : "Charge",
  "comment" : null,
  "relativeDirectory" : "ServiceRobots",
  "variables" : [ ],
  "masterPlan" : false,
  "utilityThreshold" : 0.0,
  "preCondition" : null,
  "runtimeCondition" : null,
  "entryPoints" : [ {
    "id" : 1553245568961,
    "name" : "1553245568961",
    "comment" : null,
    "successRequired" : false,
    "minCardinality" : 0,
    "maxCardinality" : 0,
    "task" : "ServiceRobotsTasks.tsk#1528875085489",
    "state" : 1553245570484,
    "plan" : 1553186270535
  } ],
  "states" : [ {
    "type" : "State",
    "id" : 1553245570484,
    "name" : "SearchDock",
    "comment" : "",
    "entryPoint" : 1553245568961,
    "parentPlan" : 1553186270535,
    "abstractPlans" : [ ],
    "parametrisations" : [ ],
    "outTransitions" : [ 1553245583942 ],
    "inTransitions" : [ ]
  }, {
    "type" : "State",
    "id" : 1553245570983,
    "name" : "ChargeAccu",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1553186270535,
    "abstractPlans" : [ ],
    "parametrisations" : [ ],
    "outTransitions" : [ 1553245593163 ],
    "inTransitions" : [ 1553245583942 ]
  }, {
    "type" : "TerminalState",
    "id" : 1553245572355,
    "name" : "FullyCharged",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1553186270535,
    "abstractPlans" : [ ],
    "parametrisations" : [ ],
    "outTransitions" : [ ],
    "inTransitions" : [ 1553245593163 ],
    "success" : true,
    "postCondition" : null
  } ],
  "transitions" : [ {
    "id" : 1553245583942,
    "name" : "FromDefault NameToDefault Name",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553245570484,
    "outState" : 1553245570983,
    "preCondition" : {
      "id" : 1553245704790,
      "name" : "1553245704790",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "docked | fully charged (child success)",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1553245593163,
    "name" : "FromDefault NameToDefault Name",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553245570983,
    "outState" : 1553245572355,
    "preCondition" : {
      "id" : 1553245713697,
      "name" : "1553245713697",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "accu full",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  } ],
  "synchronisations" : [ ]
}
