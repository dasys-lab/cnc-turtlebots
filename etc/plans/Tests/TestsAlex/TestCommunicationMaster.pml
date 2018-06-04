<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1528124971225" name="TestCommunicationMaster" comment="" masterPlan="true" utilityFunction="" utilityThreshold="0.1" destinationPath="" priority="0.0" minCardinality="0" maxCardinality="2147483647">
  <states id="1528124971226" name="TestStop" comment="" entryPoint="1528124971227">
    <outTransitions>#1528125189377</outTransitions>
  </states>
  <states id="1528125127758" name="TestSart" comment="">
    <plans xsi:type="alica:Plan">TestCommunication.pml#1528124991817</plans>
    <inTransitions>#1528125189377</inTransitions>
  </states>
  <transitions id="1528125189377" name="MISSING_NAME" comment="Start signal received" msg="">
    <preCondition id="1528125190720" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1528124971226</inState>
    <outState>#1528125127758</outState>
  </transitions>
  <entryPoints id="1528124971227" name="MISSING_NAME" comment="" successRequired="false" minCardinality="0" maxCardinality="2147483647">
    <task>../../../Misc/taskrepository.tsk#1414681164704</task>
    <state>#1528124971226</state>
  </entryPoints>
</alica:Plan>
