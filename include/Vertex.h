#ifndef VERTEX_H
#define VERTEX_H

#include <vector>

class Vertex
{
    public:
        Vertex(short name, short value);
        virtual ~Vertex();

        unsigned short getName();
        unsigned short getValue();
        std::vector<Vertex*> getAdjacencyList();
        void setName(unsigned short val);
        void setValue(unsigned short val);
        void setAdjacencyList(Vertex* v);

    private:
        unsigned short m_name;
        unsigned short m_value;
        std::vector<Vertex*> m_adjacencyList;
};

#endif // VERTEX_H
