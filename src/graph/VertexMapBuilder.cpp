#include "VertexMapBuilder.h"

std::map<vertex_id, Vertex *> VertexMapBuilder::buildVerticesMap(
    weight **adjacencyMatrix, int matrixSize) const noexcept {
  std::vector<Vertex *> vertices;

  for (vertex_id vertexId = 1; vertexId <= matrixSize + 1; vertexId++) {
    vertices.push_back(new Vertex(vertexId));
  }

  for (int i = 0; i < matrixSize; i++) {
    Vertex *currentVertex = vertices[i];

    for (int j = 0; j < matrixSize; j++) {
      if (adjacencyMatrix[i][j] == 0) continue;

      currentVertex->addAdjacency(
          Adjacency(*(vertices[j]), adjacencyMatrix[i][j]));
    }
  }

  std::map<vertex_id, Vertex *> vertexMap;

  for (Vertex *vertex : vertices) {
    vertexMap.insert({vertex->getId(), vertex});
  }

  return vertexMap;
}

VertexMapBuilder::~VertexMapBuilder() {}
