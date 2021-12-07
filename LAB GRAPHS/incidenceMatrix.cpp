#include "incidenceMatrix.h"

int main()
{
    IncidenceMatrix<int> matrix(4);
    matrix.print();
    std::cout<<"\n";
    matrix.addEdge(0, 1);
    matrix.addEdge(0, 2);
    matrix.addEdge(2, 1);
    matrix.addEdge(2, 3);
    matrix.addEdge(1, 3);
    matrix.print();
   /* matrix.adjacency(1);
    std::cout << std::endl;
    std::cout << matrix.outDegree(1) << std::endl;
    std::cout << matrix.inDegree(1) << std::endl;*/
}