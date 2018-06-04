<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1528124991817" name="TestCommunication" comment="" masterPlan="false" utilityFunction="" utilityThreshold="0.1" destinationPath="" priority="0.0" minCardinality="2" maxCardinality="2">
  <states id="1528125008667" name="Publish" comment="" entryPoint="1528125008668">
    <plans xsi:type="alica:BehaviourConfiguration">Publish.beh#1528125242157</plans>
  </states>
  <states id="1528125050252" name="Subscribe" comment="" entryPoint="1528125016366">
    <plans xsi:type="alica:BehaviourConfiguration">Subscribe.beh#1528125256074</plans>
    <outTransitions>#1528125075116</outTransitions>
  </states>
  <states xsi:type="alica:SuccessState" id="1528125060365" name="Success" comment="">
    <inTransitions>#1528125075116</inTransitions>
  </states>
  <transitions id="1528125075116" name="MISSING_NAME" comment="Read from publisher" msg="">
    <preCondition id="1528125076265" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1528125050252</inState>
    <outState>#1528125060365</outState>
  </transitions>
  <entryPoints id="1528125008668" name="Search" comment="" successRequired="false" minCardinality="1" maxCardinality="1">
    <task>../../../Misc/taskrepository.tsk#1481544910904</task>
    <state>#1528125008667</state>
  </entryPoints>
  <entryPoints id="1528125016366" name="Fetch" comment="" successRequired="true" minCardinality="1" maxCardinality="1">
    <task>../../../Misc/taskrepository.tsk#1468494562045</task>
    <state>#1528125050252</state>
  </entryPoints>
</alica:Plan>
