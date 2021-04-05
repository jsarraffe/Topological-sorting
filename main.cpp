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
    std::ofstream outputStream;
    std::string file;
    std::cout << "Enter the file to read data: ";
    std::cin >> file;

    inputStream.open(file, std::ios::in);
    outputStream.open("out"+file);

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
    inputStream.close();
    auto *graph = new Graph(clients);
    std::vector<client*> r = graph->topSort(clients);
    auto x =  graph->optimalPath(r);
    outputStream<<"Input read from "+file << std::endl<<std::endl;

    std::cout<<"There are "<<clients.size()-2 << " clients in this file" << std::endl << std::endl;
    outputStream<<"There are "<<clients.size()-2 << " clients in this file" << std::endl << std::endl;
    outputStream<<"Optimal Revenue earned is " << x[0]->pathWeight() << std::endl <<std::endl;
    outputStream<<"Clients contributing to this optimal revenue: ";
    std::cout<<"Optimal Revenue earned is " << x[0]->pathWeight() << std::endl <<std::endl;
    std::cout<<"Clients contributing to this optimal revenue: ";



    for (int i = 0; i <=  x.size()-2; i++) {
        std::cout <<  x[i]->clientIndex();
        outputStream<< x[i]->clientIndex();
        if(i != x.size()-2){
            std::cout << ", ";
            outputStream<< ", ";
        }
    }
    outputStream.close();
}