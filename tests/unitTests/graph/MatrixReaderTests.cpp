#include "MatrixReader.h"
#include "gtest.h"
#include <filesystem>
#include <functional>

// TODO: решить, что мы делаем с отрицательными числами, и добавить тест на это.

TEST(MatrixReaderTests, ReadMatrixSize_WithExmapleMap) {
  // Arrange
  const std::string pathToFile = "./unitTests/graph/testData/ExampleMap.txt";
  std::ifstream file;
  file.open(pathToFile);
  ASSERT_TRUE(file);
  MatrixReader matrixReader;

  // Act
  auto actualMatrixSize = matrixReader.readMatrixSize(file);

  // Assert
  int expectedMatrixSize = 11;
  ASSERT_EQ(actualMatrixSize, expectedMatrixSize);
}

TEST(MatrixReaderTests, ReadMatrixSize_WithMultipleEmptyRowsBeforeMatrixSize) {
  // Arrange
  const std::string pathToFile =
      "./unitTests/graph/testData/MatrixWithMultipleEmptyLinesBeforeSize.txt";
  std::ifstream file;
  file.open(pathToFile);
  ASSERT_TRUE(file);
  MatrixReader matrixReader;

  // Act
  auto actualMatrixSize = matrixReader.readMatrixSize(file);

  // Assert
  int expectedMatrixSize = 11;
  ASSERT_EQ(actualMatrixSize, expectedMatrixSize);
}

TEST(MatrixReaderTests,
     ReadMatrixSize_WithMultipleEmptyRowsAfterMatrixSize_ReturnsValidValue) {
  // Arrange
  const std::string pathToFile =
      "./unitTests/graph/testData/MatrixWithMultipleEmptyLinesAfterSize.txt";
  std::ifstream file;
  file.open(pathToFile);
  ASSERT_TRUE(file);
  MatrixReader matrixReader;

  // Act
  auto actualMatrixSize = matrixReader.readMatrixSize(file);

  // Assert
  int expectedMatrixSize = 11;
  ASSERT_EQ(actualMatrixSize, expectedMatrixSize);
}

TEST(MatrixReaderTests,
     ReadMatrixSize_WithWhiteSpacesBeforeMatrixSize_ReturnsValidValue) {
  // Arrange
  const std::string pathToFile =
      "./unitTests/graph/testData/MatrixWithWhiteSpacesBeforeSize.txt";
  std::ifstream file;
  file.open(pathToFile);
  ASSERT_TRUE(file);
  MatrixReader matrixReader;

  // Act
  auto actualMatrixSize = matrixReader.readMatrixSize(file);

  // Assert
  int expectedMatrixSize = 11;
  ASSERT_EQ(actualMatrixSize, expectedMatrixSize);
}

TEST(MatrixReaderTests,
     ReadMatrixSize_InvalidMatrixWithSymbolsBeforeSize_ThrowsException) {
  // Arrange
  const std::string pathToFile =
      "./unitTests/graph/testData/InvalidMatrixWithSymbolsBeforeSize.txt";
  std::ifstream file;
  file.open(pathToFile);
  ASSERT_TRUE(file);
  MatrixReader matrixReader;

  // Act

  // Assert
  ASSERT_THROW(matrixReader.readMatrixSize(file), std::invalid_argument);
}

TEST(MatrixReaderTests,
     ReadMatrixSize_InvalidMatrixWithSymbolsAfterSize_ThrowsException) {
  // Arrange
  const std::string pathToFile =
      "./unitTests/graph/testData/InvalidMatrixWithSymbolsAfterSize.txt";
  std::ifstream file;
  file.open(pathToFile);
  ASSERT_TRUE(file);
  MatrixReader matrixReader;

  // Act

  // Assert
  ASSERT_THROW(matrixReader.readMatrixSize(file), std::invalid_argument);
}

