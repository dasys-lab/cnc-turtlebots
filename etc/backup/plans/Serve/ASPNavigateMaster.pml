<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1475692538365" name="ASPNavigateMaster" comment="" destinationPath="Plans/Serve" priority="0.0" minCardinality="0" maxCardinality="2147483647" masterPlan="true" utilityFunction="" utilityThreshold="0.1">
  <vars id="1475698052801" name="NavMasterVar" comment="" Type=""/>
  <runtimeCondition id="1475692986360" name="NewRuntimeCondition" comment="" conditionString="" pluginName="DefaultPlugin">
    <vars>Serve/ASPNavigateMaster.pml#1475698052801</vars>
  </runtimeCondition>
  <states id="1475692538366" name="Navigate" comment="" entryPoint="1475692538367">
    <parametrisation id="1475751902681" name="MISSING_NAME" comment="">
      <subplan xsi:type="alica:Behaviour">Behaviours/ASPNavigation.beh#1475693360605</subplan>
      <subvar>Behaviours/ASPNavigation.beh#1475698026578</subvar>
      <var>Serve/ASPNavigateMaster.pml#1475698052801</var>
    </parametrisation>
    <plans xsi:type="alica:Behaviour">Behaviours/ASPNavigation.beh#1475693360605</plans>
    <outTransitions>Serve/ASPNavigateMaster.pml#1476366087934</outTransitions>
  </states>
  <states id="1476366084811" name="Stop" comment="">
    <plans xsi:type="alica:Behaviour">Behaviours/Stop.beh#1414681269156</plans>
    <inTransitions>Serve/ASPNavigateMaster.pml#1476366087934</inTransitions>
  </states>
  <transitions id="1476366087934" name="MISSING_NAME" comment="" msg="">
    <preCondition id="1476366089212" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>Serve/ASPNavigateMaster.pml#1475692538366</inState>
    <outState>Serve/ASPNavigateMaster.pml#1476366084811</outState>
  </transitions>
  <entryPoints id="1475692538367" name="MISSING_NAME" comment="" successRequired="false" minCardinality="0" maxCardinality="2147483647">
    <task>taskrepository.tsk#1414681164704</task>
    <state>Serve/ASPNavigateMaster.pml#1475692538366</state>
  </entryPoints>
</alica:Plan>