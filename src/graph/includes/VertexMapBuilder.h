#pragma once

#ifndef VERTEX_MAP_BUILDER_H
#define VERTEX_MAP_BUILDER_H

#include "IVertexMapBuilder.h"

class VertexMapBuilder : public IVertexMapBuilder {
 public:
  std::map<vertex_id, Vertex *> buildVerticesMap(weight **adjacencyMatrix,
                                                 int matrixSize) const noexcept;
  ~VertexMapBuilder();
};

#endif
