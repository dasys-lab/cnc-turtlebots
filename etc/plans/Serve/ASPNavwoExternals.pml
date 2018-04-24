<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1477229620130" name="ASPNavwoExternals" comment="" masterPlan="true" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans/Serve" priority="0.0" minCardinality="0" maxCardinality="2147483647">
  <runtimeCondition xsi:type="alica:RuntimeCondition" id="1477229706852" name="NewRuntimeCondition" comment="" conditionString="" pluginName="DefaultPlugin">
    <vars>#1477229962547</vars>
  </runtimeCondition>
  <vars id="1477229962547" name="PlanVar1" comment="" Type=""/>
  <states id="1477229620131" name="Nav1" comment="" entryPoint="1477229620132">
    <parametrisation id="1477229991230" name="MISSING_NAME" comment="">
      <subplan xsi:type="alica:Behaviour">../Behaviours/ASPNavwoExt.beh#1477229760910</subplan>
      <subvar>../Behaviours/ASPNavwoExt.beh#1477229971246</subvar>
      <var>#1477229962547</var>
    </parametrisation>
    <plans xsi:type="alica:Behaviour">../Behaviours/ASPNavwoExt.beh#1477229760910</plans>
    <outTransitions>#1477229632397</outTransitions>
  </states>
  <states id="1477229628161" name="InnerState" comment="">
    <plans xsi:type="alica:Plan">ASPNavwoExternalsInner.pml#1477229638868</plans>
    <inTransitions>#1477229632397</inTransitions>
    <outTransitions>#1477229678856</outTransitions>
  </states>
  <states xsi:type="alica:SuccessState" id="1477229672639" name="NewSuccessState" comment="">
    <inTransitions>#1477229678856</inTransitions>
  </states>
  <transitions id="1477229632397" name="MISSING_NAME" comment="success" msg="">
    <preCondition id="1477229633243" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1477229620131</inState>
    <outState>#1477229628161</outState>
  </transitions>
  <transitions id="1477229678856" name="MISSING_NAME" comment="success" msg="">
    <preCondition id="1477229680268" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1477229628161</inState>
    <outState>#1477229672639</outState>
  </transitions>
  <entryPoints id="1477229620132" name="MISSING_NAME" comment="" successRequired="true" minCardinality="0" maxCardinality="2147483647">
    <task>../../Misc/taskrepository.tsk#1414681164704</task>
    <state>#1477229620131</state>
  </entryPoints>
</alica:Plan>
