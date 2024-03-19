#pragma once
#include <unordered_map>
#include <vector>
#include <queue>
#include "graph_node.h"
#include "edge.h"

// Define INT_MAX
constexpr int INF = 1e9;

class Graph {
private:
    std::unordered_map<char, GraphNode*> vertices;
    std::vector<Edge*> edges;

public:
    // Constructor
    Graph() {}

    // Destructor
    ~Graph() {
        // Clean up dynamically allocated memory
        for (auto it = vertices.begin(); it != vertices.end(); ++it)
            delete it->second;
        for (Edge* edge : edges)
            delete edge;
    }

    // Function to add a new vertex to the graph
    void add_vertex(char name) {
        if (vertices.find(name) == vertices.end()) {
            GraphNode* newNode = new GraphNode{name};
            vertices[name] = newNode;
        }
    }

    // Function to add a new edge between two vertices of the graph
    void add_edge(char source, char destination, int weight) {
        if (vertices.find(source) != vertices.end() && vertices.find(destination) != vertices.end()) {
            Edge* newEdge = new Edge{weight, vertices[source], vertices[destination]};
            edges.push_back(newEdge);
            vertices[source]->neighbors.push_back(newEdge);
        }
    }

    // Function for Dijkstra's shortest path algorithm
    std::vector<char> shortest_path(char source, char destination) {
        std::unordered_map<char, char> parent;
        std::unordered_map<char, int> distance;
        std::priority_queue<std::pair<int, char>, std::vector<std::pair<int, char>>, std::greater<std::pair<int, char>>> pq;

        for (auto& pair : vertices) {
            distance[pair.first] = INF;
        }

        distance[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            char u = pq.top().second;
            pq.pop();

            for (Edge* edge : vertices[u]->neighbors) {
                char v = edge->destination->name;
                int weight = edge->weight;
                if (distance[v] > distance[u] + weight) {
                    distance[v] = distance[u] + weight;
                    parent[v] = u;
                    pq.push({distance[v], v});
                }
            }
        }

        std::vector<char> path;
        char current = destination;
        while (current != source) {
            path.push_back(current);
            current = parent[current];
        }
        path.push_back(source);
        reverse(path);
        return path;
    }

    // Function for Kruskal's minimum spanning tree algorithm
    std::vector<Edge*> min_span_tree() {
        std::vector<Edge*> result;
        sort_edges();

        std::unordered_map<char, char> parent;
        for (auto& pair : vertices) {
            parent[pair.first] = pair.first;
        }

        for (Edge* edge : edges) {
            char u = edge->source->name;
            char v = edge->destination->name;

            char u_parent = find_parent(parent, u);
            char v_parent = find_parent(parent, v);

            if (u_parent != v_parent) {
                result.push_back(edge);
                parent[u_parent] = v_parent;
            }
        }

        return result;
    }

private:
    char find_parent(std::unordered_map<char, char>& parent, char vertex) {
        if (parent[vertex] == vertex)
            return vertex;
        return find_parent(parent, parent[vertex]);
    }

    // Function to reverse a vector
    void reverse(std::vector<char>& path) {
        int n = path.size();
        for (int i = 0; i < n / 2; ++i) {
            char temp = path[i];
            path[i] = path[n - i - 1];
            path[n - i - 1] = temp;
        }
    }

    // Function to sort edges by weight
    void sort_edges() {
        for (size_t i = 0; i < edges.size(); ++i) {
            for (size_t j = i + 1; j < edges.size(); ++j) {
                if (edges[j]->weight < edges[i]->weight) {
                    std::swap(edges[i], edges[j]);
                }
            }
        }
    }
};
