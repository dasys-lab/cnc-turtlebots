<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1414681057676" name="TurtleTestMaster" comment="" masterPlan="true" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans" priority="0.0" minCardinality="0" maxCardinality="2147483647">
  <states id="1414681057677" name="Stop" comment="" entryPoint="1414681057678">
    <plans xsi:type="alica:BehaviourConfiguration">Behaviours/Stop.beh#1414681278745</plans>
    <inTransitions>#1414681503803</inTransitions>
    <outTransitions>#1414681083953</outTransitions>
  </states>
  <states id="1414681069778" name="DoSomething" comment="">
    <plans xsi:type="alica:BehaviourConfiguration">Behaviours/SearchDockingStation.beh#1414681446065</plans>
    <inTransitions>#1414681083953</inTransitions>
    <outTransitions>#1414681503803</outTransitions>
  </states>
  <transitions id="1414681083953" name="MISSING_NAME" comment="" msg="">
    <preCondition id="1414681086048" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1414681057677</inState>
    <outState>#1414681069778</outState>
  </transitions>
  <transitions id="1414681503803" name="MISSING_NAME" comment="" msg="">
    <preCondition id="1414681505635" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1414681069778</inState>
    <outState>#1414681057677</outState>
  </transitions>
  <entryPoints id="1414681057678" name="MISSING_NAME" comment="" successRequired="false" minCardinality="0" maxCardinality="2147483647">
    <task>../Misc/taskrepository.tsk#1414681164704</task>
    <state>#1414681057677</state>
  </entryPoints>
</alica:Plan>
