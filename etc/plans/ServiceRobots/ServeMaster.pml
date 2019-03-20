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
    "abstractPlans" : "ServiceRobots/Stop.beh#1552996811900, ",
    "parametrisations" : [ ],
    "outTransitions" : [ 1553086257494 ],
    "inTransitions" : [ 1552999344041, 1552999417491 ]
  }, {
    "type" : "State",
    "id" : 1552996404209,
    "name" : "Serve",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1552995667134,
    "abstractPlans" : "ServiceRobots/Serve.pml#1552996823626, ",
    "parametrisations" : [ ],
    "outTransitions" : [ 1552999417491, 1553086051443 ],
    "inTransitions" : [ 1552996768903, 1553086257494 ]
  }, {
    "type" : "State",
    "id" : 1552996405055,
    "name" : "Charge",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1552995667134,
    "abstractPlans" : "ServiceRobots/Charge.pml#1552996829354, ",
    "parametrisations" : [ ],
    "outTransitions" : [ 1552996768903, 1552999344041 ],
    "inTransitions" : [ 1553086051443 ]
  } ],
  "transitions" : [ {
    "id" : 1552996768903,
    "name" : "MISSING_NAME",
    "comment" : "FromChargeToServe",
    "inState" : 1552996405055,
    "outState" : 1552996404209,
    "preCondition" : {
      "id" : 1552997671153,
      "name" : "1552997671153",
      "comment" : "fully charged (child success)",
      "enabled" : true,
      "conditionString" : "",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1552999344041,
    "name" : "FromChargeToStop",
    "comment" : "FromChargeToStop",
    "inState" : 1552996405055,
    "outState" : 1552996403396,
    "preCondition" : {
      "id" : 1552999379581,
      "name" : "1552999379581",
      "comment" : "Stop received",
      "enabled" : true,
      "conditionString" : null,
      "pluginName" : "DefaultPlugin",
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
      "enabled" : true,
      "conditionString" : null,
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1553086051443,
    "name" : "FromServeToCharge",
    "comment" : null,
    "inState" : 1552996404209,
    "outState" : 1552996405055,
    "preCondition" : {
      "id" : 1553086059295,
      "name" : "1553086059295",
      "comment" : "low accu (not implemented, yet)",
      "enabled" : true,
      "conditionString" : null,
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1553086257494,
    "name" : "FromStopToServe",
    "comment" : null,
    "inState" : 1552996403396,
    "outState" : 1552996404209,
    "preCondition" : {
      "id" : 1553086274283,
      "name" : "1553086274283",
      "comment" : "Start received",
      "enabled" : true,
      "conditionString" : null,
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  } ],
  "synchronisations" : [ ]
}