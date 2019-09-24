#ifndef GRAPH_H
#define GRAPH_H
#include <stdlib.h>
#include <iostream>
#include <vector>

class Graph
{
    public:
        Graph(short numOfVertices, float density, float minRange, float maxRange);
        virtual ~Graph();

        void generate();
        void printGraph();

        // getters
        short getNumOfVertices();
        short getNumOfEdges();
        float getDensity();
        float getMinRange();
        float getMaxRange();
        float getAdjacencyMatrix(short i, short j);

        // setters
        void setNumOfVertices(short numOfVertices);
        void setNumOfEdges(short numOfEdges);
        void setDensity(float density);
        void setMinRange(float minRange);
        void setMaxRange(float maxRange);
        void setAdjacencyMatrix(short i, short j, float value);

    private:
        short m_numOfVertices;             // the total number of vertices in the graph
        short m_numOfEdges;                // the total number of edges in the graph
        float m_density;                   // the desired density of the graph
        float m_minRange;                  // the lower end of the distance range
        float m_maxRange;                  // the higher end of the distance range
        std::vector<std::vector<float>> m_adjacencyMatrix;      // the adjacency matrix
};

#endif // GRAPH_H
