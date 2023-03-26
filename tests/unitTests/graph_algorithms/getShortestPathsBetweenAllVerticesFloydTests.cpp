#include "GraphMock.h"
#include "VertexMapForTests.h"
#include "gmock.h"
#include "gtest.h"
#include "s21_graph_algorithms.h"

using ::testing::NiceMock;
using ::testing::Return;

static bool matrixComparer(int size, distance **matrix1, distance **matrix2) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (matrix1[i][j] != matrix2[i][j]) {
        return false;
      }
    }
  }
  return true;
}

static void deleteMatrix(int size, distance **&matrix) {
  for (int i = 0; i < size; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;
}

TEST(getShortestPathsBetweenAllVerticesFloydTests, Graph4) {
  // Arrange
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 4;
  weight matrix[size][size] = {
      {0, 0, -2, 0}, {4, 0, 3, 0}, {0, 0, 0, 2}, {0, -1, 0, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2], matrix[3]};

  distance matrix2[size][size] = {
      {0, -1, -2, 0}, {4, 0, 2, 4}, {5, 1, 0, 2}, {3, -1, 1, 0}};
  distance *ansMatrix[size] = {matrix2[0], matrix2[1], matrix2[2], matrix2[3]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(size));
  EXPECT_CALL(graphMock, getAdjacencyMatrix()).WillOnce(Return(weightMatrix));

  // Act
  distance **shortestPathBetweenAllVertices =
      graphAlgorithms.getShortestPathsBetweenAllVertices(graphMock);

  // Assert
  ASSERT_TRUE(matrixComparer(size, shortestPathBetweenAllVertices, ansMatrix));
  deleteMatrix(size, shortestPathBetweenAllVertices);
}

TEST(getShortestPathsBetweenAllVerticesFloydTests, Graph4_1) {
  // Arrange
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 4;
  weight matrix[size][size] = {
      {0, -2, 7, 5}, {0, 0, 8, 6}, {0, 3, 0, -4}, {-1, 0, 0, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2], matrix[3]};
  distance matrix2[size][size] = {
      {0, -2, 6, 2}, {3, 0, 8, 4}, {-5, -7, 0, -4}, {-1, -3, 5, 0}};
  distance *ansMatrix[size] = {matrix2[0], matrix2[1], matrix2[2], matrix2[3]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(size));
  EXPECT_CALL(graphMock, getAdjacencyMatrix()).WillOnce(Return(weightMatrix));

  // Act
  distance **shortestPathBetweenAllVertices =
      graphAlgorithms.getShortestPathsBetweenAllVertices(graphMock);

  // Assert
  ASSERT_TRUE(matrixComparer(size, shortestPathBetweenAllVertices, ansMatrix));
  deleteMatrix(size, shortestPathBetweenAllVertices);
}

TEST(getShortestPathsBetweenAllVerticesFloydTests, Graph5) {
  // Arrange
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 5;
  weight matrix[size][size] = {{0, 10, 0, 5, 0},
                               {10, 0, 1, 2, 0},
                               {0, 1, 0, 0, 0},
                               {5, 2, 0, 0, 2},
                               {0, 0, 0, 2, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2], matrix[3],
                                matrix[4]};
  distance matrix2[size][size] = {{0, 7, 8, 5, 7},
                                  {7, 0, 1, 2, 4},
                                  {8, 1, 0, 3, 5},
                                  {5, 2, 3, 0, 2},
                                  {7, 4, 5, 2, 0}};
  distance *ansMatrix[size] = {matrix2[0], matrix2[1], matrix2[2], matrix2[3],
                               matrix2[4]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(size));
  EXPECT_CALL(graphMock, getAdjacencyMatrix()).WillOnce(Return(weightMatrix));

  // Act
  distance **shortestPathBetweenAllVertices =
      graphAlgorithms.getShortestPathsBetweenAllVertices(graphMock);

  // Assert
  ASSERT_TRUE(matrixComparer(size, shortestPathBetweenAllVertices, ansMatrix));
  deleteMatrix(size, shortestPathBetweenAllVertices);
}

TEST(getShortestPathsBetweenAllVerticesFloydTests, Graph6) {
  // Arrange
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 6;
  weight matrix[size][size] = {{0, 1, 0, 2, 0, 8}, {1, 0, 3, 10, 0, 0},
                               {0, 3, 0, 0, 2, 0}, {2, 10, 0, 0, 4, 1},
                               {0, 0, 2, 4, 0, 0}, {8, 0, 0, 1, 0, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2],
                                matrix[3], matrix[4], matrix[5]};
  distance matrix2[size][size] = {{0, 1, 4, 2, 6, 3}, {1, 0, 3, 3, 5, 4},
                                  {4, 3, 0, 6, 2, 7}, {2, 3, 6, 0, 4, 1},
                                  {6, 5, 2, 4, 0, 5}, {3, 4, 7, 1, 5, 0}};
  distance *ansMatrix[size] = {matrix2[0], matrix2[1], matrix2[2],
                               matrix2[3], matrix2[4], matrix2[5]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(size));
  EXPECT_CALL(graphMock, getAdjacencyMatrix()).WillOnce(Return(weightMatrix));

  // Act
  distance **shortestPathBetweenAllVertices =
      graphAlgorithms.getShortestPathsBetweenAllVertices(graphMock);

  // Assert
  ASSERT_TRUE(matrixComparer(size, shortestPathBetweenAllVertices, ansMatrix));
  deleteMatrix(size, shortestPathBetweenAllVertices);
}

TEST(getShortestPathsBetweenAllVerticesFloydTests, Graph7) {
  // Arrange
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 7;
  weight matrix[size][size] = {{0, 3, 10, 0, 0, 0, 6}, {3, 0, 5, 8, 0, 0, 0},
                               {10, 5, 0, 2, 6, 8, 5}, {0, 8, 2, 0, 3, 0, 0},
                               {0, 0, 6, 3, 0, 7, 0},  {0, 0, 8, 0, 7, 0, 4},
                               {6, 0, 5, 0, 0, 4, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2], matrix[3],
                                matrix[4], matrix[5], matrix[6]};
  distance matrix2[size][size] = {
      {0, 3, 8, 10, 13, 10, 6}, {3, 0, 5, 7, 10, 13, 9},
      {8, 5, 0, 2, 5, 8, 5},    {10, 7, 2, 0, 3, 10, 7},
      {13, 10, 5, 3, 0, 7, 10}, {10, 13, 8, 10, 7, 0, 4},
      {6, 9, 5, 7, 10, 4, 0}};
  distance *ansMatrix[size] = {matrix2[0], matrix2[1], matrix2[2], matrix2[3],
                               matrix2[4], matrix2[5], matrix2[6]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(size));
  EXPECT_CALL(graphMock, getAdjacencyMatrix()).WillOnce(Return(weightMatrix));

  // Act
  distance **shortestPathBetweenAllVertices =
      graphAlgorithms.getShortestPathsBetweenAllVertices(graphMock);

  // Assert
  ASSERT_TRUE(matrixComparer(size, shortestPathBetweenAllVertices, ansMatrix));
  deleteMatrix(size, shortestPathBetweenAllVertices);
}

TEST(getShortestPathsBetweenAllVerticesFloydTests, Graph10) {
  // Arrange
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 10;
  weight matrix[size][size] = {
      {0, 10, 1, 5, 0, 0, 0, 0, 0, 3}, {10, 0, 0, 0, 2, 0, 0, 0, 15, 0},
      {1, 0, 0, 0, 8, 3, 0, 0, 0, 0},  {5, 0, 0, 0, 0, 0, 11, 4, 0, 0},
      {0, 2, 8, 0, 0, 0, 0, 0, 0, 0},  {0, 0, 3, 0, 0, 0, 7, 3, 0, 0},
      {0, 0, 0, 11, 0, 7, 0, 0, 0, 0}, {0, 0, 0, 4, 0, 3, 0, 0, 0, 8},
      {0, 15, 0, 0, 0, 0, 0, 0, 0, 0}, {3, 0, 0, 0, 0, 0, 0, 8, 0, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2], matrix[3],
                                matrix[4], matrix[5], matrix[6], matrix[7],
                                matrix[8], matrix[9]};
  distance matrix2[size][size] = {{0, 10, 1, 5, 9, 4, 11, 7, 25, 3},
                                  {10, 0, 10, 15, 2, 13, 20, 16, 15, 13},
                                  {1, 10, 0, 6, 8, 3, 10, 6, 25, 4},
                                  {5, 15, 6, 0, 14, 7, 11, 4, 30, 8},
                                  {9, 2, 8, 14, 0, 11, 18, 14, 17, 12},
                                  {4, 13, 3, 7, 11, 0, 7, 3, 28, 7},
                                  {11, 20, 10, 11, 18, 7, 0, 10, 35, 14},
                                  {7, 16, 6, 4, 14, 3, 10, 0, 31, 8},
                                  {25, 15, 25, 30, 17, 28, 35, 31, 0, 28},
                                  {3, 13, 4, 8, 12, 7, 14, 8, 28, 0}};
  distance *ansMatrix[size] = {matrix2[0], matrix2[1], matrix2[2], matrix2[3],
                               matrix2[4], matrix2[5], matrix2[6], matrix2[7],
                               matrix2[8], matrix2[9]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(size));
  EXPECT_CALL(graphMock, getAdjacencyMatrix()).WillOnce(Return(weightMatrix));

  // Act
  distance **shortestPathBetweenAllVertices =
      graphAlgorithms.getShortestPathsBetweenAllVertices(graphMock);

  // Assert
  ASSERT_TRUE(matrixComparer(size, shortestPathBetweenAllVertices, ansMatrix));
  deleteMatrix(size, shortestPathBetweenAllVertices);
}

TEST(getShortestPathsBetweenAllVerticesFloydTests, Graph4WithNegativeCycle) {
  // Arrange
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 4;
  weight matrix[size][size] = {
      {0, 0, -2, 0}, {4, 0, 3, 0}, {-2, 0, 0, 2}, {0, -1, 0, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2], matrix[3]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(size));
  EXPECT_CALL(graphMock, getAdjacencyMatrix()).WillOnce(Return(weightMatrix));

  // Act

  // Assert
  ASSERT_THROW(graphAlgorithms.getShortestPathsBetweenAllVertices(graphMock),
               std::invalid_argument);
}

TEST(getShortestPathsBetweenAllVerticesFloydTests, Graph5WithNegativeCycle) {
  // Arrange
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 5;
  weight matrix[size][size] = {{0, -3, -2, 0, 0},
                               {-3, 0, 1, 7, 0},
                               {-2, 1, 0, 0, 0},
                               {0, 0, 7, 0, 2},
                               {0, 0, 0, 2, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2], matrix[3],
                                matrix[4]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(size));
  EXPECT_CALL(graphMock, getAdjacencyMatrix()).WillOnce(Return(weightMatrix));

  // Act

  // Assert
  ASSERT_THROW(graphAlgorithms.getShortestPathsBetweenAllVertices(graphMock),
               std::invalid_argument);
}
