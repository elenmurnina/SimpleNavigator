#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <queue>
#include <unordered_set>

#include "queue.h"
#include "s21_graph_algorithms.h"
#include "stack.h"

// поиск в глубину (без рекурсии) DFS (обход всего графа от стартовой вершины)
// ориентированный или неориентированный граф
std::vector<vertex_id> GraphAlgorithms::depthFirstSearch(IGraph &graph,
                                                         int startVertex) {
  std::vector<vertex_id> traversedVertices;

  ft::stack<vertex_id> unvisitedVerticesStack;
  unvisitedVerticesStack.push(startVertex);

  std::unordered_set<vertex_id> visitedVerticesSet;

  while (!unvisitedVerticesStack.empty()) {
    vertex_id from = unvisitedVerticesStack.top();
    unvisitedVerticesStack.pop();
    if (visitedVerticesSet.count(from) == 1) {
      continue;
    }

    traversedVertices.push_back(from);
    visitedVerticesSet.insert(from);

    std::vector<Adjacency> adjacencies =
        graph.getVertexById(from).getAdjacencies();
    for (int i = int(adjacencies.size()) - 1; i >= 0; i--) {
      const Adjacency &adjacency = adjacencies[i];
      vertex_id to = adjacency.getVertex().getId();
      if (visitedVerticesSet.count(to) == 0) {
        unvisitedVerticesStack.push(to);
      }
    }
  }

  return traversedVertices;
}

// поиск в ширину BFS (обход всего графа от стартовой вершины)
// невзвешенный (ориентированный или неориентированный) граф
std::vector<vertex_id> GraphAlgorithms::breadthFirstSearch(IGraph &graph,
                                                           int startVertex) {
  std::unordered_set<vertex_id> visitedVerticesSet;
  ft::queue<vertex_id> unvisitedVerticesQueue;
  unvisitedVerticesQueue.push(startVertex);
  std::vector<vertex_id> traversedVertices;

  visitedVerticesSet.insert(startVertex);

  while (!unvisitedVerticesQueue.empty()) {
    vertex_id from = unvisitedVerticesQueue.front();
    unvisitedVerticesQueue.pop();
    traversedVertices.push_back(from);

    std::vector<Adjacency> adjacencies =
        graph.getVertexById(from).getAdjacencies();
    for (Adjacency adjacency : adjacencies) {
      vertex_id to = adjacency.getVertex().getId();
      if (visitedVerticesSet.count(to) == 0) {
        visitedVerticesSet.insert(to);
        unvisitedVerticesQueue.push(to);
      }
    }
  }

  return traversedVertices;
}

// алгоритм Дейкстры (поиск кратчайшего пути от вершины1 к вершине2)
// только для графов без рёбер отрицательного веса
distance GraphAlgorithms::getShortestPathBetweenVertices(IGraph &graph,
                                                         int vertex1,
                                                         int vertex2) {
  int sizeGraph = graph.getMatrixSize() + 1;

  std::vector<distance> distances(sizeGraph, INT_MAX);
  distances[vertex1] = 0;

  std::unordered_set<vertex_id> visitedVerticesSet;
  vertex_id minVertexId = 0;
  weight minWeight;

  while (minVertexId < INT_MAX) {
    minVertexId = INT_MAX;
    minWeight = INT_MAX;

    for (vertex_id vertexId = 1; vertexId < sizeGraph; vertexId++) {
      if (visitedVerticesSet.count(vertexId) == 0 &&
          distances[vertexId] < minWeight) {
        minVertexId = vertexId;
        minWeight = distances[vertexId];
        if (minWeight < 0) { // проверка на наличие отрицательных весов
          throw std::invalid_argument(
              "Dijkstra's algorithm only works for graphs with non-negative "
              "weights.");
        }
      }
    }

    if (minVertexId != INT_MAX) {
      std::vector<Adjacency> adjacencies =
          graph.getVertexById(minVertexId).getAdjacencies();
      for (Adjacency adjacency : adjacencies) {
        vertex_id to = adjacency.getVertex().getId();
        if ((minWeight + adjacency.getWeight()) < distances[to]) {
          distances[to] = (minWeight + adjacency.getWeight());
        }
      }
      visitedVerticesSet.insert(minVertexId);
    }
  }

  return distances[vertex2] - distances[vertex1];
}

