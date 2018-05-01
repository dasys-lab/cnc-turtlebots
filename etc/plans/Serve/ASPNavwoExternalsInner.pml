<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1477229638868" name="ASPNavwoExternalsInner" comment="" masterPlan="false" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans/Serve" priority="0.0" minCardinality="0" maxCardinality="2147483647">
  <runtimeCondition xsi:type="alica:RuntimeCondition" id="1477229712321" name="NewRuntimeCondition" comment="" conditionString="" pluginName="DefaultPlugin">
    <vars>Serve/ASPNavwoExternalsInner.pml#1477229909334</vars>
  </runtimeCondition>
  <vars id="1477229909334" name="PlanVar2" comment="" Type=""/>
  <states id="1477229659174" name="Nav2" comment="" entryPoint="1477229659175">
    <parametrisation id="1477229943530" name="MISSING_NAME" comment="">
      <subplan xsi:type="alica:Behaviour">Behaviours/ASPNavwoExt.beh#1477229760910</subplan>
      <subvar>Behaviours/ASPNavwoExt.beh#1477229925769</subvar>
      <var>Serve/ASPNavwoExternalsInner.pml#1477229909334</var>
    </parametrisation>
    <plans xsi:type="alica:Behaviour">Behaviours/ASPNavwoExt.beh#1477229760910</plans>
    <outTransitions>Serve/ASPNavwoExternalsInner.pml#1479298299806</outTransitions>
  </states>
  <states xsi:type="alica:SuccessState" id="1479298294756" name="NewSuccessState" comment="">
    <inTransitions>Serve/ASPNavwoExternalsInner.pml#1479298299806</inTransitions>
  </states>
  <transitions id="1479298299806" name="MISSING_NAME" comment="success" msg="">
    <preCondition id="1479298302100" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>Serve/ASPNavwoExternalsInner.pml#1477229659174</inState>
    <outState>Serve/ASPNavwoExternalsInner.pml#1479298294756</outState>
  </transitions>
  <entryPoints id="1477229659175" name="MISSING_NAME" comment="" successRequired="true" minCardinality="0" maxCardinality="2147483647">
    <task>taskrepository.tsk#1414681164704</task>
    <state>Serve/ASPNavwoExternalsInner.pml#1477229659174</state>
  </entryPoints>
</alica:Plan>
