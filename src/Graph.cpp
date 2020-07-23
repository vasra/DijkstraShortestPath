#include "Graph.h"

Graph::Graph(unsigned short numOfVertices, float density, int minRange, int maxRange): numOfVertices(numOfVertices),
                                                                                       numOfEdges(0),
                                                                                       density(density),
                                                                                       minRange(minRange),
                                                                                       maxRange(maxRange)
{
    generate(density, minRange, maxRange);
}

Graph::~Graph(){}

void Graph::generate(float density, int minRange, int maxRange)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> probability(0.0f, 1.0f);
    std::uniform_int_distribution<>  distVertices(0, numOfVertices - 1);
    float randomProbability = 0.0f;
    float currentDensity = 0.0f;
    unsigned short randomVertex;
    unsigned short verticesCount = 0;

    while( verticesCount < numOfVertices )
        vertices.emplace_back(std::make_shared<Vertex>(verticesCount++));

    while(currentDensity < density )
    {
        for( auto& v : vertices )
        {
            // Randomly pick a vertex to become a neighbour
            do {
                randomVertex = static_cast<short>(distVertices(gen));
            } while (randomVertex == v->getName());

            if ( std::find_if(v->getAdjacencyList().begin(), v->getAdjacencyList().end(), [&randomVertex](std::pair<short, int> p) {
                    return p.first == randomVertex;
                } ) == v->getAdjacencyList().end() )
            {
                // If the generated probability is smaller than the graph density, then proceed with making the two vertices neighbours
                randomProbability = static_cast<float>(probability(gen));
                if(randomProbability < density )
                {
                    addEdge( *v, randomVertex, minRange, maxRange);

                    currentDensity = ( 2.0f * static_cast<float>(numOfEdges) ) / (static_cast<float>(numOfVertices) * (static_cast<float>(numOfVertices) - 1.0f ) );

                    if( currentDensity >= density )
                        return;
                }
            }
        }
    }
}

void Graph::printGraph()
{
    std::string s;
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "                        GRAPH                        " << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "Vertex | Adjacency List" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    for (auto& v : vertices)
    {
        std::cout << v->getName() << "      | ";
        for( auto neighbour = v->getAdjacencyList().begin(); neighbour != v->getAdjacencyList().end(); neighbour++)
        {
            s.append( std::to_string((*neighbour).first ) );
            s.append(" -> ");
        }
        s.erase(s.size() - 3);
        std::cout << s << std::endl;
        s.clear();
    }
    std::cout << std::endl;
    std::cout << "------------" << std::endl;
    std::cout << "Graph stats:" << std::endl;
    std::cout << "------------" << std::endl;
    std::cout << "Vertices   : " << GetNumOfVertices() << std::endl;
    std::cout << "Edges      : " << GetNumOfEdges() << std::endl;
    std::cout << "Density    : " << GetDensity() << std::endl;
}

void Graph::addEdge(Vertex& x, unsigned short neighbour, int minRange, int maxRange)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(minRange, maxRange);
    int weight = dist(gen);

    SetEdgeValue( x, neighbour, weight );
    SetNumOfEdges(numOfEdges + 1 );
}

void Graph::deleteEdge(Vertex& x, unsigned short neighbour)
{
    SetEdgeValue( x, neighbour, 0 );
    SetNumOfEdges(numOfEdges - 1 );
}

short Graph::GetNumOfVertices()
{
    return numOfVertices;
}

short Graph::GetNumOfEdges()
{
    return numOfEdges;
}

float Graph::GetDensity()
{
    return density;
}

int Graph::GetMinRange()
{
    return minRange;
}

int Graph::GetMaxRange()
{
    return maxRange;
}

void Graph::SetNumOfVertices(unsigned short numOfVertices)
{
    this->numOfVertices = numOfVertices;
}

void Graph::SetNumOfEdges(unsigned short numOfEdges)
{
    this->numOfEdges = numOfEdges;
}

void Graph::SetDensity(float density)
{
    this->density = density;
}

void Graph::SetMinRange(int minRange)
{
    this->minRange = minRange;
}

void Graph::SetMaxRange(int maxRange)
{
    this->maxRange = maxRange;
}

void Graph::SetEdgeValue(Vertex& x, unsigned short neighbour, int weight)
{
    x.getAdjacencyList().emplace_front(neighbour, weight);
    std::vector< std::shared_ptr<Vertex> >::iterator it = std::find_if(vertices.begin(), vertices.end(), [&neighbour](std::shared_ptr<Vertex>& v) {
            return v->getName() == neighbour;
        });

    (*it)->getAdjacencyList().emplace_front(x.getName(), weight);
}

std::vector<std::shared_ptr<Vertex>>& Graph::getVertices()
{
    return vertices;
}