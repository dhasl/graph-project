#pragma once
#include <vector>
#include <iomanip>
#include "Node.h"

class GraphGenerator
{
private:
	int numNodes;
	std::vector<Node*> graph;
	std::vector<std::vector<int>> graphMatrix;
public:
	GraphGenerator();//GraphGenerator with minimal Beispiel Matrix and Graph
	GraphGenerator(int numNodes); //GraphGenerator with initialised graphmatrix (-1)
	~GraphGenerator();
	
	void setNumNodes(int num);
	void setGraphMatrix(std::vector<std::vector<int>>&);

	std::vector<Node*>& getGraph() { return graph; };
	std::vector<std::vector<int>>& getGraphMatrix() { return graphMatrix; };

	std::vector<std::vector<int>> initGraphMatrix(int);
	void printMatrix(std::vector<std::vector<int>>);
	void printGraph(std::vector<Node*>&);

	std::vector<Node*> generateGraph(std::vector < std::vector<int>>& matrix) ;
	void generateGraphMatrix();
	std::vector<Node*> buildMinimalBeispielGraph(); //for testing purpose
	std::vector<std::vector<int>> buildMinimalBeispielGraphMatrix();

	void writeProblemToFile();
	std::vector<std::vector<int>> readProblemFromFile(std::string& filepath);


};

