#include <iostream>
#include "graph.h"

void testAddVertex() {
    Graph graph;
    graph.add_vertex('A');
    graph.add_vertex('B');
    graph.add_vertex('C');

    std::cout << "Vertex 'A' added to the graph." << std::endl;
    std::cout << "Vertex 'B' added to the graph." << std::endl;
    std::cout << "Vertex 'C' added to the graph." << std::endl;
}

void testAddEdge() {
    Graph graph;
    graph.add_vertex('A');
    graph.add_vertex('B');
    graph.add_vertex('C');

    graph.add_edge('A', 'B', 5);
    graph.add_edge('A', 'C', 10);
    graph.add_edge('B', 'C', 3);

    std::cout << "Edge between vertices 'A' and 'B' added to the graph with weight 5." << std::endl;
    std::cout << "Edge between vertices 'A' and 'C' added to the graph with weight 10." << std::endl;
    std::cout << "Edge between vertices 'B' and 'C' added to the graph with weight 3." << std::endl;
}

void testShortestPath() {
    Graph graph;
    graph.add_vertex('A');
    graph.add_vertex('B');
    graph.add_vertex('C');

    graph.add_edge('A', 'B', 5);
    graph.add_edge('A', 'C', 10);
    graph.add_edge('B', 'C', 3);

    std::vector<char> shortestPath = graph.shortest_path('A', 'C');

    std::cout << "Shortest Path from vertex 'A' to vertex 'C': ";
    for (char vertex : shortestPath) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;
}

void testMinSpanTree() {
    Graph graph;
    graph.add_vertex('A');
    graph.add_vertex('B');
    graph.add_vertex('C');

    graph.add_edge('A', 'B', 5);
    graph.add_edge('A', 'C', 10);
    graph.add_edge('B', 'C', 3);

    std::vector<Edge*> minSpanTree = graph.min_span_tree();

    std::cout << "Minimum Spanning Tree Edges: ";
    for (Edge* edge : minSpanTree) {
        std::cout << "(" << edge->source->name << ", " << edge->destination->name << ") ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Testing Add Vertex Functionality:" << std::endl;
    testAddVertex();
    std::cout << std::endl;

    std::cout << "Testing Add Edge Functionality:" << std::endl;
    testAddEdge();
    std::cout << std::endl;

    std::cout << "Testing Shortest Path Functionality:" << std::endl;
    testShortestPath();
    std::cout << std::endl;

    std::cout << "Testing Minimum Spanning Tree Functionality:" << std::endl;
    testMinSpanTree();
    std::cout << std::endl;

    return 0;
}
