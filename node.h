#ifndef NODE_H
#define NODE_H
#include <vector>

class Node {
	public:
		bool operator==(const Node& other) const {return id == other.id;} 
		int id; 														 
				   														
		Node(){}			
														
		Node(int id)
		{
			this->id = id;
		}
	
	
};

#endif
