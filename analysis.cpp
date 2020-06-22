#include "project3.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>
#include "time.h"
#include <map>

using namespace std;


// Given any number of nodes, this function creates edges between two nodes with a probablity, p
// Uses the Merseinne Twister for random number generation 
void erdos_renyi(int n, vector<int>& v1, vector<int>& w1)
{
    double p = (2 * log(n)) / n;    
    int v = 1;
    int w = -1;

    static std::mt19937 generator(time(nullptr));
    static std::uniform_real_distribution<double> distribution(0.0,1);

    while (v < n)
    {
        double r = distribution(generator);

        double m = log(1-r) / log(1-p);
        w = w + 1 + floor(m);
        while (w >= v && v < n)
        {
            w = w - v;
            v = v + 1;
        } 
        if (v < n)
        {
            v1.push_back(v);
            w1.push_back(w);
        }
    } 
}

// Creates an undirected graph using the Erdos-Renyi Algorithm with p = (2 * log(n)) / n
// Returns the diameter, cluster coefficient and the degree distribution of the graph.  
int main()
{
    int n = 100000;                     // Set how many nodes to create the graph with
    
    vector<int> v;
    vector<int> w;
        
    erdos_renyi(n, v, w);
    Graph graph = make_graph(n, v, w);

    int diameter = get_diameter(graph);
    int cluster_coef = get_clustering_coefficient(graph);
    std::map<int, int> dd = get_degree_distribution(graph);

    return 0;
}