<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1519913821580" name="DriveToPOI" comment="" destinationPath="Plans/Serve" priority="0.0" minCardinality="0" maxCardinality="2147483647" masterPlan="false" utilityFunction="" utilityThreshold="0.1">
  <vars id="1519913984042" name="door" comment="" Type=""/>
  <vars id="1519913989387" name="poi" comment="" Type=""/>
  <runtimeCondition id="1519914269940" name="NewRuntimeCondition" comment="" conditionString="" pluginName="DefaultPlugin">
    <vars>Serve/DriveToPOI.pml#1519913984042</vars>
    <vars>Serve/DriveToPOI.pml#1519913989387</vars>
  </runtimeCondition>
  <states id="1519913874345" name="DriveToPOI" comment="" entryPoint="1519913874346">
    <parametrisation id="1519914162033" name="MISSING_NAME" comment="">
      <subplan xsi:type="alica:Behaviour">Behaviours/DriveToPOI.beh#1454329856163</subplan>
      <subvar>Behaviours/DriveToPOI.beh#1519914156317</subvar>
      <var>Serve/DriveToPOI.pml#1519913989387</var>
    </parametrisation>
    <plans xsi:type="alica:Behaviour">Behaviours/DriveToPOI.beh#1454329856163</plans>
    <inTransitions>Serve/DriveToPOI.pml#1519913901227</inTransitions>
    <outTransitions>Serve/DriveToPOI.pml#1519913899492</outTransitions>
    <outTransitions>Serve/DriveToPOI.pml#1519914091859</outTransitions>
    <outTransitions>Serve/DriveToPOI.pml#1519914331850</outTransitions>
  </states>
  <states id="1519913892405" name="OpenDoor" comment="">
    <parametrisation id="1519914173337" name="MISSING_NAME" comment="">
      <subplan xsi:type="alica:Behaviour">Behaviours/OpenDoor.beh#1519913953735</subplan>
      <subvar>Behaviours/OpenDoor.beh#1519914169008</subvar>
      <var>Serve/DriveToPOI.pml#1519913984042</var>
    </parametrisation>
    <plans xsi:type="alica:Behaviour">Behaviours/OpenDoor.beh#1519913953735</plans>
    <inTransitions>Serve/DriveToPOI.pml#1519913899492</inTransitions>
    <outTransitions>Serve/DriveToPOI.pml#1519913901227</outTransitions>
    <outTransitions>Serve/DriveToPOI.pml#1519914329278</outTransitions>
  </states>
  <states xsi:type="alica:SuccessState" id="1519914080351" name="AtGoalPOI" comment="">
    <inTransitions>Serve/DriveToPOI.pml#1519914091859</inTransitions>
  </states>
  <states xsi:type="alica:FailureState" id="1519914308674" name="WasBlocked" comment="">
    <inTransitions>Serve/DriveToPOI.pml#1519914329278</inTransitions>
    <inTransitions>Serve/DriveToPOI.pml#1519914331850</inTransitions>
  </states>
  <transitions id="1519913899492" name="MISSING_NAME" comment="From POI to door: current POI should be reached." msg="">
    <preCondition id="1519913901102" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>Serve/DriveToPOI.pml#1519913874345</inState>
    <outState>Serve/DriveToPOI.pml#1519913892405</outState>
  </transitions>
  <transitions id="1519913901227" name="MISSING_NAME" comment="From Door to POI state: Door should be open now." msg="">
    <preCondition id="1519913902356" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>Serve/DriveToPOI.pml#1519913892405</inState>
    <outState>Serve/DriveToPOI.pml#1519913874345</outState>
  </transitions>
  <transitions id="1519914091859" name="MISSING_NAME" comment="Goal POI reached" msg="">
    <preCondition id="1519914093807" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>Serve/DriveToPOI.pml#1519913874345</inState>
    <outState>Serve/DriveToPOI.pml#1519914080351</outState>
  </transitions>
  <transitions id="1519914329278" name="MISSING_NAME" comment="Unable to open some door!" msg="">
    <preCondition id="1519914331734" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>Serve/DriveToPOI.pml#1519913892405</inState>
    <outState>Serve/DriveToPOI.pml#1519914308674</outState>
  </transitions>
  <transitions id="1519914331850" name="MISSING_NAME" comment="Unable to get to the goal POI" msg="">
    <preCondition id="1519914333760" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>Serve/DriveToPOI.pml#1519913874345</inState>
    <outState>Serve/DriveToPOI.pml#1519914308674</outState>
  </transitions>
  <entryPoints id="1519913874346" name="MISSING_NAME" comment="" successRequired="true" minCardinality="0" maxCardinality="2147483647">
    <task>taskrepository.tsk#1414681164704</task>
    <state>Serve/DriveToPOI.pml#1519913874345</state>
  </entryPoints>
</alica:Plan>
