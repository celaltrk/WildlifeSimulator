# WildlifeSimulator
The wildlife simulation begins with creatures and food spawning in different places. Each creature knows the location of the highest-quality food and moves towards it. The first one to reach the food consumes it. Additional food supplies are introduced at different times. The creatures compete to survive by consuming scattered food resources.

# Food
In this simulation, the food resources spontaneously spawn at certain locations at certain times. Each food resource has 4 properties: 𝑥 and 𝑦 coordinates of their location, a unique integer ID, and their quality. Here, the quality of the food is denoted by an integer value. 

# Creatures
The creatures have 4 properties: A unique integer ID, an integer that represents their health, and 𝑥 and 𝑦 coordinates of their location. At each time tick, each creature first will look to fight other creatures. If there are other creatures within a 2-unit distance radius (Euclidean distance between creatures < 2) with less than or equal health, it will kill all of them. Then it will look for food. However, since they are greedy, they will only consume the food with the best quality and ignore the rest. Because of that, if its distance to the best food is less than 1, then it will consume the food, otherwise, it will not consume anything. If it consumes food, its health will increase based on the quality of the food. So, if a creature with 10 health, consumes food with 8 quality, its health will become 18. Then, it will move in the direction of the food with the best quality that is currently available. If there are multiple foods with the same quality, creatures should prefer the one with the lowest food ID. If there are no food supplies available, creatures will not move. If they move, the distance covered in a single time tick will depend on the current health of the creature. If the health of the creature is less than or equal to 10, then its survival instincts will kick in and it will move 1 unit distance. If it is healthy, i.e. its health is greater than 10, then it will only move 10/h unit distance where h is the current health of the creature. Lastly, it will lose 1 health. If its health becomes 0, it will die. Dead creatures do not move, and they do not interact with other creatures and food supplies.

# Input
The simulator takes one command line argument, the name of the input file. The input is stored as a simple .txt file. The first line of the input is a single integer 𝑁, denoting the number of creatures that will be in the simulation. The following 𝑁 lines hold the creature information and the rest hold food resource information. The format of the creature information is:

<ID>,<X>,<Y>,<Health>

and the format of the food information is:

<ID>,<X>,<Y>,<Quality>,<Spawntime> 

where <ID> is the ID of the creature/food, <X> and <Y> are the starting coordinates of the creature/food, <Health> is the starting health of the creature, <Quality> is the quality of the food resource and the <Spawntime> is the time (in terms of number of loop iterations) which you should add the food resource to the simulation.

Sample input:
4
2,10,2,15
1,1,1,15
3,4,5,15
4,3,5.5,15
1,7,11,1,0
2,2,2,5,13
3,1,3,11,0
4,8,2,2,0
5,2,12,10,4
