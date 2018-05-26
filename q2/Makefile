rpn: lista.o pilha.o rpn.o
	g++ -o rpn lista.o pilha.o rpn.o
rpn.o:
	g++ -g -Wall -pedantic -std=c++11 -c rpn.cpp
pilha.o: pilha.h
	g++ -g -Wall -pedantic -std=c++11 -c pilha.cpp
lista.o: lista.h
	g++ -g -Wall -pedantic -std=c++11 -c lista.cpp
clean:
	rm -f core rpn lista.o pilha.o rpn.o
