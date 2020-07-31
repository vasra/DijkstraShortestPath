#include "Graph.h"

Graph::Graph(unsigned short numOfVertices, float density, unsigned int minRange, unsigned int maxRange): numOfVertices(numOfVertices),
                                                                                       numOfEdges(0),
                                                                                       density(density),
                                                                                       minRange(minRange),
                                                                                       maxRange(maxRange) { generate(density, minRange, maxRange); }

Graph::~Graph(){}

void Graph::generate(float density, unsigned int minRange, unsigned int maxRange) {
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

    while(currentDensity < density ) {
        for( auto& v : vertices ) {
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
                if(randomProbability < density ) {
                    addEdge( v, randomVertex, minRange, maxRange);

                    currentDensity = ( 2.0f * static_cast<float>(numOfEdges) ) / (static_cast<float>(numOfVertices) * (static_cast<float>(numOfVertices) - 1.0f ) );

                    if( currentDensity >= density )
                        return;
                }
            }
        }
    }
}

void Graph::printGraph() {
    std::string s;
    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << "                        GRAPH                        "           << std::endl;
    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << "Vertex | Adjacency List: vertex(edge weight) -> next neighbour"  << std::endl;
    std::cout << "---------------------------------------------------------------" << std::endl;
    for (auto& v : vertices) {
        std::cout << v->getName() << "      | ";
        for (auto neighbour : v->getAdjacencyList()) {
            s.append( std::to_string( neighbour.first ) );
            s.append("(");
            s.append( std::to_string( neighbour.second ) );
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
    std::cout << "Density    : " << GetDensity() << std::endl << std::endl;
}

void Graph::printShortestPath(std::vector<unsigned short>& path) {
    std::cout << "The shortest path from vertex " << path.back() << " to vertex " << path.front() << " is the below with a cost of " << pathCost(path) << std::endl;
    for (auto v = path.rbegin(); v != path.rend(); v++) {
        if (v != path.rend() - 1)
            std::cout << *v << " -> ";
        else
            std::cout << *v << std::endl;
    }
}

void Graph::addEdge(std::shared_ptr<Vertex> v, unsigned short neighbour, unsigned int minRange, unsigned int maxRange, unsigned int weight) {
    if (weight == 0) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(minRange, maxRange);
        weight = dist(gen);
    }

    SetEdgeValue( v, neighbour, weight );
    SetNumOfEdges( numOfEdges + 1 );
}

void Graph::deleteEdge(std::shared_ptr<Vertex> v, unsigned short neighbour) {
    SetEdgeValue( v, neighbour, 0 );
    SetNumOfEdges( numOfEdges - 1 );
}

int Graph::pathCost(std::vector<unsigned short>& path) {
    int cost = 0;
    for (auto v : path) {
        std::shared_ptr<Vertex> vertex = getVertexFromName(v), previous = vertex->getPrevious();
        if (previous != nullptr) {
            auto edge = std::find_if(vertex->getAdjacencyList().begin(), vertex->getAdjacencyList().end(), [&previous](std::pair<unsigned short, unsigned short> p) {
                return p.first == previous->getName();
                });

            cost += edge->second;
        }
    }
    return cost;
}

// Data structures that will be used in the Dikstra algorithm:
// unchecked     - A set that will hold the names of all the vertices that the algorithm hasn't processed yet
// distances     - A map that will hold the names of all the neighbouring vertices of the current vertex that is being examined,
//                 and their total distance from the starting vertex
// path          - A vector that will hold the names of the vertices of the shortest path
// queue         - The priority queue that will be used by the algorithm
// currentVertex - Pointer to the vertex that the algorithm is currently visiting. It gets initialized to the starting vertex
std::vector<unsigned short> Graph::dijkstraShortestPath(unsigned short start, unsigned short destination) {
    std::set<unsigned short> unchecked;
    std::map<unsigned short, unsigned short> distances;
    std::vector<unsigned short> path;
    PriorityQueue queue;
    auto currentVertex = getVertexFromName(start);

    // Initialize all vertices' distances to infinite (INT_MAX), except for the starting vertex.
    for (int i = 0; i < this->GetNumOfVertices(); i++) {
        auto it = getVertexFromName(i);
        if (i != start)
            distances.emplace(it->getName(), INT_MAX);
        else
            distances.emplace(it->getName(), 0);

        unchecked.insert(i);
    }

    // Keep traversing the graph until there are no more vertices to process
    while (!unchecked.empty()) {
        for (auto v : currentVertex->getAdjacencyList()) {
            if (unchecked.find(v.first) != unchecked.end()) {
                // Find the neighbour v in the distances map...
                auto neighbour = distances.find(v.first);
                auto neighbourPointer = getVertexFromName(neighbour->first);

                // ...also find the current vertex in the distances map
                auto current = distances.find(currentVertex->getName());

                if (v.second + current->second < neighbour->second) {
                    neighbour->second = v.second + current->second;                    
                    neighbourPointer->setPrevious(currentVertex);
                }

                queue.addToQueue(neighbourPointer, neighbour->second);
            }
        }
        unchecked.erase(currentVertex->getName());
        currentVertex = queue.pop();
    }

    std::shared_ptr<Vertex> pathVertex = getVertexFromName(destination);
    path.emplace_back(pathVertex->getName());
    while (pathVertex->getPrevious() != nullptr) {
        path.emplace_back(pathVertex->getPrevious()->getName());
        pathVertex = pathVertex->getPrevious();
    }
    return path;
}

unsigned short Graph::GetNumOfVertices() {
    return numOfVertices;
}

unsigned short Graph::GetNumOfEdges() {
    return numOfEdges;
}

float Graph::GetDensity() {
    return density;
}

unsigned int Graph::GetMinRange() {
    return minRange;
}

unsigned int Graph::GetMaxRange() {
    return maxRange;
}

void Graph::SetNumOfVertices(unsigned short numOfVertices) {
    this->numOfVertices = numOfVertices;
}

void Graph::SetNumOfEdges(unsigned short numOfEdges) {
    this->numOfEdges = numOfEdges;
}

void Graph::SetDensity(float density) {
    this->density = density;
}

void Graph::SetMinRange(unsigned int minRange) {
    this->minRange = minRange;
}

void Graph::SetMaxRange(unsigned int maxRange) {
    this->maxRange = maxRange;
}

void Graph::SetEdgeValue(std::shared_ptr<Vertex> v, unsigned short neighbour, unsigned int weight) {
    auto neighbourPointer = getVertexFromName(neighbour);
    if (weight == 0) {
        v->getAdjacencyList().remove_if([&neighbour](std::pair<unsigned short, unsigned int> p) { return p.first == neighbour; });
        neighbourPointer->getAdjacencyList().remove_if([&v](std::pair<unsigned short, unsigned int> p) { return p.first == v->getName(); });
    }
    else {
        v->getAdjacencyList().emplace_front(neighbour, weight);
        neighbourPointer->getAdjacencyList().emplace_front(v->getName(), weight);
    }
}

const std::vector<std::shared_ptr<Vertex>>& Graph::getVertices() {
    return vertices;
}

const std::shared_ptr<Vertex> Graph::getVertexFromName(unsigned short name) {
    auto vertex = std::find_if(vertices.begin(), vertices.end(), [&name](std::shared_ptr<Vertex> v) {
        return v->getName() == name;
        });

    return *vertex;
}