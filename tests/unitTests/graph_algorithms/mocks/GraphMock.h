#ifndef GRAPHMOCK_H
#define GRAPHMOCK_H

#include "IGraph.h"
#include "gmock.h"

class GraphMock : public IGraph {
public:
  ~GraphMock() override = default;

  MOCK_METHOD(void, loadGraphFromFile, (std::string const &filename),
              (override));
  MOCK_METHOD(void, exportGraphToDot, (std::string const &filename),
              (override));
  MOCK_METHOD(Vertex const &, getVertexById, (vertex_id vertexId),
              (const, override));
  MOCK_METHOD(int, getMatrixSize, (), (const, override));
  MOCK_METHOD(weight **, getAdjacencyMatrix, (), (const, override));
  MOCK_METHOD(bool, isDirected, (), (const, override));
  MOCK_METHOD(bool, isWeighted, (), (const, override));
};

#endif
