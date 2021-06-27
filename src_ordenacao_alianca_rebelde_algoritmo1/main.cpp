#include <iostream> //apenas para cin, cout, etc. TODOS os metodos de ordenacao foram implementados manualmentente!
#include <string>
#include "headers/civilizacao.h"
#include "headers/quicksort.h"

int main(){
    
    int numero_civilizacoes;
    std::cin>>numero_civilizacoes;                                                   //recebendo numero de civilizacoes
    
    Civilizacao *civilizacoes;
    civilizacoes = (Civilizacao *) malloc(numero_civilizacoes*sizeof(Civilizacao));  //alocando array de Civilizacoes em memoria

    std::string nome;                                                                //preenchendo array com os atributos de cada civilizacao
    int distancia, tamanho, i = 0, checaeof;
    while (scanf("%d", &checaeof) != EOF){
        std::cin>>nome>>distancia>>tamanho;
        civilizacoes[i].set_nome(nome);
        civilizacoes[i].set_distancia(distancia);
        civilizacoes[i].set_tamanho(tamanho);
        i++;
    }
    
    Quicksort::ordena(civilizacoes, numero_civilizacoes);                             //ordenacao do array de civilizacoes propriamente dita

    for(i=0; i<numero_civilizacoes; i++){                                             //impressao das civilizacoes linha por linha
        civilizacoes[i].imprime_civilizacao();
    }
    
    free(civilizacoes);                                                               //liberacao da memoria alocada para o array
    return 0;

}