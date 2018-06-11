[ {
  "id" : 1528730596687,
  "name" : "TestMasterPlan",
  "comment" : "Test Comment String",
  "dirty" : false,
  "relativeDirectory" : "result.json",
  "masterPlan" : true,
  "activated" : true,
  "utilityThreshold" : 0.0,
  "preCondition" : null,
  "runtimeCondition" : null,
  "transitions" : [ ],
  "states" : [ {
    "id" : 1528730596689,
    "name" : "Stop",
    "comment" : "Stops the robot",
    "dirty" : false,
    "entryPoint" : {
      "id" : 1528730596690,
      "name" : "TestEP",
      "comment" : null,
      "dirty" : false,
      "task" : {
        "id" : 1528730596691,
        "name" : "DefaultTask",
        "comment" : null,
        "dirty" : false
      },
      "successRequired" : false,
      "state" : null,
      "plan" : null,
      "minCardinality" : 1,
      "maxCardinality" : 2
    },
    "parentPlan" : null,
    "plans" : null,
    "parametrisations" : null,
    "inTransitions" : null,
    "outTransitions" : null
  } ],
  "synchronizations" : [ ],
  "entryPoints" : [ {
    "id" : 1528730596690,
    "name" : "TestEP",
    "comment" : null,
    "dirty" : false,
    "task" : {
      "id" : 1528730596691,
      "name" : "DefaultTask",
      "comment" : null,
      "dirty" : false
    },
    "successRequired" : false,
    "state" : null,
    "plan" : null,
    "minCardinality" : 1,
    "maxCardinality" : 2
  } ],
  "variables" : [ ]
}, {
  "id" : 1528730596689,
  "name" : "Stop",
  "comment" : "Stops the robot",
  "dirty" : false,
  "entryPoint" : {
    "id" : 1528730596690,
    "name" : "TestEP",
    "comment" : null,
    "dirty" : false,
    "task" : {
      "id" : 1528730596691,
      "name" : "DefaultTask",
      "comment" : null,
      "dirty" : false
    },
    "successRequired" : false,
    "state" : null,
    "plan" : null,
    "minCardinality" : 1,
    "maxCardinality" : 2
  },
  "parentPlan" : null,
  "plans" : null,
  "parametrisations" : null,
  "inTransitions" : null,
  "outTransitions" : null
}, {
  "id" : 1528730596690,
  "name" : "TestEP",
  "comment" : null,
  "dirty" : false,
  "task" : {
    "id" : 1528730596691,
    "name" : "DefaultTask",
    "comment" : null,
    "dirty" : false
  },
  "successRequired" : false,
  "state" : null,
  "plan" : null,
  "minCardinality" : 1,
  "maxCardinality" : 2
}, {
  "id" : 1528730596691,
  "name" : "DefaultTask",
  "comment" : null,
  "dirty" : false
} ]
