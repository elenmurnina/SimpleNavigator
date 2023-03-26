#include "Vertex.h"

#include <iostream>

Vertex::Vertex(Vertex const &other)
    : _id(other._id), _adjacentVertices(other._adjacentVertices) {}

Vertex::Vertex(vertex_id vertexId) : _id(vertexId) {}

vertex_id Vertex::getId() const { return _id; }

std::vector<Adjacency> const Vertex::getAdjacencies() const {
  return _adjacentVertices;
}

void Vertex::addAdjacency(Adjacency const &adjacency) {
  _adjacentVertices.push_back(adjacency);
}

bool Vertex::operator==(Vertex const &other) const {
  if (other.getId() != this->getId()) {
    return false;
  }

  std::vector<Adjacency> otherAdjacencies = other.getAdjacencies();
  std::vector<Adjacency> thisAdjacencies = this->getAdjacencies();
  if (otherAdjacencies.size() != thisAdjacencies.size()) {
    return false;
  }

  for (size_t i = 0; i < otherAdjacencies.size(); i++) {
    if (otherAdjacencies[i] == thisAdjacencies[i]) continue;

    return false;
  }

  return true;
}

Vertex::~Vertex() {}
