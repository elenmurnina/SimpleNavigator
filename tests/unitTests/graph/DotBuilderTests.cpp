#include "DotBuilder.h"
#include "MatrixReader.h"
#include "VertexMapBuilder.h"
#include "gtest.h"
#include "s21_graph.h"

TEST(DotBuilderTests, BuildDotFromGraph_WithSingleElementMatrix) {
  // Arrange
  DotBuilder dotBuilder;
  MatrixReader matrixReader;
  VertexMapBuilder VertexMapBuilder;

  auto graph = Graph(matrixReader, VertexMapBuilder, dotBuilder);
  graph.loadGraphFromFile(
      "./unitTests/graph/testData/MatrixWithSingleElement.txt");
  std::string expectedDot = "graph fancyGraph {\n"
                            "\t1 -- 1 [label = \"100\"];\n"
                            "}\n";

  // Act
  std::string resultDot = dotBuilder.buildDotFromGraph(graph);

  // Assert
  ASSERT_EQ(resultDot, expectedDot);
}

TEST(DotBuilderTests, BuildDotFromGraph_WithUndirectedUnweightedGraphMatrix) {
  // Arrange
  DotBuilder dotBuilder;
  MatrixReader matrixReader;
  VertexMapBuilder VertexMapBuilder;

  auto graph = Graph(matrixReader, VertexMapBuilder, dotBuilder);
  graph.loadGraphFromFile(
      "./unitTests/graph/testData/UndirectedUnweightedGraphMatrix.txt");
  std::string expectedDot = "graph fancyGraph {\n"
                            "\t1 -- 2;\n"
                            "\t1 -- 4;\n"
                            "\n"
                            "\t2 -- 3;\n"
                            "\t2 -- 4;\n"
                            "}\n";

  // Act
  std::string resultDot = dotBuilder.buildDotFromGraph(graph);

  // Assert
  ASSERT_EQ(resultDot, expectedDot);
}

TEST(DotBuilderTests, BuildDotFromGraph_WithUndirectedWeightedGraphMatrix) {
  // Arrange
  DotBuilder dotBuilder;
  MatrixReader matrixReader;
  VertexMapBuilder VertexMapBuilder;

  auto graph = Graph(matrixReader, VertexMapBuilder, dotBuilder);
  graph.loadGraphFromFile(
      "./unitTests/graph/testData/UndirectedWeightedGraphMatrix.txt");
  std::string expectedDot = "graph fancyGraph {\n"
                            "\t1 -- 2 [label = \"4\"];\n"
                            "\t1 -- 4 [label = \"1\"];\n"
                            "\n"
                            "\t2 -- 3 [label = \"5\"];\n"
                            "\t2 -- 4 [label = \"3\"];\n"
                            "}\n";

  // Act
  std::string resultDot = dotBuilder.buildDotFromGraph(graph);

  // Assert
  ASSERT_EQ(resultDot, expectedDot);
}

TEST(DotBuilderTests, BuildDotFromGraph_WithDirectedWeightedGraphMatrix) {
  // Arrange
  DotBuilder dotBuilder;
  MatrixReader matrixReader;
  VertexMapBuilder VertexMapBuilder;

  auto graph = Graph(matrixReader, VertexMapBuilder, dotBuilder);
  graph.loadGraphFromFile(
      "./unitTests/graph/testData/DirectedWeightedGraphMatrix.txt");
  std::string expectedDot = "digraph fancyGraph {\n"
                            "\t1 -> 4 [label = \"1\"];\n"
                            "\n"
                            "\t2 -> 1 [label = \"4\"];\n"
                            "\n"
                            "\t3 -> 2 [label = \"5\"];\n"
                            "\n"
                            "\t4 -> 1 [label = \"1\"];\n"
                            "\t4 -> 2 [label = \"3\"];\n"
                            "}\n";

  // Act
  std::string resultDot = dotBuilder.buildDotFromGraph(graph);

  // Assert
  ASSERT_EQ(resultDot, expectedDot);
}

TEST(DotBuilderTests, BuildDotFromGraph_WithDirectedUnweightedGraphMatrix) {
  // Arrange
  DotBuilder dotBuilder;
  MatrixReader matrixReader;
  VertexMapBuilder VertexMapBuilder;

  auto graph = Graph(matrixReader, VertexMapBuilder, dotBuilder);
  graph.loadGraphFromFile(
      "./unitTests/graph/testData/DirectedUnweightedGraphMatrix.txt");
  std::string expectedDot = "digraph fancyGraph {\n"
                            "\t1 -> 4;\n"
                            "\n"
                            "\t2 -> 1;\n"
                            "\n"
                            "\t3 -> 2;\n"
                            "\n"
                            "\t4 -> 1;\n"
                            "\t4 -> 2;\n"
                            "}\n";

  // Act
  std::string resultDot = dotBuilder.buildDotFromGraph(graph);

  // Assert
  ASSERT_EQ(resultDot, expectedDot);
}
