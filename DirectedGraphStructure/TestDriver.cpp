//
//  TestDriver.cpp
//  DirectedGraphStructure
//
//  Created by Brandon Perry on 1/29/22.
//

#include <stdio.h>
#include "GraphType.hpp"
#include <iostream>
#include <stack>
#include <queue>
#include <fstream>
#include <string>

using namespace std;

// Function declaration
void DepthFirstSearch(ofstream &outFile, GraphType graph, VertexType startVertex, VertexType endVertex);

int main()
{
    // variable definitions
    using namespace std;
    
    ifstream inFile;        // operation file
    ofstream outFile;       // output file
    string inFileName;      // intput file name
    string outFileName;     // output file name
    string command;         // operation to be executed
    
    int numCommands;
    int weight;
    
    GraphType graph;
    VertexType startVertex;
    VertexType endVertex;
    VertexType vertex;

    
    //prompts for file name, reads in, preapres file
    cout << "Enter name of input file; press return." << endl;
    cin >> inFileName;
    inFile.open(inFileName.c_str());
    
    cout << "Enter name of output file; press return." << endl;
    cin >> outFileName;
    outFile.open(outFileName.c_str());
    
    // makes sure file is opened
    if (!inFile)
    {
        cout << "File not found." << endl;
        exit(2);
    }
    
    // initializes number of commands
    numCommands = 0;
    
    // while the end of file hasn't been reached
    while (!inFile.eof()) {
        
        // read in command
        inFile >> command;
        while (command != "Quit")
        {
            if (command == "AddVertex")
            {
                // reads in vertex
                inFile >> vertex;
                
                // calls function
                graph.AddVertex(vertex);
            }
            else if (command == "AddEdge")
            {
                // reads in two vertexes and weight
                inFile >> startVertex >> endVertex >> weight;
                
                // calls function
                graph.AddEdge(startVertex, endVertex, weight);
            }
            else
            {
                // prints out error if unrecognizable command
                outFile << "Error" << endl;
            }
            
            // increments the number of commands
            numCommands++;
            
            // prints out command operation
            cout << "Command number " << numCommands << " completed." << endl;
            inFile >> command;
        };
    };
    
    // lets user know testing is complete
    cout << "Testing completed." << endl;
    cout << "Graph Created." << endl;
    
    // redefines start and end vertexes
    startVertex = 'A';
    endVertex = 'E';
    
    // calls algorithm
    DepthFirstSearch(outFile, graph, startVertex, endVertex);
    
    return 0;
}


void DepthFirstSearch(ofstream &outFile, GraphType graph, VertexType startVertex, VertexType endVertex)
{
    using namespace std;
    
    stack <VertexType> stack;
    queue <VertexType> vertexQ;
    
    bool found = false;
    
    VertexType vertex;
    VertexType item;
    
    graph.ClearMarks();
    stack.push(startVertex);
    
    do
    {
        vertex = stack.top();
        stack.pop();
        
        if (vertex == endVertex)
        {
            outFile << vertex;
            found = true;
        }
        else
        {
            if (!graph.IsMarked(vertex))
            {
                graph.MarkVertex(vertex);
                outFile << vertex;
                graph.GetToVertices(vertex, vertexQ);
                
                while (!vertexQ.empty())
                {
                    item = vertexQ.front();
                    vertexQ.pop();
                    
                    if (!graph.IsMarked(item))
                        stack.push(item);
                }
            }
        }
    } while (!stack.empty() && !found);
    
    if (!found)
    {
        outFile << "Path not found." << endl;
    }
}