TEST(MatrixReaderTests,
     ReadMatrixSize_WithSizeMoreThanMaxSize_ThrowsException) {
  // Arrange
  const std::string pathToFile =
      "./unitTests/graph/testData/InvalidMatrixWithSizeMoreThanMaxSize.txt";
  std::ifstream file;
  file.open(pathToFile);
  ASSERT_TRUE(file);
  MatrixReader matrixReader;

  // Act

  // Assert
  ASSERT_THROW(matrixReader.readMatrixSize(file), std::invalid_argument);
}

TEST(MatrixReaderTests,
     ReadMatrixSize_WithMultipleNumbersOnTheSizeRow_ThrowsException) {
  // Arrange
  const std::string pathToFile =
      "./unitTests/graph/testData/"
      "InvalidMatrixWithMultipleNumbersOnTheSizeRow.txt";
  std::ifstream file;
  file.open(pathToFile);
  ASSERT_TRUE(file);
  MatrixReader matrixReader;

  // Act

  // Assert
  ASSERT_THROW(matrixReader.readMatrixSize(file), std::invalid_argument);
}

TEST(MatrixReaderTests, ReadMatrixSize_WithEmptyMatrix_ThrowsException) {
  // Arrange
  const std::string pathToFile =
      "./unitTests/graph/testData/InvalidEmptyMatrix.txt";
  std::ifstream file;
  file.open(pathToFile);
  ASSERT_TRUE(file);
  MatrixReader matrixReader;

  // Act

  // Assert
  ASSERT_THROW(matrixReader.readMatrixSize(file), std::invalid_argument);
}

TEST(MatrixReaderTests, ReadMatrixSize_WithNegativeMatrixSize_ThrowsException) {
  // Arrange
  const std::string pathToFile =
      "./unitTests/graph/testData/InvalidMatrixWithNegativeMatrixSize.txt";
  std::ifstream file;
  file.open(pathToFile);
  ASSERT_TRUE(file);
  MatrixReader matrixReader;

  // Act

  // Assert
  ASSERT_THROW(matrixReader.readMatrixSize(file), std::invalid_argument);
}

TEST(MatrixReaderTests,
     ReadMatrixSize_WithSeparateMinusSignOnMatrixSizeLine_ThrowsException) {
  // Arrange
  const std::string pathToFile =
      "./unitTests/graph/testData/"
      "InvalidMatrixWithSeparateMinusSignOnMatrixSizeLine.txt";
  std::ifstream file;
  file.open(pathToFile);
  ASSERT_TRUE(file);
  MatrixReader matrixReader;

  // Act

  // Assert
  ASSERT_THROW(matrixReader.readMatrixSize(file), std::invalid_argument);
}

TEST(MatrixReaderTests,
     ReadMatrixSize_WithMinusSignAfterMatrixSize_ThrowsException) {
  // Arrange
  const std::string pathToFile =
      "./unitTests/graph/testData/"
      "InvalidMatrixWithMinusSignAfterMatrixSize.txt";
  std::ifstream file;
  file.open(pathToFile);
  ASSERT_TRUE(file);
  MatrixReader matrixReader;

  // Act

  // Assert
  ASSERT_THROW(matrixReader.readMatrixSize(file), std::invalid_argument);
}

TEST(MatrixReaderTests, ReadAdjacencyMatrix_WithExmapleMap) {
  // Arrange
  const std::string pathToFile = "./unitTests/graph/testData/ExampleMap.txt";
  std::ifstream file;
  file.open(pathToFile);
  ASSERT_TRUE(file);
  MatrixReader matrixReader;
  int matrixSize = 11;

  std::string line;
  // Пропускаем размер матрицы (нам он известен из файла)
  getline(file, line);

  // Act
  auto actualMatrix = matrixReader.readAdjacencyMatrix(file, matrixSize);

  // Assert
  weight expectedMatrix[11][11] = {
      {0, 29, 20, 21, 16, 31, 100, 12, 4, 31, 18},
      {29, 0, 15, 29, 28, 40, 72, 21, 29, 41, 12},
      {20, 15, 0, 15, 14, 25, 81, 9, 23, 27, 13},
      {21, 29, 15, 0, 4, 12, 92, 12, 25, 13, 25},
      {16, 28, 14, 4, 0, 16, 94, 9, 20, 16, 22},
      {31, 40, 25, 12, 16, 0, 95, 24, 36, 3, 37},
      {100, 72, 81, 92, 94, 95, 0, 90, 101, 99, 84},
      {12, 21, 9, 12, 9, 24, 90, 0, 15, 25, 13},
      {4, 29, 23, 25, 20, 36, 101, 15, 0, 35, 18},
      {31, 41, 27, 13, 16, 3, 99, 25, 35, 0, 38},
      {18, 12, 13, 25, 22, 37, 84, 13, 18, 38, 0}};

  for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < matrixSize; j++) {
      ASSERT_EQ(actualMatrix[i][j], expectedMatrix[i][j]);
    }
  }
}

