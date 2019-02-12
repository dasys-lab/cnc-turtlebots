{
  "id" : 1535539810067,
  "name" : "TestMasterPlan2",
  "comment" : "Test Comment String",
  "relativeDirectory" : "",
  "masterPlan" : true,
  "utilityThreshold" : 0.0,
  "preCondition" : null,
  "runtimeCondition" : null,
  "entryPoints" : [ {
    "id" : 1535539810163,
    "name" : "TestEP",
    "comment" : null,
    "successRequired" : false,
    "minCardinality" : 1,
    "maxCardinality" : 2,
    "task" : "TurtleBot2.tsk#1528875085489",
    "state" : 1535539810077,
    "plan" : 1535539810067
  } ],
  "states" : [ {
    "type" : "State",
    "id" : 1535539810077,
    "name" : "Stop",
    "comment" : "Stops the robot",
    "entryPoint" : 1535539810163,
    "parentPlan" : 1535539810067,
    "plans" : "Behaviours/RunForest2.beh#1530628964195, ",
    "parametrisations" : [ ],
    "inTransitions" : [ ],
    "outTransitions" : [ 1535539810166 ]
  }, {
    "type" : "State",
    "id" : 1535539810162,
    "name" : "Stop2",
    "comment" : "Stops the robot too",
    "entryPoint" : null,
    "parentPlan" : 1535539810067,
    "plans" : "abc.pml#1534253305877, ",
    "parametrisations" : [ ],
    "inTransitions" : [ 1535539810166 ],
    "outTransitions" : [ ]
  } ],
  "transitions" : [ {
    "id" : 1535539810166,
    "name" : "1535539810166",
    "comment" : null,
    "inState" : 1535539810162,
    "outState" : 1535539810077,
    "preCondition" : null,
    "synchronization" : null
  } ],
  "synchronizations" : [ ],
  "variables" : [ {
    "id" : 1548951610618,
    "name" : "NEW_VARIABLE",
    "comment" : null,
    "variableType" : null
  }, {
    "id" : 1548951613175,
    "name" : "NEW_VARIABLE",
    "comment" : null,
    "variableType" : null
  } ]
}
