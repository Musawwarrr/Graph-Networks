#ifndef PROJECT3_H
#define PROJECT3_H

#include <vector>
#include <map>
#include "graph.h"


/******* EXPLANATIONS ********/

// construct a graph using num_nodes nodes and edges (ui, vi) for all i
// u and v will be the same length
// (ui, vi) are pairs of integers which can be mapped uniquely to (ui', vi'), pairs of Nodes
// ui, vi values are numbered from 1 to num_nodes, inclusive
Graph make_graph(int num_nodes, std::vector<int> u, std::vector<int> v);


// network algorithms
int get_diameter(Graph graph); 
float get_clustering_coefficient(Graph graph);
std::map<int, int> get_degree_distribution(Graph graph); // key-value pairs represent {degree, number of nodes with that degree}

#endif