TEST(MatrixReaderTests,
     ReadAdjacencyMatrix_WithNegativeNumbers_ReturnsValidMatrix) {
  // Arrange
  const std::string pathToFile =
      "./unitTests/graph/testData/MatrixWithNegativeNumbers.txt";
  std::ifstream file;
  file.open(pathToFile);
  ASSERT_TRUE(file);
  MatrixReader matrixReader;
  int matrixSize = 11;

  std::string line;
  // Пропускаем размер матрицы (нам он известен из файла)
  getline(file, line);

  // Act
  auto actualMatrix = matrixReader.readAdjacencyMatrix(file, matrixSize);

  // Assert
  weight expectedMatrix[11][11] = {
      {0, -29, 20, 21, 16, 31, -100, 12, 4, 31, 18},
      {29, 0, 15, 29, 28, 40, 72, 21, 29, 41, 12},
      {20, 15, 0, -15, 14, 25, 81, 9, -23, 27, 13},
      {21, 29, 15, 0, 4, 12, 92, 12, 25, 13, 25},
      {16, 28, 14, 4, 0, 16, 94, 9, 20, 16, 22},
      {31, 40, 25, 12, 16, 0, 95, 24, 36, 3, 37},
      {100, 72, 81, 92, 94, 95, 0, 90, 101, 99, 84},
      {12, 21, 9, 12, 9, 24, 90, 0, 15, 25, 13},
      {4, 29, 23, 25, 20, 36, 101, 15, 0, 35, 18},
      {31, 41, 27, -13, 16, 3, 99, 25, -35, 0, 38},
      {18, 12, 13, 25, 22, 37, 84, 13, 18, 38, 0}};

  for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < matrixSize; j++) {
      ASSERT_EQ(actualMatrix[i][j], expectedMatrix[i][j]);
    }
  }
}

TEST(MatrixReaderTests,
     ReadAdjacencyMatrix_WithUnalignedColumns_ReturnsValidMatrix) {
  // Arrange
  const std::string pathToFile =
      "./unitTests/graph/testData/MatrixWithUnalignedColumns.txt";
  std::ifstream file;
  file.open(pathToFile);
  ASSERT_TRUE(file);
  MatrixReader matrixReader;
  int matrixSize = 11;

  std::string line;
  // Пропускаем размер матрицы (нам он известен из файла)
  getline(file, line);

  // Act
  auto actualMatrix = matrixReader.readAdjacencyMatrix(file, matrixSize);

  // Assert
  weight expectedMatrix[11][11] = {
      {0, 29, 20, 21, 16, 31, 100, 12, 4, 31, 18},
      {29, 0, 15, 29, 28, 40, 72, 21, 29, 41, 12},
      {20, 15, 0, 15, 14, 25, 81, 9, 23, 27, 13},
      {21, 29, 15, 0, 4, 12, 92, 12, 25, 13, 25},
      {16, 28, 14, 4, 0, 16, 94, 9, 20, 16, 22},
      {31, 40, 25, 12, 16, 0, 95, 24, 36, 3, 37},
      {100, 72, 81, 92, 94, 95, 0, 90, 101, 99, 84},
      {12, 21, 9, 12, 9, 24, 90, 0, 15, 25, 13},
      {4, 29, 23, 25, 20, 36, 101, 15, 0, 35, 18},
      {31, 41, 27, 13, 16, 3, 99, 25, 35, 0, 38},
      {18, 12, 13, 25, 22, 37, 84, 13, 18, 38, 0}};

  for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < matrixSize; j++) {
      ASSERT_EQ(actualMatrix[i][j], expectedMatrix[i][j]);
    }
  }
}

