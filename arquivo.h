#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class GrafoListaAdj {
private:
    vector<string> vertices;

    //first � o indice do vertice, second � o peso (caso o grafo seja ponderado)
    vector<vector<pair<int, int>>> arestas;

    /**
    * A principio nao temos nenhuma ordenacao usando os rotulos.
    * Portanto, usaremos busca linear.
    **/
    int obterIndiceVertice(string rotuloVertice) {
        //IMPLEMENTAR
        for (int i = 0; i < this->vertices.size(); i++) {
            if (this->vertices[i] == rotuloVertice) {
                return i;
            }
            else {
                return -1;
            }
        }
    }

public:
    /**
    * Lembrem-se:
    *       1) nao podemos inserir vertices com mesmo rotulo
    *       2) toda vez que inserirmos um novo v�rtice, precisaremos
    *          inserir um vetor para representar as conex�es daquele
    *          v�rtice na lista de adjac�ncias
    **/
    void inserirVertice(string rotuloVertice) {
        //IMPLEMENTAR
        if(this->obterIndiceVertice(rotuloVertice) != -1){
        	this->vertices.push_back(rotuloVertice);
        	this->arestas.push_back(vector<pair<int, int>>());
        }
    }

    /**
    * Sempre que o grafo for n�o ponderado, adicionaremos o peso 1,
    * por conveni�ncia.
    **/
    void inserirArestaDirecionada(string rotuloVOrigem, string rotuloVDestino) {
        inserirArestaDirecionada(rotuloVOrigem, rotuloVDestino, 1);
    }

    void inserirArestaNaoDirecionada(string rotuloVOrigem, string rotuloVDestino) {
        inserirArestaDirecionada(rotuloVOrigem, rotuloVDestino, 1);
        inserirArestaDirecionada(rotuloVDestino, rotuloVOrigem, 1);
    }

    void inserirArestaNaoDirecionada(string rotuloVOrigem, string rotuloVDestino, int peso) {
        inserirArestaDirecionada(rotuloVOrigem, rotuloVDestino, peso);
        inserirArestaDirecionada(rotuloVDestino, rotuloVOrigem, peso);
    }

    /**
    * Inserir uma aresta entre rotuloVOrigem e rotuloVDestino com o peso
    * especificado.
    **/
    void inserirArestaDirecionada(string rotuloVOrigem, string rotuloVDestino, int peso) {
        //IMPLEMENTAR
        int Origem = this->obterIndiceVertice(rotuloVOrigem);
        int Destino = this->obterIndiceVertice(rotuloVDestino);

        if (Origem != -1 && Destino != -1) {
            return;
        }
        else {
            this->arestas[Origem].push_back(pair<int, int>(Destino, peso));
        }
    }

    /**
    * Verifica se v�rtice rotuloVOrigem e v�rtice rotuloVDestino s�o
    * conectados (vizinhos).
    **/
    bool saoConectados(string rotuloVOrigem, string rotuloVDestino) {
        //IMPLEMENTAR

        int Origem = this->obterIndiceVertice(rotuloVOrigem);
        int Destino = this->obterIndiceVertice(rotuloVDestino);
	
	if(Origem == -1 || Destino == -1) return false;
	 
         for (pair<int, int> vec : this->arestas[Origem])
            if (vec.first == Destino) return true;
            else return false;
    }
    
    vector<string> getVertices() {
        return vertices;
    }

    vector<vector<pair<int, int>>> getArestas() {
        return arestas;
    }
};
