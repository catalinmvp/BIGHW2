#include<iostream>
#include <list>
#include <stack>
#include <cstring>
#include <fstream>
#include <String.h>
using namespace std;
  ifstream fin("index.in");
string cuv[100];
int lit[30];
class Graph
{
    int V;

    // Pointer to an array containing adjacency listsList
    list<int> *adj;


    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);

    void addEdge(int v, int w);


    void topologicalSort();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}


void Graph::topologicalSortUtil(int v, bool visited[],stack<int> &Stack)
{

    visited[v] = true;

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);


    Stack.push(v);
}

// The function to do Topological Sort. It uses recursive
// topologicalSortUtil()
void Graph::topologicalSort()
{
    stack<int> Stack;

    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to store Topological
    // Sort starting from all vertices one by one
    for (int i = 0; i < V; i++)
      if (visited[i] == false)
        topologicalSortUtil(i, visited, Stack);

    // Print contents of stack
    while (Stack.empty() == false){
        if(lit[Stack.top()]!=0){
            cout << (char) ('a' + Stack.top());

        }
        Stack.pop();
    }
}

int mini(int x, int y){

    if (x<y)
        return x;
    else
        return y;

}



void af(int n){
    Graph gf(30);
    for (int i = 0; i < n-1; i++){
        string cuv1 = cuv[i];
        string cuv2 = cuv[i+1];
        for (int j = 0; j < mini(cuv1.length(), cuv2.length()); j++)
        {
            if (cuv1[j] != cuv2[j])
            {
                gf.addEdge(cuv1[j]-'a', cuv2[j]-'a');
                lit[cuv1[j]-'a']=1;
                lit[cuv2[j]-'a']=1;
                break;

            }
        }
    }
    gf.topologicalSort();

}
int main()
{

    int cont=0;
    while(fin>>cuv[cont++]){
        if(cuv[cont-1]=="."){
            cont--;
             break;
        }
    }
    for(int i=0;i<30;i++)
        lit[i]=0;

    af(cont);
    return 0;
}
