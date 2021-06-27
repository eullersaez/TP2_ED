#include "headers/mergesort.h"
#include "headers/civilizacao.h"

void Mergesort::mergeTamanho(Civilizacao * civilizacoes, int inicio, int meio, int fim){
    int range1 = meio - inicio + 1;                     //define os ranges com os tamanhos dos subarrays que serao alocados para de fato ordenar.
    int range2 = fim - meio;
    
    Civilizacao *Esquerda = new Civilizacao[range1];    //declaracao e alocacao de memoria para os subarrays caso entrada seja muito grande e nao seja pre alocada toda memoria necessaria
    Civilizacao *Direita = new Civilizacao[range2];     //contiguamente.

    for(int i=0; i<range1; i++){                        //copiando todos os elementos do array inicial para os sub-arrays.
        Esquerda[i] = civilizacoes[inicio+i];
    }
    for(int j = 0; j<range2; j++){
        Direita[j] = civilizacoes[meio+1+j];
    }
    
    int i =0, j=0, k;
    k = inicio;
    while(i<range1 && j<range2){                                    //colocando novamente no array inicial as civilizacoes dos sub-arrays na ordem daqueles que possuirem maiores tamanhos de
        if(Esquerda[i].get_tamanho() >= Direita[j].get_tamanho()){  //populacao. 
            civilizacoes[k] = Esquerda[i];
            i++;
        }else{
            civilizacoes[k] = Direita[j];
            j++;
        }
        k++;
    }
    while(i<range1){                                    //nesse e no proximo loop do tipo while, as civilizacoes remanescentes nos sub-arrays sao inseridas no array inicial. 
        civilizacoes[k] = Esquerda[i];
        i++;
        k++;
    }
    while(j<range2){
        civilizacoes[k] = Direita[j];
        j++;
        k++;
    }
    delete [] Esquerda;             //liberacao de espaco alocado para sub-arrays.
    delete [] Direita;
}

void Mergesort::mergeDistancia(Civilizacao * civilizacoes, int inicio, int meio, int fim){  //metodo segue a mesma logica do metodo implementado acima, no entanto agora combina com base na 
    int range1 = meio - inicio + 1;                                                         //ordem crescente da distancia das civilizacoes.
    int range2 = fim - meio;
    
    Civilizacao *Esquerda = new Civilizacao[range1];
    Civilizacao *Direita = new Civilizacao[range2];

    for(int i=0; i<range1; i++){
        Esquerda[i] = civilizacoes[inicio+i];
    }
    for(int j = 0; j<range2; j++){
        Direita[j] = civilizacoes[meio+1+j];
    }
    
    int i =0, j=0, k;
    k = inicio;
    while(i<range1 && j<range2){
        if(Esquerda[i].get_distancia() <= Direita[j].get_distancia()){  //coloca-se novamente no array inicial as civilizacoes dos sub-arrays na ordem daqueles que possuirem menores distancias.
            civilizacoes[k] = Esquerda[i];                              //os demais passos seguem a mesma logica do metodo implementado acima.
            i++;
        }else{
            civilizacoes[k] = Direita[j];
            j++;
        }
        k++;
    }
    while(i<range1){
        civilizacoes[k] = Esquerda[i];
        i++;
        k++;
    }
    while(j<range2){
        civilizacoes[k] = Direita[j];
        j++;
        k++;
    }
    delete [] Esquerda;
    delete [] Direita;
}

void Mergesort::mergeSortTamanho(Civilizacao * civilizacoes, int inicio, int fim){     //ordena o vetor com base no tamanho descrescente da populacao
    if(inicio<fim){
        int meio = ( inicio + fim-1 )/2;                    //calcula o meio do vetor
        mergeSortTamanho(civilizacoes, inicio, meio);       //chama recursivamete para ordenar a primeira parte
        mergeSortTamanho(civilizacoes, meio+1, fim);        //chama recursivamente para ordenar a segunda parte
        mergeTamanho(civilizacoes, inicio, meio, fim);      //combina utilizando o metodo merge para o tamanho.
    }
}

void Mergesort::mergeSortDistancia(Civilizacao * civilizacoes, int inicio, int fim){    //segue a mesma logica do metodo implementado acima, no entanto combina utilizando o metodo
    if(inicio<fim){                                                                     //merge para a distancia. assim, ordena com base na distancia crescente da civilizacao.
        int meio = ( inicio + fim-1 )/2;
        mergeSortDistancia(civilizacoes, inicio, meio);
        mergeSortDistancia(civilizacoes, meio+1, fim);
        mergeDistancia(civilizacoes, inicio, meio, fim);
    }
}


void Mergesort::ordena(Civilizacao * civilizacoes, int numero_civilizacoes){     //como o mergesort eh estavel, eh possivel que ordenemos primeiro com base no tamanho da populacao
    mergeSortTamanho(civilizacoes, 0, numero_civilizacoes-1);                    //de cada civilizacao em ordem decrescente, de modo a garantir que sempre que houver o caso de uma
    mergeSortDistancia(civilizacoes, 0, numero_civilizacoes-1);                  //civilizacao ter distancia igual a outra, suas posicoes relativas nao sejam alteradas na ordenacao
}                                                                                //por distancia. isso eh exatamente do que o metodo ordena se aproveita e assim consegue ordenar
                                                                                 //conforme pedido na especificacao do trabalho.