std::vector<int> GraphAlgorithms::getShortestPathVectorBetweenVertices(
    IGraph &graph, int vertex1, int vertex2) {
  int sizeGraph = graph.getMatrixSize() + 1;

  std::vector<distance> distances(sizeGraph, INT_MAX);
  std::vector<distance> parents(sizeGraph, -1);
  parents[vertex1] = vertex1;
  distances[vertex1] = 0;

  std::unordered_set<vertex_id> visitedVerticesSet;
  vertex_id minVertexId = 0;
  weight minWeight;

  while (minVertexId < INT_MAX) {
    minVertexId = INT_MAX;
    minWeight = INT_MAX;

    for (vertex_id vertexId = 1; vertexId < sizeGraph; vertexId++) {
      if (visitedVerticesSet.count(vertexId) == 0 &&
          distances[vertexId] < minWeight) {
        minVertexId = vertexId;
        minWeight = distances[vertexId];
      }
    }

    if (minVertexId != INT_MAX) {
      std::vector<Adjacency> adjacencies =
          graph.getVertexById(minVertexId).getAdjacencies();
      for (Adjacency adjacency : adjacencies) {
        vertex_id to = adjacency.getVertex().getId();
        if ((minWeight + adjacency.getWeight()) < distances[to]) {
          distances[to] = (minWeight + adjacency.getWeight());
          parents[to] = minVertexId;
        }
      }
      visitedVerticesSet.insert(minVertexId);
    }
  }

  // восстанавливаем кратчайший путь
  std::vector<int> result(1, vertex2);
  while (parents[vertex2] != vertex2) {
    result.push_back(parents[vertex2]);
    vertex2 = parents[vertex2];
  }
  std::reverse(result.begin(), result.end());

  return result;
}

// алгоритм Флойда-Уоршелла (поиск кратчайших путей между всеми парами вершин во
// взвешенном ориентированном или неориентированном графе с положительным или
// отрицательным весом ребер (но без отрицательных циклов))
distance **GraphAlgorithms::getShortestPathsBetweenAllVertices(IGraph &graph) {
  distance sizeGraph = graph.getMatrixSize();
  weight **adjacencyMatrix = graph.getAdjacencyMatrix();

  distance **distances = new distance *[sizeGraph];
  for (distance i = 0; i < sizeGraph; i++) {
    distances[i] = new distance[sizeGraph];
    for (distance j = 0; j < sizeGraph; j++) {
      distances[i][j] = (i == j ? 0 : INT_MAX);
    }
  }

  for (distance i = 0; i < sizeGraph; i++) {
    for (distance j = 0; j < sizeGraph; j++) {
      if (adjacencyMatrix[i][j] != 0) {
        distances[i][j] = std::min(distances[i][j], adjacencyMatrix[i][j]);
      }
      // проверка на наличие отрицательного цикла
      if (adjacencyMatrix[i][j] < 0 &&
          adjacencyMatrix[i][j] == adjacencyMatrix[j][i]) {
        // очищаем память
        for (int d = 0; d < sizeGraph; d++) {
          delete[] distances[d];
        }
        delete[] distances;
        throw std::invalid_argument(
            "Floyd-Warshall algorithm only works for graphs without negative "
            "cycles.");
      }
    }
  }

  // идем по всем вершинам и ищем более короткий путь через вершину k
  for (vertex_id k = 0; k < sizeGraph; k++) {
    for (vertex_id i = 0; i < sizeGraph; i++) {
      for (vertex_id j = 0; j < sizeGraph; j++) {
        // защита от переполнения
        if (distances[i][k] != INT_MAX && distances[k][j] != INT_MAX) {
          // Новое значение ребра равно минимальному между старым ребром и
          // суммой ребер
          distances[i][j] =
              std::min(distances[i][j], distances[i][k] + distances[k][j]);
        }
      }
    }
  }

  return distances;
}

