#include <map>

#include "gmock.h"
#include "gtest.h"
#include "DotBuilderMock.h"
#include "MatrixReaderMock.h"
#include "VertexMapBuilderMock.h"
#include "s21_graph.h"
#include <filesystem>

using ::testing::_;
using ::testing::NiceMock;
using ::testing::Return;

TEST(GraphTests, GetVertexById_MatrixNotInitialized_ThrowsException) {
  // Arrange
  MatrixReaderMock matrixReaderMock;
  VertexMapBuilderMock vertexMapBuilderMock;
  DotBuilderMock dotBuilderMock;

  auto graph = Graph(matrixReaderMock, vertexMapBuilderMock, dotBuilderMock);

  // Act

  // Assert
  ASSERT_THROW(graph.getVertexById(1), std::invalid_argument);
}

TEST(GraphTests, GetMatrixSize_MatrixNotInitialized_ThrowsException) {
  // Arrange
  MatrixReaderMock matrixReaderMock;
  VertexMapBuilderMock vertexMapBuilderMock;
  DotBuilderMock dotBuilderMock;

  auto graph = Graph(matrixReaderMock, vertexMapBuilderMock, dotBuilderMock);

  // Act

  // Assert
  ASSERT_THROW(graph.getMatrixSize(), std::invalid_argument);
}

TEST(GraphTests, IsDirected_MatrixNotInitialized_ThrowsException) {
  // Arrange
  MatrixReaderMock matrixReaderMock;
  VertexMapBuilderMock vertexMapBuilderMock;
  DotBuilderMock dotBuilderMock;

  auto graph = Graph(matrixReaderMock, vertexMapBuilderMock, dotBuilderMock);

  // Act

  // Assert
  ASSERT_THROW(graph.isDirected(), std::invalid_argument);
}

TEST(GraphTests, IsWeighted_MatrixNotInitialized_ThrowsException) {
  // Arrange
  MatrixReaderMock matrixReaderMock;
  VertexMapBuilderMock vertexMapBuilderMock;
  DotBuilderMock dotBuilderMock;

  auto graph = Graph(matrixReaderMock, vertexMapBuilderMock, dotBuilderMock);

  // Act

  // Assert
  ASSERT_THROW(graph.isWeighted(), std::invalid_argument);
}

TEST(GraphTests, GetAdjacencyMatrix_MatrixNotInitialized_ThrowsException) {
  // Arrange
  MatrixReaderMock matrixReaderMock;
  VertexMapBuilderMock vertexMapBuilderMock;
  DotBuilderMock dotBuilderMock;

  auto graph = Graph(matrixReaderMock, vertexMapBuilderMock, dotBuilderMock);

  // Act

  // Assert
  ASSERT_THROW(graph.getAdjacencyMatrix(), std::invalid_argument);
}

TEST(GraphTests,
     LoadGraphFromFile_WeightedUndirectedGraph_GraphHasValidValues) {
  // Arrange
  MatrixReaderMock matrixReaderMock;
  VertexMapBuilderMock vertexMapBuilderMock;
  DotBuilderMock dotBuilderMock;
  std::string filename = "./unitTests/graph/testData/MockMap.txt";
  std::ifstream file(filename);
  ASSERT_TRUE(file.good());
  file.close();

  const int size = 4;
  weight matrix[size][size] = {
      {0, 29, 20, 21}, {29, 0, 15, 29}, {20, 15, 0, 15}, {21, 29, 15, 0}};
  weight **expectedMatrix = new weight *[size];
  for (size_t i = 0; i < size; i++) {
    expectedMatrix[i] = new weight[size];
    for (size_t j = 0; j < size; j++) {
      expectedMatrix[i][j] = matrix[i][j];
    }
  }

  std::map<vertex_id, Vertex *> expectedVertexMap = {{1, new Vertex(1)},
                                                     {2, new Vertex(2)},
                                                     {3, new Vertex(3)},
                                                     {4, new Vertex(4)}};

  EXPECT_CALL(matrixReaderMock, readMatrixSize(_))
      .Times(1)
      .WillOnce(Return(size));
  EXPECT_CALL(matrixReaderMock, readAdjacencyMatrix(_, size))
      .Times(1)
      .WillOnce(Return(expectedMatrix));
  EXPECT_CALL(vertexMapBuilderMock, buildVerticesMap(expectedMatrix, size))
      .Times(1)
      .WillOnce(Return(expectedVertexMap));

  auto graph = Graph(matrixReaderMock, vertexMapBuilderMock, dotBuilderMock);

  // Act
  graph.loadGraphFromFile(filename);

  // Assert
  ASSERT_EQ(size, graph.getMatrixSize());
  ASSERT_FALSE(graph.isDirected());
  ASSERT_TRUE(graph.isWeighted());

  auto actualMatrix = graph.getAdjacencyMatrix();
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      ASSERT_EQ(actualMatrix[i][j], expectedMatrix[i][j]);
    }
  }

  for (size_t i = 1; i <= size; i++) {
    ASSERT_EQ(*expectedVertexMap[i], graph.getVertexById(i));
  }
}

