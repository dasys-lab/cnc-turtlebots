<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1520438299583" name="PickUp" comment="" masterPlan="false" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans/Serve" priority="0.0" minCardinality="0" maxCardinality="2147483647">
  <conditions xsi:type="alica:RuntimeCondition" id="1520438401434" name="NewRuntimeCondition" comment="" conditionString="" pluginName="DefaultPlugin">
    <vars>#1520438389375</vars>
  </conditions>
  <vars id="1520438389375" name="entity" comment="" Type=""/>
  <states id="1520438315109" name="DriveToPickUpPos" comment="" entryPoint="1520438315110">
    <parametrisation id="1520438789175" name="MISSING_NAME" comment="">
      <subplan xsi:type="alica:BehaviourConfiguration">../Behaviours/DriveToPOI.beh#1519913781149</subplan>
      <subvar>../Behaviours/DriveToPOI.beh#1519914156317</subvar>
      <var>#1520438389375</var>
    </parametrisation>
    <plans xsi:type="alica:BehaviourConfiguration">../Behaviours/DriveToPOI.beh#1519913781149</plans>
    <inTransitions>#1520438353049</inTransitions>
    <outTransitions>#1520438351648</outTransitions>
  </states>
  <states id="1520438338624" name="Grap" comment="">
    <parametrisation id="1520438802179" name="MISSING_NAME" comment="">
      <subplan xsi:type="alica:BehaviourConfiguration">../Behaviours/PickUp.beh#1520438478153</subplan>
      <subvar>../Behaviours/PickUp.beh#1520438797719</subvar>
      <var>#1520438389375</var>
    </parametrisation>
    <plans xsi:type="alica:BehaviourConfiguration">../Behaviours/PickUp.beh#1520438478153</plans>
    <inTransitions>#1520438351648</inTransitions>
    <outTransitions>#1520438353049</outTransitions>
    <outTransitions>#1520438354450</outTransitions>
  </states>
  <states xsi:type="alica:SuccessState" id="1520438345249" name="PickedUp" comment="">
    <inTransitions>#1520438354450</inTransitions>
  </states>
  <transitions id="1520438351648" name="MISSING_NAME" comment="" msg="">
    <preCondition id="1520438352890" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1520438315109</inState>
    <outState>#1520438338624</outState>
  </transitions>
  <transitions id="1520438353049" name="MISSING_NAME" comment="" msg="">
    <preCondition id="1520438354263" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1520438338624</inState>
    <outState>#1520438315109</outState>
  </transitions>
  <transitions id="1520438354450" name="MISSING_NAME" comment="" msg="">
    <preCondition id="1520438355739" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1520438338624</inState>
    <outState>#1520438345249</outState>
  </transitions>
  <entryPoints id="1520438315110" name="FetchEP" comment="" successRequired="true" minCardinality="0" maxCardinality="2147483647">
    <task>../../Misc/taskrepository.tsk#1520438413494</task>
    <state>#1520438315109</state>
  </entryPoints>
</alica:Plan>
