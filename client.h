//
// Created by jsarraffe on 3/22/2021.
//

#ifndef PROJECT2A_CLIENT_H
#define PROJECT2A_CLIENT_H


class client {
private:
    int _start;
    int _end;
    int _weight;
    int currClient;
    bool _hasIncomingEdge;
    bool _isVisited = false;
    int _inDegree = 0;
    int _pathWeight = 0;


public:
    int &start(){return _start;}
    int &inDegree(){return _inDegree;}
    int &pathWeight(){return _pathWeight;}
    bool &isVisited(){return _isVisited;}
    int &end(){return _end;}
    bool &hasInComingEdge(){return _hasIncomingEdge;}
    int &clientIndex(){return currClient;}
    int &weight(){return _weight;}
    client():_start(0), _end(0), _weight(0),currClient(0){}
    client(int start, int end, int weight, int currClient):_start(start), _end(end), _weight(weight),currClient(currClient), _hasIncomingEdge(false){}
};




#endif //PROJECT2A_CLIENT_H
