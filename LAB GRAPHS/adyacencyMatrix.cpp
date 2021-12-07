#include "adjacencyMatrix.h"
#include <vector>
int main()
{
    AdjacencyMatrix<int> matrix(4);
    matrix.addEdge(0, 1);
    matrix.addEdge(2, 1);
    matrix.addEdge(3, 2);
    matrix.addEdge(1, 3);
    matrix.addEdge(1, 2);
    matrix.print();
    matrix.adjacency(1);
    std::cout << std::endl;
    std::cout << matrix.outDegree(1) << std::endl;
    std::cout << matrix.inDegree(1) << std::endl;
    AdjacencyMatrix<int> matrix2 = matrix.retina();
    matrix2.print();
}