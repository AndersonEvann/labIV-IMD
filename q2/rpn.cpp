/**
* @file rpn.cpp
* @brief Programa resolve uma expressão pos-fixa.
* @author Anderson Evangelista da Silva
* @brief lista e pilha foram implementados por Teobaldo.
* @since 20/05/2018
* @date 26/05/2018
*/
#include <iostream>
#include <string>

#include "pilha.h"
#include "lista.h"

using namespace std;

int main(int argc, char const *argv[]) {
	int num1, num2;
	Pilha<string> posFixa;
	/** @brief caso necessite fazer outros testes basta alterar o conteudo de posFixa.push abaixo. */
	posFixa.push("/");
	posFixa.push("10");
	posFixa.push("*");
	posFixa.push("2");
	posFixa.push("*");
	posFixa.push("3");
	posFixa.push("5");

	Pilha<int> resultado;
	/** @details Abaixo seguem os testes para obter o resultado da expressão passada. Uma nova
		pilha é criada para armazenar e receber o valor das operações.
	*/
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
		} else {
			num2 = resultado.top();
			resultado.pop();
			num1 = resultado.top();
			resultado.pop();
			resultado.push(num1 / num2);
			posFixa.pop();
		}
	}

	cout << "resultado final: " << resultado.top() << endl;

	return 0;
}