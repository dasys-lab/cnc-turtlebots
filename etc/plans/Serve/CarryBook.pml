<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1468494583802" name="CarryBook" comment="" masterPlan="false" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans/Serve" priority="0.0" minCardinality="0" maxCardinality="2147483647">
  <conditions xsi:type="alica:RuntimeCondition" id="1468495216221" name="NewRuntimeCondition" comment="" conditionString="" pluginName="DefaultPlugin">
    <vars>#1468494716925</vars>
  </conditions>
  <conditions xsi:type="alica:PreCondition" id="1468495219218" name="NewPreCondition" comment="" conditionString="agent(A), in(A,p1462889426092, tsk1225112227903, S),  carries(A, harryPotter1)." pluginName="DefaultPlugin" enabled="true"/>
  <vars id="1468494716925" name="BookPlanVar" comment="" Type=""/>
  <states id="1468494595478" name="CarryBook" comment="" entryPoint="1468494595479">
    <parametrisation id="1468495008359" name="MISSING_NAME" comment="">
      <subplan xsi:type="alica:BehaviourConfiguration">../Behaviours/Carry.beh#1468494631985</subplan>
      <subvar>../Behaviours/Carry.beh#1468494997353</subvar>
      <var>#1468494716925</var>
    </parametrisation>
    <plans xsi:type="alica:BehaviourConfiguration">../Behaviours/Carry.beh#1468494631985</plans>
  </states>
  <entryPoints id="1468494595479" name="MISSING_NAME" comment="" successRequired="false" minCardinality="0" maxCardinality="2147483647">
    <task>../../Misc/taskrepository.tsk#1414681164704</task>
    <state>#1468494595478</state>
  </entryPoints>
</alica:Plan>
