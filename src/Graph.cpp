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
    short numOfEdges = getNumOfEdges();

    for(short i = 0; i < getNumOfVertices(); i++)
    {
        if( currentDensity >= getDensity() )
            return;

        for(short j = i + 1; j < getNumOfVertices(); j++)
        {
            if( currentDensity >= getDensity() )
                return;

            randomValue = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) + 1.0f);

            if(randomValue < getDensity())
            {
                weight = (1.0f + static_cast<float>(rand())) / (static_cast<float>(RAND_MAX) + 10.0f);
                setAdjacencyMatrix(i, j, weight);
                numOfEdges++;
                currentDensity = (2 * numOfEdges) / (getNumOfVertices() * (getNumOfVertices() - 1));
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
                cout << getAdjacencyMatrix(i, j) << ((i == (getNumOfVertices() - 1))?" ] ]":" ],") << endl;
            else
                cout << getAdjacencyMatrix(i, j) << ", ";
        }
    }
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

float Graph::getAdjacencyMatrix(short i, short j)
{
    return this->m_adjacencyMatrix[i][j];
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

void Graph::setAdjacencyMatrix(short i, short j, float value)
{
    this->m_adjacencyMatrix[i][j] = value;
    this->m_adjacencyMatrix[j][i] = value;
}
