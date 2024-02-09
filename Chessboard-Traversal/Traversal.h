#ifndef TRAVERSAL_H
#define TRAVERSAL_H
#include "Queue.h"

class Traversal
{
public:
    Queue q;
    int vertices;
    int** Matrix;
    bool* visited;
    Traversal();
    void AddEdge(int, int);
    void AddChessBoardEdges();
    void BreadthFirstSearch();
    int getStartVertex(int, int);
    void Display(int);

};
#endif //TRAVERSAL_H
