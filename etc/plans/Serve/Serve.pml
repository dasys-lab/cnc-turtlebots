<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1454331313621" name="Serve" comment="" masterPlan="false" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans/Serve" priority="0.0" minCardinality="0" maxCardinality="2147483647">
  <states id="1454331321919" name="WaitForTask" comment="" entryPoint="1454331321920">
    <plans xsi:type="alica:BehaviourConfiguration">../Behaviours/Stop.beh#1414681278745</plans>
    <inTransitions>#1454331501621</inTransitions>
    <inTransitions>#1486383766847</inTransitions>
    <inTransitions>#1486383788195</inTransitions>
    <inTransitions>#1520511978130</inTransitions>
    <outTransitions>#1454331382859</outTransitions>
    <outTransitions>#1454331384188</outTransitions>
    <outTransitions>#1486383786264</outTransitions>
    <outTransitions>#1520511976445</outTransitions>
  </states>
  <states id="1454331334336" name="DriveToPOI" comment="">
    <plans xsi:type="alica:Plan">DriveToPOI.pml#1519913821580</plans>
    <inTransitions>#1454331382859</inTransitions>
    <outTransitions>#1454331501621</outTransitions>
  </states>
  <states id="1454331358257" name="SearchFor" comment="">
    <plans xsi:type="alica:Plan">Search.pml#1520437018620</plans>
    <inTransitions>#1454331384188</inTransitions>
    <outTransitions>#1486383766847</outTransitions>
  </states>
  <states id="1486383776159" name="PickUp" comment="">
    <plans xsi:type="alica:Plan">PickUp.pml#1520438299583</plans>
    <inTransitions>#1486383786264</inTransitions>
    <outTransitions>#1486383788195</outTransitions>
  </states>
  <states id="1520511867671" name="PutDown" comment="">
    <plans xsi:type="alica:Plan">PutDown.pml#1520511951867</plans>
    <inTransitions>#1520511976445</inTransitions>
    <outTransitions>#1520511978130</outTransitions>
  </states>
  <transitions id="1454331382859" name="MISSING_NAME" comment="POI received" msg="">
    <preCondition id="1454331384091" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1454331321919</inState>
    <outState>#1454331334336</outState>
  </transitions>
  <transitions id="1454331384188" name="MISSING_NAME" comment="start box search" msg="">
    <preCondition id="1454331385501" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1454331321919</inState>
    <outState>#1454331358257</outState>
  </transitions>
  <transitions id="1454331501621" name="MISSING_NAME" comment="reached goal | failed" msg="">
    <preCondition id="1454331503425" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1454331334336</inState>
    <outState>#1454331321919</outState>
  </transitions>
  <transitions id="1486383766847" name="MISSING_NAME" comment="found all boxes" msg="">
    <preCondition id="1486383768270" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1454331358257</inState>
    <outState>#1454331321919</outState>
  </transitions>
  <transitions id="1486383786264" name="MISSING_NAME" comment="start pick up" msg="">
    <preCondition id="1486383787970" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1454331321919</inState>
    <outState>#1486383776159</outState>
  </transitions>
  <transitions id="1486383788195" name="MISSING_NAME" comment="picked up" msg="">
    <preCondition id="1486383790747" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1486383776159</inState>
    <outState>#1454331321919</outState>
  </transitions>
  <transitions id="1520511976445" name="MISSING_NAME" comment="start put down" msg="">
    <preCondition id="1520511978036" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1454331321919</inState>
    <outState>#1520511867671</outState>
  </transitions>
  <transitions id="1520511978130" name="MISSING_NAME" comment="finished putting object down" msg="">
    <preCondition id="1520511979544" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1520511867671</inState>
    <outState>#1454331321919</outState>
  </transitions>
  <entryPoints id="1454331321920" name="MISSING_NAME" comment="" successRequired="false" minCardinality="0" maxCardinality="2147483647">
    <task>../../Misc/taskrepository.tsk#1414681164704</task>
    <state>#1454331321919</state>
  </entryPoints>
</alica:Plan>
