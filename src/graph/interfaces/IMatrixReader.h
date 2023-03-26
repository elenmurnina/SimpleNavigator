#ifndef MATRIX_READER_INTERFACE_H
#define MATRIX_READER_INTERFACE_H

#include <cstddef>
#include <fstream>

#include "types.h"

class IMatrixReader {
 public:
  virtual int readMatrixSize(std::ifstream &file) const = 0;

  virtual weight **readAdjacencyMatrix(std::ifstream &file,
                                       int const matrixSize) const = 0;

  virtual ~IMatrixReader() = default;
};

#endif
