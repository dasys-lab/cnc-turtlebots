<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1454329810785" name="TestPOI" comment="" masterPlan="false" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans" priority="0.0" minCardinality="0" maxCardinality="2147483647">
  <states id="1454329810786" name="POI1" comment="" entryPoint="1454329810787">
    <plans xsi:type="alica:BehaviourConfiguration">Behaviours/DriveToPOI.beh#1454329864420</plans>
    <outTransitions>#1454329834261</outTransitions>
  </states>
  <states id="1454329828515" name="POI2" comment="">
    <plans xsi:type="alica:BehaviourConfiguration">Behaviours/DriveToPOI.beh#1454329905072</plans>
    <inTransitions>#1454329834261</inTransitions>
    <outTransitions>#1454329835521</outTransitions>
  </states>
  <states id="1454329830500" name="POI3" comment="">
    <plans xsi:type="alica:BehaviourConfiguration">Behaviours/DriveToPOI.beh#1454329918634</plans>
    <inTransitions>#1454329835521</inTransitions>
  </states>
  <transitions id="1454329834261" name="MISSING_NAME" comment="any child success" msg="">
    <preCondition id="1454329835328" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1454329810786</inState>
    <outState>#1454329828515</outState>
  </transitions>
  <transitions id="1454329835521" name="MISSING_NAME" comment="any child success" msg="">
    <preCondition id="1454329836408" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1454329828515</inState>
    <outState>#1454329830500</outState>
  </transitions>
  <entryPoints id="1454329810787" name="MISSING_NAME" comment="" successRequired="false" minCardinality="0" maxCardinality="2147483647">
    <task>../Misc/taskrepository.tsk#1414681164704</task>
    <state>#1454329810786</state>
  </entryPoints>
</alica:Plan>
