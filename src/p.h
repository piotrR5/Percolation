#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fmt/color.h>
#include <fmt/core.h>
#include <queue>



using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::queue;

class Link{
public:
    size_t x1,x2,y1,y2;
    size_t p;
    bool visited=false;
    Link(size_t x1, size_t y1, size_t x2, size_t y2);
};

class Node{

public:
    size_t cluster;
    bool visited=false;
    vector<Link>links;

    Node(size_t pos_x, size_t pos_y, size_t max_x, size_t max_y);   //should fill up links vector with possible links
    Node();
};


class Grid{

    void DFS(size_t p, size_t x, size_t y);
public:
    size_t n_of_clusters=0;
    void getClusters(size_t p);
    vector<vector<Node>>grid;
    Grid(size_t size_x, size_t size_y); //should fill grid matrix with
    Grid();
};


