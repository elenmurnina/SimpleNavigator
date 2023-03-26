#include "GraphMock.h"
#include "VertexMapForTests.h"
#include "gmock.h"
#include "gtest.h"
#include "s21_graph_algorithms.h"

using ::testing::NiceMock;
using ::testing::Return;
using ::testing::ReturnRef;

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

TEST(getLeastSpanningTreePrimTests, Graph2) {
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 2;
  weight matrix[size][size] = {{0, 10}, {10, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1]};
  distance matrix2[size][size] = {{0, 10}, {10, 0}};
  distance *ansMatrix[size] = {matrix2[0], matrix2[1]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(size));
  for (vertex_id i = 1; i <= size; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  weight **adjacencyMatrixLeastSpanningTree =
      graphAlgorithms.getLeastSpanningTree(graphMock);

  // Assert
  ASSERT_TRUE(
      matrixComparer(size, adjacencyMatrixLeastSpanningTree, ansMatrix));
  deleteMatrix(size, adjacencyMatrixLeastSpanningTree);
}

TEST(getLeastSpanningTreePrimTests, Graph3) {
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 3;
  weight matrix[size][size] = {{0, 15, 7}, {15, 0, 8}, {7, 8, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2]};
  distance matrix2[size][size] = {{0, 0, 7}, {0, 0, 8}, {7, 8, 0}};
  distance *ansMatrix[size] = {matrix2[0], matrix2[1], matrix2[2]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(size));
  for (vertex_id i = 1; i <= size; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  weight **adjacencyMatrixLeastSpanningTree =
      graphAlgorithms.getLeastSpanningTree(graphMock);

  // Assert
  ASSERT_TRUE(
      matrixComparer(size, adjacencyMatrixLeastSpanningTree, ansMatrix));
  deleteMatrix(size, adjacencyMatrixLeastSpanningTree);
}

TEST(getLeastSpanningTreePrimTests, Graph4) {
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 4;
  weight matrix[size][size] = {
      {0, 10, 0, 11}, {10, 0, 9, 5}, {0, 9, 0, 8}, {11, 5, 8, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2], matrix[3]};
  distance matrix2[size][size] = {
      {0, 10, 0, 0}, {10, 0, 0, 5}, {0, 0, 0, 8}, {0, 5, 8, 0}};
  distance *ansMatrix[size] = {matrix2[0], matrix2[1], matrix2[2], matrix2[3]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(size));
  for (vertex_id i = 1; i <= size; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  weight **adjacencyMatrixLeastSpanningTree =
      graphAlgorithms.getLeastSpanningTree(graphMock);

  // Assert
  ASSERT_TRUE(
      matrixComparer(size, adjacencyMatrixLeastSpanningTree, ansMatrix));
  deleteMatrix(size, adjacencyMatrixLeastSpanningTree);
}

TEST(getLeastSpanningTreePrimTests, Graph4_1) {
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 4;
  weight matrix[size][size] = {
      {0, 15, 7, 9}, {15, 0, 8, 3}, {7, 8, 0, 1}, {9, 3, 1, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2], matrix[3]};
  distance matrix2[size][size] = {
      {0, 0, 7, 0}, {0, 0, 0, 3}, {7, 0, 0, 1}, {0, 3, 1, 0}};
  distance *ansMatrix[size] = {matrix2[0], matrix2[1], matrix2[2], matrix2[3]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(size));
  for (vertex_id i = 1; i <= size; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  weight **adjacencyMatrixLeastSpanningTree =
      graphAlgorithms.getLeastSpanningTree(graphMock);

  // Assert
  ASSERT_TRUE(
      matrixComparer(size, adjacencyMatrixLeastSpanningTree, ansMatrix));
  deleteMatrix(size, adjacencyMatrixLeastSpanningTree);
}

TEST(getLeastSpanningTreePrimTests, Graph5) {
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 5;
  weight matrix[size][size] = {{0, 3, 4, 0, 1},
                               {3, 0, 5, 0, 0},
                               {4, 5, 0, 2, 6},
                               {0, 0, 2, 0, 7},
                               {1, 0, 6, 7, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2], matrix[3],
                                matrix[4]};
  distance matrix2[size][size] = {{0, 3, 4, 0, 1},
                                  {3, 0, 0, 0, 0},
                                  {4, 0, 0, 2, 0},
                                  {0, 0, 2, 0, 0},
                                  {1, 0, 0, 0, 0}};
  distance *ansMatrix[size] = {matrix2[0], matrix2[1], matrix2[2], matrix2[3],
                               matrix2[4]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(size));
  for (vertex_id i = 1; i <= size; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  weight **adjacencyMatrixLeastSpanningTree =
      graphAlgorithms.getLeastSpanningTree(graphMock);

  // Assert
  ASSERT_TRUE(
      matrixComparer(size, adjacencyMatrixLeastSpanningTree, ansMatrix));
  deleteMatrix(size, adjacencyMatrixLeastSpanningTree);
}

TEST(getLeastSpanningTreePrimTests, Graph6) {
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 6;
  weight matrix[size][size] = {{0, 6, 8, 5, 5, 4},  {6, 0, 7, 7, 6, 2},
                               {8, 7, 0, 5, 10, 9}, {5, 7, 5, 0, 7, 10},
                               {5, 6, 10, 7, 0, 3}, {4, 2, 9, 10, 3, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2],
                                matrix[3], matrix[4], matrix[5]};
  distance matrix2[size][size] = {{0, 0, 0, 5, 0, 4}, {0, 0, 0, 0, 0, 2},
                                  {0, 0, 0, 5, 0, 0}, {5, 0, 5, 0, 0, 0},
                                  {0, 0, 0, 0, 0, 3}, {4, 2, 0, 0, 3, 0}};
  distance *ansMatrix[size] = {matrix2[0], matrix2[1], matrix2[2],
                               matrix2[3], matrix2[4], matrix2[5]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(size));
  for (vertex_id i = 1; i <= size; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  weight **adjacencyMatrixLeastSpanningTree =
      graphAlgorithms.getLeastSpanningTree(graphMock);

  // Assert
  ASSERT_TRUE(
      matrixComparer(size, adjacencyMatrixLeastSpanningTree, ansMatrix));
  deleteMatrix(size, adjacencyMatrixLeastSpanningTree);
}

TEST(getLeastSpanningTreePrimTests, Graph7) {
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 7;
  weight matrix[size][size] = {{0, 7, 0, 5, 0, 0, 0},  {7, 0, 8, 9, 7, 0, 0},
                               {0, 8, 0, 0, 5, 0, 0},  {5, 9, 0, 0, 15, 6, 0},
                               {0, 7, 5, 15, 0, 8, 9}, {0, 0, 0, 6, 8, 0, 11},
                               {0, 0, 0, 0, 9, 11, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2], matrix[3],
                                matrix[4], matrix[5], matrix[6]};
  distance matrix2[size][size] = {{0, 7, 0, 5, 0, 0, 0}, {7, 0, 0, 0, 7, 0, 0},
                                  {0, 0, 0, 0, 5, 0, 0}, {5, 0, 0, 0, 0, 6, 0},
                                  {0, 7, 5, 0, 0, 0, 9}, {0, 0, 0, 6, 0, 0, 0},
                                  {0, 0, 0, 0, 9, 0, 0}};
  distance *ansMatrix[size] = {matrix2[0], matrix2[1], matrix2[2], matrix2[3],
                               matrix2[4], matrix2[5], matrix2[6]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(size));
  for (vertex_id i = 1; i <= size; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  weight **adjacencyMatrixLeastSpanningTree =
      graphAlgorithms.getLeastSpanningTree(graphMock);

  // Assert
  ASSERT_TRUE(
      matrixComparer(size, adjacencyMatrixLeastSpanningTree, ansMatrix));
  deleteMatrix(size, adjacencyMatrixLeastSpanningTree);
}

TEST(getLeastSpanningTreePrimTests, Graph8) {
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 8;
  weight matrix[size][size] = {
      {0, 6, 2, 4, 0, 0, 0, 0}, {6, 0, 0, 6, 0, 6, 0, 0},
      {2, 0, 0, 0, 0, 0, 0, 4}, {4, 6, 0, 0, 1, 0, 0, 0},
      {0, 0, 0, 1, 0, 4, 7, 0}, {0, 6, 0, 0, 4, 0, 5, 3},
      {0, 0, 0, 0, 7, 5, 0, 5}, {0, 0, 4, 0, 0, 3, 5, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2], matrix[3],
                                matrix[4], matrix[5], matrix[6], matrix[7]};
  distance matrix2[size][size] = {
      {0, 6, 2, 4, 0, 0, 0, 0}, {6, 0, 0, 0, 0, 0, 0, 0},
      {2, 0, 0, 0, 0, 0, 0, 0}, {4, 0, 0, 0, 1, 0, 0, 0},
      {0, 0, 0, 1, 0, 4, 0, 0}, {0, 0, 0, 0, 4, 0, 5, 3},
      {0, 0, 0, 0, 0, 5, 0, 0}, {0, 0, 0, 0, 0, 3, 0, 0}};
  distance *ansMatrix[size] = {matrix2[0], matrix2[1], matrix2[2], matrix2[3],
                               matrix2[4], matrix2[5], matrix2[6], matrix2[7]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(size));
  for (vertex_id i = 1; i <= size; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  weight **adjacencyMatrixLeastSpanningTree =
      graphAlgorithms.getLeastSpanningTree(graphMock);

  // Assert
  ASSERT_TRUE(
      matrixComparer(size, adjacencyMatrixLeastSpanningTree, ansMatrix));
  deleteMatrix(size, adjacencyMatrixLeastSpanningTree);
}

TEST(getLeastSpanningTreePrimTests, Graph8_1) {
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 8;
  weight matrix[size][size] = {
      {0, 6, 8, 4, 0, 0, 0, 0}, {6, 0, 0, 6, 0, 6, 0, 0},
      {8, 0, 0, 0, 0, 0, 0, 4}, {4, 6, 0, 0, 1, 0, 0, 0},
      {0, 0, 0, 1, 0, 4, 7, 0}, {0, 6, 0, 0, 4, 0, 5, 3},
      {0, 0, 0, 0, 7, 5, 0, 5}, {0, 0, 4, 0, 0, 3, 5, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2], matrix[3],
                                matrix[4], matrix[5], matrix[6], matrix[7]};
  distance matrix2[size][size] = {
      {0, 6, 0, 4, 0, 0, 0, 0}, {6, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 4}, {4, 0, 0, 0, 1, 0, 0, 0},
      {0, 0, 0, 1, 0, 4, 0, 0}, {0, 0, 0, 0, 4, 0, 5, 3},
      {0, 0, 0, 0, 0, 5, 0, 0}, {0, 0, 4, 0, 0, 3, 0, 0}};
  distance *ansMatrix[size] = {matrix2[0], matrix2[1], matrix2[2], matrix2[3],
                               matrix2[4], matrix2[5], matrix2[6], matrix2[7]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(size));
  for (vertex_id i = 1; i <= size; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  weight **adjacencyMatrixLeastSpanningTree =
      graphAlgorithms.getLeastSpanningTree(graphMock);

  // Assert
  ASSERT_TRUE(
      matrixComparer(size, adjacencyMatrixLeastSpanningTree, ansMatrix));
  deleteMatrix(size, adjacencyMatrixLeastSpanningTree);
}

TEST(getLeastSpanningTreePrimTests, Graph9) {
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 9;
  weight matrix[size][size] = {
      {0, 4, 0, 0, 0, 0, 0, 8, 0},  {4, 0, 8, 0, 0, 0, 0, 11, 0},
      {0, 8, 0, 7, 0, 4, 0, 0, 2},  {0, 0, 7, 0, 9, 14, 0, 0, 0},
      {0, 0, 0, 9, 0, 10, 0, 0, 0}, {0, 0, 4, 14, 10, 0, 2, 0, 0},
      {0, 0, 0, 0, 0, 2, 0, 1, 6},  {8, 11, 0, 0, 0, 0, 1, 0, 7},
      {0, 0, 2, 0, 0, 0, 6, 7, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2],
                                matrix[3], matrix[4], matrix[5],
                                matrix[6], matrix[7], matrix[8]};
  distance matrix2[size][size] = {
      {0, 4, 0, 0, 0, 0, 0, 0, 0}, {4, 0, 8, 0, 0, 0, 0, 0, 0},
      {0, 8, 0, 7, 0, 4, 0, 0, 2}, {0, 0, 7, 0, 9, 0, 0, 0, 0},
      {0, 0, 0, 9, 0, 0, 0, 0, 0}, {0, 0, 4, 0, 0, 0, 2, 0, 0},
      {0, 0, 0, 0, 0, 2, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0},
      {0, 0, 2, 0, 0, 0, 0, 0, 0}};
  distance *ansMatrix[size] = {matrix2[0], matrix2[1], matrix2[2],
                               matrix2[3], matrix2[4], matrix2[5],
                               matrix2[6], matrix2[7], matrix2[8]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(size));
  for (vertex_id i = 1; i <= size; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  weight **adjacencyMatrixLeastSpanningTree =
      graphAlgorithms.getLeastSpanningTree(graphMock);

  // Assert
  ASSERT_TRUE(
      matrixComparer(size, adjacencyMatrixLeastSpanningTree, ansMatrix));
  deleteMatrix(size, adjacencyMatrixLeastSpanningTree);
}

TEST(getLeastSpanningTreePrimTests, Graph10) {
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 10;
  weight matrix[size][size] = {
      {0, 6, 0, 0, 0, 0, 0, 9, 0, 3},  {6, 0, 9, 0, 0, 0, 0, 0, 2, 4},
      {0, 9, 0, 4, 5, 0, 7, 0, 9, 0},  {0, 0, 4, 0, 1, 4, 0, 0, 0, 0},
      {0, 0, 5, 1, 0, 3, 9, 0, 0, 0},  {0, 0, 0, 4, 3, 0, 10, 18, 0, 0},
      {0, 0, 7, 0, 9, 10, 0, 8, 8, 9}, {9, 0, 0, 0, 0, 18, 8, 0, 0, 9},
      {0, 2, 9, 0, 0, 0, 8, 0, 0, 2},  {3, 4, 0, 0, 0, 0, 9, 9, 2, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2], matrix[3],
                                matrix[4], matrix[5], matrix[6], matrix[7],
                                matrix[8], matrix[9]};
  distance matrix2[size][size] = {
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 3}, {0, 0, 0, 0, 0, 0, 0, 0, 2, 0},
      {0, 0, 0, 4, 0, 0, 7, 0, 0, 0}, {0, 0, 4, 0, 1, 0, 0, 0, 0, 0},
      {0, 0, 0, 1, 0, 3, 0, 0, 0, 0}, {0, 0, 0, 0, 3, 0, 0, 0, 0, 0},
      {0, 0, 7, 0, 0, 0, 0, 8, 8, 0}, {0, 0, 0, 0, 0, 0, 8, 0, 0, 0},
      {0, 2, 0, 0, 0, 0, 8, 0, 0, 2}, {3, 0, 0, 0, 0, 0, 0, 0, 2, 0}};
  distance *ansMatrix[size] = {matrix2[0], matrix2[1], matrix2[2], matrix2[3],
                               matrix2[4], matrix2[5], matrix2[6], matrix2[7],
                               matrix2[8], matrix2[9]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(size));
  for (vertex_id i = 1; i <= size; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  weight **adjacencyMatrixLeastSpanningTree =
      graphAlgorithms.getLeastSpanningTree(graphMock);

  // Assert
  ASSERT_TRUE(
      matrixComparer(size, adjacencyMatrixLeastSpanningTree, ansMatrix));
  deleteMatrix(size, adjacencyMatrixLeastSpanningTree);
}

TEST(getLeastSpanningTreePrimTests, Graph10_1) {
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 10;
  weight matrix[size][size] = {
      {0, 6, 0, 0, 0, 0, 0, 9, 0, 3},  {6, 0, 9, 0, 0, 0, 0, 0, 2, 4},
      {0, 9, 0, 4, 5, 0, 7, 0, 9, 0},  {0, 0, 4, 0, 1, 4, 0, 0, 0, 0},
      {0, 0, 5, 1, 0, 3, 9, 0, 0, 0},  {0, 0, 0, 4, 3, 0, 10, 18, 0, 0},
      {0, 0, 7, 0, 9, 10, 0, 8, 8, 1}, {9, 0, 0, 0, 0, 18, 8, 0, 0, 9},
      {0, 2, 9, 0, 0, 0, 8, 0, 0, 2},  {3, 4, 0, 0, 0, 0, 1, 9, 2, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2], matrix[3],
                                matrix[4], matrix[5], matrix[6], matrix[7],
                                matrix[8], matrix[9]};
  distance matrix2[size][size] = {
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 3}, {0, 0, 0, 0, 0, 0, 0, 0, 2, 0},
      {0, 0, 0, 4, 0, 0, 7, 0, 0, 0}, {0, 0, 4, 0, 1, 0, 0, 0, 0, 0},
      {0, 0, 0, 1, 0, 3, 0, 0, 0, 0}, {0, 0, 0, 0, 3, 0, 0, 0, 0, 0},
      {0, 0, 7, 0, 0, 0, 0, 8, 0, 1}, {0, 0, 0, 0, 0, 0, 8, 0, 0, 0},
      {0, 2, 0, 0, 0, 0, 0, 0, 0, 2}, {3, 0, 0, 0, 0, 0, 1, 0, 2, 0}};
  distance *ansMatrix[size] = {matrix2[0], matrix2[1], matrix2[2], matrix2[3],
                               matrix2[4], matrix2[5], matrix2[6], matrix2[7],
                               matrix2[8], matrix2[9]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(size));
  for (vertex_id i = 1; i <= size; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  weight **adjacencyMatrixLeastSpanningTree =
      graphAlgorithms.getLeastSpanningTree(graphMock);

  // Assert
  ASSERT_TRUE(
      matrixComparer(size, adjacencyMatrixLeastSpanningTree, ansMatrix));
  deleteMatrix(size, adjacencyMatrixLeastSpanningTree);
}

TEST(getLeastSpanningTreePrimTests, Graph10_2) {
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 10;
  weight matrix[size][size] = {
      {0, 6, 0, 0, 0, 0, 0, 7, 0, 3},  {6, 0, 9, 0, 0, 0, 0, 0, 2, 4},
      {0, 9, 0, 4, 5, 0, 7, 0, 9, 0},  {0, 0, 4, 0, 1, 4, 0, 0, 0, 0},
      {0, 0, 5, 1, 0, 3, 9, 0, 0, 0},  {0, 0, 0, 4, 3, 0, 10, 18, 0, 0},
      {0, 0, 7, 0, 9, 10, 0, 8, 8, 9}, {7, 0, 0, 0, 0, 18, 8, 0, 0, 9},
      {0, 2, 9, 0, 0, 0, 8, 0, 0, 2},  {3, 4, 0, 0, 0, 0, 9, 9, 2, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2], matrix[3],
                                matrix[4], matrix[5], matrix[6], matrix[7],
                                matrix[8], matrix[9]};
  distance matrix2[size][size] = {
      {0, 0, 0, 0, 0, 0, 0, 7, 0, 3}, {0, 0, 0, 0, 0, 0, 0, 0, 2, 0},
      {0, 0, 0, 4, 0, 0, 7, 0, 0, 0}, {0, 0, 4, 0, 1, 0, 0, 0, 0, 0},
      {0, 0, 0, 1, 0, 3, 0, 0, 0, 0}, {0, 0, 0, 0, 3, 0, 0, 0, 0, 0},
      {0, 0, 7, 0, 0, 0, 0, 8, 0, 0}, {7, 0, 0, 0, 0, 0, 8, 0, 0, 0},
      {0, 2, 0, 0, 0, 0, 0, 0, 0, 2}, {3, 0, 0, 0, 0, 0, 0, 0, 2, 0}};
  distance *ansMatrix[size] = {matrix2[0], matrix2[1], matrix2[2], matrix2[3],
                               matrix2[4], matrix2[5], matrix2[6], matrix2[7],
                               matrix2[8], matrix2[9]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(size));
  for (vertex_id i = 1; i <= size; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  weight **adjacencyMatrixLeastSpanningTree =
      graphAlgorithms.getLeastSpanningTree(graphMock);

  // Assert
  ASSERT_TRUE(
      matrixComparer(size, adjacencyMatrixLeastSpanningTree, ansMatrix));
  deleteMatrix(size, adjacencyMatrixLeastSpanningTree);
}

TEST(getLeastSpanningTreePrimTests, Graph11) {
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 11;
  weight matrix[size][size] = {{0, 29, 20, 21, 16, 31, 100, 12, 4, 31, 18},
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
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2], matrix[3],
                                matrix[4], matrix[5], matrix[6], matrix[7],
                                matrix[8], matrix[9], matrix[10]};
  distance matrix2[size][size] = {
      {0, 0, 0, 0, 0, 0, 0, 12, 4, 0, 0}, {0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 12},
      {0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 13}, {0, 0, 0, 0, 4, 12, 0, 0, 0, 0, 0},
      {0, 0, 0, 4, 0, 0, 0, 9, 0, 0, 0},  {0, 0, 0, 12, 0, 0, 0, 0, 0, 3, 0},
      {0, 72, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {12, 0, 9, 0, 9, 0, 0, 0, 0, 0, 0},
      {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  {0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0},
      {0, 12, 13, 0, 0, 0, 0, 0, 0, 0, 0}};
  distance *ansMatrix[size] = {matrix2[0], matrix2[1], matrix2[2], matrix2[3],
                               matrix2[4], matrix2[5], matrix2[6], matrix2[7],
                               matrix2[8], matrix2[9], matrix2[10]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillOnce(Return(size));
  for (vertex_id i = 1; i <= size; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillOnce(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  weight **adjacencyMatrixLeastSpanningTree =
      graphAlgorithms.getLeastSpanningTree(graphMock);

  // Assert
  ASSERT_TRUE(
      matrixComparer(size, adjacencyMatrixLeastSpanningTree, ansMatrix));
  deleteMatrix(size, adjacencyMatrixLeastSpanningTree);
}
