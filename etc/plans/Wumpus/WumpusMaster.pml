<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1489673406228" name="WumpusMaster" comment="" masterPlan="true" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans/Wumpus" priority="0.0" minCardinality="0" maxCardinality="2147483647">
  <states id="1489673406229" name="Stop" comment="" entryPoint="1489673406230">
    <plans xsi:type="alica:BehaviourConfiguration">../Behaviours/Wumpus/SpawnAgent.beh#1489673543981</plans>
    <outTransitions>#1489673563202</outTransitions>
  </states>
  <states id="1489673551929" name="Play" comment="">
    <plans xsi:type="alica:Plan">InteractWIthPlayground.pml#1489673751539</plans>
    <inTransitions>#1489673563202</inTransitions>
    <outTransitions>#1489673632039</outTransitions>
    <outTransitions>#1489673685018</outTransitions>
  </states>
  <states xsi:type="alica:FailureState" id="1489673616222" name="AgentDead" comment="">
    <inTransitions>#1489673632039</inTransitions>
  </states>
  <states xsi:type="alica:SuccessState" id="1489673668786" name="AgentLeftCave" comment="">
    <inTransitions>#1489673685018</inTransitions>
  </states>
  <transitions id="1489673563202" name="MISSING_NAME" comment="Spawn Agent Message Received" msg="">
    <preCondition id="1489673564931" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1489673406229</inState>
    <outState>#1489673551929</outState>
  </transitions>
  <transitions id="1489673632039" name="MISSING_NAME" comment="Agent is Dead" msg="">
    <preCondition id="1489673638984" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1489673551929</inState>
    <outState>#1489673616222</outState>
  </transitions>
  <transitions id="1489673685018" name="MISSING_NAME" comment="Agent left with gold" msg="">
    <preCondition id="1489673686543" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1489673551929</inState>
    <outState>#1489673668786</outState>
  </transitions>
  <entryPoints id="1489673406230" name="MISSING_NAME" comment="" successRequired="true" minCardinality="0" maxCardinality="2147483647">
    <task>../../Misc/taskrepository.tsk#1414681164704</task>
    <state>#1489673406229</state>
  </entryPoints>
</alica:Plan>
