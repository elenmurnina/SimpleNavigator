#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

#include "Constants.h"
#include "s21_graph.h"

Graph::Graph(IMatrixReader const &matrixReader,
             IVertexMapBuilder const &vertexMapBuilder,
             IDotBuilder const &dotBuilder)
    : _matrixReader(matrixReader),
      _vertexMapBuilder(vertexMapBuilder),
      _dotBuilder(dotBuilder) {}

GraphProperties Graph::determineGraphProperties(weight **adjacencyMatrix,
                                                int matrixSize) const {
  bool isDirected = false;
  bool isWeighted = false;

  for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < matrixSize; j++) {
      if (adjacencyMatrix[i][j] != 1 && adjacencyMatrix[i][j] != 0) {
        isWeighted = true;
      }
      if (adjacencyMatrix[i][j] != adjacencyMatrix[j][i]) {
        isDirected = true;
      }

      if ((isWeighted && isDirected)) {
        return GraphProperties{.isDirected = isDirected,
                               .isWeighted = isWeighted};
      }
    }
  }

  return GraphProperties{.isDirected = isDirected, .isWeighted = isWeighted};
}

void Graph::loadGraphFromFile(std::string const &filename) {
  if (_isInitialized) {
    for (int i = 0; i < _matrixSize; i++) {
      delete[] _adjecencyMatrix[i];
      delete _vertexMap.at(i + 1);
    }

    delete[] _adjecencyMatrix;
  }

  std::ifstream file(filename);
  if (!file.good()) {
    file.clear();
    throw std::invalid_argument("file could not be opened");
  }

  try {
    _matrixSize = _matrixReader.readMatrixSize(file);
    _adjecencyMatrix = _matrixReader.readAdjacencyMatrix(file, _matrixSize);
  } catch (std::invalid_argument ex) {
	  file.close();
    throw ex;
  }

  _vertexMap =
      _vertexMapBuilder.buildVerticesMap(_adjecencyMatrix, _matrixSize);
  _graphProperties = determineGraphProperties(_adjecencyMatrix, _matrixSize);
  _isInitialized = true;

  file.close();
}

void Graph::exportGraphToDot(std::string const &filename) {
  std::ofstream file(filename);
  if (!file.good()) {
    file.clear();
    throw std::invalid_argument("file could not be opened or created");
  }

  file << _dotBuilder.buildDotFromGraph(*this);

  file.close();
}

Vertex const &Graph::getVertexById(vertex_id vertexId) const {
  if (!_isInitialized) {
    throw std::invalid_argument("matrix is not initialized");
  }
  if (_vertexMap.find(vertexId) == _vertexMap.end()) {
    throw std::out_of_range("vertex index " + std::to_string(vertexId) +
                            " is not present in the adjecency matrix");
  }

  return *(_vertexMap.at(vertexId));
}

int Graph::getMatrixSize() const {
  if (_isInitialized) {
    return _matrixSize;
  } else {
    throw std::invalid_argument("matrix is not initialized");
  }
}

weight **Graph::getAdjacencyMatrix() const {
  if (_isInitialized) {
    return _adjecencyMatrix;
  } else {
    throw std::invalid_argument("matrix is not initialized");
  }
}

bool Graph::isWeighted() const {
  if (_isInitialized) {
    return _graphProperties.isWeighted;
  } else {
    throw std::invalid_argument("matrix is not initialized");
  }
}

bool Graph::isDirected() const {
  if (_isInitialized) {
    return _graphProperties.isDirected;
  } else {
    throw std::invalid_argument("matrix is not initialized");
  }
}

bool Graph::isInitialized() const {
  return _isInitialized;
}

Graph::~Graph() {
  if (_isInitialized) {
    for (int i = 0; i < _matrixSize; i++) {
      delete[] _adjecencyMatrix[i];
      delete _vertexMap.at(i + 1);
    }

    delete[] _adjecencyMatrix;
  }
}
