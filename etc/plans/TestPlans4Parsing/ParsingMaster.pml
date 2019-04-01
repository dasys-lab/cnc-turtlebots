{
  "id" : 1554119089093,
  "name" : "ParsingMaster",
  "comment" : null,
  "relativeDirectory" : "TestPlans4Parsing",
  "variables" : [ ],
  "masterPlan" : true,
  "utilityThreshold" : 0.0,
  "preCondition" : null,
  "runtimeCondition" : null,
  "entryPoints" : [ {
    "id" : 1554119152379,
    "name" : "1554119152379",
    "comment" : null,
    "successRequired" : false,
    "minCardinality" : 0,
    "maxCardinality" : 0,
    "task" : "ServiceRobotsTasks.tsk#1528875085489",
    "state" : 1554119147402,
    "plan" : 1554119089093
  } ],
  "states" : [ {
    "type" : "State",
    "id" : 1554119147402,
    "name" : "Default Name",
    "comment" : "",
    "entryPoint" : 1554119152379,
    "parentPlan" : 1554119089093,
    "abstractPlans" : [ "TestPlans4Parsing/PT1.pty#1554119168374" ],
    "parametrisations" : [ ],
    "outTransitions" : [ ],
    "inTransitions" : [ 1554121191105 ]
  }, {
    "type" : "State",
    "id" : 1554121185525,
    "name" : "Default Name",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1554119089093,
    "abstractPlans" : [ "ServiceRobots/Behaviours/DriveToPOI.beh#1553249791474" ],
    "parametrisations" : [ ],
    "outTransitions" : [ 1554121191105 ],
    "inTransitions" : [ ]
  } ],
  "transitions" : [ {
    "id" : 1554121191105,
    "name" : "FromDefault NameToDefault Name",
    "comment" : "MISSING_COMMENT",
    "inState" : 1554121185525,
    "outState" : 1554119147402,
    "preCondition" : null,
    "synchronisation" : 1554121183572
  } ],
  "synchronisations" : [ {
    "id" : 1554121183572,
    "name" : "Sync Default",
    "comment" : "",
    "talkTimeout" : 0,
    "syncTimeout" : 0,
    "failOnSyncTimeout" : false,
    "plan" : 1554119089093,
    "syncedTransitions" : [ 1554121191105 ]
  } ]
}