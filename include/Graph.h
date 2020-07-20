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
        void printConnectivityMatrix();
        bool adjacent(short x, short y);
        std::vector<short> neighbors(short x);
        void addEdge(short x, short y);
        void deleteEdge(short x, short y);

        // Getm_ters
        short Getm_numOfVertices();
        short Getm_numOfEdges();
        float Getm_density();
        float Getm_minRange();
        float Getm_maxRange();
        short Getm_nodeValue(short x);
        float Getm_edgeValue(short x, short y);

        // Setm_ters
        void Setm_numOfVertices(short numOfVertices);
        void Setm_numOfEdges(short numOfEdges);
        void Setm_density(float density);
        void Setm_minRange(float minRange);
        void Setm_maxRange(float maxRange);
        void Setm_nodeValue(short x, short a);
        void Setm_edgeValue(short x, short y, float v);

    private:
        short m_numOfVertices;                                  // the total number of vertices in the graph
        short m_numOfEdges;                                     // the total number of edges in the graph
        float m_density;                                        // the desired density of the graph
        float m_minRange;                                       // the lower end of the distance range
        float m_maxRange;                                       // the higher end of the distance range
        std::vector<std::vector<float>> m_adjacencyMatrix;      // the adjacency matrix
};

#endif // GRAPH_H
