#include "VertexMapBuilder.h"
#include "gtest.h"
#include <filesystem>
#include <iostream>

// TODO: оставить для дебага
std::ostream &operator<<(std::ostream &os, Adjacency const &obj) {
  os << "\tAdjacency vertex id: " << obj.getVertex().getId() << std::endl;
  os << "\tAdjacency weight: " << obj.getWeight() << std::endl;
  return os;
}

// TODO: оставить для дебага
std::ostream &operator<<(std::ostream &os, Vertex const &obj) {
  os << "Vertex id: " << obj.getId() << std::endl;
  os << "Adjacency list:" << std::endl;
  for (auto &&adjacency : obj.getAdjacencies()) {
    os << std::endl;
    os << adjacency << std::endl;
  }

  os << std::endl << std::endl;
  return os;
}

TEST(VertexMapBuilderTests,
     BuildVerticesMap_UndirectredGraph_ReturnsValidGraph) {
  // Arrange
  VertexMapBuilder vertexMapBuilder;
  const int size = 4;
  weight matrix[size][size] = {
      {0, 29, 20, 21}, {29, 0, 15, 29}, {20, 15, 0, 15}, {21, 29, 15, 0}};
  // Да, костыль, ну а что поделать!?
  weight *indexMatrix[size] = {matrix[0], matrix[1], matrix[2], matrix[3]};

  // Act
  auto vertexMap = vertexMapBuilder.buildVerticesMap(indexMatrix, size);

  // Assert
  std::map<vertex_id, Vertex> expectedVertexMap = {
      {1, Vertex(1)}, {2, Vertex(2)}, {3, Vertex(3)}, {4, Vertex(4)}};

  expectedVertexMap.at(1).addAdjacency(
      Adjacency(expectedVertexMap.at(2), matrix[0][1]));
  expectedVertexMap.at(1).addAdjacency(
      Adjacency(expectedVertexMap.at(3), matrix[0][2]));
  expectedVertexMap.at(1).addAdjacency(
      Adjacency(expectedVertexMap.at(4), matrix[0][3]));
  expectedVertexMap.at(2).addAdjacency(
      Adjacency(expectedVertexMap.at(1), matrix[1][0]));
  expectedVertexMap.at(2).addAdjacency(
      Adjacency(expectedVertexMap.at(3), matrix[1][2]));
  expectedVertexMap.at(2).addAdjacency(
      Adjacency(expectedVertexMap.at(4), matrix[1][3]));
  expectedVertexMap.at(3).addAdjacency(
      Adjacency(expectedVertexMap.at(1), matrix[2][0]));
  expectedVertexMap.at(3).addAdjacency(
      Adjacency(expectedVertexMap.at(2), matrix[2][1]));
  expectedVertexMap.at(3).addAdjacency(
      Adjacency(expectedVertexMap.at(4), matrix[2][3]));
  expectedVertexMap.at(4).addAdjacency(
      Adjacency(expectedVertexMap.at(1), matrix[3][0]));
  expectedVertexMap.at(4).addAdjacency(
      Adjacency(expectedVertexMap.at(2), matrix[3][1]));
  expectedVertexMap.at(4).addAdjacency(
      Adjacency(expectedVertexMap.at(3), matrix[3][2]));

  for (vertex_id i = 1; i <= size; i++) {
    EXPECT_EQ(*(vertexMap.at(i)), expectedVertexMap.at(i));
  }
}

