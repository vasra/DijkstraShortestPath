#include "Graph.h"

using namespace std;

Graph::Graph(short numOfVertices, short density, short minRange, short maxRange): m_numOfVertices(numOfVertices),
                                                                                  m_numOfEdges(0),
                                                                                  m_density(density),
                                                                                  m_minRange(minRange),
                                                                                  m_maxRange(maxRange),
                                                                                  m_adjacencyMatrix(m_numOfVertices, std::vector<short>(m_numOfVertices, 0)){}
Graph::~Graph(){}

void Graph::generateGraph()
{
    short randomValue = 0.0f;
    short currentDensity = 0.0f;

    srand( static_cast<short>( time( NULL ) ) );

    while( currentDensity < getm_density() )
    {
        for( short i = 0; i < getm_numOfVertices(); i++ )
        {
            if(getm_edgeValue(i, j) == 0)
            {
                randomValue = static_cast<short>( rand() ) / (static_cast<short>( RAND_MAX ) + 1.0f);

                if( randomValue < getm_density() )
                {
                    addEdge( i, j );

                    currentDensity = ( 2.0f * getm_numOfEdges() ) / ( getm_numOfVertices() * ( getm_numOfVertices() - 1.0f ) );

                    if( currentDensity >= getm_density() )
                        return;
                }
            }

        }
    }
}

void Graph::printGraph()
{
    cout << "[";
    for(short i = 0; i < getm_numOfVertices(); i++)
    {
        cout << ( i == 0? " [":"  [");
        for(short j = 0; j < getm_numOfVertices(); j++)
        {
            if(j == (getm_numOfVertices() - 1))
                cout << getm_edgeValue(i, j) << ((i == (getm_numOfVertices() - 1))? " ] ]":" ],") << endl;
            else
                cout << getm_edgeValue(i, j) << ", ";
        }
    }
    cout << endl;
    cout << "------------" << endl;
    cout << "Graph stats:" << endl;
    cout << "------------" << endl;
    cout << "Vertices   : " << getm_numOfVertices() << endl;
    cout << "Edges      : " << getm_numOfEdges() << endl;
    cout << "Density    : " << getm_density() << endl;
}

bool Graph::adjacent(Vertex* v1, Vertex* v2)
{
    return (std::find( v1->));
}

std::vector<short> Graph::neighbors(Vertex* v)
{
    std::vector<short> neighbors;
    for(short i = 0; i < getm_numOfVertices(); i++)
    {
        if( adjacent(x, i) )
            neighbors.push_back(i);
    }
    return neighbors;
}

void Graph::addEdge(short x, short y)
{
    short weight = (static_cast<short>(rand()) / (static_cast<short>(RAND_MAX))) * 10.0f + 1.0f;
    if( weight > 10.0f )
        weight = 10.0f;
    setm_edgeValue(x, y, weight);
    setm_numOfEdges( getm_numOfEdges() + 1 );
}

void Graph::deleteEdge(short x, short y)
{
    setm_edgeValue( x, y, 0.0f );
    setm_numOfEdges( getm_numOfEdges() - 1 );
}

short Graph::getm_numOfVertices()
{
    return m_numOfVertices;
}

short Graph::getm_numOfEdges()
{
    return m_numOfEdges;
}

short Graph::getm_density()
{
    return m_density;
}

short Graph::getm_minRange()
{
    return m_minRange;
}

short Graph::getm_maxRange()
{
    return m_maxRange;
}

short Graph::getm_nodeValue(Vertex* v)
{
    return v->getValue();
}

short Graph::getm_edgeValue(Vertex* v1, Vertex* v2)
{
    return m_adjacencyMatrix[v1->getName()][v2->getName()];
}

std::vector<std::vector<short>>* Graph::getm_AdjacencyMatrix()
{
    return &m_adjacencyMatrix;
}

void Graph::setm_numOfVertices(short numOfVertices)
{
    m_numOfVertices = numOfVertices;
}

void Graph::setm_numOfEdges(short numOfEdges)
{
    m_numOfEdges = numOfEdges;
}

void Graph::setm_density(short density)
{
    m_density = density;
}

void Graph::setm_minRange(short minRange)
{
    m_minRange = minRange;
}

void Graph::setm_maxRange(short maxRange)
{
    m_maxRange = maxRange;
}

void Graph::setm_edgeValue(Vertex* v1, Vertex* v2, short v)
{
    m_adjacencyMatrix[v1->getName()][v2->getName()] = value;
    m_adjacencyMatrix[v2->getName()][v1->getName()] = value;
    v1->
}
