#ifndef GRAPH_H
#define GRAPH_H
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <cmath>

class Graph
{
    public:
        Graph(short numOfVertices, float density, float minRange, float maxRange);
        virtual ~Graph();

        void generate();
        void printGraph();
        bool adjacent(short x, short y);
        std::vector<short> neighbors(short x);
        void addEdge(short x, short y);
        void deleteEdge(short x, short y);

        // getters
        short getNumOfVertices();
        short getNumOfEdges();
        float getDensity();
        float getMinRange();
        float getMaxRange();
        short getNodeValue(short x);
        float getEdgeValue(short x, short y);

        // setters
        void setNumOfVertices(short numOfVertices);
        void setNumOfEdges(short numOfEdges);
        void setDensity(float density);
        void setMinRange(float minRange);
        void setMaxRange(float maxRange);
        void setNodeValue(short x, short a);
        void setEdgeValue(short x, short y, float v);

    private:
        short m_numOfVertices;                                  // the total number of vertices in the graph
        short m_numOfEdges;                                     // the total number of edges in the graph
        float m_density;                                        // the desired density of the graph
        float m_minRange;                                       // the lower end of the distance range
        float m_maxRange;                                       // the higher end of the distance range
        std::vector<std::vector<float>> m_adjacencyMatrix;      // the adjacency matrix
};

#endif // GRAPH_H