TEST(MatrixReaderTests,
     ReadAdjacencyMatrix_WithSelfAdjacentVertexes_ReturnsValidMatrix) {
  // Arrange
  const std::string pathToFile =
      "./unitTests/graph/testData/MatrixWithSelfAdjacentVertexes.txt";
  std::ifstream file;
  file.open(pathToFile);
  ASSERT_TRUE(file);
  MatrixReader matrixReader;
  int matrixSize = 11;

  std::string line;
  // Пропускаем размер матрицы (нам он известен из файла)
  getline(file, line);

  // Act
  auto actualMatrix = matrixReader.readAdjacencyMatrix(file, matrixSize);

  // Assert
  weight expectedMatrix[11][11] = {
      {1, 29, 20, 21, 16, 31, 100, 12, 4, 31, 18},
      {29, 2, 15, 29, 28, 40, 72, 21, 29, 41, 12},
      {20, 15, 3, 15, 14, 25, 81, 9, 23, 27, 13},
      {21, 29, 15, 4, 4, 12, 92, 12, 25, 13, 25},
      {16, 28, 14, 4, 5, 16, 94, 9, 20, 16, 22},
      {31, 40, 25, 12, 16, 6, 95, 24, 36, 3, 37},
      {100, 72, 81, 92, 94, 95, 7, 90, 101, 99, 84},
      {12, 21, 9, 12, 9, 24, 90, 8, 15, 25, 13},
      {4, 29, 23, 25, 20, 36, 101, 15, 9, 35, 18},
      {31, 41, 27, 13, 16, 3, 99, 25, 35, 10, 38},
      {18, 12, 13, 25, 22, 37, 84, 13, 18, 38, 11}};

  for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < matrixSize; j++) {
      ASSERT_EQ(actualMatrix[i][j], expectedMatrix[i][j]);
    }
  }
}

TEST(MatrixReaderTests, ReadAdjacencyMatrix_WithOddColumns_ReturnsValidMatrix) {
  // Arrange
  const std::string pathToFile =
      "./unitTests/graph/testData/MatrixWithOddColumns.txt";
  std::ifstream file;
  file.open(pathToFile);
  ASSERT_TRUE(file);
  MatrixReader matrixReader;
  int matrixSize = 11;

  std::string line;
  // Пропускаем размер матрицы (нам он известен из файла)
  getline(file, line);

  // Act
  auto actualMatrix = matrixReader.readAdjacencyMatrix(file, matrixSize);

  // Assert
  weight expectedMatrix[11][11] = {
      {0, 29, 20, 21, 16, 31, 100, 12, 4, 31, 18},
      {29, 0, 15, 29, 28, 40, 72, 21, 29, 41, 12},
      {20, 15, 0, 15, 14, 25, 81, 9, 23, 27, 13},
      {21, 29, 15, 0, 4, 12, 92, 12, 25, 13, 25},
      {16, 28, 14, 4, 0, 16, 94, 9, 20, 16, 22},
      {31, 40, 25, 12, 16, 0, 95, 24, 36, 3, 37},
      {100, 72, 81, 92, 94, 95, 0, 90, 101, 99, 84},
      {12, 21, 9, 12, 9, 24, 90, 0, 15, 25, 13},
      {4, 29, 23, 25, 20, 36, 101, 15, 0, 35, 18},
      {31, 41, 27, 13, 16, 3, 99, 25, 35, 0, 38},
      {18, 12, 13, 25, 22, 37, 84, 13, 18, 38, 0}};

  for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < matrixSize; j++) {
      ASSERT_EQ(actualMatrix[i][j], expectedMatrix[i][j]);
    }
  }
}

