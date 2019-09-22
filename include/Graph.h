#ifndef GRAPH_H
#define GRAPH_H

#include "Vertex.h"

class Graph
{
    public:
        Graph(short numOfVertices, float density, short range);
        virtual ~Graph();

        // getters and setters
        short getNumOfVertices();
        float getDensity();
        short getRange();
        std::vector<Vertex> getVertices();

        void setNumOfVertices(short vertices);
        void setDensity(float density);
        void setRange(short range);

    private:
        short m_numOfVertices;             // the total number of vertices in the graph
        float m_density;                   // the desired density of the graph
        short m_range;                     // distance range
        std::vector<Vertex> m_vertices;    // vector containing all the vertices of the graph
};

#endif // GRAPH_H
