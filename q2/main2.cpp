#include <iostream>
#include <string>

#include "pilha.h"
#include "lista.h"

using namespace std;

int main(int argc, char const *argv[]) {
	int num1, num2;
	Pilha<string> posFixa;
	posFixa.push("/");
	posFixa.push("10");
	posFixa.push("*");
	posFixa.push("2");
	posFixa.push("*");
	posFixa.push("3");
	posFixa.push("5");

	Pilha<int> resultado;

	while(!posFixa.empty()) {
		if(posFixa.top() != "+" && posFixa.top() != "-" && posFixa.top() != "*" && posFixa.top() != "/") {
			resultado.push(stoi(posFixa.top(), nullptr, 10));
			posFixa.pop();
		} else if(posFixa.top() == "+") {
			num2 = resultado.top();
			resultado.pop();
			num1 = resultado.top();
			resultado.pop();
			resultado.push(num1 + num2);
			posFixa.pop();
		} else if(posFixa.top() == "-") {
			num2 = resultado.top();
			resultado.pop();
			num1 = resultado.top();
			resultado.pop();
			resultado.push(num1 - num2);
			posFixa.pop();
		} else if(posFixa.top() == "*") {
			num2 = resultado.top();
			resultado.pop();
			num1 = resultado.top();
			resultado.pop();
			resultado.push(num1 * num2);
			posFixa.pop();
		} else if(posFixa.top() == "/") {
			num2 = resultado.top();
			resultado.pop();
			num1 = resultado.top();
			resultado.pop();
			resultado.push(num1 / num2);
			posFixa.pop();
		} else {
			cout << "A operacao passada nao existe! Neste programa sao aceitos apenas +, -, *, /" << endl;
		}
	}

	cout << "resultado final: " << resultado.top() << endl;

	return 0;
}