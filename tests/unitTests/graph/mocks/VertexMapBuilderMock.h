#ifndef VERTEX_MAP_BUILDER_MOCK_H
#define VERTEX_MAP_BUILDER_MOCK_H

#include "IVertexMapBuilder.h"
#include "gmock.h"

class VertexMapBuilderMock : public IVertexMapBuilder {
public:
  ~VertexMapBuilderMock() override = default;

  MOCK_METHOD((std::map<vertex_id, Vertex *>), buildVerticesMap,
              (weight **adjacencyMatrix, int matrixSize),
              (const, noexcept, override));
};

#endif
