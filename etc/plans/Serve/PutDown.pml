<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1520511951867" name="PutDown" comment="" masterPlan="false" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans/Serve" priority="0.0" minCardinality="0" maxCardinality="2147483647">
  <runtimeCondition xsi:type="alica:RuntimeCondition" id="1520850075314" name="NewRuntimeCondition" comment="" conditionString="" pluginName="DefaultPlugin">
    <vars>Serve/PutDown.pml#1520850749297</vars>
    <vars>Serve/PutDown.pml#1520850749534</vars>
    <vars>Serve/PutDown.pml#1520872574322</vars>
    <vars>Serve/PutDown.pml#1520850764148</vars>
  </runtimeCondition>
  <vars id="1520850749297" name="x" comment="" Type=""/>
  <vars id="1520850749534" name="y" comment="" Type=""/>
  <vars id="1520850764148" name="entity" comment="" Type=""/>
  <vars id="1520872574322" name="z" comment="" Type=""/>
  <states id="1520511964767" name="DriveToPoint" comment="" entryPoint="1520511964768">
    <parametrisation id="1520851098640" name="MISSING_NAME" comment="">
      <subplan xsi:type="alica:Behaviour">Behaviours/DriveToPoint.beh#1520850811997</subplan>
      <subvar>Behaviours/DriveToPoint.beh#1520851080475</subvar>
      <var>Serve/PutDown.pml#1520850749297</var>
    </parametrisation>
    <parametrisation id="1520851104524" name="MISSING_NAME" comment="">
      <subplan xsi:type="alica:Behaviour">Behaviours/DriveToPoint.beh#1520850811997</subplan>
      <subvar>Behaviours/DriveToPoint.beh#1520851082139</subvar>
      <var>Serve/PutDown.pml#1520850749534</var>
    </parametrisation>
    <plans xsi:type="alica:Behaviour">Behaviours/DriveToPoint.beh#1520850811997</plans>
    <inTransitions>Serve/PutDown.pml#1520849450854</inTransitions>
    <outTransitions>Serve/PutDown.pml#1520849449636</outTransitions>
    <outTransitions>Serve/PutDown.pml#1520849520077</outTransitions>
  </states>
  <states id="1520845381633" name="PutDown" comment="">
    <parametrisation id="1520851109354" name="MISSING_NAME" comment="">
      <subplan xsi:type="alica:Behaviour">Behaviours/PutDown.beh#1520850797525</subplan>
      <subvar>Behaviours/PutDown.beh#1520851061716</subvar>
      <var>Serve/PutDown.pml#1520850764148</var>
    </parametrisation>
    <parametrisation id="1520851114255" name="MISSING_NAME" comment="">
      <subplan xsi:type="alica:Behaviour">Behaviours/PutDown.beh#1520850797525</subplan>
      <subvar>Behaviours/PutDown.beh#1520851062978</subvar>
      <var>Serve/PutDown.pml#1520850749297</var>
    </parametrisation>
    <parametrisation id="1520851116894" name="MISSING_NAME" comment="">
      <subplan xsi:type="alica:Behaviour">Behaviours/PutDown.beh#1520850797525</subplan>
      <subvar>Behaviours/PutDown.beh#1520851063507</subvar>
      <var>Serve/PutDown.pml#1520850749534</var>
    </parametrisation>
    <parametrisation id="1520872605849" name="MISSING_NAME" comment="">
      <subplan xsi:type="alica:Behaviour">Behaviours/PutDown.beh#1520850797525</subplan>
      <subvar>Behaviours/PutDown.beh#1520872596739</subvar>
      <var>Serve/PutDown.pml#1520872574322</var>
    </parametrisation>
    <plans xsi:type="alica:Behaviour">Behaviours/PutDown.beh#1520850797525</plans>
    <inTransitions>Serve/PutDown.pml#1520849449636</inTransitions>
    <outTransitions>Serve/PutDown.pml#1520849450854</outTransitions>
    <outTransitions>Serve/PutDown.pml#1520849521816</outTransitions>
    <outTransitions>Serve/PutDown.pml#1520849523989</outTransitions>
  </states>
  <states xsi:type="alica:FailureState" id="1520849454900" name="DriveToFail" comment="">
    <inTransitions>Serve/PutDown.pml#1520849520077</inTransitions>
  </states>
  <states xsi:type="alica:FailureState" id="1520849456871" name="FailedToPlaceObject" comment="">
    <inTransitions>Serve/PutDown.pml#1520849521816</inTransitions>
  </states>
  <states xsi:type="alica:SuccessState" id="1520849459774" name="ObjectPlaced" comment="">
    <inTransitions>Serve/PutDown.pml#1520849523989</inTransitions>
  </states>
  <transitions id="1520849449636" name="MISSING_NAME" comment="Arrived at point" msg="">
    <preCondition id="1520849450688" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>Serve/PutDown.pml#1520511964767</inState>
    <outState>Serve/PutDown.pml#1520845381633</outState>
  </transitions>
  <transitions id="1520849450854" name="MISSING_NAME" comment="PutDown to DriveToPoint" msg="">
    <preCondition id="1520849451727" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>Serve/PutDown.pml#1520845381633</inState>
    <outState>Serve/PutDown.pml#1520511964767</outState>
  </transitions>
  <transitions id="1520849520077" name="MISSING_NAME" comment="failed to drive to point" msg="">
    <preCondition id="1520849521568" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>Serve/PutDown.pml#1520511964767</inState>
    <outState>Serve/PutDown.pml#1520849454900</outState>
  </transitions>
  <transitions id="1520849521816" name="MISSING_NAME" comment="Failed putting down" msg="">
    <preCondition id="1520849523765" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>Serve/PutDown.pml#1520845381633</inState>
    <outState>Serve/PutDown.pml#1520849456871</outState>
  </transitions>
  <transitions id="1520849523989" name="MISSING_NAME" comment="Putting down Successful" msg="">
    <preCondition id="1520849525667" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>Serve/PutDown.pml#1520845381633</inState>
    <outState>Serve/PutDown.pml#1520849459774</outState>
  </transitions>
  <entryPoints id="1520511964768" name="MISSING_NAME" comment="" successRequired="false" minCardinality="0" maxCardinality="2147483647">
    <task>taskrepository.tsk#1414681164704</task>
    <state>Serve/PutDown.pml#1520511964767</state>
  </entryPoints>
</alica:Plan>
