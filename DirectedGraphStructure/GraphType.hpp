//
//  GraphType.hpp
//  DirectedGraphStructure
//
//  Created by Brandon Perry on 1/29/22.
//

#ifndef GraphType_hpp
#define GraphType_hpp

#include <stdio.h>
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
    //bool IsEmpty() const;     // unused functions
    //bool IsFull() const;
    
    // functions for GraphType
    void AddVertex(VertexType vertexv);
    void AddEdge(VertexType startVertex, VertexType endVertex, int weight);
    void GetToVertices(VertexType toVertex, queue<VertexType>& endVertex);
    void ClearMarks();
    void MarkVertex(VertexType vertex);
    bool IsMarked(VertexType vertex);
    
    // Additional Helper Functions
    int IndexIs(VertexType* vertices, VertexType vertex);
    
private:
    int numVertices;
    int maxVertices = 7;
    VertexType* vertices;
    int edges[7][7];
    bool* marks; // marks[i] is mark for vertices[i].
};

#endif /* GraphType_hpp */
