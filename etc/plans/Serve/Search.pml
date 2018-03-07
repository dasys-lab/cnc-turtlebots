<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1520437018620" name="Search" comment="" masterPlan="false" utilityFunction="" utilityThreshold="0.1" destinationPath="" priority="0.0" minCardinality="0" maxCardinality="2147483647">
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
  </states>
  <entryPoints id="1520437031578" name="MISSING_NAME" comment="" successRequired="false" minCardinality="0" maxCardinality="2147483647">
    <task>../../Misc/taskrepository.tsk#1414681164704</task>
    <state>#1520437031577</state>
  </entryPoints>
</alica:Plan>
