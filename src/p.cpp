#include "p.h"

Grid::Grid(size_t size_x, size_t size_y){
    srand(time(NULL));
    grid=vector<vector<Node>>(size_y, vector<Node>(size_x, Node()));
    for(size_t i=0;i<size_x;i++){
        for(size_t j=0;j<size_y;j++){
            grid[i][j]=Node(i,j,size_x,size_y);
        }
    }
    n_of_clusters=1;
}

Grid::Grid(){
    srand(time(NULL));
}

void Grid::getClusters(size_t p){
    for(size_t i=0;i<grid.size();i++){
        for(size_t j=0;j<grid[0].size();j++){
            if(grid[i][j].visited==false)
                DFS(p, i, j);
        }
    }
}

void Grid::DFS(size_t p, size_t x, size_t y){
    queue<Node>toVisit;
    if(grid[x][y].visited==false && grid[x][y].links[0].p>p)toVisit.push(grid[x][y]);
    else if(grid[x][y].links[0].p<=p){
        return;
    }
    int color_of_cluster=(grid[x][y].cluster%12==0 ? n_of_clusters : grid[x][y].cluster);
    int iW=0,iF=0;
    while(toVisit.empty()==false){
        iW++;
        auto tempNode=toVisit.front().links;
        grid[x][y].visited=true;
        grid[x][y].cluster=color_of_cluster;
        for(auto& i:tempNode){
            iF++;
            if(grid[i.x2][i.y2].visited==false && i.p>p){
                toVisit.push(grid[i.x2][i.y2]);
                grid[i.x2][i.y2].visited=true;
                grid[i.x2][i.y2].cluster=color_of_cluster;
            }
            x=toVisit.front().links[0].x1;
            y=toVisit.front().links[0].y1;
        }
        

        toVisit.pop();
    }
    toVisit=queue<Node>();
    n_of_clusters=rand()%11+1; 
}

Node::Node(size_t pos_x, size_t pos_y, size_t max_x, size_t max_y){
    if(pos_x > 0)
        links.push_back(Link(pos_x, pos_y, pos_x-1, pos_y));
    if(pos_x < max_x -1)
        links.push_back(Link(pos_x, pos_y, pos_x+1, pos_y));
    if(pos_y > 0)
        links.push_back(Link(pos_x, pos_y, pos_x, pos_y-1));
    if(pos_y < max_y -1)
        links.push_back(Link(pos_x, pos_y, pos_x, pos_y+1));
    cluster=0;
}

Node::Node(){
    cluster=0;
    return;
}

Link::Link(size_t x1, size_t y1, size_t x2, size_t y2){
    this->x1 = x1;
    this->x2 = x2;
    this->y1 = y1;
    this->y2 = y2; 
    p=rand()%100;
}




