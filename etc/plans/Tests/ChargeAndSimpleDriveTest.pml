<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1414681057676" name="ChargeAndSimpleDriveTest" comment="" masterPlan="false" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans" priority="0.0" minCardinality="0" maxCardinality="2147483647">
  <states id="1414681057677" name="Stop" comment="" entryPoint="1414681057678">
    <plans xsi:type="alica:BehaviourConfiguration">../Behaviours/Stop.beh#1414681278745</plans>
    <inTransitions>#1414681503803</inTransitions>
    <inTransitions>#1447068022712</inTransitions>
    <inTransitions>#1447958162755</inTransitions>
    <inTransitions>#1447958171762</inTransitions>
    <outTransitions>#1447068026011</outTransitions>
    <outTransitions>#1447919928532</outTransitions>
  </states>
  <states id="1414681069778" name="DriveForward" comment="">
    <plans xsi:type="alica:BehaviourConfiguration">../Behaviours/SimpleDrive.beh#1432735473356</plans>
    <inTransitions>#1447068020601</inTransitions>
    <inTransitions>#1447068026011</inTransitions>
    <outTransitions>#1414681503803</outTransitions>
    <outTransitions>#1447068019298</outTransitions>
  </states>
  <states id="1447067994402" name="Rotating" comment="">
    <plans xsi:type="alica:BehaviourConfiguration">../Behaviours/Rotate.beh#1447068225787</plans>
    <inTransitions>#1447068019298</inTransitions>
    <outTransitions>#1447068020601</outTransitions>
    <outTransitions>#1447068022712</outTransitions>
  </states>
  <states id="1447919813367" name="SearchDockingStation" comment="">
    <plans xsi:type="alica:BehaviourConfiguration">../Behaviours/SearchDockingStation.beh#1414681446065</plans>
    <inTransitions>#1447919928532</inTransitions>
    <outTransitions>#1447958158825</outTransitions>
    <outTransitions>#1447958171762</outTransitions>
  </states>
  <states id="1447958080453" name="Charging" comment="">
    <plans xsi:type="alica:BehaviourConfiguration">../Behaviours/ChargingDefault.beh#1447958132701</plans>
    <inTransitions>#1447958158825</inTransitions>
    <outTransitions>#1447958162755</outTransitions>
  </states>
  <transitions id="1414681503803" name="MISSING_NAME" comment="on robot stop" msg="">
    <preCondition id="1414681505635" name="DoSomething2Stop" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1414681069778</inState>
    <outState>#1414681057677</outState>
  </transitions>
  <transitions id="1447068019298" name="MISSING_NAME" comment="on bumber activated" msg="">
    <preCondition id="1447068020434" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1414681069778</inState>
    <outState>#1447067994402</outState>
  </transitions>
  <transitions id="1447068020601" name="MISSING_NAME" comment="any child success" msg="">
    <preCondition id="1447068022583" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1447067994402</inState>
    <outState>#1414681069778</outState>
  </transitions>
  <transitions id="1447068022712" name="MISSING_NAME" comment="on robot stop" msg="">
    <preCondition id="1447068025867" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1447067994402</inState>
    <outState>#1414681057677</outState>
  </transitions>
  <transitions id="1447068026011" name="MISSING_NAME" comment="on robot start" msg="">
    <preCondition id="1447068027882" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1414681057677</inState>
    <outState>#1414681069778</outState>
  </transitions>
  <transitions id="1447919928532" name="MISSING_NAME" comment="akku too low (start temporary)" msg="">
    <preCondition id="1447919930987" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1414681057677</inState>
    <outState>#1447919813367</outState>
  </transitions>
  <transitions id="1447958158825" name="MISSING_NAME" comment="any children success" msg="">
    <preCondition id="1447958162066" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1447919813367</inState>
    <outState>#1447958080453</outState>
  </transitions>
  <transitions id="1447958162755" name="MISSING_NAME" comment="done loading (state 2 Docking charged) any children success" msg="">
    <preCondition id="1447958165046" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1447958080453</inState>
    <outState>#1414681057677</outState>
  </transitions>
  <transitions id="1447958171762" name="MISSING_NAME" comment="stop" msg="">
    <preCondition id="1447958174005" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1447919813367</inState>
    <outState>#1414681057677</outState>
  </transitions>
  <entryPoints id="1414681057678" name="MISSING_NAME" comment="" successRequired="false" minCardinality="0" maxCardinality="2147483647">
    <task>../../Misc/taskrepository.tsk#1414681164704</task>
    <state>#1414681057677</state>
  </entryPoints>
</alica:Plan>
