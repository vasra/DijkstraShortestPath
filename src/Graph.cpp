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
    float currentDensity = 0.0f;

    srand( static_cast<float>( time( NULL ) ) );

    while(currentDensity < Getm_density())
    {
        for( short i = 0; i < Getm_numOfVertices(); i++ )
        {
            for( short j = i + 1; j < Getm_numOfVertices(); j++ )
            {
                if(Getm_edgeValue(i, j) == 0)
                {
                    randomValue = static_cast<float>( rand() ) / (static_cast<float>( RAND_MAX ) + 1.0f);

                    if( randomValue < Getm_density() )
                    {
                        addEdge( i, j );

                        currentDensity = ( 2.0f * Getm_numOfEdges() ) / ( Getm_numOfVertices() * ( Getm_numOfVertices() - 1.0f ) );

                        if( currentDensity >= Getm_density() )
                            return;
                    }
                }
            }
        }
    }
}

void Graph::printConnectivityMatrix()
{
    cout << "[";
    for(short i = 0; i < Getm_numOfVertices(); i++)
    {
        cout << ( i == 0? " [":"  [");
        for(short j = 0; j < Getm_numOfVertices(); j++)
        {
            if(j == (Getm_numOfVertices() - 1))
                cout << Getm_edgeValue(i, j) << ((i == (Getm_numOfVertices() - 1))? " ] ]":" ],") << endl;
            else
                cout << Getm_edgeValue(i, j) << ", ";
        }
    }
    cout << endl;
    cout << "------------" << endl;
    cout << "Graph stats:" << endl;
    cout << "------------" << endl;
    cout << "Vertices   : " << Getm_numOfVertices() << endl;
    cout << "Edges      : " << Getm_numOfEdges() << endl;
    cout << "Density    : " << Getm_density() << endl;
}

bool Graph::adjacent(short x, short y)
{
    return Getm_edgeValue(x, y) > 0.0f;
}

std::vector<short> Graph::neighbors(short x)
{
    std::vector<short> neighbors;
    for(short i = 0; i < Getm_numOfVertices(); i++)
    {
        if( adjacent(x, i) )
            neighbors.push_back(i);
    }
    return neighbors;
}

void Graph::addEdge(short x, short y)
{
    float weight = (static_cast<float>(rand()) / (static_cast<float>(RAND_MAX))) * 10.0f + 1.0f;
    if( weight > 10.0f )
        weight = 10.0f;
    Setm_edgeValue(x, y, weight);
    Setm_numOfEdges( Getm_numOfEdges() + 1 );
}

void Graph::deleteEdge(short x, short y)
{
    Setm_edgeValue( x, y, 0.0f );
    Setm_numOfEdges( Getm_numOfEdges() - 1 );
}

short Graph::Getm_numOfVertices()
{
    return m_numOfVertices;
}

short Graph::Getm_numOfEdges()
{
    return m_numOfEdges;
}

float Graph::Getm_density()
{
    return m_density;
}

float Graph::Getm_minRange()
{
    return m_minRange;
}

float Graph::Getm_maxRange()
{
    return m_maxRange;
}

short Graph::Getm_nodeValue(short x)
{
    short value = 0;
    for(short y = 0; y < Getm_numOfVertices(); y++)
    {
        if( adjacent( x, y ) )
            value++;
    }
    return value;
}

float Graph::Getm_edgeValue(short x, short y)
{
    return m_adjacencyMatrix[x][y];
}

void Graph::Setm_numOfVertices(short numOfVertices)
{
    m_numOfVertices = numOfVertices;
}

void Graph::Setm_numOfEdges(short numOfEdges)
{
    m_numOfEdges = numOfEdges;
}

void Graph::Setm_density(float density)
{
    m_density = density;
}

void Graph::Setm_minRange(float minRange)
{
    m_minRange = minRange;
}

void Graph::Setm_maxRange(float maxRange)
{
    m_maxRange = maxRange;
}

void Graph::Setm_edgeValue(short i, short j, float value)
{
    m_adjacencyMatrix[i][j] = value;
    m_adjacencyMatrix[j][i] = value;
}
