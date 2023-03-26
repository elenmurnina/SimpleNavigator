#ifndef GRAPHINTERFACE_H
#define GRAPHINTERFACE_H

#include "Vertex.h"

class IGraph {
 public:
  virtual ~IGraph() = default;
  virtual void loadGraphFromFile(std::string const &filename) = 0;
  virtual void exportGraphToDot(std::string const &filename) = 0;
  virtual Vertex const &getVertexById(vertex_id vertexId) const = 0;
  virtual int getMatrixSize() const = 0;
  virtual weight **getAdjacencyMatrix() const = 0;
  virtual bool isDirected() const = 0;
  virtual bool isWeighted() const = 0;
};

#endif
