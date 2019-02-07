{
  "id" : 1528810473500,
  "name" : "TestMasterPlan",
  "comment" : "Test Comment String",
  "relativeDirectory" : "",
  "masterPlan" : true,
  "utilityThreshold" : 0.5,
  "preCondition" : null,
  "runtimeCondition" : null,
  "entryPoints" : [ {
    "id" : 1528810473595,
    "name" : "TestEP",
    "comment" : null,
    "successRequired" : false,
    "minCardinality" : 1,
    "maxCardinality" : 2,
    "task" : "TurtleBot2.tsk#1528875085489",
    "state" : 1528810473502,
    "plan" : 1528810473500
  } ],
  "states" : [ {
    "type" : "State",
    "id" : 1528810473502,
    "name" : "Stop",
    "comment" : "Stops the robot",
    "entryPoint" : 1528810473595,
    "parentPlan" : 1528810473500,
    "plans" : "",
    "parametrisations" : [ ],
    "inTransitions" : [ ],
    "outTransitions" : [ ]
  }, {
    "type" : "State",
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
  "variables" : [ {
    "id" : 1549536108736,
    "name" : "2221",
    "comment" : "asdf",
    "variableType" : "a"
  }, {
    "id" : 1549538237387,
    "name" : "NEW_VARIABLE",
    "comment" : null,
    "variableType" : null
  } ]
}