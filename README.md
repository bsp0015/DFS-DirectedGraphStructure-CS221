# Depth First Search on a created Directed Graph Structure CS221
This is a program from my CS221 class. It creates a directed graph and then performs a Depth First Search on it to find a path from two designated vertex.

Completed: 11-22-2020

Assigned by: Mr. Troung Tran

&nbsp;

## Assignment

## 1. Overview
This assignment is to implement and test a directed graph structure. The directed graph G = (V, E) in this assignment contains vertices of character type with weighted edges. 

&nbsp;

## 2. Requirements
### 2.1 (Class) 
Implement a GraphType class that can hold up to 7 vertices of character type using the following specification file:
```C++
#include <stack>
#include <queue>

using namespace std;

typedef char VertexType;

class GraphType
{
public:
   GraphType(); // Default of 7 vertices
   ~GraphType();
   //void MakeEmpty();
   //bool IsEmpty() const;
   //bool IsFull() const;
   void AddVertex(VertexType);
   void AddEdge(VertexType, VertexType, int);
   void GetToVertices(VertexType, queue<VertexType>&);
   void ClearMarks();
   void MarkVertex(VertexType);
   bool IsMarked(VertexType);
   
private:
   int numVertices;
   int maxVertices;
   VertexType* vertices;
   int edges[7][7];
   bool* marks; // marks[i] is mark for vertices[i].
};
```
The implementation of the graph may follow the code in the textbook pages 741 to 744.

There are important notices from the specification above:

- VertexType is declared as char type
- The graph can hold up to 7 vertices
- Just using a default constructor
- The adjacency matrix has a fixed size of 7x7
- The 'stack' type is the STL C++ from #include <stack>. Sample code for the stack can see here: https://www.geeksforgeeks.org/stack-in-cpp-stl/ (Links to an external site.)
- The 'queue' type is the STL C++ from #include <queue>. This STL queue use 'push' and 'pop' function names for 'enqueue' and 'dequeue' operation. Please modify your code to match these function names. Sample code for a queue can see here: https://www.geeksforgeeks.org/queue-cpp-stl/ (Links to an external site.)
### 2.2 (Test Driver) 
Implement a test program that contains a main function and a DepthFirstSearch function.

### Main function:

Read the input file and call suitable functions in the graph type to create a graph based on the following input data: </summary>

- AddVertex A
- AddVertex B
- AddVertex C
- AddVertex D
- AddVertex E
- AddVertex F
- AddVertex G
- AddEdge A C 1
- AddEdge A D 1
- AddEdge B A 1
- AddEdge B D 1
- AddEdge C B 1
- AddEdge C D 1
- AddEdge D F 1
- AddEdge F E 1
- AddEdge F G 1
- AddEdge G E 1
- Quit 

After creating the graph, the main function calls the DepthFirstSearch to find and print the path from vertex A to vertex E

### DepthFirstSearch function: 
This function takes in a GraphType object, a start vertex, and an end vertex as the parameters. Then it will find and print the vertices on the path from the start to the end vertex following the depth-first search algorithm. If the path does not exist, the function prints a 'path not found' to the output file. The sample code for the DepthFirstSearch function is on textbook pages 731 and 732. Remember to modify the code to fit with the stack, queue, and VertexType as in the specification code in section 2.1 above.

&nbsp;

## 3. Submission

### 3.2 Program Test Plan Documentation: 
The student shall provide the test plan that contains:
- The input and expected outputs.
-  For the testing of the DepthFirstSearch function, the expected output must be included in the test plan. 
- Testing result: A drawing (by the student, not by this program) of the graph based on the vertices and edges above, the actual output in the output file, any existing errors, copy of the terminal output. 
