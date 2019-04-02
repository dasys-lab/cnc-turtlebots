{
  "id" : 1553184964252,
  "name" : "ServeMaster",
  "comment" : null,
  "relativeDirectory" : "ServiceRobots",
  "variables" : [ ],
  "masterPlan" : true,
  "utilityThreshold" : 0.0,
  "preCondition" : null,
  "runtimeCondition" : null,
  "entryPoints" : [ {
    "id" : 1553185666788,
    "name" : "1553185666788",
    "comment" : null,
    "successRequired" : false,
    "minCardinality" : 0,
    "maxCardinality" : 0,
    "task" : "ServiceRobotsTasks.tsk#1528875085489",
    "state" : 1553185656305,
    "plan" : 1553184964252
  } ],
  "states" : [ {
    "type" : "State",
    "id" : 1553185656305,
    "name" : "Stop",
    "comment" : "",
    "entryPoint" : 1553185666788,
    "parentPlan" : 1553184964252,
    "abstractPlans" : [ "ServiceRobots/Behaviours/Stop.beh#1553185137554" ],
    "variableBindings" : [ ],
    "outTransitions" : [ 1553185745471 ],
    "inTransitions" : [ 1553185754607, 1553186159975 ]
  }, {
    "type" : "State",
    "id" : 1553185657036,
    "name" : "Serve",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1553184964252,
    "abstractPlans" : [ "ServiceRobots/Serve.pml#1553186258644" ],
    "variableBindings" : [ ],
    "outTransitions" : [ 1553185750137, 1553186159975 ],
    "inTransitions" : [ 1553185745471, 1553186193775 ]
  }, {
    "type" : "State",
    "id" : 1553185657561,
    "name" : "Charge",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1553184964252,
    "abstractPlans" : [ "ServiceRobots/Charge.pml#1553186270535" ],
    "variableBindings" : [ ],
    "outTransitions" : [ 1553185754607, 1553186193775 ],
    "inTransitions" : [ 1553185750137 ]
  } ],
  "transitions" : [ {
    "id" : 1553185745471,
    "name" : "FromStopToServe",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553185656305,
    "outState" : 1553185657036,
    "preCondition" : {
      "id" : 1553185893509,
      "name" : "1553185893509",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "Start received",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1553185750137,
    "name" : "FromServeToCharge",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553185657036,
    "outState" : 1553185657561,
    "preCondition" : {
      "id" : 1553185932074,
      "name" : "1553185932074",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "low accu",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1553185754607,
    "name" : "FromChargeToStop",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553185657561,
    "outState" : 1553185656305,
    "preCondition" : {
      "id" : 1553185967081,
      "name" : "1553185967081",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "Stop received",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1553186159975,
    "name" : "FromServeToStop",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553185657036,
    "outState" : 1553185656305,
    "preCondition" : {
      "id" : 1553186173260,
      "name" : "1553186173260",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "Stop received",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1553186193775,
    "name" : "FromChargeToServe",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553185657561,
    "outState" : 1553185657036,
    "preCondition" : {
      "id" : 1553186199715,
      "name" : "1553186199715",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "fully charged (child success)",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  } ],
  "synchronisations" : [ ]
}
