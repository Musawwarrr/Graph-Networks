#include "graph.h"
#include <unordered_map>
#include <vector>
#include "node.h"
#include <iostream>
#include <unordered_set>
#include <map>
using namespace std;

// Makes a graph network using elemtens from vector u and creating an edge with the corresponding index of vector v.  
Graph make_graph(int num_nodes, std::vector<int> u, std::vector<int> v){
	Graph graph;
	map<int, Node> gnode = graph.get_id_to_node_map();

	for (int i = 1; i <= num_nodes; i++)
	{
		Node* n = new Node(i);
		gnode[i] = *n;
		std::vector<int> vect;
		graph.alist[i] = vect;
	}

	int n = u.size();
	graph.num_nodes = num_nodes;
	graph.num_edges = n;
	if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			graph.alist[u[i]].push_back(v[i]);
			graph.alist[v[i]].push_back(u[i]);
		}
	}

	return graph;
}

// Gets the number of nodes in the graph
int Graph::get_num_nodes() {
	return this->num_nodes;
}

// Gets the number of edges in the graph
int Graph::get_num_edges() {
	return this->num_edges;
}

// Gets the neighbors of the Node, i.e., all the nodes that share an edge with the given Node
std::vector<Node> Graph::get_neighbors(Node u) {
	std::vector<Node> vect;
	std::vector<int> n = this->alist[u.id];
	std::map<int, Node> gnode = this->get_id_to_node_map();

	for (int i = 1; i <= n.size(); i++)
	{
		vect.push_back(gnode[n[i]]);
	}

	return vect;

}

// Returns the id to node map 
std::map<int, Node>Graph::get_id_to_node_map(){
	return this->id_to_node_map;
}



