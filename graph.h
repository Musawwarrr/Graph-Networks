#ifndef GRAPH_H
#define GRAPH_H
#include <map>
#include <vector>
#include "node.h"
#include <unordered_map>


class Graph 
{
	public:
        int get_num_nodes(); 									// get number of nodes
        int get_num_edges(); 									// get number of edges
        std::vector<Node> get_neighbors(Node u); 				// return neighbors of u 
        std::map<int, Node> get_id_to_node_map(); 				// allows lookup of nodes from ids
		Graph(){};												// Constructor for the Graph
		std::unordered_map<int, std::vector<int>> alist;		// Adjacency List to hold all the nodes
		std::map<int,Node> id_to_node_map;						// Map containing ints as keys and the corresponding Node as values

		int num_nodes = 0;										// Number of Nodes in the Graph  
		int num_edges = 0;										// Number of Edges in the Graph
};

#endif
