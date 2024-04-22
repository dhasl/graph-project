#include "GraphGenerator.h"
GraphGenerator::GraphGenerator(int numNodes) {
	
    /*Graph Matrix is nxn with n = number of nodes including root and sink
    First node is always the root node, last node is always the sink node.
    Numbers represent the edge weight. -1 means there is no edge between the two nodes.
    In a directed graph it is read like "from row to column" meaning the edge from node 1 to node 4 costs 6 units.

          r  1   2   3   4   s
     r  {-1, 0,  0, -1, -1, -1},
     1  {-1,-1,  2,  3,  6, -1},
     2  {-1, 2, -1, -1,  4, -1},
     3  {-1,-1, -1, -1,  2,  0},
     4  {-1,-1, -1,  2, -1,  0},
     s  {-1,-1, -1, -1, -1, -1}
    */
    graphMatrix = initGraphMatrix(numNodes);
	

}
GraphGenerator::GraphGenerator() {
    graphMatrix = buildMinimalBeispielGraphMatrix();
    graph = buildMinimalBeispielGraph();
}

GraphGenerator::~GraphGenerator() {

}

void GraphGenerator::setNumNodes(int num) {
	numNodes = num;
}
void GraphGenerator::setGraphMatrix(std::vector<std::vector<int>>& matrix) {
    graphMatrix = matrix;
}

/*returns a matrix of dimension nxn filled with -1*/
std::vector<std::vector<int>> GraphGenerator::initGraphMatrix(int n) {
	
	std::vector<int> t(n, -1); // Creating a vector 't' of size 'n' filled with 'n'
	std::vector<std::vector<int>> arr(n, t); // Creating a 2D vector 'arr' of size 'n x n' filled with vector 't'
	return arr; // Returning the 'n x n' matrix

}

void GraphGenerator::printMatrix(std::vector<std::vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		std::cout << "[";
		for (int j = 0; j < arr[i].size(); j++) {
			std::cout <<std::setw(3) << arr[i][j];
			if (j != arr[i].size()-1)
			{
				std::cout << ", ";
			}
		}
		std::cout << "]\n";
	}
}
void GraphGenerator::printGraph(std::vector<Node*>& nodes) {
    for (Node*& n : nodes) {
        n->printNeighbors();
    }
}


std::vector<Node*> GraphGenerator::generateGraph(std::vector<std::vector<int>>& matrix) {
    //generates the Nodes from the GraphMatrix

    std::vector<Node*> nodes;
    //populate vector with all the nodes
    for (int row = 0; row < matrix.size(); row++) {
        Node* n = new Node(row);
        nodes.push_back(n);       
    }
    //add edges for all nodes
    for (int row = 0; row < matrix.size(); row++) {
        for (int col = 0; col < matrix[row].size(); col++)
        {
            if (matrix[row][col] > -1) {
                //current col is a neighbor of row
                nodes[row]->addEdge(nodes[col], matrix[row][col]);
            }
        }
    }
    return nodes;

}


void GraphGenerator::generateGraphMatrix() {
    //generates a VALID graph matrix from randomness
}

std::vector<Node*> GraphGenerator::buildMinimalBeispielGraph() {

    std::vector<Node*> nodes;

    // Erstellen der Knoten
    Node* root = new Node(0);
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* sink = new Node(5);

    // Hinzufügen der erstellten Knoten zum Vektor
    nodes.push_back(root);
    nodes.push_back(node1);
    nodes.push_back(node2);
    nodes.push_back(node3);
    nodes.push_back(node4);
    nodes.push_back(sink);

    // Hinzufügen von Kanten zwischen den Knoten
    root->addEdge(node1, 0);
    root->addEdge(node2, 0);

    node1->addEdge(node2, 2);
    node1->addEdge(node3, 3);
    node1->addEdge(node4, 6);

    node2->addEdge(node1, 2);
    node2->addEdge(node4, 4);

    node3->addEdge(node4, 2);
    node3->addEdge(sink, 0);

    node4->addEdge(node3, 2);
    node4->addEdge(sink, 0);

    // Rückgabe des Vektors mit den erstellten Knoten
    return nodes;
}

std::vector<std::vector<int>> GraphGenerator::buildMinimalBeispielGraphMatrix() {
    std::vector<std::vector<int>> arr = {
        {-1, 0, 0, -1, -1, -1},
        {-1, -1, 2, 3, 6, -1},
        {-1, 2, -1, -1, 4, -1},
        {-1, -1, -1, -1, 2, 0},
        {-1, -1, -1, 2, -1, 0},
        {-1, -1, -1, -1, -1, -1}
    };

    return arr;
}
