#include "Adjacency.h"
#include "Vertex.h"
#include "gtest.h"

TEST(AdjacencyTests, GettersReturnValidValues) {
  // Arrange
  vertex_id vertexId = 10;
  auto expectedVertex = Vertex(vertexId);
  weight expectedWeight = 100;
  auto adjacency = Adjacency(expectedVertex, expectedWeight);

  // Act
  auto actualWeight = adjacency.getWeight();
  auto actualVertex = adjacency.getVertex();

  // Assert
  ASSERT_EQ(actualWeight, expectedWeight);
  ASSERT_EQ(actualVertex, expectedVertex);
}

TEST(AdjacencyTests, EqautionOperatorReturnsFalse) {
  // Arrange
  vertex_id firstVertexId = 10;
  vertex_id secondVertexId = 11;
  auto firstVertex = Vertex(firstVertexId);
  auto secondVertex = Vertex(secondVertexId);
  weight firstWeight = 100;
  weight secondWeight = 110;
  auto firstAdjacency = Adjacency(firstVertex, firstWeight);
  auto secondAdjacency = Adjacency(secondVertex, secondWeight);

  // Act
  auto result = firstAdjacency == secondAdjacency;

  // Assert
  ASSERT_FALSE(result);
}

TEST(AdjacencyTests, EqautionOperatorReturnsTrue) {
  // Arrange
  vertex_id vertexId = 10;
  auto vertex = Vertex(vertexId);
  weight weight = 100;
  auto firstAdjacency = Adjacency(vertex, weight);
  auto secondAdjacency = Adjacency(vertex, weight);

  // Act
  auto result = firstAdjacency == secondAdjacency;

  // Assert
  ASSERT_TRUE(result);
}
