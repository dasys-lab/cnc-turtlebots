<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1520437018620" name="Search" comment="" masterPlan="false" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans/Serve" priority="0.0" minCardinality="0" maxCardinality="2147483647">
  <conditions xsi:type="alica:RuntimeCondition" id="1520437448508" name="NewRuntimeCondition" comment="" conditionString="" pluginName="DefaultPlugin">
    <vars>#1520437454401</vars>
  </conditions>
  <vars id="1520437454401" name="entity" comment="" Type=""/>
  <states id="1520437031577" name="DriveAround" comment="" entryPoint="1520437031578">
    <parametrisation id="1520437631553" name="MISSING_NAME" comment="">
      <subplan xsi:type="alica:BehaviourConfiguration">../Behaviours/Sweep.beh#1520437614544</subplan>
      <subvar>../Behaviours/Sweep.beh#1520437620566</subvar>
      <var>#1520437454401</var>
    </parametrisation>
    <plans xsi:type="alica:BehaviourConfiguration">../Behaviours/Sweep.beh#1520437614544</plans>
    <outTransitions>#1520438035537</outTransitions>
  </states>
  <states xsi:type="alica:SuccessState" id="1520438026668" name="FoundEntity" comment="">
    <inTransitions>#1520438035537</inTransitions>
  </states>
  <transitions id="1520438035537" name="MISSING_NAME" comment="" msg="">
    <preCondition id="1520438036937" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1520437031577</inState>
    <outState>#1520438026668</outState>
  </transitions>
  <entryPoints id="1520437031578" name="Search" comment="" successRequired="true" minCardinality="0" maxCardinality="2147483647">
    <task>../../Misc/taskrepository.tsk#1481544910904</task>
    <state>#1520437031577</state>
  </entryPoints>
</alica:Plan>
