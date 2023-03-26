#ifndef VERTEXMAPFORTESTS_H
#define VERTEXMAPFORTESTS_H

#include <map>

#include "Vertex.h"
#include "VertexMapBuilder.h"

class VertexMapForTests {
private:
  std::map<vertex_id, Vertex *> vertexMap;

public:
  VertexMapForTests(vertex_id matrixSize, weight **adjecencyMatrix);
  Vertex const &getVertexById(vertex_id vertexId);

  ~VertexMapForTests();
};

#endif
