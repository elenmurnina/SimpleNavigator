#pragma once

#ifndef DOTBUILDER_H
#define DOTBUILDER_H

#include "IDotBuilder.h"

class DotBuilder : public IDotBuilder {
 private:
  bool isGraphDirected(weight **adjacencyMatrix, int matrixSize) const noexcept;
  std::string buildWeightLabel(weight weight) const noexcept;

 public:
  std::string buildDotFromGraph(IGraph const &graph) const noexcept;
};

#endif
