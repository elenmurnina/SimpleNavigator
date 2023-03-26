#ifndef DOT_BUILDER_INTERFACE_H
#define DOT_BUILDER_INTERFACE_H

#include <string>

#include "IGraph.h"

class IDotBuilder {
 public:
  virtual ~IDotBuilder() = default;
  virtual std::string buildDotFromGraph(IGraph const &graph) const noexcept = 0;
};

#endif
