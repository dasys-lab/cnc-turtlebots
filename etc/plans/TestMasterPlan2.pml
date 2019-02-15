{
  "id" : 1535539810067,
  "name" : "TestMasterPlan2",
  "comment" : "Test Comment String",
  "relativeDirectory" : "",
  "masterPlan" : true,
  "utilityThreshold" : 0.0,
  "preCondition" : {
    "id" : 1550238664553,
    "name" : "1550238664553",
    "comment" : null,
    "conditionString" : null,
    "pluginName" : "DefaultPlugin",
    "enabled" : false,
    "variables" : [ ],
    "quantifiers" : [ ]
  },
  "runtimeCondition" : {
    "id" : 1550238674404,
    "name" : "1550238674404",
    "comment" : null,
    "conditionString" : null,
    "pluginName" : "DefaultPlugin",
    "enabled" : false,
    "variables" : [ ],
    "quantifiers" : [ ]
  },
  "entryPoints" : [ {
    "id" : 1535539810163,
    "name" : "TestEP",
    "comment" : null,
    "successRequired" : false,
    "minCardinality" : 1,
    "maxCardinality" : 2,
    "task" : "TurtleBot2.tsk#1532076462542",
    "state" : 1535539810162,
    "plan" : 1535539810067
  } ],
  "states" : [ {
    "type" : "State",
    "id" : 1535539810077,
    "name" : "Stop",
    "comment" : "Stops the robot",
    "entryPoint" : null,
    "parentPlan" : 1535539810067,
    "plans" : "",
    "parametrisations" : [ ],
    "inTransitions" : [ ],
    "outTransitions" : [ 1535539810166 ]
  }, {
    "type" : "State",
    "id" : 1535539810162,
    "name" : "Stop2",
    "comment" : "Stops the robot too",
    "entryPoint" : 1535539810163,
    "parentPlan" : 1535539810067,
    "plans" : "abc.pml#1534253305877, ",
    "parametrisations" : [ {
      "id" : 1550249703548,
      "name" : "1550249703548",
      "comment" : null,
      "subPlan" : "abc.pml#1534253305877",
      "subVariable" : "abc.pml#1550244736864",
      "variable" : null
    } ],
    "inTransitions" : [ 1535539810166 ],
    "outTransitions" : [ ]
  }, {
    "type" : "TerminalState",
    "id" : 1550238482719,
    "name" : "Default Name",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1535539810067,
    "plans" : "",
    "parametrisations" : [ ],
    "inTransitions" : [ ],
    "outTransitions" : [ ],
    "postCondition" : null,
    "success" : true
  }, {
    "type" : "TerminalState",
    "id" : 1550238485259,
    "name" : "Default Name",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1535539810067,
    "plans" : "",
    "parametrisations" : [ ],
    "inTransitions" : [ ],
    "outTransitions" : [ ],
    "postCondition" : null,
    "success" : false
  } ],
  "transitions" : [ {
    "id" : 1535539810166,
    "name" : "1535539810166",
    "comment" : null,
    "inState" : 1535539810162,
    "outState" : 1535539810077,
    "preCondition" : null,
    "synchronisation" : null
  }, {
    "id" : 1550238546974,
    "name" : "1550238546974",
    "comment" : null,
    "inState" : 1535539810077,
    "outState" : 1550238482719,
    "preCondition" : null,
    "synchronisation" : null
  }, {
    "id" : 1550238549951,
    "name" : "1550238549951",
    "comment" : null,
    "inState" : 1535539810077,
    "outState" : 1550238485259,
    "preCondition" : null,
    "synchronisation" : null
  } ],
  "synchronisations" : [ ],
  "variables" : [ {
    "id" : 1550238656475,
    "name" : "NEW_VARIABLE",
    "comment" : null,
    "variableType" : null,
    "parentPlan" : null
  }, {
    "id" : 1550249706341,
    "name" : "NEW_VARIABLE",
    "comment" : null,
    "variableType" : null,
    "parentPlan" : 1535539810067
  } ]
}