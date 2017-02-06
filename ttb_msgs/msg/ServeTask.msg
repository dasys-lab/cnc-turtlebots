int32 senderId

# ReceiverID 0 is reserved as wildcard for all robots. If it is > 0, it represents the ID of the robot.
int32 receiverId

# The type of task that is encoded with this message
string type

# Denotes the item to pickup, to putdown, to search for, or the poi id to drive to  
string entitiy