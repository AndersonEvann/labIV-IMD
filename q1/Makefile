palindromo: lista.o pilha.o palindromo.o
	g++ -o palindromo lista.o pilha.o palindromo.o
palindromo.o:
	g++ -g -Wall -pedantic -std=c++11 -c palindromo.cpp
pilha.o: pilha.h
	g++ -g -Wall -pedantic -std=c++11 -c pilha.cpp
lista.o: lista.h
	g++ -g -Wall -pedantic -std=c++11 -c lista.cpp
clean:
	rm -f core palindromo lista.o pilha.o palindromo.o
