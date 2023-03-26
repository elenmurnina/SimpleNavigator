#include "DotBuilder.h"

#include <sstream>
#include <unordered_set>

bool DotBuilder::isGraphDirected(weight **adjacencyMatrix,
                                 int matrixSize) const noexcept {
  for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < matrixSize; j++) {
      if (adjacencyMatrix[i][j] != adjacencyMatrix[j][i]) {
        return true;
      }
    }
  }

  return false;
}

std::string DotBuilder::buildWeightLabel(weight weight) const noexcept {
  return " [label = \"" + std::to_string(weight) + "\"]";
}

std::string DotBuilder::buildDotFromGraph(IGraph const &graph) const noexcept {
  std::string const graphName = "fancyGraph";

  std::stringstream dotResult;

  if (graph.isDirected()) {
    dotResult << "digraph"
              << " " << graphName << " {";

    for (vertex_id id = 1; id <= graph.getMatrixSize(); id++) {
      // Используем, чтобы разделить свзязи вершин по секциям
      bool firstPrint = true;
      Vertex vertex = graph.getVertexById(id);

      for (Adjacency const &adjacency : vertex.getAdjacencies()) {
        if (firstPrint) {
          dotResult << std::endl;
          firstPrint = false;
        }
        dotResult << "\t" << vertex.getId();
        dotResult << " "
                  << "->"
                  << " ";
        dotResult << adjacency.getVertex().getId();
        if (graph.isWeighted()) {
          dotResult << buildWeightLabel(adjacency.getWeight());
        }
        dotResult << ";" << std::endl;
      }
    }
  } else {
    dotResult << "graph"
              << " " << graphName << " {";
    std::unordered_set<vertex_id> visitedVerticesSet;

    for (vertex_id id = 1; id <= graph.getMatrixSize(); id++) {
      // Используем, чтобы разделить свзязи вершин по секциям
      bool firstPrint = true;
      Vertex const &vertex = graph.getVertexById(id);

      for (Adjacency const &adjacency : vertex.getAdjacencies()) {
        if (visitedVerticesSet.count(adjacency.getVertex().getId()) != 1) {
          if (firstPrint) {
            dotResult << std::endl;
            firstPrint = false;
          }
          dotResult << "\t" << vertex.getId();
          dotResult << " "
                    << "--"
                    << " ";
          dotResult << adjacency.getVertex().getId();
          if (graph.isWeighted()) {
            dotResult << buildWeightLabel(adjacency.getWeight());
          }
          dotResult << ";" << std::endl;
        }
      }

      visitedVerticesSet.insert(vertex.getId());
    }
  }

  dotResult << "}" << std::endl;
  return dotResult.str();
}
