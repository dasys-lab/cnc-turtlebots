<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1520437018620" name="Search" comment="" destinationPath="Plans/Serve" priority="0.0" minCardinality="0" maxCardinality="2147483647" masterPlan="false" utilityFunction="" utilityThreshold="0.1">
  <vars id="1520437454401" name="entity" comment="" Type=""/>
  <runtimeCondition id="1520437448508" name="NewRuntimeCondition" comment="" conditionString="" pluginName="DefaultPlugin">
    <vars>Serve/Search.pml#1520437454401</vars>
  </runtimeCondition>
  <states id="1520437031577" name="DriveAround" comment="" entryPoint="1520437031578">
    <parametrisation id="1520437631553" name="MISSING_NAME" comment="">
      <subplan xsi:type="alica:Behaviour">Behaviours/Sweep.beh#1520437499749</subplan>
      <subvar>Behaviours/Sweep.beh#1520437620566</subvar>
      <var>Serve/Search.pml#1520437454401</var>
    </parametrisation>
    <plans xsi:type="alica:Behaviour">Behaviours/Sweep.beh#1520437499749</plans>
    <outTransitions>Serve/Search.pml#1520438035537</outTransitions>
  </states>
  <states xsi:type="alica:SuccessState" id="1520438026668" name="FoundEntity" comment="">
    <inTransitions>Serve/Search.pml#1520438035537</inTransitions>
  </states>
  <transitions id="1520438035537" name="MISSING_NAME" comment="" msg="">
    <preCondition id="1520438036937" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>Serve/Search.pml#1520437031577</inState>
    <outState>Serve/Search.pml#1520438026668</outState>
  </transitions>
  <entryPoints id="1520437031578" name="Search" comment="" successRequired="true" minCardinality="0" maxCardinality="2147483647">
    <task>taskrepository.tsk#1481544910904</task>
    <state>Serve/Search.pml#1520437031577</state>
  </entryPoints>
</alica:Plan>
