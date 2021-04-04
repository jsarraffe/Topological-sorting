#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "client.h"
#include "Graph.h"

int main() {
    std::string line;
    int start = 0, end = 0, weight = 0, index = 1;
    std::ifstream inputStream;
    inputStream.open("data3.txt", std::ios::in);

    std::vector<client *> clients;

    if (!inputStream.is_open()) {
        std::cout << "Unable top open " << "S" << ". Terminating...";
        perror("Error when attempting to open the input file.");
        exit(1);
    }
    clients.push_back(new client(0,0,0,0));
    while (inputStream >> start && inputStream >> end && inputStream >> weight) {
        auto *newClient = new client(start, end, weight, index);
        clients.push_back(newClient);
        index++;
    }
    auto *graph = new Graph(clients);
    graph->printGraph();

    for (auto &x:clients){
        std::cout<<x->inDegree()<< ": ";
    }

    std::cout<<std::endl;
    std::cout<<clients.size()<<"size"<<std::endl;
    std::vector<client*> r = graph->topSort(clients);

    for (auto &z : r){
        std::cout<<z->clientIndex()<<", ";
    }

    graph->optimalPath(clients);




}
