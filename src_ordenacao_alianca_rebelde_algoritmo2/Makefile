# == VARIAVEIS ===

CC=g++ # compilador
CFLAGS=-Wall -Wextra # compiler flags
EXEC=./tp2 # nome do executavel que sera gerado

# === REGRAS =====

$(EXEC): main.cpp civilizacao.o mergesort.o
	$(CC) $(CFLAGS) main.cpp civilizacao.o mergesort.o -o $(EXEC)

main.o: main.cpp 
	g++ -c main.cpp

civilizacao.o: civilizacao.cpp headers/civilizacao.h
	g++ -c civilizacao.cpp

mergesort.o: mergesort.cpp headers/mergesort.h
	g++ -c mergesort.cpp 

clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf main.o civilizacao.o mergesort.o
