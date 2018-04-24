<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1477125857343" name="ASPMinimizePathMaster" comment="" masterPlan="true" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans/Serve" priority="0.0" minCardinality="0" maxCardinality="2147483647">
  <runtimeCondition xsi:type="alica:RuntimeCondition" id="1477125906086" name="NewRuntimeCondition" comment="" conditionString="" pluginName="DefaultPlugin">
    <vars>#1477125989168</vars>
  </runtimeCondition>
  <vars id="1477125989168" name="PlanVar" comment="" Type=""/>
  <states id="1477125857344" name="Minimize" comment="" entryPoint="1477125857346">
    <parametrisation id="1477126009717" name="MISSING_NAME" comment="">
      <subplan xsi:type="alica:Behaviour">../Behaviours/ASPMinimizePath.beh#1477125924367</subplan>
      <subvar>../Behaviours/ASPMinimizePath.beh#1477125960857</subvar>
      <var>#1477125989168</var>
    </parametrisation>
    <plans xsi:type="alica:Behaviour">../Behaviours/ASPMinimizePath.beh#1477125924367</plans>
  </states>
  <entryPoints id="1477125857346" name="MISSING_NAME" comment="" successRequired="false" minCardinality="0" maxCardinality="2147483647">
    <task>../../Misc/taskrepository.tsk#1414681164704</task>
    <state>#1477125857344</state>
  </entryPoints>
</alica:Plan>
