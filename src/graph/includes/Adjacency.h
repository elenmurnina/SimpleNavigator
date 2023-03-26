#pragma once

#ifndef ADJACENCY_H
#define ADJACENCY_H

#include <Vertex.h>

#include <iostream>

#include "types.h"

class Vertex;

class Adjacency {
 private:
  Vertex const &_vertex;
  weight const _weight;

 public:
  Adjacency(Vertex const &vertex, weight weight);
  Adjacency(Adjacency const &other);

  Vertex const &getVertex() const;
  weight getWeight() const;

  bool operator==(Adjacency const &other) const;
};

#endif
