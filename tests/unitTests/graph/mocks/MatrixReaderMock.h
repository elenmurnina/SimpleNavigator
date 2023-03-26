#ifndef MATRIX_READER_MOCK_H
#define MATRIX_READER_MOCK_H

#include "IMatrixReader.h"
#include "gmock.h"

class MatrixReaderMock : public IMatrixReader {
public:
  ~MatrixReaderMock() override = default;

  MOCK_METHOD(int, readMatrixSize, (std::ifstream & file), (const, override));
  MOCK_METHOD(weight **, readAdjacencyMatrix,
              (std::ifstream & file, int const matrixSize), (const, override));
};

#endif
