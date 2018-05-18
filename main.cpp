#include <iostream>

#include "pilha.h"
#include "lista.h"

using namespace std;

//using std::string;
//using std::cout;
//using std::endl;

int main(int argc, char const *argv[]) {
	//bool teste;

	ListaLigada<string> lista;
	lista.InsereNoFinal("a");
	lista.InsereNoFinal("r");
	lista.InsereNoFinal("a");
	lista.InsereNoFinal("r");
	lista.InsereNoFinal("a");

	shared_ptr<Node<string>> aux = lista.getCabeca();

	Pilha<string> pilha;

	while(aux != nullptr) {
		pilha.push(aux->getValor());
		aux = aux->getNext();
	}

	string num = pilha.pop();

	return 0;
}