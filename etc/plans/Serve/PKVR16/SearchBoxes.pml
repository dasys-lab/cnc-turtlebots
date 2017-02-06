<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1481545038564" name="SearchBoxes" comment="" masterPlan="false" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans/Serve/PKVR16" priority="0.0" minCardinality="0" maxCardinality="2147483647">
  <states id="1481545053783" name="SearchBoxes" comment="" entryPoint="1481545053784">
    <plans xsi:type="alica:BehaviourConfiguration">DriveSearchPattern.beh#1481546413105</plans>
    <outTransitions>#1485789245855</outTransitions>
  </states>
  <states id="1485789207566" name="Investigate" comment="">
    <plans xsi:type="alica:BehaviourConfiguration">PickUp.beh#1486381497239</plans>
    <inTransitions>#1485789245855</inTransitions>
  </states>
  <transitions id="1485789245855" name="MISSING_NAME" comment="all landmarks found" msg="">
    <preCondition id="1485789247329" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1481545053783</inState>
    <outState>#1485789207566</outState>
  </transitions>
  <entryPoints id="1481545053784" name="MISSING_NAME" comment="" successRequired="false" minCardinality="0" maxCardinality="2147483647">
    <task>../../../Misc/taskrepository.tsk#1414681164704</task>
    <state>#1481545053783</state>
  </entryPoints>
</alica:Plan>
