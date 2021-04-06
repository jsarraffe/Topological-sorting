#include <iostream>
#include "Graph.h"
#include <list>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

std::vector<client *> Graph::topSort(std::vector<client *> clients) {
    std::queue<client *> q;
    std::vector<client *> result;
    auto *currClient = new client(0, 0, 0, 0);
    for (auto &c : clients) {
        if (c->inDegree() == 0) {
            q.push(c);
        }
        while (q.size() > 0) {
            currClient = q.front();
            currClient->inDegree() = -1;
            q.pop();
            result.push_back(currClient);
            for (auto &neighbors : _adjList[currClient->clientIndex()]) {
                neighbors->inDegree()--;
                if (neighbors->inDegree() == 0) {
                    q.push(neighbors);
                }
            }
        }
    }
    return result;
}
Graph::Graph(std::vector<client *> &clients) {
    std::list<client *> startList;
    _adjList.push_back(startList);
    for (auto &c : clients) {
        std::list<client *> cl;
        for (auto &cc : clients) {
            if (c->end() <= cc->start() && (c->clientIndex() != cc->clientIndex()) && c->clientIndex() != 0) {
                cc->hasInComingEdge() = true;
                cc->inDegree()++;
                cl.push_back(cc);
            }
        }
        if (c->clientIndex() != 0)_adjList.push_back(cl);
    }
    auto *end = new client(0, 0, 0, clients.size());
    for (auto &client : clients) {
        if (!client->hasInComingEdge() && client->clientIndex() != 0) {
            client->hasInComingEdge() = true;
            client->inDegree()++;
            _adjList[0].push_back(client);
        }
    }
    //end date
    for (auto &list : _adjList) {
        if (list.empty()) {
            end->hasInComingEdge() = true;
            end->inDegree()++;
            list.push_back(end);
        }
    }
    clients.push_back(end);
    _adjList.push_back(std::list<client *>());
}
void Graph::printGraph() {
    int counter = 0;
    std::cout << _adjList.size() << std::endl;
    for (auto &x : _adjList) {
        std::cout << counter << ":";
        for (auto &list: x) {
            std::cout << list->clientIndex() << "-";
        }
        std::cout << std::endl;
        counter++;
    }
}
std::vector<client *> Graph::optimalPath(std::vector<client *> clients) {
    std::reverse(clients.begin(), clients.end());
    std::map<int, client *> maxPathAndClient;
    for (auto &w : clients) {
        maxPathAndClient.insert(std::pair<int, client *>(w->clientIndex(), maxNeighbor(w)));
    }
    std::vector<client *> solution;
    int clientKEY = 0;
    while (clientKEY != -1 && clientKEY != maxPathAndClient.size() - 1) {
        solution.push_back(maxPathAndClient[clientKEY]);
        clientKEY = maxPathAndClient[clientKEY]->clientIndex();
    }
    for (auto del = maxPathAndClient.begin(); del != maxPathAndClient.end(); ++del) {
        client *temp = del->second;
        delete temp;
    }
    maxPathAndClient.clear();
    return solution;
}
client *Graph::maxNeighbor(client *v) {
    client *tmp = new client(0, 0, 0, -1);
    int max = 0;
    for (auto *c : _adjList[v->clientIndex()]) {
        if (c->pathWeight() >= max) {
            max = c->pathWeight();
            tmp = c;
        }
    }
    v->pathWeight() = v->weight() + max;
    return tmp;
}