TEST(GraphTests, LoadGraphFromFile_WeightedDirectedGraph_GraphHasValidValues) {
  // Arrange
  MatrixReaderMock matrixReaderMock;
  VertexMapBuilderMock vertexMapBuilderMock;
  DotBuilderMock dotBuilderMock;
  std::string filename = "./unitTests/graph/testData/MockMap.txt";
  std::ifstream file(filename);
  ASSERT_TRUE(file.good());
  file.close();

  const int size = 4;
  weight matrix[size][size] = {
      {0, 29, 0, 21}, {29, 0, 15, 29}, {20, 15, 0, 0}, {21, 29, 15, 0}};
  weight **expectedMatrix = new weight *[size];
  for (size_t i = 0; i < size; i++) {
    expectedMatrix[i] = new weight[size];
    for (size_t j = 0; j < size; j++) {
      expectedMatrix[i][j] = matrix[i][j];
    }
  }

  std::map<vertex_id, Vertex *> expectedVertexMap = {{1, new Vertex(1)},
                                                     {2, new Vertex(2)},
                                                     {3, new Vertex(3)},
                                                     {4, new Vertex(4)}};

  EXPECT_CALL(matrixReaderMock, readMatrixSize(_))
      .Times(1)
      .WillOnce(Return(size));
  EXPECT_CALL(matrixReaderMock, readAdjacencyMatrix(_, size))
      .Times(1)
      .WillOnce(Return(expectedMatrix));
  EXPECT_CALL(vertexMapBuilderMock, buildVerticesMap(expectedMatrix, size))
      .Times(1)
      .WillOnce(Return(expectedVertexMap));

  auto graph = Graph(matrixReaderMock, vertexMapBuilderMock, dotBuilderMock);

  // Act
  graph.loadGraphFromFile(filename);

  // Assert
  ASSERT_EQ(size, graph.getMatrixSize());
  ASSERT_TRUE(graph.isDirected());
  ASSERT_TRUE(graph.isWeighted());

  auto actualMatrix = graph.getAdjacencyMatrix();
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      ASSERT_EQ(actualMatrix[i][j], expectedMatrix[i][j]);
    }
  }

  for (size_t i = 1; i <= size; i++) {
    ASSERT_EQ(*expectedVertexMap[i], graph.getVertexById(i));
  }
}

