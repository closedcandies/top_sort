#include <iostream>
#include <fstream>
#include <string>
#include "lib/TopoSort.h"

int main(int argc, const char * argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./main <filename>" << std::endl;
        return 1;
    }

    const char* filename = argv[1];

    std::ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open file: " << filename << std::endl;
        return 1;
    }

    std::string nodes;
    std::getline(file, nodes);
    int numNodes = std::stoi(nodes);

    std::string edges;
    std::getline(file, edges);
    int numEdges = std::stoi(edges);


    TopoSort::Graph graph(numNodes);

    for (int i = 0; i < numNodes; i++) {
        std::string* node = new std::string;
        std::getline(file, *node);
        graph.addNode((void*)node);
    }

    for (int i = 0; i < numEdges; i++) {
        std::string* data = new std::string;
        std::getline(file, *data);
        size_t delimiterPosition = data->find('-');
        auto* from = new std::string(data->substr(0, delimiterPosition));
        auto* to = new std::string(data->substr(delimiterPosition + 2, data->length()));

        graph.addEdge((void*)from, (void*)to);

        delete data;
        delete from;
        delete to;
    }

    graph.topologicalSort();


    return 0;
}
