//
// Created by jsarraffe on 3/23/2021.
//

#include <queue>
#include "client.h"
#include <vector>
#include <list>
#include <map>

#ifndef PROJECT2A_GRAPH_H
#define PROJECT2A_GRAPH_H
class Graph{
public:

    Graph(std::vector<client *> &clients);
    std::vector<client*> topSort(std::vector<client *> clients);
    std::vector<client*> optimalPath(std::vector<client*> clients);
    client *  maxNeighbor(client * v);

    void printGraph();
    void topSortHelper();

private:

    std::vector<std::list<client *>> _adjList;
    std::queue<client*> topSortQueue;

};









#endif //PROJECT2A_GRAPH_H



