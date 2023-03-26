# SimpleNavigator

Implementation of the Simple Navigator project. Working with graphs and graph algorithms using the console interface.
Prepare full coverage of the Graph and the GraphAlgorithms classes methods with unit-tests.


## Contents

1. [Introduction](#introduction)
2. [Algorithms](#algorithms) \
    2.1. [Depth- and breadth-first-search](#depth--and-breadth-first-search)  
    2.2. [Finding the shortest paths in a graph](#finding-the-shortest-paths-in-a-graph)  
    2.3. [Finding the minimum spanning tree](#finding-the-minimum-spanning-tree)  
    2.4. [Travelling salesman problem](#travelling-salesman-problem)  
    2.5. [Console interface](#console-interface)


## Introduction

In this project you will implement several basic algorithms on graphs. Graphs are one of the basic data structures in programming that are used everywhere. Graphs can be used, for example, to interpret road maps, electrical circuits, geographic maps, for communication between people in social networks, and many other things.  

### Ways of representing a graph
You can find an example of representing a graph with an adjacency matrix in the materials.

## Algorithms

Within this task, all graphs must meet the following requirements:
- Edge weights are only natural numbers
- There may be loops
- Weights may differ on all edges
- Only a nonzero connected graph

## Depth- and Breadth-first search 

Implementation of the _s21_graph.h_  library:
* When writing code it is necessary to follow the Google style
* Make it as a static library (with the _s21_graph.h_ header file)
* The library must be represented as a `Graph` class that stores information about the graph using an **adjacency matrix**. The dimensionality of the adjacency matrix should be set dynamically when initializing the graph (when loading it from a file)
*Prepare full coverage of the `Graph` class methods with unit-tests
* The class `Graph` must contain at least the following public methods:
    + `loadGraphFromFile(string filename)` - loading a graph from a file in the adjacency matrix format
    + `exportGraphToDot(string filename)`- exporting a graph to a dot file (see materials)

Implementation of the _s21_graph_algorithms.h_ library:  
* Make it as a static library (with the _s21_graph_algorithms.h_ header file)
*Prepare full coverage of the `GraphAlgorithms` class methods with unit-tests
* The class ` GraphAlgorithms ` must contain at least the following public methods:
    + `depthFirstSearch(Graph &graph, int startVertex)` - a *non-recursive* depth-first search in the graph from a given vertex. The function should return an array that contains the traversed vertices in the order they were traversed. When implementing this function, you must use the *self-written* data structure **stack**, which should be previously made as a separate static library
    + `breadthFirstSearch(Graph &graph, int startVertex)` - breadth-first search in the graph from a given vertex. The function should return an array that contains the traversed vertices in the order they were traversed. When implementing this function, you must use the *self-written* data structure **queue**, which should be previously made as a separate static library
* It is necessary to use *self-written* helper classes `Stack` and `Queue` (you can reuse your solution from the *CPP2* project for this). These classes must contain the following methods:
    + `init()` - creating an empty stack/queue
    + `push(value)` - adding an element to the stack/queue
    + `pop()` - getting an element from the stack/queue followed by its removal from the stack/queue
    + `peek()` - getting an element from the stack/queue without its removal from the stack/queue

*In this and the following tasks, consider that the vertex numbers start from 1*

## Finding the shortest paths in a graph

* Add two new methods to the `GraphAlgorithms` class:
    + `getShortestPathBetweenVertices(Graph &graph, int vertex1, int vertex2)` - searching for the shortest path between two vertices in a graph using *Dijkstra's algorithm*. The function accepts as input the numbers of two vertices and returns a numerical result equal to the smallest distance between them
    + `getShortestPathsBetweenAllVertices(Graph &graph)` - searching for the shortest paths between all pairs of vertices in a graph using the *Floyd-Warshall algorithm*. As a result, the function returns the matrix of the shortest paths between all vertices of the graph

## Finding the minimum spanning tree

* Add a new method to the `GraphAlgorithms` class:
    + `getLeastSpanningTree(Graph &graph)` - searching for the minimal spanning tree in a graph using *Prim's algorithm*. As a result, the function should return the adjacency matrix for the minimal spanning tree

## Travelling salesman problem

* Add a new method to the `GraphAlgorithms` class:
    + `solveTravelingSalesmanProblem(Graph &graph)` - solving the traveling salesman's problem using the *ant colony algorithm*.
You need to find the shortest path that goes through all vertices of the graph at least once, followed by a return to the original vertex. As a result, the function should return the `TsmResult` structure described below:
    ```cpp
    struct TsmResult {
        int* vertices;    // an array with the route you are looking for (with the vertex traverse order). Instead of int* you can use std::vector<int>
        double distance;  // the length of this route
    }
    ``` 

*If it is impossible to solve the problem with a given graph, output an error.*

## Console interface

* You need to write the main program, which is a console application for testing the functionality of the implemented s21_graph.h and s21_graph_algorithms.h libraries 
* The console interface must provide the following functionality:
    1. loading the original graph from a file
    2. graph traversal in breadth with output of the result to the console   
    3. graph traversal in depth with output of the result to the console
    4. searching for the shortest path between any two vertices and displaying the result to the console
    5. searching for the shortest paths between all pairs of vertices in the graph with the output of the resulting matrix to the console
    6. searching for the minimal spanning tree in the graph with the output of the resulting adjacency matrix to the console
    7. solving the salesman problem with the output of the resulting route and its length to the console