TEST(GraphTests,
     LoadGraphFromFile_UnweightedDirectedGraph_GraphHasValidValues) {
  // Arrange
  MatrixReaderMock matrixReaderMock;
  VertexMapBuilderMock vertexMapBuilderMock;
  DotBuilderMock dotBuilderMock;
  std::string filename = "./unitTests/graph/testData/MockMap.txt";
  std::ifstream file(filename);
  ASSERT_TRUE(file.good());
  file.close();

  const int size = 4;
  weight matrix[size][size] = {
      {0, 1, 0, 1}, {1, 0, 1, 1}, {1, 1, 0, 0}, {1, 1, 1, 0}};
  weight **expectedMatrix = new weight *[size];
  for (size_t i = 0; i < size; i++) {
    expectedMatrix[i] = new weight[size];
    for (size_t j = 0; j < size; j++) {
      expectedMatrix[i][j] = matrix[i][j];
    }
  }

  std::map<vertex_id, Vertex *> expectedVertexMap = {{1, new Vertex(1)},
                                                     {2, new Vertex(2)},
                                                     {3, new Vertex(3)},
                                                     {4, new Vertex(4)}};

  EXPECT_CALL(matrixReaderMock, readMatrixSize(_))
      .Times(1)
      .WillOnce(Return(size));
  EXPECT_CALL(matrixReaderMock, readAdjacencyMatrix(_, size))
      .Times(1)
      .WillOnce(Return(expectedMatrix));
  EXPECT_CALL(vertexMapBuilderMock, buildVerticesMap(expectedMatrix, size))
      .Times(1)
      .WillOnce(Return(expectedVertexMap));

  auto graph = Graph(matrixReaderMock, vertexMapBuilderMock, dotBuilderMock);

  // Act
  graph.loadGraphFromFile(filename);

  // Assert
  ASSERT_EQ(size, graph.getMatrixSize());
  ASSERT_TRUE(graph.isDirected());
  ASSERT_FALSE(graph.isWeighted());

  auto actualMatrix = graph.getAdjacencyMatrix();
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      ASSERT_EQ(actualMatrix[i][j], expectedMatrix[i][j]);
    }
  }

  for (size_t i = 1; i <= size; i++) {
    ASSERT_EQ(*expectedVertexMap[i], graph.getVertexById(i));
  }
}

TEST(GraphTests,
     LoadGraphFromFile_UnweightedUndirectedGraph_GraphHasValidValues) {
  // Arrange
  MatrixReaderMock matrixReaderMock;
  VertexMapBuilderMock vertexMapBuilderMock;
  DotBuilderMock dotBuilderMock;
  std::string filename = "./unitTests/graph/testData/MockMap.txt";
  std::ifstream file(filename);
  ASSERT_TRUE(file.good());
  file.close();

  const int size = 4;
  weight matrix[size][size] = {
      {0, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 0}};
  weight **expectedMatrix = new weight *[size];
  for (size_t i = 0; i < size; i++) {
    expectedMatrix[i] = new weight[size];
    for (size_t j = 0; j < size; j++) {
      expectedMatrix[i][j] = matrix[i][j];
    }
  }

  std::map<vertex_id, Vertex *> expectedVertexMap = {{1, new Vertex(1)},
                                                     {2, new Vertex(2)},
                                                     {3, new Vertex(3)},
                                                     {4, new Vertex(4)}};

  EXPECT_CALL(matrixReaderMock, readMatrixSize(_))
      .Times(1)
      .WillOnce(Return(size));
  EXPECT_CALL(matrixReaderMock, readAdjacencyMatrix(_, size))
      .Times(1)
      .WillOnce(Return(expectedMatrix));
  EXPECT_CALL(vertexMapBuilderMock, buildVerticesMap(expectedMatrix, size))
      .Times(1)
      .WillOnce(Return(expectedVertexMap));

  auto graph = Graph(matrixReaderMock, vertexMapBuilderMock, dotBuilderMock);

  // Act
  graph.loadGraphFromFile(filename);

  // Assert
  ASSERT_EQ(size, graph.getMatrixSize());
  ASSERT_FALSE(graph.isDirected());
  ASSERT_FALSE(graph.isWeighted());

  auto actualMatrix = graph.getAdjacencyMatrix();
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      ASSERT_EQ(actualMatrix[i][j], expectedMatrix[i][j]);
    }
  }

  for (size_t i = 1; i <= size; i++) {
    ASSERT_EQ(*expectedVertexMap[i], graph.getVertexById(i));
  }
}

