<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1489673751539" name="InteractWIthPlayground" comment="" masterPlan="false" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans/Wumpus" priority="0.0" minCardinality="0" maxCardinality="2147483647">
  <states id="1489673770246" name="Wait" comment="" entryPoint="1489673770247">
    <plans xsi:type="alica:BehaviourConfiguration">../Behaviours/Wumpus/WaitForTurn.beh#1489673907866</plans>
    <inTransitions>#1489674024781</inTransitions>
    <outTransitions>#1489674022732</outTransitions>
  </states>
  <states id="1489673919099" name="Turn" comment="">
    <plans xsi:type="alica:Plan">Turn.pml#1489674129255</plans>
    <inTransitions>#1489674022732</inTransitions>
    <outTransitions>#1489674024781</outTransitions>
    <outTransitions>#1489674025985</outTransitions>
    <outTransitions>#1489674028109</outTransitions>
  </states>
  <states xsi:type="alica:FailureState" id="1489673921908" name="AgentDead" comment="">
    <inTransitions>#1489674025985</inTransitions>
  </states>
  <states xsi:type="alica:SuccessState" id="1489673925540" name="AgentLeftCave" comment="">
    <inTransitions>#1489674028109</inTransitions>
  </states>
  <transitions id="1489674022732" name="MISSING_NAME" comment="Your turn" msg="">
    <preCondition id="1489674024580" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1489673770246</inState>
    <outState>#1489673919099</outState>
  </transitions>
  <transitions id="1489674024781" name="MISSING_NAME" comment="Turn finished" msg="">
    <preCondition id="1489674025736" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1489673919099</inState>
    <outState>#1489673770246</outState>
  </transitions>
  <transitions id="1489674025985" name="MISSING_NAME" comment="Agent Dead" msg="">
    <preCondition id="1489674027916" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1489673919099</inState>
    <outState>#1489673921908</outState>
  </transitions>
  <transitions id="1489674028109" name="MISSING_NAME" comment="Agent left Cave" msg="">
    <preCondition id="1489674029655" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1489673919099</inState>
    <outState>#1489673925540</outState>
  </transitions>
  <entryPoints id="1489673770247" name="MISSING_NAME" comment="" successRequired="true" minCardinality="0" maxCardinality="2147483647">
    <task>../../Misc/taskrepository.tsk#1414681164704</task>
    <state>#1489673770246</state>
  </entryPoints>
</alica:Plan>
