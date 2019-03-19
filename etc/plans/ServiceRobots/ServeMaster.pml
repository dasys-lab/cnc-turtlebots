{
  "id" : 1552995667134,
  "name" : "ServeMaster",
  "comment" : null,
  "relativeDirectory" : "ServiceRobots",
  "variables" : [ ],
  "masterPlan" : true,
  "utilityThreshold" : 0.0,
  "preCondition" : null,
  "runtimeCondition" : null,
  "entryPoints" : [ {
    "id" : 1552996396322,
    "name" : "1552996396322",
    "comment" : null,
    "successRequired" : false,
    "minCardinality" : 0,
    "maxCardinality" : 0,
    "task" : "ServiceRobotsTasks.tsk#1528875085489",
    "state" : 1552996403396,
    "plan" : 1552995667134
  } ],
  "states" : [ {
    "type" : "State",
    "id" : 1552996403396,
    "name" : "Stop",
    "comment" : "",
    "entryPoint" : 1552996396322,
    "parentPlan" : 1552995667134,
    "plans" : "ServiceRobots/Stop.beh#1552996811900, ",
    "parametrisations" : [ ],
    "inTransitions" : [ 1552999344041, 1552999417491 ],
    "outTransitions" : [ 1552996591281 ]
  }, {
    "type" : "State",
    "id" : 1552996404209,
    "name" : "Serve",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1552995667134,
    "plans" : "ServiceRobots/Serve.pml#1552996823626, ",
    "parametrisations" : [ ],
    "inTransitions" : [ 1552996591281, 1552996768903 ],
    "outTransitions" : [ 1552999417491 ]
  }, {
    "type" : "State",
    "id" : 1552996405055,
    "name" : "Charge",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1552995667134,
    "plans" : "ServiceRobots/Charge.pml#1552996829354, ",
    "parametrisations" : [ ],
    "inTransitions" : [ ],
    "outTransitions" : [ 1552996768903, 1552999344041 ]
  } ],
  "transitions" : [ {
    "id" : 1552996591281,
    "name" : "MISSING_NAME",
    "comment" : "FromStopToServe",
    "inState" : 1552996403396,
    "outState" : 1552996404209,
    "preCondition" : {
      "id" : 1552999126699,
      "name" : "1552999126699",
      "comment" : "Start received",
      "conditionString" : null,
      "pluginName" : "DefaultPlugin",
      "enabled" : true,
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1552996768903,
    "name" : "MISSING_NAME",
    "comment" : "FromChargeToServe",
    "inState" : 1552996405055,
    "outState" : 1552996404209,
    "preCondition" : {
      "id" : 1552997671153,
      "name" : "1552997671153",
      "comment" : "fully charged (child success)",
      "conditionString" : null,
      "pluginName" : "DefaultPlugin",
      "enabled" : true,
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1552999344041,
    "name" : "MISSING_NAME",
    "comment" : "FromChargeToStop",
    "inState" : 1552996405055,
    "outState" : 1552996403396,
    "preCondition" : {
      "id" : 1552999379581,
      "name" : "1552999379581",
      "comment" : "Stop received",
      "conditionString" : null,
      "pluginName" : "DefaultPlugin",
      "enabled" : true,
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1552999417491,
    "name" : "MISSING_NAME",
    "comment" : "FromServeToStop",
    "inState" : 1552996404209,
    "outState" : 1552996403396,
    "preCondition" : {
      "id" : 1552999434614,
      "name" : "1552999434614",
      "comment" : "Stop received",
      "conditionString" : null,
      "pluginName" : "DefaultPlugin",
      "enabled" : true,
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  } ],
  "synchronisations" : [ ]
}