TEST(MatrixReaderTests, ReadAdjacencyMatrix_WithOddRows_ReturnsValidMatrix) {
  // Arrange
  const std::string pathToFile =
      "./unitTests/graph/testData/MatrixWithOddRows.txt";
  std::ifstream file;
  file.open(pathToFile);
  ASSERT_TRUE(file);
  MatrixReader matrixReader;
  int matrixSize = 11;

  std::string line;
  // Пропускаем размер матрицы (нам он известен из файла)
  getline(file, line);

  // Act
  auto actualMatrix = matrixReader.readAdjacencyMatrix(file, matrixSize);

  // Assert
  weight expectedMatrix[11][11] = {
      {0, 29, 20, 21, 16, 31, 100, 12, 4, 31, 18},
      {29, 0, 15, 29, 28, 40, 72, 21, 29, 41, 12},
      {20, 15, 0, 15, 14, 25, 81, 9, 23, 27, 13},
      {21, 29, 15, 0, 4, 12, 92, 12, 25, 13, 25},
      {16, 28, 14, 4, 0, 16, 94, 9, 20, 16, 22},
      {31, 40, 25, 12, 16, 0, 95, 24, 36, 3, 37},
      {100, 72, 81, 92, 94, 95, 0, 90, 101, 99, 84},
      {12, 21, 9, 12, 9, 24, 90, 0, 15, 25, 13},
      {4, 29, 23, 25, 20, 36, 101, 15, 0, 35, 18},
      {31, 41, 27, 13, 16, 3, 99, 25, 35, 0, 38},
      {18, 12, 13, 25, 22, 37, 84, 13, 18, 38, 0}};

  for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < matrixSize; j++) {
      ASSERT_EQ(actualMatrix[i][j], expectedMatrix[i][j]);
    }
  }
}

TEST(MatrixReaderTests,
     ReadAdjacencyMatrix_WithSingleElement_ReturnsValidMatrix) {
  // Arrange
  const std::string pathToFile =
      "./unitTests/graph/testData/MatrixWithSingleElement.txt";
  std::ifstream file;
  file.open(pathToFile);
  ASSERT_TRUE(file);
  MatrixReader matrixReader;
  int matrixSize = 1;

  std::string line;
  // Пропускаем размер матрицы (нам он известен из файла)
  getline(file, line);

  // Act
  auto actualMatrix = matrixReader.readAdjacencyMatrix(file, matrixSize);

  // Assert
  weight expectedMatrix[1][1] = {{100}};

  for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < matrixSize; j++) {
      ASSERT_EQ(actualMatrix[i][j], expectedMatrix[i][j]);
    }
  }
}

TEST(MatrixReaderTests,
     ReadAdjacencyMatrix_MatrixWithFourElements_ReturnsValidMatrix) {
  // Arrange
  const std::string pathToFile =
      "./unitTests/graph/testData/MatrixWithFourElements.txt";
  std::ifstream file;
  file.open(pathToFile);
  ASSERT_TRUE(file);
  MatrixReader matrixReader;
  int matrixSize = 4;

  std::string line;
  // Пропускаем размер матрицы (нам он известен из файла)
  getline(file, line);

  // Act
  auto actualMatrix = matrixReader.readAdjacencyMatrix(file, matrixSize);

  // Assert
  weight expectedMatrix[4][4] = {
      {0, 29, 20, 21}, {29, 0, 15, 29}, {20, 15, 0, 15}, {21, 29, 15, 0}};

  for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < matrixSize; j++) {
      ASSERT_EQ(actualMatrix[i][j], expectedMatrix[i][j]);
    }
  }
}

