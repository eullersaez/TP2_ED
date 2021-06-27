#include "headers/civilizacao.h"
#include <iostream>
#include <string>

void Civilizacao::set_nome(std::string _nome){                  //setters and getters
    this->nome = _nome;
}

void Civilizacao::set_distancia(int _distancia){
    this->distancia = _distancia;
}
          
void Civilizacao::set_tamanho(int _tamanho){
    this->tamanho = _tamanho;
}

int Civilizacao::get_distancia(){
    return distancia;
}

int Civilizacao::get_tamanho(){
    return tamanho;
}

void Civilizacao::imprime_civilizacao(){                        //metodo para impressao dos atributos da civilizacao em uma unica linha
    std::cout<<nome<<" "<<distancia<<" "<<tamanho<<std::endl;
}