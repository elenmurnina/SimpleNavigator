#include "GraphMock.h"
#include "VertexMapForTests.h"
#include "gmock.h"
#include "gtest.h"
#include "s21_graph_algorithms.h"

using ::testing::NiceMock;
using ::testing::Return;
using ::testing::ReturnRef;

TEST(solveTravelingSalesmanProblemAntsTests, Graph3) {
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 3;
  weight matrix[size][size] = {{0, 1, 1}, {1, 0, 1}, {1, 1, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillRepeatedly(Return(size));
  EXPECT_CALL(graphMock, getAdjacencyMatrix())
      .WillRepeatedly(Return(weightMatrix));
  for (vertex_id i = 1; i <= size; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillRepeatedly(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  TsmResult result = graphAlgorithms.solveTravelingSalesmanProblem(graphMock);

  // Assert
  ASSERT_EQ(result.distance, 3);
  ASSERT_TRUE(result.vertices == std::vector<vertex_id>({1, 2, 3, 1}) ||
              result.vertices == std::vector<vertex_id>({1, 3, 2, 1}));
}

TEST(solveTravelingSalesmanProblemAntsTests, Graph3_1) {
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 3;
  weight matrix[size][size] = {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillRepeatedly(Return(size));
  EXPECT_CALL(graphMock, getAdjacencyMatrix())
      .WillRepeatedly(Return(weightMatrix));
  for (vertex_id i = 1; i <= size; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillRepeatedly(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  TsmResult result = graphAlgorithms.solveTravelingSalesmanProblem(graphMock);

  // Assert
  ASSERT_EQ(result.distance, 4);
  ASSERT_EQ(result.vertices, std::vector<vertex_id>({1, 2, 3, 2, 1}));
}

TEST(solveTravelingSalesmanProblemAntsTests, Graph4) {
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 4;
  weight matrix[size][size] = {
      {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}, {1, 1, 1, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2], matrix[3]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillRepeatedly(Return(size));
  EXPECT_CALL(graphMock, getAdjacencyMatrix())
      .WillRepeatedly(Return(weightMatrix));
  for (vertex_id i = 1; i <= size; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillRepeatedly(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  TsmResult result = graphAlgorithms.solveTravelingSalesmanProblem(graphMock);

  // Assert
  ASSERT_EQ(result.distance, 6);
  ASSERT_TRUE(result.vertices ==
                  std::vector<vertex_id>({1, 4, 2, 4, 3, 4, 1}) ||
              result.vertices == std::vector<vertex_id>({1, 4, 3, 4, 2, 4, 1}));
}

TEST(solveTravelingSalesmanProblemAntsTests, Graph4_1) {
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 4;
  weight matrix[size][size] = {
      {0, 4, 1, 6}, {10, 0, 7, 2}, {9, 5, 0, 2}, {8, 5, 7, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2], matrix[3]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillRepeatedly(Return(size));
  EXPECT_CALL(graphMock, getAdjacencyMatrix())
      .WillRepeatedly(Return(weightMatrix));
  for (vertex_id i = 1; i <= size; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillRepeatedly(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  TsmResult result = graphAlgorithms.solveTravelingSalesmanProblem(graphMock);

  // Assert
  ASSERT_EQ(result.distance, 16);
  ASSERT_EQ(result.vertices, std::vector<vertex_id>({1, 3, 2, 4, 1}));
}

TEST(solveTravelingSalesmanProblemAntsTests, Graph5) {
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 5;
  weight matrix[size][size] = {{0, 20, 18, 12, 8},
                               {5, 0, 14, 7, 11},
                               {12, 18, 0, 6, 11},
                               {11, 17, 11, 0, 12},
                               {5, 5, 5, 5, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2], matrix[3],
                                matrix[4]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillRepeatedly(Return(size));
  EXPECT_CALL(graphMock, getAdjacencyMatrix())
      .WillRepeatedly(Return(weightMatrix));
  for (vertex_id i = 1; i <= size; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillRepeatedly(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  TsmResult result = graphAlgorithms.solveTravelingSalesmanProblem(graphMock);

  // Assert
  ASSERT_EQ(result.distance, 41);
  ASSERT_TRUE(result.vertices == std::vector<vertex_id>({1, 5, 3, 4, 2, 1}) ||
              result.vertices == std::vector<vertex_id>({1, 2, 4, 3, 5, 1}) ||
              result.vertices == std::vector<vertex_id>({1, 5, 3, 4, 5, 2, 1}));
}

TEST(solveTravelingSalesmanProblemAntsTests, Graph5_1) {
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 5;
  weight matrix[size][size] = {{0, 100, 50, 0, 200},
                               {0, 0, 200, 50, 300},
                               {50, 300, 0, 50, 0},
                               {0, 150, 50, 0, 50},
                               {200, 400, 0, 50, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2], matrix[3],
                                matrix[4]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillRepeatedly(Return(size));
  EXPECT_CALL(graphMock, getAdjacencyMatrix())
      .WillRepeatedly(Return(weightMatrix));
  for (vertex_id i = 1; i <= size; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillRepeatedly(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  TsmResult result = graphAlgorithms.solveTravelingSalesmanProblem(graphMock);

  // Assert
  ASSERT_EQ(result.distance, 350);
  ASSERT_EQ(result.vertices, std::vector<vertex_id>({1, 2, 4, 5, 4, 3, 1}));
}

TEST(solveTravelingSalesmanProblemAntsTests, Graph5_2) {
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 5;
  weight matrix[size][size] = {{0, 90, 80, 40, 100},
                               {60, 0, 40, 50, 70},
                               {50, 30, 0, 60, 20},
                               {10, 70, 20, 0, 50},
                               {20, 40, 50, 20, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2], matrix[3],
                                matrix[4]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillRepeatedly(Return(size));
  EXPECT_CALL(graphMock, getAdjacencyMatrix())
      .WillRepeatedly(Return(weightMatrix));
  for (vertex_id i = 1; i <= size; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillRepeatedly(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  TsmResult result = graphAlgorithms.solveTravelingSalesmanProblem(graphMock);

  // Assert
  ASSERT_EQ(result.distance, 170);
  ASSERT_EQ(result.vertices, std::vector<vertex_id>({1, 4, 3, 2, 3, 5, 1}));
}

TEST(solveTravelingSalesmanProblemAntsTests, Graph6) {
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 6;
  weight matrix[size][size] = {{0, 26, 42, 15, 29, 25}, {7, 0, 16, 1, 30, 25},
                               {20, 13, 0, 35, 5, 0},   {21, 16, 25, 0, 18, 18},
                               {12, 46, 27, 48, 0, 5},  {23, 5, 5, 9, 5, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2],
                                matrix[3], matrix[4], matrix[5]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillRepeatedly(Return(size));
  EXPECT_CALL(graphMock, getAdjacencyMatrix())
      .WillRepeatedly(Return(weightMatrix));
  for (vertex_id i = 1; i <= size; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillRepeatedly(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  TsmResult result = graphAlgorithms.solveTravelingSalesmanProblem(graphMock);

  // Assert
  ASSERT_EQ(result.distance, 60);
  ASSERT_EQ(result.vertices, std::vector<vertex_id>({1, 4, 6, 3, 5, 6, 2, 1}));
}

TEST(solveTravelingSalesmanProblemAntsTests, Graph7) {
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 7;
  weight matrix[size][size] = {
      {0, 751, 344, 600, 737, 257, 582}, {492, 0, 884, 277, 30, 64, 208},
      {472, 836, 0, 895, 673, 557, 154}, {150, 791, 263, 0, 163, 247, 301},
      {17, 547, 219, 211, 0, 915, 811},  {386, 171, 744, 229, 657, 0, 505},
      {38, 42, 64, 510, 877, 231, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2], matrix[3],
                                matrix[4], matrix[5], matrix[6]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillRepeatedly(Return(size));
  EXPECT_CALL(graphMock, getAdjacencyMatrix())
      .WillRepeatedly(Return(weightMatrix));
  for (vertex_id i = 1; i <= size; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillRepeatedly(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  TsmResult result = graphAlgorithms.solveTravelingSalesmanProblem(graphMock);

  // Assert
  ASSERT_EQ(result.distance, 992);
  ASSERT_EQ(result.vertices, std::vector<vertex_id>({1, 6, 4, 3, 7, 2, 5, 1}));
}

TEST(solveTravelingSalesmanProblemAntsTests, Graph8) {
  NiceMock<GraphMock> graphMock;
  GraphAlgorithms graphAlgorithms;
  const int size = 8;
  weight matrix[size][size] = {
      {0, 5, 3, 2, 4, 5, 2, 7}, {7, 0, 1, 6, 7, 8, 9, 6},
      {3, 2, 0, 3, 2, 4, 5, 7}, {4, 6, 2, 0, 1, 3, 6, 2},
      {4, 5, 1, 2, 0, 4, 2, 3}, {3, 8, 9, 6, 4, 0, 1, 5},
      {1, 6, 6, 4, 2, 1, 0, 0}, {7, 8, 7, 2, 8, 3, 0, 0}};
  weight *weightMatrix[size] = {matrix[0], matrix[1], matrix[2], matrix[3],
                                matrix[4], matrix[5], matrix[6], matrix[7]};

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillRepeatedly(Return(size));
  EXPECT_CALL(graphMock, getAdjacencyMatrix())
      .WillRepeatedly(Return(weightMatrix));
  for (vertex_id i = 1; i <= size; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillRepeatedly(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  TsmResult result = graphAlgorithms.solveTravelingSalesmanProblem(graphMock);

  // Assert
  ASSERT_EQ(result.distance, 17);
  ASSERT_TRUE(
      result.vertices == std::vector<vertex_id>({1, 4, 5, 3, 2, 8, 6, 7, 1}) ||
      result.vertices == std::vector<vertex_id>({1, 4, 5, 3, 2, 8, 6, 7, 1}) ||
      result.vertices ==
          std::vector<vertex_id>({1, 4, 5, 3, 2, 3, 4, 8, 6, 7, 1}) ||
      result.vertices ==
          std::vector<vertex_id>({1, 4, 8, 4, 5, 3, 2, 3, 6, 7, 1}) ||
      result.vertices ==
          std::vector<vertex_id>({1, 3, 2, 3, 5, 4, 8, 6, 7, 1}));
}

TEST(solveTravelingSalesmanProblemAntsTests, Graph11) {
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

  VertexMapForTests vertexMapForTests(size, weightMatrix);
  EXPECT_CALL(graphMock, getMatrixSize()).WillRepeatedly(Return(size));
  EXPECT_CALL(graphMock, getAdjacencyMatrix())
      .WillRepeatedly(Return(weightMatrix));
  for (vertex_id i = 1; i <= size; i++) {
    EXPECT_CALL(graphMock, getVertexById(i))
        .WillRepeatedly(ReturnRef(vertexMapForTests.getVertexById(i)));
  }

  // Act
  TsmResult result = graphAlgorithms.solveTravelingSalesmanProblem(graphMock);

  // Assert
  ASSERT_EQ(result.distance, 253);
  ASSERT_TRUE(result.vertices == std::vector<vertex_id>(
                                     {1, 8, 5, 4, 10, 6, 3, 7, 2, 11, 9, 1}) ||
              result.vertices == std::vector<vertex_id>(
                                     {1, 9, 11, 2, 7, 3, 6, 10, 4, 5, 8, 1}));
}
