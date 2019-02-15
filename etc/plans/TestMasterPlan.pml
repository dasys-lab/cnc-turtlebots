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
    "state" : 1549540314646,
    "plan" : 1528810473500
  }, {
    "id" : 1549540818844,
    "name" : "1549540818844",
    "comment" : null,
    "successRequired" : false,
    "minCardinality" : 0,
    "maxCardinality" : 0,
    "task" : "TurtleBot2.tsk#1531986856778",
    "state" : 1549540526226,
    "plan" : 1528810473500
  } ],
  "states" : [ {
    "type" : "State",
    "id" : 1528810473502,
    "name" : "Stop",
    "comment" : "Stops the robot",
    "entryPoint" : null,
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
  }, {
    "type" : "TerminalState",
    "id" : 1549540314646,
    "name" : "Default Name",
    "comment" : "",
    "entryPoint" : 1528810473595,
    "parentPlan" : 1528810473500,
    "plans" : "",
    "parametrisations" : [ ],
    "inTransitions" : [ ],
    "outTransitions" : [ ],
    "postCondition" : null,
    "success" : true
  }, {
    "type" : "TerminalState",
    "id" : 1549540322070,
    "name" : "Default Name",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1528810473500,
    "plans" : "",
    "parametrisations" : [ ],
    "inTransitions" : [ ],
    "outTransitions" : [ ],
    "postCondition" : null,
    "success" : false
  }, {
    "type" : "TerminalState",
    "id" : 1549540325776,
    "name" : "Default Name",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1528810473500,
    "plans" : "",
    "parametrisations" : [ ],
    "inTransitions" : [ ],
    "outTransitions" : [ ],
    "postCondition" : null,
    "success" : false
  }, {
    "type" : "TerminalState",
    "id" : 1549540326250,
    "name" : "Default Name",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1528810473500,
    "plans" : "",
    "parametrisations" : [ ],
    "inTransitions" : [ ],
    "outTransitions" : [ ],
    "postCondition" : null,
    "success" : false
  }, {
    "type" : "TerminalState",
    "id" : 1549540426195,
    "name" : "Default Name",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1528810473500,
    "plans" : "",
    "parametrisations" : [ ],
    "inTransitions" : [ ],
    "outTransitions" : [ ],
    "postCondition" : null,
    "success" : false
  }, {
    "type" : "State",
    "id" : 1549540519918,
    "name" : "Default Name",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1528810473500,
    "plans" : "",
    "parametrisations" : [ ],
    "inTransitions" : [ ],
    "outTransitions" : [ ]
  }, {
    "type" : "State",
    "id" : 1549540521392,
    "name" : "Default Name",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1528810473500,
    "plans" : "",
    "parametrisations" : [ ],
    "inTransitions" : [ ],
    "outTransitions" : [ ]
  }, {
    "type" : "State",
    "id" : 1549540526226,
    "name" : "Default Name",
    "comment" : "",
    "entryPoint" : 1549540818844,
    "parentPlan" : 1528810473500,
    "plans" : "",
    "parametrisations" : [ ],
    "inTransitions" : [ ],
    "outTransitions" : [ ]
  } ],
  "transitions" : [ {
    "id" : 1549540610150,
    "name" : "1549540610150",
    "comment" : null,
    "inState" : 1549540314646,
    "outState" : 1549540519918,
    "preCondition" : null,
    "synchronisation" : null
  }, {
    "id" : 1549540621720,
    "name" : "1549540621720",
    "comment" : null,
    "inState" : 1549540521392,
    "outState" : 1549540326250,
    "preCondition" : null,
    "synchronisation" : null
  }, {
    "id" : 1549540625530,
    "name" : "1549540625530",
    "comment" : null,
    "inState" : 1549540326250,
    "outState" : 1549540426195,
    "preCondition" : null,
    "synchronisation" : null
  }, {
    "id" : 1549540644716,
    "name" : "1549540644716",
    "comment" : null,
    "inState" : 1549540314646,
    "outState" : 1528810473593,
    "preCondition" : null,
    "synchronisation" : null
  }, {
    "id" : 1549540649574,
    "name" : "1549540649574",
    "comment" : null,
    "inState" : 1549540314646,
    "outState" : 1549540526226,
    "preCondition" : null,
    "synchronisation" : null
  } ],
  "synchronisations" : [ {
    "id" : 1549540704303,
    "name" : "Sync Default",
    "comment" : "",
    "talkTimeout" : 0,
    "syncTimeout" : 0,
    "failOnSyncTimeout" : false,
    "syncedTransitions" : [ 1549540625530 ]
  }, {
    "id" : 1549540705521,
    "name" : "Sync Default",
    "comment" : "",
    "talkTimeout" : 0,
    "syncTimeout" : 0,
    "failOnSyncTimeout" : false,
    "syncedTransitions" : [ 1549540625530 ]
  }, {
    "id" : 1549540708914,
    "name" : "Sync Default",
    "comment" : "",
    "talkTimeout" : 0,
    "syncTimeout" : 0,
    "failOnSyncTimeout" : false,
    "syncedTransitions" : [ ]
  } ],
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
