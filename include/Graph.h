#ifndef GRAPH_H
#define GRAPH_H
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <random>
#include "Vertex.h"

class Graph
{
    public:
        Graph(short numOfVertices, float density, int minRange, int maxRange);
        virtual ~Graph();

        void generate();
        void printConnectivityMatrix();
        bool adjacent(short x, short y);
        std::vector<short> neighbors(short x);
        void addEdge(Vertex& x, Vertex& y);
        void deleteEdge(short x, short y);

        // Getters
        short Getm_numOfVertices();
        short Getm_numOfEdges();
        float Getm_density();
        int Getm_minRange();
        int Getm_maxRange();
        short Getm_nodeValue(short x);
        int Getm_edgeValue(Vertex x, Vertex y);

        // Setters
        void Setm_numOfVertices(short numOfVertices);
        void Setm_numOfEdges(short numOfEdges);
        void Setm_density(float density);
        void Setm_minRange(int minRange);
        void Setm_maxRange(int maxRange);
        void Setm_nodeValue(Vertex& x, Vertex& a);
        void Setm_edgeValue(Vertex& x, Vertex& y, int weight);

    private:
        short m_numOfVertices;                                 // the total number of vertices in the graph
        short m_numOfEdges;                                    // the total number of edges in the graph
        float m_density;                                       // the desired density of the graph
        int m_minRange;                                        // the lower end of the distance range
        int m_maxRange;                                        // the higher end of the distance range
        //std::vector<std::vector<float>> m_adjacencyMatrix;      // the adjacency matrix
};

#endif // GRAPH_H
