{
  "id" : 1528810473500,
  "name" : "TestMasterPlan",
  "comment" : "Test Comment String",
  "relativeDirectory" : "result.json",
  "masterPlan" : true,
  "activated" : true,
  "utilityThreshold" : 0.0,
  "preCondition" : null,
  "runtimeCondition" : null,
  "entryPoints" : [ {
    "id" : 1528810473595,
    "name" : "TestEP",
    "comment" : null,
    "task" : "result.json/taskrepository.tsk#1528810473598",
    "successRequired" : false,
    "state" : 1528810473502,
    "plan" : 1528810473500,
    "minCardinality" : 1,
    "maxCardinality" : 2
  } ],
  "states" : [ {
    "id" : 1528810473502,
    "name" : "Stop",
    "comment" : "Stops the robot",
    "entryPoint" : 1528810473595,
    "parentPlan" : 1528810473500,
    "plans" : "result.json/TestBehaviour.beh#1528810473503, result.json/TestBehaviour2.beh#1528810473592, ",
    "parametrisations" : [ ],
    "inTransitions" : [ ],
    "outTransitions" : [ ]
  }, {
    "id" : 1528810473593,
    "name" : "Stop2",
    "comment" : "Stops the robot too",
    "entryPoint" : null,
    "parentPlan" : 1528810473500,
    "plans" : "",
    "parametrisations" : [ ],
    "inTransitions" : [ ],
    "outTransitions" : [ ]
  } ],
  "transitions" : [ ],
  "synchronizations" : [ ],
  "variables" : [ ]
}
