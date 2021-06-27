#include "headers/insercao.h"
#include "headers/civilizacao.h"

void Insercao::ordena(Civilizacao *civilizacoes,int numero_civilizacoes){
        int i,j;
        Civilizacao aux;
        for(i=1;i<numero_civilizacoes;i++){                                         //percorre o vetor da posicao 1 ate a ultima posicao
            aux = civilizacoes[i];                                                  //variavel auxiliar do tipo Civilizacao recebe cada item na posicao i para comparacao.
            j = i-1;
            while(j>=0 && aux.get_tamanho() > civilizacoes[j].get_tamanho()){       //loop percorre todas as posicoes anteriores procurando a posicao correta da civilizacao armazenada em aux, que deve ser >= que a próxima civilizacao.
                        civilizacoes[j+1] = civilizacoes[j];                        //vai trocando a posicao da civilizacao anterior ate que a civilizacao chegue na posicao correta.
                j--;
            }
            civilizacoes[j+1] = aux;                                                //insere a civilizacao na posicao correta.
        }
        for(i=1;i<numero_civilizacoes;i++){                                         //mesmas etapas dos aneis anteriores, pois como o algoritmo eh estavel, civilizacoes com tamanhos iguais permanecerao
            aux = civilizacoes[i];                                                  //na mesma posicao relativa umas as outras quando ordenado novamente. assim, como os loops anteriores ficaram responsaveis
            j = i-1;                                                                //por ordenar de forma decrescente por tamanho de populacao, agora basta ordenar de forma crescente por distancia.
            while(j>=0 && aux.get_distancia() < civilizacoes[j].get_distancia()){   //esse loop while faz justamente isso com a condicao da civilizacao na posicao anterior ter distancia <= a distancia de aux.
                    civilizacoes[j+1] = civilizacoes[j];                            
                j--;
            }
            civilizacoes[j+1] = aux;
        }
}