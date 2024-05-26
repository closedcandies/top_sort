#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>

namespace TopoSort{

struct Node;

struct Edge{
  void* index;
  std::vector<Edge*> neighbors;
  int InDegree = 0;

  Edge(void* d) : index(d), InDegree(0) {}
};

struct Node{
  void* index;
  Edge* edge = nullptr;
  Node* next = nullptr;
};


class Stack{
  Node* head = nullptr;

  public:
    ~Stack();

    Node* push(void* index);
    Node* pop();
    Node* top();
    bool isEmpty();
};


class Graph{
  public:
    int size;
    std::unordered_map<std::string, Edge*> nodes;

    Graph(int size);
    ~Graph();

    void addEdge(void* from, void* to);
    void addNode(void* index);

    void topologicalSort();
};

}
