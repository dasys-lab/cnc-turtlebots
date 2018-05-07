<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1454332108133" name="ServeMaster" comment="" destinationPath="Plans/Serve" priority="0.0" minCardinality="0" maxCardinality="2147483647" masterPlan="true" utilityFunction="" utilityThreshold="0.1">
  <states id="1454332108134" name="Stop" comment="" entryPoint="1454332108135">
    <plans xsi:type="alica:Behaviour">Behaviours/Stop.beh#1414681269156</plans>
    <inTransitions>Serve/ServeMaster.pml#1454332141413</inTransitions>
    <inTransitions>Serve/ServeMaster.pml#1454332145537</inTransitions>
    <outTransitions>Serve/ServeMaster.pml#1454332146639</outTransitions>
  </states>
  <states id="1454332119685" name="Serve" comment="">
    <plans xsi:type="alica:Plan">Serve/Serve.pml#1454331313621</plans>
    <inTransitions>Serve/ServeMaster.pml#1454332144573</inTransitions>
    <inTransitions>Serve/ServeMaster.pml#1454332146639</inTransitions>
    <outTransitions>Serve/ServeMaster.pml#1454332142505</outTransitions>
    <outTransitions>Serve/ServeMaster.pml#1454332145537</outTransitions>
  </states>
  <states id="1454332121310" name="Charge" comment="">
    <plans xsi:type="alica:Plan">Serve/Charge.pml#1454331030770</plans>
    <inTransitions>Serve/ServeMaster.pml#1454332142505</inTransitions>
    <outTransitions>Serve/ServeMaster.pml#1454332141413</outTransitions>
    <outTransitions>Serve/ServeMaster.pml#1454332144573</outTransitions>
  </states>
  <states id="1525694191203" name="MISSING NAME" comment=""/>
  <transitions id="1454332141413" name="MISSING_NAME" comment="stop" msg="">
    <preCondition id="1454332142376" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>Serve/ServeMaster.pml#1454332121310</inState>
    <outState>Serve/ServeMaster.pml#1454332108134</outState>
  </transitions>
  <transitions id="1454332142505" name="MISSING_NAME" comment="low accu (not implemented, yet)" msg="">
    <preCondition id="1454332144469" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>Serve/ServeMaster.pml#1454332119685</inState>
    <outState>Serve/ServeMaster.pml#1454332121310</outState>
  </transitions>
  <transitions id="1454332144573" name="MISSING_NAME" comment="fully charged (child success)" msg="">
    <preCondition id="1454332145416" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>Serve/ServeMaster.pml#1454332121310</inState>
    <outState>Serve/ServeMaster.pml#1454332119685</outState>
  </transitions>
  <transitions id="1454332145537" name="MISSING_NAME" comment="stop" msg="">
    <preCondition id="1454332146510" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>Serve/ServeMaster.pml#1454332119685</inState>
    <outState>Serve/ServeMaster.pml#1454332108134</outState>
  </transitions>
  <transitions id="1454332146639" name="MISSING_NAME" comment="start" msg="">
    <preCondition id="1454332147978" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>Serve/ServeMaster.pml#1454332108134</inState>
    <outState>Serve/ServeMaster.pml#1454332119685</outState>
  </transitions>
  <entryPoints id="1454332108135" name="MISSING_NAME" comment="" successRequired="false" minCardinality="0" maxCardinality="2147483647">
    <task>taskrepository.tsk#1414681164704</task>
    <state>Serve/ServeMaster.pml#1454332108134</state>
  </entryPoints>
</alica:Plan>
