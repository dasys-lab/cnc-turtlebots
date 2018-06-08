<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1520438299583" name="PickUp" comment="" destinationPath="Plans/Serve" priority="0.0" minCardinality="0" maxCardinality="2147483647" masterPlan="false" utilityFunction="" utilityThreshold="0.1">
  <vars id="1520438389375" name="entity" comment="" Type=""/>
  <runtimeCondition id="1520438401434" name="NewRuntimeCondition" comment="" conditionString="" pluginName="DefaultPlugin">
    <vars>Serve/PickUp.pml#1520438389375</vars>
  </runtimeCondition>
  <states id="1520438315109" name="DriveToPickUpPos" comment="" entryPoint="1520438315110">
    <parametrisation id="1520603215322" name="MISSING_NAME" comment="">
      <subplan xsi:type="alica:Behaviour">Behaviours/DriveCloseToObject.beh#1520521852939</subplan>
      <subvar>Behaviours/DriveCloseToObject.beh#1520603151573</subvar>
      <var>Serve/PickUp.pml#1520438389375</var>
    </parametrisation>
    <plans xsi:type="alica:Behaviour">Behaviours/DriveCloseToObject.beh#1520521852939</plans>
    <inTransitions>Serve/PickUp.pml#1520518910440</inTransitions>
    <outTransitions>Serve/PickUp.pml#1520438351648</outTransitions>
    <outTransitions>Serve/PickUp.pml#1520589542298</outTransitions>
  </states>
  <states id="1520438338624" name="Grap" comment="">
    <parametrisation id="1520438802179" name="MISSING_NAME" comment="">
      <subplan xsi:type="alica:Behaviour">Behaviours/PickUp.beh#1520438451345</subplan>
      <subvar>Behaviours/PickUp.beh#1520438797719</subvar>
      <var>Serve/PickUp.pml#1520438389375</var>
    </parametrisation>
    <plans xsi:type="alica:Behaviour">Behaviours/PickUp.beh#1520438451345</plans>
    <inTransitions>Serve/PickUp.pml#1520438351648</inTransitions>
    <outTransitions>Serve/PickUp.pml#1520438354450</outTransitions>
    <outTransitions>Serve/PickUp.pml#1520516953565</outTransitions>
    <outTransitions>Serve/PickUp.pml#1520518910440</outTransitions>
  </states>
  <states xsi:type="alica:SuccessState" id="1520438345249" name="PickedUp" comment="">
    <inTransitions>Serve/PickUp.pml#1520438354450</inTransitions>
  </states>
  <states xsi:type="alica:FailureState" id="1520516913557" name="PickUpFail" comment="">
    <inTransitions>Serve/PickUp.pml#1520516953565</inTransitions>
  </states>
  <states xsi:type="alica:FailureState" id="1520589504282" name="DriveToObjectFail" comment="">
    <inTransitions>Serve/PickUp.pml#1520589542298</inTransitions>
  </states>
  <transitions id="1520438351648" name="MISSING_NAME" comment="arrived at poi" msg="">
    <preCondition id="1520438352890" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>Serve/PickUp.pml#1520438315109</inState>
    <outState>Serve/PickUp.pml#1520438338624</outState>
  </transitions>
  <transitions id="1520438354450" name="MISSING_NAME" comment="successfully picked up object" msg="">
    <preCondition id="1520438355739" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>Serve/PickUp.pml#1520438338624</inState>
    <outState>Serve/PickUp.pml#1520438345249</outState>
  </transitions>
  <transitions id="1520516953565" name="MISSING_NAME" comment="Failed to pick up object" msg="">
    <preCondition id="1520516954761" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>Serve/PickUp.pml#1520438338624</inState>
    <outState>Serve/PickUp.pml#1520516913557</outState>
  </transitions>
  <transitions id="1520518910440" name="MISSING_NAME" comment="pos not reached" msg="">
    <preCondition id="1520518912633" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>Serve/PickUp.pml#1520438338624</inState>
    <outState>Serve/PickUp.pml#1520438315109</outState>
  </transitions>
  <transitions id="1520589542298" name="MISSING_NAME" comment="object position not available" msg="">
    <preCondition id="1520589543849" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>Serve/PickUp.pml#1520438315109</inState>
    <outState>Serve/PickUp.pml#1520589504282</outState>
  </transitions>
  <entryPoints id="1520438315110" name="FetchEP" comment="" successRequired="true" minCardinality="0" maxCardinality="2147483647">
    <task>taskrepository.tsk#1520438413494</task>
    <state>Serve/PickUp.pml#1520438315109</state>
  </entryPoints>
</alica:Plan>
