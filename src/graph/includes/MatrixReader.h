#pragma once

#ifndef MATRIX_READER_H
#define MATRIX_READER_H

#include <cstddef>
#include <fstream>
#include <algorithm>

#include "IMatrixReader.h"
#include "types.h"

class MatrixReader : public IMatrixReader {
 private:
  int readNextNumberOrThrow(std::string const &line, size_t *offset,
                            std::string const &notFoundErrorMessage) const;

 public:
  int readMatrixSize(std::ifstream &file) const;

  weight **readAdjacencyMatrix(std::ifstream &file, int const matrixSize) const;

  ~MatrixReader();
};

#endif
