#include "Graph.h"

using namespace std;

Graph::Graph(short numOfVertices, float density, float minRange, float maxRange): m_numOfVertices(numOfVertices),
                                                                                  m_numOfEdges(0),
                                                                                  m_density(density),
                                                                                  m_minRange(minRange),
                                                                                  m_maxRange(maxRange),
                                                                                  m_adjacencyMatrix(m_numOfVertices, std::vector<float>(m_numOfVertices, 0)){}
Graph::~Graph(){}

void Graph::generate()
{
    float randomValue = 0.0f;
    float weight = 0.0f;
    float currentDensity = 0.0f;

    srand(static_cast<float>(time(NULL)));
    for(short i = 0; i < getNumOfVertices(); i++)
    {
        for(short j = i + 1; j < getNumOfVertices(); j++)
        {
            randomValue = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) + 1.0f);

            if(randomValue < getDensity())
            {
                weight = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX)) * 10.0f + 1.0f;
                setEdgeValue(i, j, weight);
                setNumOfEdges(getNumOfEdges() + 1);
                currentDensity = (2 * getNumOfEdges()) / (getNumOfVertices() * (getNumOfVertices() - 1));
                if( currentDensity >= getDensity() )
                    return;
            }
        }
    }
}

void Graph::printGraph()
{
    cout << "[";
    for(short i = 0; i < getNumOfVertices(); i++)
    {
        cout << ( i == 0? " [":"  [");
        for(short j = 0; j < getNumOfVertices(); j++)
        {
            if(j == (getNumOfVertices() - 1))
                cout << getEdgeValue(i, j) << ((i == (getNumOfVertices() - 1))?" ] ]":" ],") << endl;
            else
                cout << getEdgeValue(i, j) << ", ";
        }
    }
}

bool Graph::adjacent(short x, short y)
{
    return getEdgeValue(x, y) > 0.0f;
}

std::vector<short> Graph::neighbors(short x)
{
    std::vector<short> neighbors;
    for(short i = 0; i < getNumOfVertices(); i++)
    {
        if( adjacent(x, i) )
            neighbors.push_back(i);
    }
    return neighbors;
}

void Graph::addEdge(short x, short y)
{
    srand(static_cast<float>(time(NULL)));
    float weight = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX)) * 10.0f + 1.0f;
    setEdgeValue(x, y, weight);
}

short Graph::getNumOfVertices()
{
    return this->m_numOfVertices;
}

short Graph::getNumOfEdges()
{
    return this->m_numOfEdges;
}

float Graph::getDensity()
{
    return this->m_density;
}

float Graph::getMinRange()
{
    return this->m_minRange;
}

float Graph::getMaxRange()
{
    return this->m_maxRange;
}

float Graph::getEdgeValue(short x, short y)
{
    return this->m_adjacencyMatrix[x][y];
}

void Graph::setNumOfVertices(short numOfVertices)
{
    this->m_numOfVertices = numOfVertices;
}

void Graph::setNumOfEdges(short numOfEdges)
{
    this->m_numOfEdges = numOfEdges;
}

void Graph::setDensity(float density)
{
    this->m_density = density;
}

void Graph::setMinRange(float minRange)
{
    this->m_minRange = minRange;
}

void Graph::setMaxRange(float maxRange)
{
    this->m_maxRange = maxRange;
}

void Graph::setEdgeValue(short i, short j, float value)
{
    this->m_adjacencyMatrix[i][j] = value;
    this->m_adjacencyMatrix[j][i] = value;
}
