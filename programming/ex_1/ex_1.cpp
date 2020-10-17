#include <iostream>
#include <fstream>

using namespace std;

struct Edge {
    int node_1, node_2, value;
}* graph;

int v, e;

void get_graph() {
    ifstream fin;
    fin.open("graph.txt");
    fin >> v >> e;
    graph = new Edge[e];
    for (int i = 0; i < e; i++)
    {
        fin >> graph[i].node_1 >> graph[i].node_2 >> graph[i].value;
    }
    fin.close();
}


int main()
{
    get_graph();
    /*for (int i = 0; i < e; i++)
    {
        cout << graph[i].node_1 << " " << graph[i].node_2 << " " << graph[i].value << endl; 
    }*/
    return 0;
}