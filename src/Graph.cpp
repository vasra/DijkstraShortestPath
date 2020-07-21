#include "Graph.h"

Graph::Graph(short numOfVertices, float density, int minRange, int maxRange): m_numOfVertices(numOfVertices),
                                                                              m_numOfEdges(0),
                                                                              m_density(density),
                                                                              m_minRange(minRange),
                                                                              m_maxRange(maxRange) {
                                                                                  /*m_adjacencyMatrix(m_numOfVertices, std::vector<float>(m_numOfVertices, 0))*/
    generate();
}

Graph::~Graph(){}

void Graph::generate()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(0.0f, 1.0f);
    float randomValue = 0.0f;
    float currentDensity = 0.0f;

    while(currentDensity < Getm_density())
    {
        for( short i = 0; i < Getm_numOfVertices(); i++ )
        {
            for( short j = i + 1; j < Getm_numOfVertices(); j++ )
            {
                if(Getm_edgeValue(i, j) == 0)
                {
                    randomValue = static_cast<float>(dist(gen));
                    if( randomValue < Getm_density() )
                    {
                        addEdge( i, j );

                        currentDensity = ( 2.0f * Getm_numOfEdges() ) / ( Getm_numOfVertices() * ( Getm_numOfVertices() - 1 ) );

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
    std::cout << "[";
    for(short i = 0; i < Getm_numOfVertices(); i++)
    {
        std::cout << ( i == 0? " [":"  [");
        for(short j = 0; j < Getm_numOfVertices(); j++)
        {
            if(j == (Getm_numOfVertices() - 1))
                std::cout << Getm_edgeValue(i, j) << ((i == (Getm_numOfVertices() - 1))? " ] ]":" ],") << std::endl;
            else
                std::cout << Getm_edgeValue(i, j) << ", ";
        }
    }
    std::cout << std::endl;
    std::cout << "------------" << std::endl;
    std::cout << "Graph stats:" << std::endl;
    std::cout << "------------" << std::endl;
    std::cout << "Vertices   : " << Getm_numOfVertices() << std::endl;
    std::cout << "Edges      : " << Getm_numOfEdges() << std::endl;
    std::cout << "Density    : " << Getm_density() << std::endl;
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

void Graph::addEdge(Vertex& x, Vertex& y)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 10);
    int weight = dist(gen);

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

int Graph::Getm_minRange()
{
    return m_minRange;
}

int Graph::Getm_maxRange()
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

int Graph::Getm_edgeValue(Vertex x, Vertex y)
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

void Graph::Setm_minRange(int minRange)
{
    m_minRange = minRange;
}

void Graph::Setm_maxRange(int maxRange)
{
    m_maxRange = maxRange;
}

void Graph::Setm_edgeValue(Vertex& x, Vertex& y, int weight)
{
    x.getAdjacencyList().emplace_front(std::make_pair<y, weight>);
    //m_adjacencyMatrix[i][j] = value;
    //m_adjacencyMatrix[j][i] = value;
}
