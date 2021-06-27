# == VARIAVEIS ===

CC=g++ # compilador
CFLAGS=-Wall -Wextra # compiler flags
EXEC=./tp2 # nome do executavel que sera gerado

# === REGRAS =====

$(EXEC): main.cpp civilizacao.o selecao.o
	$(CC) $(CFLAGS) main.cpp civilizacao.o selecao.o -o $(EXEC)

main.o: main.cpp 
	g++ -c main.cpp

civilizacao.o: civilizacao.cpp headers/civilizacao.h
	g++ -c civilizacao.cpp

selecao.o: selecao.cpp headers/selecao.h
	g++ -c selecao.cpp 

clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf main.o civilizacao.o selecao.o