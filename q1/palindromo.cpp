/**
* @file palindromo.cpp
* @brief Programa que teste se uma palavra é palindromo.
* @author Anderson Evangelista da Silva
* @brief lista e pilha foram implementados por Teobaldo.
* @since 20/05/2018
* @date 25/05/2018
*/

#include <iostream>

#include "pilha.h"
#include "lista.h"

using namespace std;

int main(int argc, char const *argv[]) {
	bool teste = true;

	ListaLigada<string> lista;
	/**
	*@brief Para testar outras palavras basta colocar na lista abaixo.
	*/
	lista.InsereNoFinal("h");
	lista.InsereNoFinal("a");
	lista.InsereNoFinal("n");
	lista.InsereNoFinal("a");
	lista.InsereNoFinal("h");
	

	shared_ptr<Node<string>> aux = lista.getCabeca();

	Pilha<string> pilha;
	/**
	* @brief empilhando...
	*/
	while(aux != nullptr) {
		pilha.push(aux->getValor());
		aux = aux->getNext();
	}

	aux = lista.getCabeca();
	/**
	* @details aqui é comparado o começo da lista com o topo da fila, caso
		as letras sejam diferentes será retornado false para indicar que nao
		é palindromo, caso contrario será palindromo.
	*/
	while(aux != nullptr) {
		if(aux->getValor() == "," || aux->getValor() == " " || aux->getValor() == "-") {
			aux = aux->getNext();
			continue;
		}

		if(pilha.top() == "," || pilha.top() == " " || pilha.top() == "-") {
			pilha.pop();
			continue;
		}

		if(aux->getValor() != pilha.top()) {
			teste = false;
			aux = nullptr;
		} else {
			aux = aux->getNext();
			pilha.pop();
		}
	}

	if(teste) {
		cout << "E palindromo!" << endl;
	} else {
		cout << "Nao e palindromo." << endl;
	}

	return 0;
}