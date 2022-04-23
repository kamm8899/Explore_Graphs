#include <iostream>
#include <set>
#include <queue>
#include <cstdio>

using namespace std;


#include "graph.h"

using namespace std;

Graph::Graph(int nodes)
{
    this->nodes = nodes;
    this->matrix = new int*[nodes];

    for (int i = 0; i < nodes; ++i) {
        (this->matrix)[i] = new int[nodes];

        for (int j = 0; j < nodes; ++j) {
            (this->matrix)[i][j] = NO_EDGE;
        }
    }
}

Graph::Graph(int **matrix, int nodes) {
    this->nodes = nodes;
    this->matrix = new int*[nodes];

    for (int i = 0; i < nodes; ++i) {
        (this->matrix)[i] = new int[nodes];

        for (int j = 0; j < nodes; ++j) {
            (this->matrix)[i][j] = matrix[i][j];
        }
    }
}

Graph::~Graph()
{
    for (int i = 0; i < this->nodes; ++i) {
        delete[] (this->matrix)[i];
    }
    delete[] this->matrix;
}

bool Graph::set_edge(int i, int j, int edge)
{
    if (i < this->nodes && j < this->nodes && i >= 0 && j >= 0) {
        (this->matrix)[i][j] = edge;
        return true;
    }

    return false;
}

void Graph::dfs()
{
    set<int>visited;
    visited.insert(0);
    
    cout<< 0 << " ";
    dfs(0,&visited);

}
void Graph::dfs(int curNode, set<int> *visited)
{
    //visited 01
    //stop at curNode 0 otherNode 1
    for (int otherNode = 0; otherNode < nodes; otherNode++) {
        //check to see if the current "otherNode" is a neighbor of the cur node
        if (matrix[curNode][otherNode] == 1) {
            //we found a neighbor
            if (visited->count(otherNode) == 0) {
                //if this node has not been visited yet
                //print it, then continue the search
                cout << otherNode << " ";
                //mark this node visited
                visited->insert(otherNode);
                dfs(otherNode, visited);
            }
        }
    }
}
void Graph::bfs(int start)
{
    set<int> visited;
    bfs(start, &visited);
}
void Graph::bfs(int start, set<int> *visited)
{

    std::queue<int> q;
    //put the first node on the queue
    q.push(start);
    //print
    cout << start << " ";
    //mark is visited
    visited->insert(start);
    //q
    //visited 0 1 2 3 4
    //print 0 1 2 3 4
    while (!q.empty()) {
        int curNode = q.front();    //curNode 4
        //pop that node off the q
        q.pop();
        for (int otherNode = 0; otherNode < nodes; otherNode++) {
            //if this node is a neighbor
            if (matrix[curNode][otherNode] == 1) {
                //we found a neighbor check if it has been visited
                if (visited->count(otherNode) == 0) {
                    //if this node has not been visited yet
                    //print it, then continue the search
                    cout << otherNode << " ";
                    //mark this node visited
                    visited->insert(otherNode);
                    //add it to the q to be gone through later
                    q.push(otherNode);
                }
            }
        }
}
}
