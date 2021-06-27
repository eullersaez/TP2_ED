#include "headers/selecao.h"
#include "headers/civilizacao.h"

void Selecao::ordena(Civilizacao *civilizacoes,int numero_civilizacoes){ 
        int i, j, indice_a_trocar;
        Civilizacao aux;
        for(i=0;i<numero_civilizacoes-1;i++){               //para cada posicao i contendo uma civilizacao no array
            indice_a_trocar = i;
            for(j=i+1;j<numero_civilizacoes;j++){           //percorre-se todas as posicoes apos a posicao i procurando a civilizacao que contenha a menor distancia, ou ditancia igual porem com maior tamanho de populacao.
                if(civilizacoes[j].get_distancia()<civilizacoes[indice_a_trocar].get_distancia() || civilizacoes[j].get_distancia()==civilizacoes[indice_a_trocar].get_distancia() && civilizacoes[j].get_tamanho()>civilizacoes[indice_a_trocar].get_tamanho()){
                    indice_a_trocar = j;
                }
            }
            aux = civilizacoes[i];                           //troca de posicao da civilizacao em i com a civilizacao em indice_a_tocar
            civilizacoes[i] = civilizacoes[indice_a_trocar];
            civilizacoes[indice_a_trocar] = aux; 

        }
}
