<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1454331030770" name="Charge" comment="" masterPlan="false" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans/Serve" priority="0.0" minCardinality="0" maxCardinality="2147483647">
  <states id="1454331097632" name="SearchDock" comment="" entryPoint="1454331045285">
    <plans xsi:type="alica:Behaviour">Behaviours/SearchDockingStation.beh#1414681429307</plans>
    <outTransitions>Serve/Charge.pml#1454331126208</outTransitions>
  </states>
  <states id="1454331108755" name="ChargeAccu" comment="">
    <plans xsi:type="alica:Behaviour">Behaviours/ChargingDefault.beh#1447958115909</plans>
    <inTransitions>Serve/Charge.pml#1454331126208</inTransitions>
    <outTransitions>Serve/Charge.pml#1454331143741</outTransitions>
  </states>
  <states xsi:type="alica:SuccessState" id="1454331131268" name="FullyCharged" comment="">
    <inTransitions>Serve/Charge.pml#1454331143741</inTransitions>
  </states>
  <transitions id="1454331126208" name="MISSING_NAME" comment="docked | fully charged (child success)" msg="">
    <preCondition id="1454331127179" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>Serve/Charge.pml#1454331097632</inState>
    <outState>Serve/Charge.pml#1454331108755</outState>
  </transitions>
  <transitions id="1454331143741" name="MISSING_NAME" comment="accu full" msg="">
    <preCondition id="1454331145639" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>Serve/Charge.pml#1454331108755</inState>
    <outState>Serve/Charge.pml#1454331131268</outState>
  </transitions>
  <entryPoints id="1454331045285" name="MISSING_NAME" comment="" successRequired="true" minCardinality="0" maxCardinality="2147483647">
    <task>taskrepository.tsk#1414681164704</task>
    <state>Serve/Charge.pml#1454331097632</state>
  </entryPoints>
</alica:Plan>
