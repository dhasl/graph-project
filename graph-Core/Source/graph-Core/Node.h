#pragma once
#include <unordered_map>
#include <vector>
#include <iostream>
class Node
{
private:
	int id;
	std::unordered_map<Node*, int> neighbors; //Map of a nodes neighbors with edge weights

public:
	Node(int _id) : id(_id) {}
	int getID() const;
	std::vector<Node*> getNeighborNodes();
	
	void addEdge(Node* dest, int weight); // Funktion zum Hinzufügen einer Kante zwischen zwei Knoten	
	void printNeighbors();
	
};

