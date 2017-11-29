<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1480766525772" name="ASPRCCTestMaster" comment="" masterPlan="true" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans/Serve" priority="0.0" minCardinality="0" maxCardinality="2147483647">
  <conditions xsi:type="alica:RuntimeCondition" id="1480766551805" name="NewRuntimeCondition" comment="" conditionString="" pluginName="DefaultPlugin">
    <vars>#1480766663869</vars>
  </conditions>
  <vars id="1480766663869" name="PlanVar" comment="" Type=""/>
  <states id="1480766525773" name="NewState" comment="" entryPoint="1480766525774">
    <parametrisation id="1480766690594" name="MISSING_NAME" comment="">
      <subplan xsi:type="alica:BehaviourConfiguration">../Behaviours/ASPRCCTest.beh#1480766599215</subplan>
      <subvar>../Behaviours/ASPRCCTest.beh#1480766654296</subvar>
      <var>#1480766663869</var>
    </parametrisation>
    <plans xsi:type="alica:BehaviourConfiguration">../Behaviours/ASPRCCTest.beh#1480766599215</plans>
    <outTransitions>#1480766545779</outTransitions>
  </states>
  <states xsi:type="alica:SuccessState" id="1480766535708" name="Succ" comment="">
    <inTransitions>#1480766545779</inTransitions>
  </states>
  <transitions id="1480766545779" name="MISSING_NAME" comment="" msg="">
    <preCondition id="1480766547208" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1480766525773</inState>
    <outState>#1480766535708</outState>
  </transitions>
  <entryPoints id="1480766525774" name="MISSING_NAME" comment="" successRequired="false" minCardinality="0" maxCardinality="2147483647">
    <task>../../Misc/taskrepository.tsk#1414681164704</task>
    <state>#1480766525773</state>
  </entryPoints>
</alica:Plan>