TEST(GraphTests, GetVertexById_IndexIsNotPresent_ThrowsException) {
  // Arrange
  MatrixReaderMock matrixReaderMock;
  VertexMapBuilderMock vertexMapBuilderMock;
  DotBuilderMock dotBuilderMock;
  std::string filename = "./unitTests/graph/testData/MockMap.txt";
  std::ifstream file(filename);
  ASSERT_TRUE(file.good());
  file.close();

  const int size = 4;
  weight matrix[size][size] = {
      {0, 29, 20, 21}, {29, 0, 15, 29}, {20, 15, 0, 15}, {21, 29, 15, 0}};
  weight **expectedMatrix = new weight *[size];
  for (size_t i = 0; i < size; i++) {
    expectedMatrix[i] = new weight[size];
    for (size_t j = 0; j < size; j++) {
      expectedMatrix[i][j] = matrix[i][j];
    }
  }

  std::map<vertex_id, Vertex *> expectedVertexMap = {{1, new Vertex(1)},
                                                     {2, new Vertex(2)},
                                                     {3, new Vertex(3)},
                                                     {4, new Vertex(4)}};

  EXPECT_CALL(matrixReaderMock, readMatrixSize(_))
      .Times(1)
      .WillOnce(Return(size));
  EXPECT_CALL(matrixReaderMock, readAdjacencyMatrix(_, size))
      .Times(1)
      .WillOnce(Return(expectedMatrix));
  EXPECT_CALL(vertexMapBuilderMock, buildVerticesMap(expectedMatrix, size))
      .Times(1)
      .WillOnce(Return(expectedVertexMap));

  auto graph = Graph(matrixReaderMock, vertexMapBuilderMock, dotBuilderMock);
  graph.loadGraphFromFile(filename);

  // Act

  // Assert
  ASSERT_THROW(graph.getVertexById(size + 1), std::out_of_range);
}

TEST(GraphTests, ExportGraphToDot_ExportsGraphToExistentFile) {
  // Arrange
  MatrixReaderMock matrixReaderMock;
  VertexMapBuilderMock vertexMapBuilderMock;
  DotBuilderMock dotBuilderMock;
  std::string filename = "./unitTests/graph/testData/ExistentDot.txt";
  std::ofstream file(filename);
  ASSERT_TRUE(file.good());
  file.close();

  std::string expectedString = "testString";

  auto graph = Graph(matrixReaderMock, vertexMapBuilderMock, dotBuilderMock);

  EXPECT_CALL(dotBuilderMock, buildDotFromGraph(_))
      .Times(1)
      .WillOnce(Return(expectedString));

  // Act
  graph.exportGraphToDot(filename);

  // Assert
  std::ifstream resultFile(filename);
  std::string resultFileContentLine;
  std::getline(resultFile, resultFileContentLine);

  ASSERT_EQ(resultFile.peek(), EOF);
  ASSERT_EQ(resultFileContentLine, expectedString);
  resultFile.close();
}

TEST(GraphTests, ExportGraphToDot_ExportsGraphToNonExistentFile) {
  // Arrange
  MatrixReaderMock matrixReaderMock;
  VertexMapBuilderMock vertexMapBuilderMock;
  DotBuilderMock dotBuilderMock;
  std::string filename = "./unitTests/graph/testData/NonExistentDot.txt";

  std::string expectedString = "testString";

  auto graph = Graph(matrixReaderMock, vertexMapBuilderMock, dotBuilderMock);

  EXPECT_CALL(dotBuilderMock, buildDotFromGraph(_))
      .Times(1)
      .WillOnce(Return(expectedString));

  // Act
  graph.exportGraphToDot(filename);

  // Assert
  std::ifstream resultFile(filename);
  std::string resultFileContentLine;
  std::getline(resultFile, resultFileContentLine);

  ASSERT_EQ(resultFile.peek(), EOF);
  ASSERT_EQ(resultFileContentLine, expectedString);

  resultFile.close();
  std::filesystem::remove(filename);
}
