#include "Graph.h"

Graph::Graph(unsigned short numOfVertices, float density, unsigned int minRange, unsigned int maxRange): numOfVertices(numOfVertices),
                                                                                       numOfEdges(0),
                                                                                       density(density),
                                                                                       minRange(minRange),
                                                                                       maxRange(maxRange)
{
    generate(density, minRange, maxRange);
}

Graph::~Graph(){}

void Graph::generate(float density, unsigned int minRange, unsigned int maxRange)
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

            if ( std::find_if(v->getAdjacencyList().begin(), v->getAdjacencyList().end(), [&randomVertex](std::pair<short, unsigned int> p) {
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
    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << "                        GRAPH                        " << std::endl;
    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << "Vertex | Adjacency List: vertex(edge weight) -> next neighbour" << std::endl;
    std::cout << "---------------------------------------------------------------" << std::endl;
    for (auto& v : vertices)
    {
        std::cout << v->getName() << "      | ";
        for( auto neighbour = v->getAdjacencyList().begin(); neighbour != v->getAdjacencyList().end(); neighbour++)
        {
            s.append( std::to_string( (*neighbour).first ) );
            s.append("(");
            s.append( std::to_string( (*neighbour).second ) );
            s.append(")");
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

void Graph::addEdge(Vertex& x, unsigned short neighbour, unsigned int minRange, unsigned int maxRange, unsigned int weight)
{
    //unsigned int w;
    if (weight == 0)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(minRange, maxRange);
        weight = dist(gen);
    }
    /*else
        w = weight;*/

    SetEdgeValue( x, neighbour, weight );
    SetNumOfEdges( numOfEdges + 1 );
}

void Graph::deleteEdge(Vertex& x, unsigned short neighbour)
{
    SetEdgeValue( x, neighbour, 0 );
    SetNumOfEdges( numOfEdges - 1 );
}

void Graph::dijkstraShortestPath(unsigned short start, unsigned short destination)
{
    // Data structures that will be used in the Dikstra algorithm:
    // unchecked     - A set that will hold the names of all the vertices that the algorithm hasn't processed yet
    // distances     - A map that will hold the names of all the neighbouring vertices of the current vertex that is being examined,
    //                 and their total distance from the starting vertex
    // path          - A vector that will hold the names of the vertices of the shortest path
    // queue         - The priority queue that will be used by the algorithm
    // currentVertex - Pointer to the vertex that the algorithm is currently visiting. It gets initialized to the starting vertex
    std::set<unsigned short> unchecked;
    std::map<unsigned short, unsigned short> distances;
    std::vector<unsigned short> path;
    PriorityQueue queue;
    auto currentVertex = *(std::find_if(vertices.begin(), vertices.end(), [&start](std::shared_ptr<Vertex> v) { return v->getName() == start; } ));

    // Initialize all vertices' distances to infinite (INT_MAX), except for the starting vertex.
    for (int i = 0; i < this->GetNumOfVertices(); i++)
    {
        auto it = std::find_if(vertices.begin(), vertices.end(), [&i](std::shared_ptr<Vertex> v) { return v->getName() == i; });
        if (i != start)
        {
            distances.emplace((*it)->getName(), INT_MAX);
            unchecked.insert(i);
        }
        else
            distances.emplace((*it)->getName(), 0);
    }

    // Keep traversing the graph until there are no more vertices to process
    while (!unchecked.empty())
    {
        for (auto v : currentVertex->getAdjacencyList())
        {
            if (unchecked.find(v.first) != unchecked.end())
            {
                // Find the neighbour v in the distances map...
                auto neighbour = distances.find(v.first);/*std::find_if(distances.begin(), distances.end(), [&v](std::pair<std::shared_ptr<Vertex>, unsigned short> p) {
                    return p.first->getName() == v.first;
                    });*/

                    // ...also find the current vertex in the distances map
                auto current = distances.find(currentVertex->getName());/*std::find_if(distances.begin(), distances.end(), [&currentVertex](std::pair<std::shared_ptr<Vertex>, unsigned short> p) {
                    return currentVertex->getName() == p.first->getName();
                    });*/

                if (v.second + current->second < neighbour->second)
                {
                    neighbour->second = v.second + current->second;
                    auto neighbourPointer = std::find_if(this->getVertices().begin(), this->getVertices().end(), [&neighbour](std::shared_ptr<Vertex> vptr) {
                        return neighbour->first == vptr->getName();
                        });
                    (*neighbourPointer)->setPrevious(currentVertex);
                }
            }
            unchecked.erase(currentVertex->getName());
        }
    }
}

unsigned short Graph::GetNumOfVertices()
{
    return numOfVertices;
}

unsigned short Graph::GetNumOfEdges()
{
    return numOfEdges;
}

float Graph::GetDensity()
{
    return density;
}

unsigned int Graph::GetMinRange()
{
    return minRange;
}

unsigned int Graph::GetMaxRange()
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

void Graph::SetMinRange(unsigned int minRange)
{
    this->minRange = minRange;
}

void Graph::SetMaxRange(unsigned int maxRange)
{
    this->maxRange = maxRange;
}

void Graph::SetEdgeValue(Vertex& x, unsigned short neighbour, unsigned int weight)
{
    if (weight == 0)
    {
        x.getAdjacencyList().remove_if([&neighbour](std::pair<unsigned short, unsigned int> p) { return p.first == neighbour; });
        auto it = std::find_if(vertices.begin(), vertices.end(), [&neighbour](std::shared_ptr<Vertex>& v) {
            return v->getName() == neighbour;
            });
        (*it)->getAdjacencyList().remove_if([&x](std::pair<unsigned short, unsigned int> p) { return p.first == x.getName(); });
    }
    else
    {
        x.getAdjacencyList().emplace_front(neighbour, weight);
        auto it = std::find_if(vertices.begin(), vertices.end(), [&neighbour](std::shared_ptr<Vertex>& v) {
            return v->getName() == neighbour;
            });

        (*it)->getAdjacencyList().emplace_front(x.getName(), weight);
    }
}

std::vector<std::shared_ptr<Vertex>>& Graph::getVertices()
{
    return vertices;
}