# Robocon-A-
My name is Edmund. Year 1 in Electronic Engineering.

This project was assisted by Website such as stackoverflow (https://stackoverflow.com/questions/19193413/pathfinding-in-a-grid-system)
and AI for generating the base code.
The website help me in understanding the algorithm and figuring out the equations in the algorithm, i used about 2 days to get a foot hold in A*.
then I took 3 days to generate and write the code, with sometime used in debuging.

Out of many algorithm such as:
Dijkstra’s algorithm, 
Minimum Spanning Trees algorithm, 
Breadth first search,

I created my pathing algorithm using A* algorithm, 

The reasons for choosing A* are as follow:

1) A* outputs the shortest path from the start node to the target node 
2) A* never over estimates the true cost
3) A* uses both actual cost from the starting node and estimated cost to the goal, balancing exploration of new paths with efficient progression toward the goal.
4) A* are more suitable for applying to real world problem such as deliveries.

==========

Code Explanation

Firstly structure is used to hold the details of the package inputed

![image](https://github.com/user-attachments/assets/37176582-ba4b-4340-9c47-4be179aeaee8)

the details include Package Id, Package urgency, Package weight and its descirption.


![image](https://github.com/user-attachments/assets/308b3cb9-0413-43c5-875d-8ff3e9308f10)

The node structure is used for implementing A* pathfinding.
x and y represent the coordinates of the node in the grid, 
cost is the cost from the starting point to this node,
priority is the priority value calculated by adding cost to determining how likely this node is good for exploration.


![image](https://github.com/user-attachments/assets/dbca3d1e-455a-4bd1-aa2b-e41ef157a503)

The first part defines the function for the direction of moving.
The second part is to check wherether if the the cell the package is on is valid or not.


![image](https://github.com/user-attachments/assets/3fe76e98-1c44-4b5b-bf61-fe4878399ce6)

This is the A* algorithm to find the path of the shortest from the starting point to the end.


![image](https://github.com/user-attachments/assets/258fe4c1-6a8a-4df6-83a4-aee99a2c9e0f)

This is the setup to start processing nodes, while maintaining a record of the shortest path costs.


![image](https://github.com/user-attachments/assets/6b69863d-2b95-40cd-8a72-8b3ce1be73a1)

This initializes the starting point in the cameFrom map, marking it with {-1, -1} to indicate that it has no parent, making  it the beginning of the path.


![image](https://github.com/user-attachments/assets/e771b84e-3782-49d9-9126-6c35f76d963a)

This part is to loop while the openset is not empty and advancing the A* search. 
And also to break the loop when the end goal is reached.


![image](https://github.com/user-attachments/assets/6f1cc355-548a-4d54-8a49-9bbaa4da10fb)

This part is to calculate the cost of the path found and continue to find the next direction.


![image](https://github.com/user-attachments/assets/d89cfb39-4b55-4b5f-ac18-1d0fab03145c)

After a path with the lower cost is found, this line of code reconstruct the path from the starting point {-1,-1} to the end point.


![image](https://github.com/user-attachments/assets/dc4e2735-cc7a-402d-a47e-1eb4b16570fa)

sortPackages is used to sort the package inputed based on its urgency.
The first condition is when two packages have the same urgency, they are sorted by weight in ascending order, prioritizing lighter packages.
The second condition is when urgency values differ, packages are sorted by urgency, with lower urgency values come first.

displayPackages is to displayed the sorted package.


![image](https://github.com/user-attachments/assets/6d6acde8-db6a-4661-b7a1-bfb2dd2292b1)

This part is to call the user to input the packages details for x amount of package the user input.


![image](https://github.com/user-attachments/assets/609de4d4-b710-4b71-90b9-be75e9206055)

This part is to predefined the layout and size of the map, any changes to the map will hace to done manually in this part,
easier for deebuging.


![image](https://github.com/user-attachments/assets/01549d57-ebd5-49fd-94a8-b63e08753400)

this part is run when user first start, it initialise the amount of package have and the call for the inputPackages functions.
It also ask for the starting point and ending point the user desired.
Lastly it outputs the result obtain from calculating the shortest path.


==========

Ouput


![image](https://github.com/user-attachments/assets/f7eec1df-0bf9-4ef5-98be-fcdb1f616cbf)

This is how the algorithm will run under normal condition, first it will ask for the amount of packages, then the details of the packages.
The next question is the point where the package will start and the point where the package will be delivered.
Lastly is the pathing where the delivery will take.


![image](https://github.com/user-attachments/assets/2350fcd5-043e-41ff-956e-bcfb0860bdbf)

When the user inputs 0 package for delivery, the output will show there is no package.
but the pathing code will still run as the package count part is seperated from the path algorithm.


![image](https://github.com/user-attachments/assets/75ef2594-3137-4ba5-9f58-2e5d297a0d72)

When the user input value of urgency out of the range, the code will still sort it from smallest to largest.
This part could be improve to include limiters.


![image](https://github.com/user-attachments/assets/363e6203-0687-47b2-b67d-9dd552944698)

When the user input value of weight out of the range, the code will still sort it from lightest to heaviest.
This part could also be improve to include limiters.


![image](https://github.com/user-attachments/assets/b3338bd0-3a68-4545-bd08-dfbed106b54b)

When the user input a starting or ending point out of the defined map, the code will stop abruptly and would not continue.


![image](https://github.com/user-attachments/assets/c9356725-8768-4978-897e-6b40601dab26)
as the ending point of the path is using a coordinate system, so the code will not allow multiple end points,
its would on consider the first 2 point as its coordinate for the end point.
It could be seen as a more accurate system but could also is limited to only 1 end point.


![image](https://github.com/user-attachments/assets/526867a3-23c7-4e89-9d45-16aabaf67a12)

When the map is manually expanded to a 30 x 30 map, the algorithm would run as normal but will moe time and more path of go over.


![image](https://github.com/user-attachments/assets/a735e97b-50a2-4241-8aa9-fc91e42c7266)

This is because the map the altered manually and the space is just same as 10 x 10 but only bigger , thus the algorithm will still be able to path through it.


![image](https://github.com/user-attachments/assets/b7b06a8b-d48d-41ca-ab35-8a2cc968a4ce)

When the map is altered till it is not physically possible to path through it, the output will staright output its start point and ending point.


![image](https://github.com/user-attachments/assets/223675e6-1c49-4c61-9108-6e3a2629ccfa)

This is because the algorithm only calculate the cost when the space it can move to have a total distance cost less than the space its on, when it reach the uncrossable barrier,
the algorithm will not be able to calculate the cost or any space beside it.

![image](https://github.com/user-attachments/assets/0b13186d-f415-431e-b24d-d45261e5de54)

=========


Time Complexity

1. A* algorithm 

  Best Case (O(1))

   The best case scenario is when the start and end points are adjacent, or there is a direct, immediate path with minimal processing.
   In this case, the algorithm might only check a few nodes, so it executes very quickly, potentially in O(1) time.

  
  Average Case (O(m * log m))

   m is the number of grid cells (let m = rows * cols).
   The priority queue operations take O(log m) time. In the average case, the algorithm will explore several nodes, and the total number of nodes explored is O(m).
   The average-case time complexity is O(V * log V).

  
  Worst Case (O(V * log V))

   In worst case scenario, the algorithm might need to explore all m nodes , and each node will require O(log m) operations for the priority queue.
   Therefore, the worst-case time complexity remains O(m * log m).


  
2. Sorting Packages

   n is the number of packages.

  
  Best Case (O(n log n))
  
   The best-case scenario occurs if the packages are already sorted. The average-case sorting algorithm has a time complexity of O(n log n).

  
  Average Case (O(n log n)):
  
   Sorting using std::sort() on a vector of n packages typically takes O(n log n) time.

  
  Worst Case (O(n log n)):

   The worst-case time complexity of std::sort() is also O(n log n). This happens when the sorting algorithm has to perform the maximum number of comparisons.


  
3. Input and Output
   
  Best Case (O(1))

   In the best case, if there are very few packages (e.g., n = 1), the I/O operations take constant time O(1).

   
  Average Case (O(n))

   If there are n packages, the time complexity for input and output operations is O(n) because the program processes each package individually.

   
  Worst Case (O(n))

   In the worst case, if there are n packages, the program still performs O(n) I/O operations.


   
4. Overall Time Complexity

   
Combining the time complexities of the major operations (A* pathfinding, package sorting, Input and Output ):


A* Pathfinding

Best Case: O(1) 

Average Case: O(m * log m)

Worst Case: O(m * log m)


Package Sorting

Best Case: O(n log n

Average Case: O(n log n)

Worst Case: O(n log n


Input and Output 

Best Case: O(1) 

Average Case: O(n)

Worst Case: O(n)



Total Time Complexity

  Best Case: O(n log n)
  
    The best-case scenario would occur when A* pathfinding finds a quick solution (O(1)), and I/O operations and sorting are minimal. 
    
  Average Case: O(m * log m + n log n)
  
    The average-case complexity combines sorting and pathfinding with the sorting and A* pathfinding operations contributing significantly.

  Worst Case: O(m * log m + n log n) 
  
    The worst-case scenario happens when A* pathfinding needs to explore all nodes in the grid, and sorting takes the longest time. 









