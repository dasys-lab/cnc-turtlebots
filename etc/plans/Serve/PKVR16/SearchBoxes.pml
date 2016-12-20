<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1481545038564" name="SearchBoxes" comment="" masterPlan="false" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans/Serve/PKVR16" priority="0.0" minCardinality="0" maxCardinality="2147483647">
  <states id="1481545053783" name="SearchBoxes" comment="" entryPoint="1481545053784">
    <plans xsi:type="alica:BehaviourConfiguration">DriveSearchPattern.beh#1481546413105</plans>
  </states>
  <entryPoints id="1481545053784" name="MISSING_NAME" comment="" successRequired="false" minCardinality="0" maxCardinality="2147483647">
    <task>../../../Misc/taskrepository.tsk#1414681164704</task>
    <state>#1481545053783</state>
  </entryPoints>
</alica:Plan>