TEST(MatrixReaderTests, ReadAdjacencyMatrix_WithEmtpyLines_ThrowsExceptio) {
  // Arrange
  const std::string pathToFile =
      "./unitTests/graph/testData/InvalidMatrixWithEmtpyLines.txt";
  std::ifstream file;
  file.open(pathToFile);
  ASSERT_TRUE(file);
  MatrixReader matrixReader;
  int matrixSize = 11;

  std::string line;
  // Пропускаем размер матрицы (нам он известен из файла)
  getline(file, line);

  // Act

  // Assert
  ASSERT_THROW(matrixReader.readAdjacencyMatrix(file, matrixSize),
               std::invalid_argument);
}

TEST(MatrixReaderTests,
     ReadAdjacencyMatrix_WithMultipleShorterRows_ThrowsExceptio) {
  // Arrange
  const std::string pathToFile =
      "./unitTests/graph/testData/InvalidMatrixWithMultipleShorterRows.txt";
  std::ifstream file;
  file.open(pathToFile);
  ASSERT_TRUE(file);
  MatrixReader matrixReader;
  int matrixSize = 11;

  std::string line;
  // Пропускаем размер матрицы (нам он известен из файла)
  getline(file, line);

  // Act

  // Assert
  ASSERT_THROW(matrixReader.readAdjacencyMatrix(file, matrixSize),
               std::invalid_argument);
}

TEST(MatrixReaderTests,
     ReadAdjacencyMatrix_WithSingleShorterRow_ThrowsExceptio) {
  // Arrange
  const std::string pathToFile =
      "./unitTests/graph/testData/InvalidMatrixWithSingleShorterRow.txt";
  std::ifstream file;
  file.open(pathToFile);
  ASSERT_TRUE(file);
  MatrixReader matrixReader;
  int matrixSize = 11;

  std::string line;
  // Пропускаем размер матрицы (нам он известен из файла)
  getline(file, line);

  // Act

  // Assert
  ASSERT_THROW(matrixReader.readAdjacencyMatrix(file, matrixSize),
               std::invalid_argument);
}

TEST(MatrixReaderTests,
     ReadAdjacencyMatrix_WithInsufficientColumnAmount_ThrowsException) {
  // Arrange
  const std::string pathToFile =
      "./unitTests/graph/testData/"
      "InvalidMatrixWithInsufficientColumnAmount.txt";
  std::ifstream file;
  file.open(pathToFile);
  ASSERT_TRUE(file);
  MatrixReader matrixReader;
  int matrixSize = 11;

  std::string line;
  // Пропускаем размер матрицы (нам он известен из файла)
  getline(file, line);

  // Act

  // Assert
  ASSERT_THROW(matrixReader.readAdjacencyMatrix(file, matrixSize),
               std::invalid_argument);
}

TEST(MatrixReaderTests,
     ReadAdjacencyMatrix_WithSeparateMinusSignOnMatrixRow_ThrowsException) {
  // Arrange
  const std::string pathToFile =
      "./unitTests/graph/testData/"
      "InvalidMatrixWithSeparateMinusSignOnMatrixRow.txt";
  std::ifstream file;
  file.open(pathToFile);
  ASSERT_TRUE(file);
  MatrixReader matrixReader;
  int matrixSize = 11;

  std::string line;
  // Пропускаем размер матрицы (нам он известен из файла)
  getline(file, line);

  // Act

  // Assert
  ASSERT_THROW(matrixReader.readAdjacencyMatrix(file, matrixSize),
               std::invalid_argument);
}

TEST(MatrixReaderTests,
     ReadAdjacencyMatrix_WithSingleMinusSignOnRow_ThrowsException) {
  // Arrange
  const std::string pathToFile =
      "./unitTests/graph/testData/InvalidMatrixWithSingleMinusSignOnRow.txt";
  std::ifstream file;
  file.open(pathToFile);
  ASSERT_TRUE(file);
  MatrixReader matrixReader;
  int matrixSize = 11;

  std::string line;
  // Пропускаем размер матрицы (нам он известен из файла)
  getline(file, line);

  // Act

  // Assert
  ASSERT_THROW(matrixReader.readAdjacencyMatrix(file, matrixSize),
               std::invalid_argument);
}
