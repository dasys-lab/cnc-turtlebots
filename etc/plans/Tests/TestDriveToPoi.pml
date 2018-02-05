<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1517819007614" name="TestDriveToPoi" comment="" masterPlan="true" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans/Tests" priority="0.0" minCardinality="0" maxCardinality="2147483647">
  <states id="1517819007615" name="TestBeh" comment="" entryPoint="1517819007616">
    <plans xsi:type="alica:BehaviourConfiguration">DummyDriveToPoibeh.beh#1517819108899</plans>
  </states>
  <entryPoints id="1517819007616" name="MISSING_NAME" comment="" successRequired="false" minCardinality="0" maxCardinality="2147483647">
    <task>../../Misc/taskrepository.tsk#1414681164704</task>
    <state>#1517819007615</state>
  </entryPoints>
</alica:Plan>
