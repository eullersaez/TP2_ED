#ifndef INSERCAO_H
#define INSERCAO_H
#include <string>
#include "civilizacao.h"

class Mergesort{                                        
    public:
        void static mergeDistancia(Civilizacao * , int , int , int ); //metodo merge para combinar as civilizacoes pela distancia em ordem crescente
        void static mergeTamanho(Civilizacao * , int , int , int );   //metodo merge para combinar as civilizacoes pelo tamanho em ordem decrescente
        void static mergeSortDistancia(Civilizacao * , int , int );   //metodo combina partes separadamente com base na distancia em ordem crescente
        void static mergeSortTamanho(Civilizacao * , int , int );     //metodo combina partes separadamente com base no tamanho em ordem decrescente
        void static ordena(Civilizacao *, int );                      //metodo realiza a ordenacao com base no mergesort
};

#endif