// Алгоритм Прима
// построение минимального остовного дерева взвешенного связного
// неориентированного графа
weight **GraphAlgorithms::getLeastSpanningTree(IGraph &graph) {
  distance sizeGraph = graph.getMatrixSize();

  weight **adjacencyMatrixLeastSpanningTree = new weight *[sizeGraph];
  for (vertex_id i = 0; i < sizeGraph; i++) {
    adjacencyMatrixLeastSpanningTree[i] = new weight[sizeGraph];
    // заполняем матрицу нулями
    memset(adjacencyMatrixLeastSpanningTree[i], 0, sizeGraph * sizeof(weight));
  }

  // приоритетная очередь, содержащая ребро в виде пары:
  // {вес, {id вершины куда, id вершины откуда}}
  std::priority_queue<
      std::pair<weight, std::pair<vertex_id, vertex_id>>,
      std::vector<std::pair<weight, std::pair<vertex_id, vertex_id>>>,
      std::greater<std::pair<weight, std::pair<vertex_id, vertex_id>>>>
      unvisitedVerticesQueue;
  unvisitedVerticesQueue.push({0, {1, -1}}); // начинаем с вершины 1, предка нет
  std::unordered_set<vertex_id> includedVerticesInSpanningTree;

  while (!unvisitedVerticesQueue.empty()) {
    std::pair<weight, std::pair<vertex_id, vertex_id>> from =
        unvisitedVerticesQueue.top();
    unvisitedVerticesQueue.pop();

    weight weightFrom = from.first;
    vertex_id vertexId = from.second.first;
    vertex_id vertexIdFrom = from.second.second;

    // проверяем добавлена ли вершина в остовное дерево
    if (includedVerticesInSpanningTree.count(vertexId) == 1) {
      continue;
    }

    // добавляем вершину в остовное дерево
    includedVerticesInSpanningTree.insert(vertexId);
    if (vertexIdFrom != -1) {
      // заполняем матрицу смежности для минимального остовного дерева
      adjacencyMatrixLeastSpanningTree[vertexId - 1][vertexIdFrom - 1] =
          weightFrom;
      adjacencyMatrixLeastSpanningTree[vertexIdFrom - 1][vertexId - 1] =
          weightFrom;
    }

    std::vector<Adjacency> adjacencies =
        graph.getVertexById(vertexId).getAdjacencies();

    for (Adjacency adjacency : adjacencies) {
      weight weightTo = adjacency.getWeight();
      vertex_id vertexIdTo = adjacency.getVertex().getId();

      if (includedVerticesInSpanningTree.count(vertexIdTo) == 0) {
        // добавляем ребро в очередь
        unvisitedVerticesQueue.push({weightTo, {vertexIdTo, vertexId}});
      }
    }
  }

  return adjacencyMatrixLeastSpanningTree;
}

// функция считает вероятности перехода в каждую из вершин и возвращает лучшую
vertex_id getNext(Ant ant, double **pheromone, double **distances,
                  int sizeGraph) {
  std::vector<std::pair<vertex_id, double>> result;

  double sum = 0.0;
  vertex_id from = ant.path.back();

  // считаем сумму в знаменателе
  for (vertex_id i = 0; i < sizeGraph; i++) {
    if (ant.tabu.count(i) == 0) {
      sum += pow(pheromone[from][i], ALPHA) * pow(distances[from][i], BETA);
    }
  }

  for (vertex_id i = 0; i < sizeGraph; i++) {
    // если вершина i не посещена считаем вероятность перехода в неё
    if (ant.tabu.count(i) == 0) {
      result.emplace_back(i, pow(pheromone[from][i], ALPHA) *
                                 pow(distances[from][i], BETA) / sum);
    }
  }

  if (result.empty()) {
    return -1;
  }

  double x = rand() / double(RAND_MAX); // рандомное число от 0 до 1
  for (size_t i = 0; i < result.size() - 1; i++) {
    if (x < result[i].second) {
      return result[i].first;
    } else {
      x -= result[i].second;
    }
  }

  return result.back().first;
}

