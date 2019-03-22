{
  "id" : 1553186258644,
  "name" : "Serve",
  "comment" : null,
  "relativeDirectory" : "ServiceRobots",
  "variables" : [ ],
  "masterPlan" : false,
  "utilityThreshold" : 0.0,
  "preCondition" : null,
  "runtimeCondition" : null,
  "entryPoints" : [ {
    "id" : 1553186334263,
    "name" : "1553186334263",
    "comment" : null,
    "successRequired" : false,
    "minCardinality" : 0,
    "maxCardinality" : 0,
    "task" : "ServiceRobotsTasks.tsk#1528875085489",
    "state" : 1553186329060,
    "plan" : 1553186258644
  } ],
  "states" : [ {
    "type" : "State",
    "id" : 1553186329060,
    "name" : "WaitForTask",
    "comment" : "",
    "entryPoint" : 1553186334263,
    "parentPlan" : 1553186258644,
    "abstractPlans" : "ServiceRobots/Behaviours/Stop.beh#1553185137554, ",
    "parametrisations" : [ ],
    "outTransitions" : [ 1553186806326, 1553186839271, 1553186914413, 1553186936424 ],
    "inTransitions" : [ 1553245775226, 1553246232965, 1553246237498, 1553246242651 ]
  }, {
    "type" : "State",
    "id" : 1553186370876,
    "name" : "DriveToPOI",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1553186258644,
    "abstractPlans" : "ServiceRobots/DriveToPOI.pml#1553186299639, ",
    "parametrisations" : [ ],
    "outTransitions" : [ 1553245775226 ],
    "inTransitions" : [ 1553186806326 ]
  }, {
    "type" : "State",
    "id" : 1553186372096,
    "name" : "PickUp",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1553186258644,
    "abstractPlans" : "ServiceRobots/PickUp.pml#1553186320902, ",
    "parametrisations" : [ ],
    "outTransitions" : [ 1553246232965 ],
    "inTransitions" : [ 1553186839271 ]
  }, {
    "type" : "State",
    "id" : 1553186373294,
    "name" : "PutDown",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1553186258644,
    "abstractPlans" : "ServiceRobots/PutDown.pml#1553186313956, ",
    "parametrisations" : [ ],
    "outTransitions" : [ 1553246237498 ],
    "inTransitions" : [ 1553186914413 ]
  }, {
    "type" : "State",
    "id" : 1553186374398,
    "name" : "SearchFor",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1553186258644,
    "abstractPlans" : "ServiceRobots/Search.pml#1553186306469, ",
    "parametrisations" : [ ],
    "outTransitions" : [ 1553246242651 ],
    "inTransitions" : [ 1553186936424 ]
  } ],
  "transitions" : [ {
    "id" : 1553186806326,
    "name" : "FromWaitForTaskToDriveToPOI",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553186329060,
    "outState" : 1553186370876,
    "preCondition" : {
      "id" : 1553186819414,
      "name" : "1553186819414",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "POI received",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1553186839271,
    "name" : "FromWaitForTaskToPickUp",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553186329060,
    "outState" : 1553186372096,
    "preCondition" : {
      "id" : 1553186845525,
      "name" : "1553186845525",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "start pick up",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1553186914413,
    "name" : "FromWaitForTaskToPutDown",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553186329060,
    "outState" : 1553186373294,
    "preCondition" : {
      "id" : 1553186921238,
      "name" : "1553186921238",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "start put down",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1553186936424,
    "name" : "FromWaitForTaskToSearchFor",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553186329060,
    "outState" : 1553186374398,
    "preCondition" : {
      "id" : 1553186941342,
      "name" : "1553186941342",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "start box search",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1553245775226,
    "name" : "FromDriveToPOIToWaitForTask",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553186370876,
    "outState" : 1553186329060,
    "preCondition" : {
      "id" : 1553246543385,
      "name" : "1553246543385",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "reached goal | failed",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1553246232965,
    "name" : "FromPickUpToWaitForTask",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553186372096,
    "outState" : 1553186329060,
    "preCondition" : {
      "id" : 1553246504180,
      "name" : "1553246504180",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "picked up",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1553246237498,
    "name" : "FromPutDownToWaitForTask",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553186373294,
    "outState" : 1553186329060,
    "preCondition" : {
      "id" : 1553246517033,
      "name" : "1553246517033",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "finished putting object down",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1553246242651,
    "name" : "FromSearchForToWaitForTask",
    "comment" : "MISSING_COMMENT",
    "inState" : 1553186374398,
    "outState" : 1553186329060,
    "preCondition" : {
      "id" : 1553246528041,
      "name" : "1553246528041",
      "comment" : null,
      "enabled" : true,
      "conditionString" : "found all boxes",
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  } ],
  "synchronisations" : [ ]
}