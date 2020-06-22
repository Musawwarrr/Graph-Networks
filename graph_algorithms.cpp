#include "graph.h"
#include <vector>
#include <queue>
#include <stdlib.h>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

// Finds the diameter of the entire graph network
int get_diameter(Graph graph)
{
	int num_nodes = graph.get_num_nodes();
	int dmax = 0;
	int id = (rand() % num_nodes) + 1;

	for (int it = 0; it < 2; it++)
	{
		std::vector<int> dist(num_nodes, -1);
		std::queue<int> q; 

		q.push(id);

		dist[id-1] = 0;

		while (!q.empty())
		{
			id = q.front(); 
			q.pop();
			int len = graph.alist[id].size();
			for (int i = 0; i < len; i++)
			{
				int v = graph.alist[id][i];

				if (dist[v-1] == -1)
				{
					q.push(v);
					dist[v-1] = dist[id-1] + 1;
				}
			}
		}

		for (int i = 0; i < num_nodes; i++)
		{
			if (dist[i] > dmax)
			{
				dmax = dist[i];
				id = i+1;
			}
		}
	}

	return dmax;
}

// Finds the clustering Coefficient of the graph 
float get_clustering_coefficient(Graph graph) 
{
	float denom = 0;
	int num_nodes = graph.num_nodes;
	std::vector<int> L;
	std::vector<std::set<int>> D(num_nodes);
	std::unordered_map<int, std::vector<int>> N;
	std::unordered_set<int> H;
	std::map<int, Node> id_node = graph.get_id_to_node_map();
	
	for (int n = 1; n <= num_nodes; n++)
	{
		int dv = graph.alist[n].size();
		D[dv].insert(n);
		denom += (dv * (dv-1))/2;
	}

	for (int n = 0; n < num_nodes; n++)
	{
		int i  = 0;
		while (D[i].empty())
		{
			i++;
		}

		auto it = D[i].begin();
		int v = *it;

		L.push_back(v);
		H.insert(v);
		D[i].erase(v);

		for (int q = 0; q < graph.alist[v].size(); q++)
		{
			int w = graph.alist[v][q];
			if (H.find(w) == H.end())
			{
				D[graph.alist[w].size()-1].insert(w);
				D[graph.alist[w].size()].erase(w);
				N[v].push_back(w);
			}
		}
	}
	
	float triangle = 0;

	for (int v = 1; v <= L.size(); v++)
	{
		for (int w = 0; w < N[v].size(); w++)
		{
			for (int u = 0; u < N[v].size(); u++)
			{
				if (w != u)
				{
					for (int q = 0; q < graph.alist[N[v][w]].size(); q++)
					{
						if (graph.alist[N[v][w]][q] == N[v][u])
						{
							triangle++;
							break;
						}
					}
				}
			}
		}
	}
	triangle = triangle/2;
	
	float C = (3 * triangle)/denom;
	return C;
}


// Finds the degree distribution of the graph 
std::map<int, int> get_degree_distribution(Graph graph) 
{
	std::map<int, int> dd;

	for (int i = 1; i <= graph.num_nodes; i++)
	{
		dd[graph.alist[i].size()]++;
	}

	return dd;
}
