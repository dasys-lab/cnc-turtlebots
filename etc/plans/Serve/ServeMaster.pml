<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1454332108133" name="ServeMaster" comment="" masterPlan="true" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans/Serve" priority="0.0" minCardinality="0" maxCardinality="2147483647">
  <states id="1454332108134" name="Stop" comment="" entryPoint="1454332108135">
    <plans xsi:type="alica:BehaviourConfiguration">../Behaviours/Stop.beh#1414681278745</plans>
    <inTransitions>#1454332141413</inTransitions>
    <inTransitions>#1454332145537</inTransitions>
    <outTransitions>#1454332146639</outTransitions>
  </states>
  <states id="1454332119685" name="Serve" comment="">
    <plans xsi:type="alica:Plan">Serve.pml#1454331313621</plans>
    <inTransitions>#1454332144573</inTransitions>
    <inTransitions>#1454332146639</inTransitions>
    <outTransitions>#1454332142505</outTransitions>
    <outTransitions>#1454332145537</outTransitions>
  </states>
  <states id="1454332121310" name="Charge" comment="">
    <plans xsi:type="alica:Plan">Charge.pml#1454331030770</plans>
    <inTransitions>#1454332142505</inTransitions>
    <outTransitions>#1454332141413</outTransitions>
    <outTransitions>#1454332144573</outTransitions>
  </states>
  <transitions id="1454332141413" name="MISSING_NAME" comment="stop" msg="">
    <preCondition id="1454332142376" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1454332121310</inState>
    <outState>#1454332108134</outState>
  </transitions>
  <transitions id="1454332142505" name="MISSING_NAME" comment="low accu (not implemented, yet)" msg="">
    <preCondition id="1454332144469" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1454332119685</inState>
    <outState>#1454332121310</outState>
  </transitions>
  <transitions id="1454332144573" name="MISSING_NAME" comment="fully charged (child success)" msg="">
    <preCondition id="1454332145416" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1454332121310</inState>
    <outState>#1454332119685</outState>
  </transitions>
  <transitions id="1454332145537" name="MISSING_NAME" comment="stop" msg="">
    <preCondition id="1454332146510" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1454332119685</inState>
    <outState>#1454332108134</outState>
  </transitions>
  <transitions id="1454332146639" name="MISSING_NAME" comment="start" msg="">
    <preCondition id="1454332147978" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1454332108134</inState>
    <outState>#1454332119685</outState>
  </transitions>
  <entryPoints id="1454332108135" name="MISSING_NAME" comment="" successRequired="false" minCardinality="0" maxCardinality="2147483647">
    <task>../../Misc/taskrepository.tsk#1414681164704</task>
    <state>#1454332108134</state>
  </entryPoints>
</alica:Plan>
