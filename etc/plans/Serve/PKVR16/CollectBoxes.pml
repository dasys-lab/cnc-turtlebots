<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1481544845570" name="CollectBoxes" comment="" masterPlan="false" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans/Serve/PKVR16" priority="0.0" minCardinality="0" maxCardinality="2147483647">
  <states id="1481544845571" name="SearchState" comment="" entryPoint="1481544845572">
    <plans xsi:type="alica:Plan">SearchBoxes.pml#1481545038564</plans>
  </states>
  <states id="1481544999230" name="TransportState" comment="" entryPoint="1481544865851"/>
  <entryPoints id="1481544845572" name="MISSING_NAME" comment="" successRequired="false" minCardinality="0" maxCardinality="2147483647">
    <task>../../../Misc/taskrepository.tsk#1481544910904</task>
    <state>#1481544845571</state>
  </entryPoints>
  <entryPoints id="1481544865851" name="MISSING_NAME" comment="" successRequired="false" minCardinality="0" maxCardinality="2147483647">
    <task>../../../Misc/taskrepository.tsk#1481544924225</task>
    <state>#1481544999230</state>
  </entryPoints>
</alica:Plan>
