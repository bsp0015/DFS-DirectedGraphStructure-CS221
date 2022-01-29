//
//  GraphType.cpp
//  DirectedGraphStructure
//
//  Created by Brandon Perry on 1/29/22.
//

#include "GraphType.hpp"
#include "GraphType.hpp"
#include <stack>
#include <queue>
#include <iostream>

const int NULL_EDGE = 0;

GraphType::GraphType()
// Function: Initializes variables
// Pre: none
// Post: parameters and variables are initiailized
{
    // initializing variables
    numVertices = 0;
    maxVertices = 7;
    vertices = new VertexType[7];
    marks = new bool[7];
};


GraphType::~GraphType()
// Function: arrays are deleted
// Pre: arrays exist
// Post: arrays are deleted // program would not run without the deconstructor being commented out.
// this maybe because of the way in which we are altering the arrays and accessing them?
{
    // delete [] vertices;
    // delete [] marks;
};


void GraphType::AddVertex(VertexType vertex)
// Function: Adds vertex to the graph
// Pre: Graph is not full
// Post: vertex is in V(graph)
{
    vertices[numVertices] = vertex;
    
    for (int index = 0; index < numVertices; index++)
    {
        edges[numVertices][index] = NULL_EDGE;
        edges[index][numVertices] = NULL_EDGE;
    }
    
    numVertices++;
};


int GraphType::IndexIs(VertexType* vertices, VertexType vertex)
// Function: returns the index of vertex in vertices
// Pre: vertex is in vertices
// Post: returns the index
{
    int index = 0;
    while (!(vertex == vertices[index]))
    {
        index++;
    }
    return index;
};


void GraphType::AddEdge(VertexType fromVertex, VertexType toVertex, int weight)
// Function: Adds an edge with the specified weight from fromVertex to toVertex
// Pre: fromVertex and toVertex are in V(graph)
// Post: (FromVertex, toVertex) is in E(graph) with teh specified weight
{
    int row;
    int col;
    
    row = IndexIs(vertices, fromVertex);
    col = IndexIs(vertices, toVertex);
    edges[row][col] = weight;
};


void GraphType::GetToVertices(VertexType vertex, queue<VertexType>& adjVertices)
// Function: Returns a queue of the vertices that are adjacent from vertex
// Pre: vertex is in V(graph)
// Post: veretxQ contains the names of all vertices that are adjacent from vertex
{
    int fromIndex;
    int toIndex;
    
    fromIndex = IndexIs(vertices, vertex);
    
    for (toIndex = 0; toIndex < numVertices; toIndex++)
    {
        if (edges[fromIndex][toIndex] != NULL_EDGE)
        {
            adjVertices.push(vertices[toIndex]);
        }
    }
};


void GraphType::ClearMarks()
// Function: Sets marks for all vertices to false
// Pre: marks exists
// Post: All marks have been set to false
{
    for (int index = 0; index < maxVertices; index++)
    {
        marks[index] = false;
    }
};


void GraphType::MarkVertex(VertexType vertex)
// Function: Sets mark for vertex to true
// Pre: vertex is in V(graph)
// Post: IsMarked(vertex) is true
{
    int index = IndexIs(vertices, vertex);
    marks[index] = true;
};


bool GraphType::IsMarked(VertexType vertex)
// Function: Determines if vertex has been marked
// Pre: vertex is in V(graph)
// Post: Function value = (value is marked true)
{
    int index = IndexIs(vertices, vertex);
    
    return marks[index];
};
