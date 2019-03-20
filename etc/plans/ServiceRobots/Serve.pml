{
  "id" : 1552996823626,
  "name" : "Serve",
  "comment" : null,
  "relativeDirectory" : "ServiceRobots",
  "variables" : [ ],
  "masterPlan" : false,
  "utilityThreshold" : 0.0,
  "preCondition" : null,
  "runtimeCondition" : null,
  "entryPoints" : [ {
    "id" : 1552996861087,
    "name" : "1552996861087",
    "comment" : null,
    "successRequired" : false,
    "minCardinality" : 0,
    "maxCardinality" : 0,
    "task" : "ServiceRobotsTasks.tsk#1528875085489",
    "state" : 1552996863380,
    "plan" : 1552996823626
  } ],
  "states" : [ {
    "type" : "State",
    "id" : 1552996863380,
    "name" : "WaitForTask",
    "comment" : "",
    "entryPoint" : 1552996861087,
    "parentPlan" : 1552996823626,
    "abstractPlans" : "ServiceRobots/Stop.beh#1552996811900, ",
    "parametrisations" : [ ],
    "outTransitions" : [ 1552997093129, 1552997165525, 1552997169007 ],
    "inTransitions" : [ 1552998019217, 1552998040332, 1552998049553 ]
  }, {
    "type" : "State",
    "id" : 1552997081975,
    "name" : "DriveTo",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1552996823626,
    "abstractPlans" : "ServiceRobots/DriveToWMsPOI.beh#1552997315918, ",
    "parametrisations" : [ ],
    "outTransitions" : [ 1552998019217 ],
    "inTransitions" : [ 1552997093129 ]
  }, {
    "type" : "State",
    "id" : 1552997082976,
    "name" : "PickUp",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1552996823626,
    "abstractPlans" : "ServiceRobots/PickUp.beh#1552997304057, ",
    "parametrisations" : [ ],
    "outTransitions" : [ 1552998040332 ],
    "inTransitions" : [ 1552997165525 ]
  }, {
    "type" : "State",
    "id" : 1552997084306,
    "name" : "SearchFor",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1552996823626,
    "abstractPlans" : "ServiceRobots/DriveSearchPattern.beh#1552997370653, ",
    "parametrisations" : [ ],
    "outTransitions" : [ 1552998049553 ],
    "inTransitions" : [ 1552997169007 ]
  } ],
  "transitions" : [ {
    "id" : 1552997093129,
    "name" : "MISSING_COMMENT",
    "comment" : "ToDriveTo",
    "inState" : 1552996863380,
    "outState" : 1552997081975,
    "preCondition" : {
      "id" : 1552997523219,
      "name" : "1552997523219",
      "comment" : "POI received",
      "enabled" : true,
      "conditionString" : null,
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1552997165525,
    "name" : "MISSING_COMMENT",
    "comment" : "ToPickUp",
    "inState" : 1552996863380,
    "outState" : 1552997082976,
    "preCondition" : {
      "id" : 1552997565145,
      "name" : "1552997565145",
      "comment" : "Need to pick something up",
      "enabled" : true,
      "conditionString" : null,
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1552997169007,
    "name" : "MISSING_COMMENT",
    "comment" : "ToSearchFor",
    "inState" : 1552996863380,
    "outState" : 1552997084306,
    "preCondition" : {
      "id" : 1552997575777,
      "name" : "1552997575777",
      "comment" : "Need to search for something",
      "enabled" : true,
      "conditionString" : null,
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1552998019217,
    "name" : "MISSING_COMMENT",
    "comment" : "ToStop",
    "inState" : 1552997081975,
    "outState" : 1552996863380,
    "preCondition" : {
      "id" : 1552998060293,
      "name" : "1552998060293",
      "comment" : "Stop received",
      "enabled" : true,
      "conditionString" : null,
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1552998040332,
    "name" : "MISSING_COMMENT",
    "comment" : "ToStop",
    "inState" : 1552997082976,
    "outState" : 1552996863380,
    "preCondition" : {
      "id" : 1552998086675,
      "name" : "1552998086675",
      "comment" : "Stop received",
      "enabled" : true,
      "conditionString" : null,
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1552998049553,
    "name" : "MISSING_COMMENT",
    "comment" : "ToStop",
    "inState" : 1552997084306,
    "outState" : 1552996863380,
    "preCondition" : {
      "id" : 1552998099101,
      "name" : "1552998099101",
      "comment" : "Stop received",
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