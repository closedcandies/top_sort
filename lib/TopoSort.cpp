#include "TopoSort.h"

namespace TopoSort {

Stack::~Stack() {
  Node *node = this->head;
  while (node != nullptr) {
    Node *next = node->next;
    delete node;
    node = next;
  }
}

Node* Stack::push(void *index) {
  if (this->head == nullptr) {
      this->head = new Node;
      this->head->index = index;
      this->head->next = nullptr;
      return this->head;
  }
  Node *node = new Node;
  node->index = index;
  node->next = this->head;
  this->head = node;
  return this->head;
}

Node* Stack::pop() {
  if (this->head == nullptr) {
    return nullptr;
  }
  Node *node = this->head;
  this->head = this->head->next;
  delete node;
  return this->head;
}

Node* Stack::top() {
  return this->head;
}

bool Stack::isEmpty() {
  return this->head == nullptr;
}


Graph::Graph(int size) {
  this->size = size;
}

Graph::~Graph() {
  for (auto it = this->nodes.begin(); it != this->nodes.end(); it++) {
    delete it->second;
  }
}


void Graph::addEdge(void *from, void *to) {
  char* fromName = static_cast<char*>(from);
  char* toName = static_cast<char*>(to);

  Edge *fromNode = this->nodes[std::string(fromName)];
  Edge *toNode = this->nodes[std::string(toName)];
  if (fromNode == nullptr) {
    fromNode = new Edge(from);
    this->nodes[static_cast<char*>(from)] = fromNode;
  }
  if (toNode == nullptr) {
    toNode = new Edge(to);
    this->nodes[static_cast<char*>(to)] = toNode;
  }
  fromNode->neighbors.push_back(toNode);
  toNode->InDegree++;
}


void Graph::addNode(void *index) {
  this->nodes[std::string(static_cast<char*>(index))] = new Edge(index);
}


void Graph::topologicalSort() {
  Stack stack;
  std::list<Edge*> zeroInDegree;

  for (auto& pair : this->nodes) {
    if (pair.second->InDegree == 0) {
      zeroInDegree.push_back(pair.second);
    }
  }

  while (!zeroInDegree.empty()) {
    Edge* node = zeroInDegree.front();
    zeroInDegree.pop_front();
    stack.push(node->index);

    for (Edge* neighbor : node->neighbors) {
      neighbor->InDegree--;
      if (neighbor->InDegree == 0) {
        zeroInDegree.push_back(neighbor);
      }
    }
  }

  for (auto& pair : this->nodes) {
    if (pair.second->InDegree > 0) {
      std::cerr << "Graph has a cycle, topological sort not possible." << std::endl;
      return;
    }
  }

  // Печать результата топологической сортировки
  Node* node = stack.top();

  Stack reversedStack;
  while (node != nullptr) {
    reversedStack.push(node->index);
    node = stack.pop();
  }
  node = reversedStack.top();

  while (!reversedStack.isEmpty()) {
    if (node == nullptr) {
      break;
    }
    char* name = static_cast<char*>(node->index);
    std::cout << name << " ";
    node = reversedStack.pop();
  }
  std::cout << std::endl;
}

}