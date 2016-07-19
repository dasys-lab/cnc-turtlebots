<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1468493942500" name="CarryBookMaster" comment="" masterPlan="true" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans/Serve" priority="0.0" minCardinality="0" maxCardinality="2147483647">
  <states id="1468493942502" name="CarryBookState1" comment="" entryPoint="1468494403537">
    <plans xsi:type="alica:Plan">CarryBook.pml#1468494583802</plans>
  </states>
  <entryPoints id="1468494403537" name="NewEntryPoint" comment="" successRequired="false" minCardinality="0" maxCardinality="2147483647">
    <task>../../Misc/taskrepository.tsk#1414681164704</task>
    <state>#1468493942502</state>
  </entryPoints>
</alica:Plan>
