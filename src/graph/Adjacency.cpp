#include "Adjacency.h"

#include "Vertex.h"

Adjacency::Adjacency(Vertex const &vertex, int weight)
    : _vertex(vertex), _weight(weight) {}

Adjacency::Adjacency(Adjacency const &other)
    : _vertex(other._vertex), _weight(other._weight) {}

Vertex const &Adjacency::getVertex() const { return _vertex; }

weight Adjacency::getWeight() const { return _weight; }

bool Adjacency::operator==(Adjacency const &other) const {
  return other.getVertex().getId() == this->getVertex().getId() &&
         other.getWeight() == this->getWeight();
}
