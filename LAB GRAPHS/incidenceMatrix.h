#ifndef __INCIDENSEMATRIX_H__
#define __INCIDENSEMATRIX_H__
#include <iostream>
template <typename T>
class IncidenceMatrix
{
/* Implemente la estructura grafo utilizando una matriz de incidencia. La estructura debe tener las siguientes operaciones:

X newGraph(V,A): Inicializa la estructura grafo con V vértices y A aristas.
X addEdge(G,v,w): Inserta la arista de v a w en el grafo G.
X adj(G,v): retorna la lista de vértices adyacentes del vértice v.
outdegree(G,v): retorna el número de vecinos del vértice v.
indegree(G,v): retorna el número de vecinos que apuntan al vértice v.

    */
private:
    int vertex; //k
    int A; //v / w

    T **matrix;
    void init()
    {
        for (int i = 0; i < vertex; i++)
        {
            for (int j = 0; j < A; j++)
            {
                this->matrix[i][j] = 0;
            }
        }
    }

public:
    IncidenceMatrix()
    {
        this->vertex = 0;
        this->A = 0;
        this->matrix = nullptr;
    }
    IncidenceMatrix(int vertex){
        this->vertex = vertex;
        this->A = 5; 
        this->matrix = new T *[this->vertex];
        for (int i = 0; i < this->vertex; i++){   
            this->matrix[i] = new T[this->A];      
        }
        this->init();
    }

    IncidenceMatrix(const IncidenceMatrix &m)
    {
        this->vertex = m.vertex;
        for (int i = 0; i < this->vertex; i++)
        {
            for (int j = 0; j < this->vertex; j++)
            {
                this->matrix[i][j] = m.matrix[i][j];
            }
        }
    }
    ~IncidenceMatrix()
    {
        for (int i = 0; i < this->vertex; i++)
            delete[] this->matrix[i];
        delete[] this->matrix;
    }
    void print()
    {
        for (int i = 0; i < this->vertex; i++)
        {
            for (int j = 0; j < this->A; j++)
            {
                std::cout << *(*(this->matrix + i) + j) << "\t";
            }
            std::cout << std::endl;
        }
    }
    void addEdge(int v, int w)
    {
        if (v > this->vertex || w > this->vertex)
        {
            std::cout << "El vertice indicado no existe" << std::endl;
        }
        else

        //1
        {   /*for (int i = 0; i < this->A; i++)
            {
                if (i == w )
                {
                    for (int j = 0; j < this->vertex; j++)
                    {
                        if (j == v)
                        {
                            this->matrix[j][i] = -1;
                        }
                        else if (j == w)
                        {
                            this->matrix[j][i] = 1;
                        }
                        //else this->matrix[j][i] = 0;
                    }
                }
            }*//*
            for(int k=0; k<this->vertex;k++){
                    if(k==v && k!=w ) this->matrix[v][w] = -1;
                    else if(k==w && k!=v) this->matrix[v][w] = 1;

                }*/
            }
        }                  
    }
         

    void adjacency(int vertex)
    {
        for (int i = 0; i < this->vertex; i++)
        {
        if (this->matrix[vertex][i] == 1 || this->matrix[vertex][i] == -1 )
            {
                std::cout << i << ",";
            }
        }
    }

    int outDegree(int vertex)
    {
        int contador = 0;
        for (int i = 0; i < this->vertex; i++)
        {
            if (this->matrix[vertex][i] == 1 || this->matrix[vertex][i] == -1)
            {
                contador++;
            }
        }
        return contador;
    }
    int inDegree(int vertex)
    {
        int contador = 0;
        for (int i = 0; i < this->vertex; i++)
        {
            if (this->matrix[i][vertex] == 1 || this->matrix[vertex][i] == -1)
            {
                contador++;
            }
        }
        return contador;
    }
};

#endif // ADJACENCYMATRIX_H