#ifndef CIVILIZACAO_H
#define CIVILIZACAO_H
#include <string>

class Civilizacao{                        //estrutura de dados para comportar uma civilizacao
    private:
        std::string nome;
        int distancia;
        int tamanho;                     //tamanho da populacao 
    
    public:                               
        void set_nome(std::string );     //setters and getters
        void set_distancia(int );
        void set_tamanho(int );
        int get_distancia();
        int get_tamanho();
        void imprime_civilizacao();      //metodo para imprimir os atributos de uma civilizacao em uma unica linha

};

#endif