#ifndef INSERCAO_H
#define INSERCAO_H
#include <string>
#include "civilizacao.h"

class Quicksort{                                        
    public:
        void static particao(Civilizacao* , int, int, int* , int* ); //metodo responsavel pelo particionamento do array, trocando as posicoes das civilizacoes com base no pivo
        void static ordenacao(Civilizacao* , int , int );            //metodo responsavel por ordenar um range do array
        void static ordena(Civilizacao* ,int );                      //metodo responsavel por chamar ordenacao em todo o array
};

#endif