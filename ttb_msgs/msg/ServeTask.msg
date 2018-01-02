agent_id/AgentID sender

# ReceiverID 0 is reserved as wildcard for all robots. If it is > 0, it represents the ID of the robot.
agent_id/AgentID receiver

# The type of task that is encoded with this message
uint8 type

# Denotes the item to pickup, to putdown, to search for, or the poi id to drive to  
string entity


# constants for type
uint8 PICK_UP = 0
uint8 PUT_DOWN = 1
uint8 SEARCH = 2
uint8 DRIVE_TO = 3