TEST(VertexMapBuilderTests,
     BuildVerticesMap_DirectedGraph_ReturnsValidVerticesMap) {
  // Arrange
  VertexMapBuilder vertexMapBuilder;
  const int size = 4;
  weight matrix[size][size] = {
      {0, 29, 20, 21}, {0, 0, 15, 29}, {20, 15, 0, 15}, {21, 29, 0, 0}};
  // Да, костыль, ну а что поделать!?
  weight *indexMatrix[size] = {matrix[0], matrix[1], matrix[2], matrix[3]};

  // Act
  auto vertexMap = vertexMapBuilder.buildVerticesMap(indexMatrix, size);

  // Assert
  std::map<vertex_id, Vertex> expectedVertexMap = {
      {1, Vertex(1)}, {2, Vertex(2)}, {3, Vertex(3)}, {4, Vertex(4)}};

  expectedVertexMap.at(1).addAdjacency(
      Adjacency(expectedVertexMap.at(2), matrix[0][1]));
  expectedVertexMap.at(1).addAdjacency(
      Adjacency(expectedVertexMap.at(3), matrix[0][2]));
  expectedVertexMap.at(1).addAdjacency(
      Adjacency(expectedVertexMap.at(4), matrix[0][3]));
  expectedVertexMap.at(2).addAdjacency(
      Adjacency(expectedVertexMap.at(3), matrix[1][2]));
  expectedVertexMap.at(2).addAdjacency(
      Adjacency(expectedVertexMap.at(4), matrix[1][3]));
  expectedVertexMap.at(3).addAdjacency(
      Adjacency(expectedVertexMap.at(1), matrix[2][0]));
  expectedVertexMap.at(3).addAdjacency(
      Adjacency(expectedVertexMap.at(2), matrix[2][1]));
  expectedVertexMap.at(3).addAdjacency(
      Adjacency(expectedVertexMap.at(4), matrix[2][3]));
  expectedVertexMap.at(4).addAdjacency(
      Adjacency(expectedVertexMap.at(1), matrix[3][0]));
  expectedVertexMap.at(4).addAdjacency(
      Adjacency(expectedVertexMap.at(2), matrix[3][1]));

  for (vertex_id i = 1; i <= size; i++) {
    EXPECT_EQ(*(vertexMap.at(i)), expectedVertexMap.at(i));
  }
}

TEST(VertexMapBuilderTests,
     BuildVerticesMap_GraphWithSelfAdjacentVertices_ReturnsValidGraph) {
  // Arrange
  VertexMapBuilder vertexMapBuilder;
  const int size = 4;
  weight matrix[size][size] = {
      {13, 29, 20, 21}, {29, 0, 15, 29}, {20, 15, 0, 15}, {21, 29, 15, 0}};
  // Да, костыль, ну а что поделать!?
  weight *indexMatrix[size] = {matrix[0], matrix[1], matrix[2], matrix[3]};

  // Act
  auto vertexMap = vertexMapBuilder.buildVerticesMap(indexMatrix, size);

  // Assert
  std::map<vertex_id, Vertex> expectedVertexMap = {
      {1, Vertex(1)}, {2, Vertex(2)}, {3, Vertex(3)}, {4, Vertex(4)}};

  expectedVertexMap.at(1).addAdjacency(
      Adjacency(expectedVertexMap.at(1), matrix[0][0]));
  expectedVertexMap.at(1).addAdjacency(
      Adjacency(expectedVertexMap.at(2), matrix[0][1]));
  expectedVertexMap.at(1).addAdjacency(
      Adjacency(expectedVertexMap.at(3), matrix[0][2]));
  expectedVertexMap.at(1).addAdjacency(
      Adjacency(expectedVertexMap.at(4), matrix[0][3]));
  expectedVertexMap.at(2).addAdjacency(
      Adjacency(expectedVertexMap.at(1), matrix[1][0]));
  expectedVertexMap.at(2).addAdjacency(
      Adjacency(expectedVertexMap.at(3), matrix[1][2]));
  expectedVertexMap.at(2).addAdjacency(
      Adjacency(expectedVertexMap.at(4), matrix[1][3]));
  expectedVertexMap.at(3).addAdjacency(
      Adjacency(expectedVertexMap.at(1), matrix[2][0]));
  expectedVertexMap.at(3).addAdjacency(
      Adjacency(expectedVertexMap.at(2), matrix[2][1]));
  expectedVertexMap.at(3).addAdjacency(
      Adjacency(expectedVertexMap.at(4), matrix[2][3]));
  expectedVertexMap.at(4).addAdjacency(
      Adjacency(expectedVertexMap.at(1), matrix[3][0]));
  expectedVertexMap.at(4).addAdjacency(
      Adjacency(expectedVertexMap.at(2), matrix[3][1]));
  expectedVertexMap.at(4).addAdjacency(
      Adjacency(expectedVertexMap.at(3), matrix[3][2]));

  for (vertex_id i = 1; i <= size; i++) {
    EXPECT_EQ(*(vertexMap.at(i)), expectedVertexMap.at(i));
  }
}
