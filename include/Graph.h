#ifndef GRAPH_H
#define GRAPH_H
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <cmath>

#include "Vertex.h"

class Graph
{
    public:
        Graph(short numOfVertices, short density, short minRange, short maxRange);
        virtual ~Graph();

        void generateGraph();
        void printAdjacencyMatrix();
        bool adjacent(Vertex* v1, Vertex* v2);
        std::vector<Vertex*> neighbors(Vertex* v);
        void addEdge(Vertex* v1, Vertex* v2);
        void deleteEdge(Vertex* v1, Vertex* v2);

        // getters
        short getm_numOfVertices();
        short getm_numOfEdges();
        short getm_density();
        short getm_minRange();
        short getm_maxRange();
        short getm_nodeValue(Vertex* v);
        short getm_edgeValue(Vertex* v1, Vertex* v2);
        std::vector<std::vector<short>>* getm_AdjacencyMatrix();

        // setters
        void setm_numOfVertices(short numOfVertices);
        void setm_numOfEdges(short numOfEdges);
        void setm_density(short density);
        void setm_minRange(short minRange);
        void setm_maxRange(short maxRange);
        void setm_edgeValue(Vertex* v1, Vertex* v2, short v);

    private:
        std::vector<Vertex> m_vertices;                         // vector containing all the vertices of the graph
        short m_numOfVertices;                                  // the total number of vertices in the graph
        short m_numOfEdges;                                     // the total number of edges in the graph
        short m_density;                                        // the desired density of the graph
        short m_minRange;                                       // the lower end of the distance range
        short m_maxRange;                                       // the higher end of the distance range
        std::vector<std::vector<short>> m_adjacencyMatrix;      // the adjacency matrix
};

#endif // GRAPH_H
