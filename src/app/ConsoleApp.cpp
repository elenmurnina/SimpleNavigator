#include "ConsoleApp.h"

#include "StringUtils.h"
#include "s21_graph.h"
#include "s21_graph_algorithms.h"
#include "MatrixReader.h"
#include "VertexMapBuilder.h"
#include "DotBuilder.h"
#include <limits>

void		ConsoleApp::askToPressAnyKey()
{
  std::cout << "Press ENTER to continue . . . ";
  std::cin.ignore();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

bool		ConsoleApp::tryParseIntFromInput(int &num)
{
    std::string input;
    std::cin >> input;
	StringUtils::trim(input);

    try {
		num = std::stoi(input);
    } catch (const std::exception &e) {
      return false;
    }

    return true;
}

command ConsoleApp::getCommand() {
  while (true) {
  std::cout << std::endl
            << "\n_____________________________________________________________\n"
            "Please, choose an action, then hit a number and press 'enter': \n"
            "#1: load graph from file (do this first if you haven't done it "
            "yet)\n"
            "#2: breadth first search\n"
            "#3: depth first search\n"
            "#4: shortest path between a pair of vertices\n"
            "#5: shortest path between all vertices\n"
            "#6: least spanning tree\n"
            "#7: solve travelling salesman problem\n"
            "#8: quit the program\n"
            "_____________________________________________________________"
            << std::endl;

    int number;
    if (!tryParseIntFromInput(number))
    {
      std::cout << "invalid input. Input should be of integer type. Try again." << std::endl;
      askToPressAnyKey();
      continue;
    }

    if (number > MAX_COMMAND || number < MIN_COMMAND) {
      std::cout << number
                << " is out of bounds of expected command numbers. Try again" << std::endl;
      askToPressAnyKey();
      continue;
    }

    return (enum command) number;
  }
}

void ConsoleApp::executeCommand(command command, Graph &graph) {
  switch (command) {
    case loadGraph:
    {
      std::cout << "Please, provide the filename to export from: " << std::endl;
      std::string filename;
      std::cin >> filename;
      graph.loadGraphFromFile(filename);
      std::cout << "Graph has been successfully loaded!" << std::endl;
	    break;
    }
    case breadthFirstSearch:
    {
      GraphAlgorithms graphAlgos;

      std::cout << "Please, provide vertex number to start searching from: ";
      vertex_id vertexId;
      if (!tryParseIntFromInput(vertexId))
      {
        std::cout << "invalid input. Input should be of integer type. Try again." << std::endl;
        return;
      }
      if (vertexId >= graph.getMatrixSize() || vertexId < 1)
      {
        std::cout << "out of boudns of expected vetex ids. Try again." << std::endl;
        return;
      }

      std::__1::vector<vertex_id> result = graphAlgos.breadthFirstSearch(graph, vertexId);
      std::cout << "result: ";
      for (vertex_id id : result) {
        std::cout << id << " ";
      }
      std::cout << std::endl;

      break;
    }
    case depthFirstSearch:
    {
      GraphAlgorithms graphAlgos;
      std::cout << "Please, provide vertex number to start searching from: ";
      vertex_id vertexId;
      if (!tryParseIntFromInput(vertexId))
      {
        std::cout << "invalid input. Input should be of integer type. Try again." << std::endl;
        return;
      }
      if (vertexId >= graph.getMatrixSize() || vertexId < 1)
      {
        std::cout << "out of boudns of expected vetex ids. Try again." << std::endl;
        return;
      }

      std::__1::vector<vertex_id> result = graphAlgos.depthFirstSearch(graph, vertexId);
      std::cout << "result: ";
      for (vertex_id id : result) {
        std::cout << id << " ";
      }
      std::cout << std::endl;
      break;
    }
    case shortestBetweenTwo:
    {
      GraphAlgorithms graphAlgos;
      std::cout << "Please, provide first vertex id: ";
      vertex_id firstVertexId;
      if (!tryParseIntFromInput(firstVertexId))
      {
        std::cout << "invalid input. Input should be of integer type. Try again." << std::endl;
        return;
      }
      if (firstVertexId >= graph.getMatrixSize() || firstVertexId < 1)
      {
        std::cout << "out of boudns of expected vetex ids. Try again." << std::endl;
        return;
      }

      std::cout << "Please, provide second vertex id: ";
      vertex_id secondVetexId;
      if (!tryParseIntFromInput(secondVetexId))
      {
        std::cout << "invalid input. Input should be of integer type. Try again." << std::endl;
        return;
      }
      if (secondVetexId >= graph.getMatrixSize() || secondVetexId < 1)
      {
        std::cout << "out of boudns of expected vetex ids. Try again." << std::endl;
        return;
      }

      distance result = graphAlgos.getShortestPathBetweenVertices(graph, firstVertexId, secondVetexId);
      std::cout << "result: " << result << std::endl;
      break;
    }
    case shortestBetweenAll:
    {
      GraphAlgorithms graphAlgos;
      distance **result = graphAlgos.getShortestPathsBetweenAllVertices(graph);
      std::cout << "result: " << std::endl;
      for (int i = 0; i < graph.getMatrixSize(); i++)
      {
        for (int j = 0; j < graph.getMatrixSize(); j++) {
          std::cout << result[i][j] << " ";
        }
		delete[] result[i];
        std::cout << std::endl;
      }
	  delete result;
      break;
    }
    case leastSpanningTree:
    {
      GraphAlgorithms graphAlgos;
      weight **result = graphAlgos.getLeastSpanningTree(graph);
      std::cout << "result: " << std::endl;
      for (int i = 0; i < graph.getMatrixSize(); i++)
      {
        for (int j = 0; j < graph.getMatrixSize(); j++) {
          std::cout << result[i][j] << " ";
		}
			delete[] result[i];
        std::cout << std::endl;
      }
		delete result;
		break;
    }
    case salesmanProblem:
    {
      GraphAlgorithms graphAlgos;
      TsmResult result = graphAlgos.solveTravelingSalesmanProblem(graph);
	  std::cout << "Total distance: " << result.distance << std::endl;
	  std::cout << "Path: " << std::endl;
	  for (size_t i = 0; i < result.vertices.size(); i++)
      {
		  std::cout << result.vertices[i] << " ";
      }
	  std::cout << std::endl;
      break;
    }
    default:
    {
      std::cout << "Sorry I have paws (^-人-^)" << std::endl;
    }
  }
}

void ConsoleApp::start() {

  MatrixReader matrixReader;
  VertexMapBuilder vertexMapBuilder;
  DotBuilder dotBuilder;

  Graph graph = Graph(matrixReader,
    vertexMapBuilder,
    dotBuilder);

  while (true) {
    command command = getCommand();
	if (command == quit) {
		return;
	}
    try {
      executeCommand(command, graph);
      askToPressAnyKey();
    }
    catch (std::invalid_argument &ex) {
      std::cout << "invalid argument: " << ex.what() << std::endl;
      askToPressAnyKey();
    }
    catch (std::exception &ex) {
      std::cout << "unexpected exception: " << ex.what() << std::endl;
      askToPressAnyKey();
    }
  }
}
