#ifndef GRAPH_H
#define GRAPH_H
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <ctime>
#include <random>
#include <string>
#include "Vertex.h"
#include "PriorityQueue.h"

class Graph
{
    public:
        Graph(unsigned short numOfVertices, float density, unsigned int minRange, unsigned int maxRange);
        virtual ~Graph();

        void generate(float density, unsigned int minRange, unsigned int maxRange);
        void printGraph();
        void addEdge(Vertex& x, unsigned short neighbour, unsigned int minRange, unsigned int maxRange, unsigned int weight = 0);
        void deleteEdge(Vertex& x, unsigned short neighbour);
        void dijkstraShortestPath(unsigned short start, unsigned short destination);

        // Getters
        unsigned short GetNumOfVertices();
        unsigned short GetNumOfEdges();
        float GetDensity();
        unsigned int GetMinRange();
        unsigned int GetMaxRange();
        std::vector<std::shared_ptr<Vertex>>& getVertices();

        // Setters
        void SetNumOfVertices(unsigned  short numOfVertices);
        void SetNumOfEdges(unsigned  short numOfEdges);
        void SetDensity(float density);
        void SetMinRange(unsigned int minRange);
        void SetMaxRange(unsigned int maxRange);
        void SetEdgeValue(Vertex& x, unsigned short neighbour, unsigned int weight);

    private:
        unsigned short numOfVertices;                       // the total number of vertices in the graph
        unsigned short numOfEdges;                          // the total number of edges in the graph
        float density;                                      // the desired density of the graph
        unsigned int   minRange;                            // the lower end of the distance range
        unsigned int   maxRange;                            // the higher end of the distance range
        std::vector<std::shared_ptr<Vertex>> vertices;      // the vertices of the graph
};
#endif GRAPH_H