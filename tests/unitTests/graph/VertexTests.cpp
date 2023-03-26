#include "Vertex.h"
#include "gtest.h"

TEST(VertexTests, GetIdReturnsValidId) {
  // Arrange
  vertex_id expectedVertexId = 10;
  auto vertex = Vertex(expectedVertexId);

  // Act
  auto actualVertexId = vertex.getId();

  // Assert
  EXPECT_EQ(actualVertexId, expectedVertexId);
}

TEST(VertexTests, GetAdjacenciesReturnsEmptyVector) {
  // Arrange
  auto vertex = Vertex(10);

  // Act
  auto adjacencyList = vertex.getAdjacencies();

  // Assert
  EXPECT_TRUE(adjacencyList.empty());
}

TEST(VertexTests, EquationOperatorReturnsTrueForEqualVertexes) {
  // Arrange
  auto firstVertex = Vertex(10);
  auto secondVertex = Vertex(10);

  // Act
  auto result = firstVertex == secondVertex;

  // Assert
  EXPECT_TRUE(result);
}

TEST(VertexTests, GetAdjacenciesReturnsVectorWithAddedAdjacencies) {
  // Arrange
  auto vertex = Vertex(10);
  auto firstAdjacency = Adjacency(Vertex(11), 0);
  auto secondAdjacency = Adjacency(Vertex(12), 20);
  auto thirdAjacency = Adjacency(Vertex(13), 30);

  // Act
  vertex.addAdjacency(firstAdjacency);
  vertex.addAdjacency(secondAdjacency);
  vertex.addAdjacency(thirdAjacency);
  auto adjacencyList = vertex.getAdjacencies();

  // Assert
  ASSERT_EQ(adjacencyList[0], firstAdjacency);
  ASSERT_EQ(adjacencyList[1], secondAdjacency);
  ASSERT_EQ(adjacencyList[2], thirdAjacency);
}

TEST(VertexTests, CanBuildBidirectionalAdjacency) {
  // Arrange
  auto firstVertex = Vertex(10);
  auto secondVertex = Vertex(11);

  // Act
  weight weight = 10;
  firstVertex.addAdjacency(Adjacency(secondVertex, weight));
  secondVertex.addAdjacency(Adjacency(firstVertex, weight));

  // Assert
  auto firstVertexAdjacencies = firstVertex.getAdjacencies();
  auto secondVertexAdjacencies = secondVertex.getAdjacencies();
  size_t expectedSize = 1;
  ASSERT_EQ(firstVertexAdjacencies.size(), expectedSize);
  ASSERT_EQ(secondVertexAdjacencies.size(), expectedSize);
  ASSERT_EQ(firstVertexAdjacencies[0].getVertex(), secondVertex);
  ASSERT_EQ(secondVertexAdjacencies[0].getVertex(), firstVertex);
  ASSERT_EQ(firstVertexAdjacencies[0].getWeight(), weight);
  ASSERT_EQ(secondVertexAdjacencies[0].getWeight(), weight);
}

TEST(VertexTests, CanBuildCircledAdjacency) {
  // Arrange
  auto vertex = Vertex(10);
  auto firstAdjacency = Adjacency(Vertex(11), 0);
  auto secondAdjacency = Adjacency(Vertex(12), 20);
  auto thirdAjacency = Adjacency(Vertex(13), 30);

  // Act
  vertex.addAdjacency(firstAdjacency);
  vertex.addAdjacency(secondAdjacency);
  vertex.addAdjacency(thirdAjacency);
  auto adjacencyList = vertex.getAdjacencies();

  // Assert
  ASSERT_EQ(adjacencyList[0], firstAdjacency);
  ASSERT_EQ(adjacencyList[1], secondAdjacency);
  ASSERT_EQ(adjacencyList[2], thirdAjacency);
}
