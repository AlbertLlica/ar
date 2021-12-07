#ifndef __ADJACENCYMATRIX_H__
#define __ADJACENCYMATRIX_H__
#include <iostream>
template <typename T>
/*
Implemente la estructura grafo utilizando una matriz de adyacencia. La estructura debe tener las siguientes operaciones:

newGraph(V): Inicializa la estructura grafo con V vértices.
addEdge(G,v,w): Inserta la arista de v a w en el grafo G.
adj(G,v): retorna la lista de vértices adyacentes del vértice v.
outdegree(G,v): retorna el número de vecinos del vértice v.
indegree(G,v): retorna el número de vecinos que apuntan al vértice v.
reverse(G): retina un grafo con las aristas de G invertidas.
*/
class AdjacencyMatrix
{
private:
    int size;
    T **matrix;
    void init()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                this->matrix[i][j] = 0;
            }
        }
    }

public:
    AdjacencyMatrix()
    {
        this->size = 0;
        this->matrix = nullptr;
    }
    AdjacencyMatrix(int size)
    {
        this->size = size;
        this->matrix = new T *[this->size];
        for (int i = 0; i < this->size; i++)
        {
            this->matrix[i] = new T[this->size];
        }
        this->init();
    }
    AdjacencyMatrix(const AdjacencyMatrix &m)
    {
        this->size = m.size;
        for (int i = 0; i < this->size; i++)
        {
            for (int j = 0; j < this->size; j++)
            {
                this->matrix[i][j] = m.matrix[i][j];
            }
        }
    }
    ~AdjacencyMatrix()
    {
        for (int i = 0; i < this->size; i++)
            delete[] this->matrix[i];
        delete[] this->matrix;
    }
    void print()
    {
        for (int i = 0; i < this->size; i++)
        {
            for (int j = 0; j < this->size; j++)
            {
                std::cout << *(*(this->matrix + i) + j) << "\t";
            }
            std::cout << std::endl;
        }
    }
    void addEdge(int vertex1, int vertex2)
    {
        if (vertex1 > this->size || vertex2 > this->size)
        {
            std::cout << "El vertice indicado no existe" << std::endl;
        }
        else
        {
            this->matrix[vertex1][vertex2] = 1;
        }
    }
    void adjacency(int vertex)
    {
        for (int i = 0; i < this->size; i++)
        {
            if (this->matrix[vertex][i] == 1)
            {
                std::cout << i << ",";
            }
        }
    }
    int outDegree(int vertex)
    {
        int contador = 0;
        for (int i = 0; i < this->size; i++)
        {
            if (this->matrix[vertex][i] == 1)
            {
                contador++;
            }
        }
        return contador;
    }
    int inDegree(int vertex)
    {
        int contador = 0;
        for (int i = 0; i < this->size; i++)
        {
            if (this->matrix[i][vertex] == 1)
            {
                contador++;
            }
        }
        return contador;
    }
    AdjacencyMatrix<T> retina()
    {
        AdjacencyMatrix<int> result(this->size);
        for (int i = 0; i < this->size; i++)
        {
            for (int j = 0; j < this->size; j++)
            {
                if (this->matrix[i][j] == 1)
                {
                    result.matrix[j][i] = 1;
                }
            }
        }
        return result;
    }
};

#endif // ADJACENCYMATRIX_H