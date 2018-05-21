#include <iostream>

#include "pilha.h"
#include "lista.h"

using namespace std;

int main(int argc, char const *argv[]) {
	bool teste = true;

	ListaLigada<string> lista;
	lista.InsereNoFinal("s");
	lista.InsereNoFinal("o");
	lista.InsereNoFinal("c");
	lista.InsereNoFinal("o");
	lista.InsereNoFinal("r");
	lista.InsereNoFinal("r");
	lista.InsereNoFinal("a");
	lista.InsereNoFinal("m");
	lista.InsereNoFinal("-");
	lista.InsereNoFinal("m");
	lista.InsereNoFinal("e");
	lista.InsereNoFinal(",");
	lista.InsereNoFinal(" ");
	lista.InsereNoFinal("s");
	lista.InsereNoFinal("u");
	lista.InsereNoFinal("b");
	lista.InsereNoFinal("i");
	lista.InsereNoFinal(" ");
	lista.InsereNoFinal("n");
	lista.InsereNoFinal("o");
	lista.InsereNoFinal(" ");
	lista.InsereNoFinal("o");
	lista.InsereNoFinal("n");
	lista.InsereNoFinal("i");
	lista.InsereNoFinal("b");
	lista.InsereNoFinal("u");
	lista.InsereNoFinal("s");
	lista.InsereNoFinal(" ");
	lista.InsereNoFinal("e");
	lista.InsereNoFinal("m");
	lista.InsereNoFinal(" ");
	lista.InsereNoFinal("m");
	lista.InsereNoFinal("a");
	lista.InsereNoFinal("r");
	lista.InsereNoFinal("r");
	lista.InsereNoFinal("o");
	lista.InsereNoFinal("c");
	lista.InsereNoFinal("o");
	lista.InsereNoFinal("s");

	shared_ptr<Node<string>> aux = lista.getCabeca();

	Pilha<string> pilha;

	while(aux != nullptr) {
		pilha.push(aux->getValor());
		aux = aux->getNext();
	}

	aux = lista.getCabeca();

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