// решение задачи коммивояжера с помощью муравьиного алгоритма
// нахождение самого выгодного (короткого) маршрута,
// проходящего через все вершины графа хотя бы по одному разу с возвратом в
// исходную вершину
TsmResult GraphAlgorithms::solveTravelingSalesmanProblem(IGraph &graph) {
  distance sizeGraph = graph.getMatrixSize();

  // инициализация данных о лучшем маршруте
  TsmResult result;
  result.distance = INT_MAX;

  // с помощью алгоритма Флойда-Уоршелла ищем матрицу весов кратчайших путей
  // между всеми парами вершин
  distance **weightMatrix = getShortestPathsBetweenAllVertices(graph);

  // инициализация данных о расстоянии и количестве феромона
  double **distances = new double *[sizeGraph];
  double **pheromone = new double *[sizeGraph];

  for (vertex_id i = 0; i < sizeGraph; i++) {
    distances[i] = new double[sizeGraph];
    pheromone[i] = new double[sizeGraph];
    for (vertex_id j = 0; j < sizeGraph; j++) {
      if (i != j) {
        distances[i][j] = 1.0 / weightMatrix[i][j];
        pheromone[i][j] = 1.0 / sizeGraph;
      }
    }
  }

  // инициализация муравьев
  Ant ants[CNT_ANTS];

  // время жизни муравьиной колонии
  for (int t = 0; t < T_MAX; t++) {

    // цикл по муравьям
    for (auto &ant : ants) {
      // инициализация муравья
      ant.distance = 0.0;
      ant.tabu.clear();
      ant.tabu.insert(0);
      ant.path.clear();
      ant.path.push_back(0);

      // поиск маршрута для a-го муравья
      while (true) { // пока не посетим все вершины
        // получаем следущую вершину высчитывая вероятности
        vertex_id to = getNext(ant, pheromone, distances, sizeGraph);
        if (to == -1) {
          break;
        }

        ant.distance += weightMatrix[ant.path.back()][to];
        ant.tabu.insert(to);
        ant.path.push_back(to);
      }

      ant.distance += weightMatrix[ant.path.back()][0];
      ant.path.push_back(0);

      // проверка на лучшее решение и обновление пути
      if (ant.distance < result.distance) {
        result.distance = ant.distance;
        result.vertices = ant.path;
      }
    }

    // цикл по ребрам
    for (vertex_id i = 0; i < sizeGraph; i++) {
      for (vertex_id j = 0; j < sizeGraph; j++) {
        // испарение феромона для ребра (i, j)
        if (i != j) {
          pheromone[i][j] *= PH_EVAROPATION;
        }
      }
    }

    // оставляем феромон на пути муравья
    for (auto &ant : ants) {
      for (size_t i = 0; i < ant.path.size() - 1; i++) {
        vertex_id from = ant.path[i];
        vertex_id to = ant.path[i + 1];
        pheromone[from][to] += Q_PH / ant.distance;
      }
    }
  }

  std::vector<int> newVertices(1, 1);
  for (size_t i = 0; i < result.vertices.size(); i++) {
    result.vertices[i]++; // возвращаем 1-индексацию
    if (i > 0) {
      // с помощью алгоритма Дейкстры восстанавливаем кратчайший путь
      std::vector<int> shortestPath = getShortestPathVectorBetweenVertices(
          graph, result.vertices[i - 1], result.vertices[i]);
      newVertices.insert(newVertices.end(), shortestPath.begin() + 1,
                         shortestPath.end());
    }
  }
  result.vertices = newVertices;

  for (vertex_id i = 0; i < sizeGraph; i++) {
    delete[] distances[i];
    delete[] weightMatrix[i];
    delete[] pheromone[i];
  }
  delete[] distances;
  delete[] pheromone;
  delete[] weightMatrix;

  // возвращаем кратчайший маршрут
  return result;
}
