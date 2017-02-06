<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1481545038564" name="SearchBoxes" comment="" masterPlan="false" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans/Serve/PKVR16" priority="0.0" minCardinality="0" maxCardinality="2147483647">
  <states id="1481545053783" name="SearchBoxes" comment="" entryPoint="1481545053784">
    <plans xsi:type="alica:BehaviourConfiguration">DriveSearchPattern.beh#1481546413105</plans>
    <outTransitions>#1486383884467</outTransitions>
  </states>
  <states xsi:type="alica:SuccessState" id="1486383878962" name="NewSuccessState" comment="">
    <inTransitions>#1486383884467</inTransitions>
  </states>
  <transitions id="1486383884467" name="MISSING_NAME" comment="" msg="">
    <preCondition id="1486383886372" name="MISSING_NAME" comment="" conditionString="" pluginName="DefaultPlugin" enabled="true"/>
    <inState>#1481545053783</inState>
    <outState>#1486383878962</outState>
  </transitions>
  <entryPoints id="1481545053784" name="MISSING_NAME" comment="" successRequired="true" minCardinality="0" maxCardinality="2147483647">
    <task>../../../Misc/taskrepository.tsk#1414681164704</task>
    <state>#1481545053783</state>
  </entryPoints>
</alica:Plan>
