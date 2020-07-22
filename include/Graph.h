#ifndef GRAPH_H
#define GRAPH_H
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <random>
#include <string>
#include "Vertex.h"

class Graph
{
    public:
        Graph(short numOfVertices, float density, int minRange, int maxRange);
        virtual ~Graph();

        void generate();
        void printGraph();
        void addEdge(Vertex& x, unsigned short neighbour);
        void deleteEdge(Vertex& x, unsigned short neighbour);

        // Getters
        short GetNumOfVertices();
        short GetNumOfEdges();
        float GetDensity();
        int GetMinRange();
        int GetMaxRange();

        // Setters
        void SetNumOfVertices(short numOfVertices);
        void SetNumOfEdges(short numOfEdges);
        void SetDensity(float density);
        void SetMinRange(int minRange);
        void SetMaxRange(int maxRange);
        //void SetNodeValue(Vertex& x, Vertex& a);
        void SetEdgeValue(Vertex& x, unsigned short neighbour, int weight);

    private:
        short numOfVertices;                                // the total number of vertices in the graph
        short numOfEdges;                                   // the total number of edges in the graph
        float density;                                      // the desired density of the graph
        int   minRange;                                     // the lower end of the distance range
        int   maxRange;                                     // the higher end of the distance range
        std::vector<std::unique_ptr<Vertex>> vertices;      // the vertices of the graph
};

#endif // GRAPH_H
