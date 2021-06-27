#include "headers/quicksort.h"
#include "headers/civilizacao.h"

void Quicksort::particao(Civilizacao *civilizacoes, int inicio, int fim, int *i, int *j){
    Civilizacao x, aux_troca;
    *i = inicio, *j= fim;
    x = civilizacoes[(*i+*j)/2];  //definicao do pivo na metade do array
    do{ 
        //acha a posicao i e j das civilizacoes a serem trocadas, de modo que a da posicao i tera distancia maior do que o pivo, ou distancia igual porem tamanho de populacao menor,
        //enquanto j tem distancia menor do que o pivo ou distancia igual porem tamanho de populacao maior, e, portanto deve vir antes, assim como i deve vir depois.
        while(x.get_distancia() > civilizacoes[*i].get_distancia() || x.get_distancia() == civilizacoes[*i].get_distancia() && x.get_tamanho() < civilizacoes[*i].get_tamanho()) (*i)++;
        while(x.get_distancia() < civilizacoes[*j].get_distancia() || x.get_distancia() == civilizacoes[*j].get_distancia() && x.get_tamanho() > civilizacoes[*j].get_tamanho()) (*j)--;
        if(*i<=*j){
            aux_troca = civilizacoes[*i];           //troca as civilizacoes de posicao sempre que os criterios acima sao atendidos.
            civilizacoes[*i] = civilizacoes[*j];
            civilizacoes[*j] = aux_troca;
            (*i)++;          //incrementando e decrementando os iteradores, servira como condicao de parada da recursao no metodo ordenacao e do proprio metodo particao.
            (*j)--;
        }
    }while(*i<=*j);         //condicao de parada da particao, ou seja, ja passaram do pivo
}

void Quicksort::ordenacao(Civilizacao *civilizacoes, int inicio, int fim){ //metodo recebe array, as posicoes iniciais e finais a serem ordenadas 
    int i, j;
    particao(civilizacoes, inicio, fim, &i, &j);                           //realiza particionamento e trocas de posicoes das civilizacoes
    if(inicio<j){                                                          //e faz isso de forma recursiva ate ter passado por todo o array
        ordenacao(civilizacoes, inicio, j);                                //de forma a deixa-lo ordenado. 
    }
    if(i<fim){
        ordenacao(civilizacoes, i, fim);
    }

}

void Quicksort::ordena(Civilizacao *civilizacoes,int numero_civilizacoes){   //recebe o array a ser ordenado, seu numero de civilizacoes e chama o metodo ordena para todo o array.
        ordenacao(civilizacoes, 0, numero_civilizacoes-1);
}