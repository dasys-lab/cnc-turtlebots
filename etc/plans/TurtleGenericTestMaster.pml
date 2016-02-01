<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1454329729827" name="TurtleGenericTestMaster" comment="" masterPlan="false" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans" priority="0.0" minCardinality="0" maxCardinality="2147483647">
  <states id="1454329729828" name="Stop" comment="" entryPoint="1454329729829">
    <plans xsi:type="alica:BehaviourConfiguration">Behaviours/Stop.beh#1414681278745</plans>
    <inTransitions>#1454329747260</inTransitions>
    <outTransitions>#1454329745494</outTransitions>
  </states>
  <states id="1454329743284" name="Test" comment="">
    <plans xsi:type="alica:Plan">TestPOI.pml#1454329810785</plans>
    <inTransitions>#1454329745494</inTransitions>
    <outTransitions>#1454329747260</outTransitions>
  </states>
  <transitions id="1454329745494" name="MISSING_NAME" comment="start" msg="">
    <preCondition id="1454329746996" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1454329729828</inState>
    <outState>#1454329743284</outState>
  </transitions>
  <transitions id="1454329747260" name="MISSING_NAME" comment="stop" msg="">
    <preCondition id="1454329748126" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1454329743284</inState>
    <outState>#1454329729828</outState>
  </transitions>
  <entryPoints id="1454329729829" name="MISSING_NAME" comment="" successRequired="false" minCardinality="0" maxCardinality="2147483647">
    <task>../Misc/taskrepository.tsk#1414681164704</task>
    <state>#1454329729828</state>
  </entryPoints>
</alica:Plan>
