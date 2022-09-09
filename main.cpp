#include <iostream>
#include "src/p.h"
#include <unistd.h>

using namespace std;

fmt::color table[]={
    fmt::color::azure,
    fmt::color::blue,
    fmt::color::crimson,
    fmt::color::cyan,
    fmt::color::floral_white,
    fmt::color::green,
    fmt::color::honey_dew,
    fmt::color::brown,
    fmt::color::yellow,
    fmt::color::red,
    fmt::color::violet,
    fmt::color::orange
};

void debugLink(const Link& link){
    cout<<"[LINK]\n";
    cout<<"p: "<<link.p<<"\n("<<link.x1<<", "<<link.y1<<") ("<<link.x2<<", "<<link.y2<<")\n";
}

void debugNode(const Node& node){
    cout<<"[NODE]\n";
    for(auto i:node.links){
        debugLink(i);
    }
}

void debugGrid(const Grid& grid){
    cout<<"[GRID]\n";
    for(size_t i=0;i<grid.grid.size();i++){
        cout<<"["<<i<<"]";
        for(auto j:grid.grid[i]){
            debugNode(j);
        }
    }
}

void debugShowGrid(const Grid& grid, size_t p){
    for(auto i:grid.grid){
        for(auto j:i){
            for(auto k:j.links){
                // if(k.p > p ){
                //     fmt::print(fg(table[j.cluster%12]) | fmt::emphasis::bold,"{} ", k.p);
                // }
                // else cout<<k.p<<" ";
                fmt::print(fg(table[j.cluster%12]) | fmt::emphasis::bold,"{},", k.p);
            }//cout<<k.p<<" ";
            //cout<<"["<<j.cluster<<"] ";
            //cout<<"["<<j.visited<<"] ";
            if(j.links.size() < 3 )cout<<"\t";
            cout<<"\t|";
        }
        cout<<endl;
    }
}

void debugShowColors(const Grid& grid){
    for(auto i:grid.grid){
        for(auto j:i){
            fmt::print(fg(table[j.cluster%12]) | fmt::emphasis::bold,"{},", "##");
        }
        cout<<endl;
    }
}

int main(int argc, char* argv[]){


    if(argc==1){
        Grid template_grid(50,50);
        Grid temp=template_grid;

        for(int i=0;i<100;i++){
            temp.getClusters(i);
            system("clear");
            debugShowColors(temp);
            usleep(100000);
            temp=template_grid;
            temp.n_of_clusters=1;
        }
    }

    else{
        size_t size=50;
        size_t p=50;
        for(int i=1;i<argc-1;i++){
            if(argv[i][0]=='-' && argv[i][1]=='s'){
                string temp(argv[i+1]);
                size=stoi(temp);
            }
            else if(argv[i][0]=='-' && argv[i][1]=='p'){
                string temp(argv[i+1]);
                cout<<temp<<"gsdgdsdsg\n";
                p=stoi(temp);
            }
        }

        Grid grid(size, size);
        debugShowColors(grid);
        grid.getClusters(p);
        debugShowColors(grid);
    }

    
    return 0;

}