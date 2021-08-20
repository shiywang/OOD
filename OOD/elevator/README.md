Description
Design a elevator system for a building

No need to consider overweight
The building currently has only one elevator, and this building has n floors
Each elevator has three states: up, down, idle
When the elevator moves in one direction, the reverse floor button cannot be pressed in the elevator
We have provided several implemented classes, you only need to implement some of the functions in Elevator Class.

We will call the elevatorStatusDescription function to test if you are in a correct state after each command.

Example
Example 1

Input:
5
ExternalRequest(3, "Down")
ExternalRequest(1, "Up")
openGate()
closeGate()
openGate()
closeGate()

Output:
Currently elevator status is : DOWN.
Current level is at: 1.
up stop list looks like: [false, false, false, false, false].
down stop list looks like:  [false, false, true, false, false].
*****************************************
Currently elevator status is : DOWN.
Current level is at: 1.
up stop list looks like: [true, false, false, false, false].
down stop list looks like:  [false, false, true, false, false].
*****************************************
Currently elevator status is : DOWN.
Current level is at: 3.
up stop list looks like: [true, false, false, false, false].
down stop list looks like:  [false, false, false, false, false].
*****************************************
Currently elevator status is : UP.
Current level is at: 3.
up stop list looks like: [true, false, false, false, false].
down stop list looks like:  [false, false, false, false, false].
*****************************************
Currently elevator status is : UP.
Current level is at: 1.
up stop list looks like: [true, false, false, false, false].
down stop list looks like:  [false, false, false, false, false].
*****************************************
Currently elevator status is : IDLE.
Current level is at: 1.
up stop list looks like: [false, false, false, false, false].
down stop list looks like:  [false, false, false, false, false].
*****************************************
