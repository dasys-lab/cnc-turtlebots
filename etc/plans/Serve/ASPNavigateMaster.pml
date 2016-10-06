<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1475692538365" name="ASPNavigateMaster" comment="" masterPlan="true" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans/Serve" priority="0.0" minCardinality="0" maxCardinality="2147483647">
  <conditions xsi:type="alica:RuntimeCondition" id="1475692986360" name="NewRuntimeCondition" comment="" conditionString="" pluginName="DefaultPlugin">
    <vars>#1475698052801</vars>
  </conditions>
  <vars id="1475698052801" name="NavMasterVar" comment="" Type=""/>
  <states id="1475692538366" name="Navigate" comment="" entryPoint="1475692538367">
    <parametrisation id="1475751902681" name="MISSING_NAME" comment="">
      <subplan xsi:type="alica:BehaviourConfiguration">../Behaviours/ASPNavigation.beh#1475693376771</subplan>
      <subvar>../Behaviours/ASPNavigation.beh#1475698026578</subvar>
      <var>#1475698052801</var>
    </parametrisation>
    <plans xsi:type="alica:BehaviourConfiguration">../Behaviours/ASPNavigation.beh#1475693376771</plans>
    <outTransitions>#1475752160047</outTransitions>
  </states>
  <states xsi:type="alica:SuccessState" id="1475752156074" name="NewSuccessState" comment="">
    <inTransitions>#1475752160047</inTransitions>
  </states>
  <transitions id="1475752160047" name="MISSING_NAME" comment="success" msg="">
    <preCondition id="1475752162193" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1475692538366</inState>
    <outState>#1475752156074</outState>
  </transitions>
  <entryPoints id="1475692538367" name="MISSING_NAME" comment="" successRequired="false" minCardinality="0" maxCardinality="2147483647">
    <task>../../Misc/taskrepository.tsk#1414681164704</task>
    <state>#1475692538366</state>
  </entryPoints>
</alica:Plan>
