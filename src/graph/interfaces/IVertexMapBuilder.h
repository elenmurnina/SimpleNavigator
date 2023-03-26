#ifndef VERTEX_MAP_BUILDER_INTERFACE_H
#define VERTEX_MAP_BUILDER_INTERFACE_H

#include <map>

#include "Vertex.h"

class IVertexMapBuilder {
 public:
  virtual std::map<vertex_id, Vertex *> buildVerticesMap(
      weight **adjacencyMatrix, int matrixSize) const noexcept = 0;

  virtual ~IVertexMapBuilder() = default;
};

#endif
