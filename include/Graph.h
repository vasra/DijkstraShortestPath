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
        Graph(unsigned short numOfVertices, float density, int minRange, int maxRange);
        virtual ~Graph();

        void generate(float density, int minRange, int maxRange);
        void printGraph();
        void addEdge(Vertex& x, unsigned short neighbour, int minRange, int maxRange);
        void deleteEdge(Vertex& x, unsigned short neighbour);

        // Getters
        short GetNumOfVertices();
        short GetNumOfEdges();
        float GetDensity();
        int GetMinRange();
        int GetMaxRange();
        std::vector<std::shared_ptr<Vertex>>& getVertices();

        // Setters
        void SetNumOfVertices(unsigned  short numOfVertices);
        void SetNumOfEdges(unsigned  short numOfEdges);
        void SetDensity(float density);
        void SetMinRange(int minRange);
        void SetMaxRange(int maxRange);
        void SetEdgeValue(Vertex& x, unsigned short neighbour, int weight);

    private:
        unsigned short numOfVertices;                       // the total number of vertices in the graph
        unsigned short numOfEdges;                          // the total number of edges in the graph
        float density;                                      // the desired density of the graph
        int   minRange;                                     // the lower end of the distance range
        int   maxRange;                                     // the higher end of the distance range
        std::vector<std::shared_ptr<Vertex>> vertices;      // the vertices of the graph
};

#endif // GRAPH_H
