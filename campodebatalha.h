#ifndef CAMPODEBATALHA_H_
#define CAMPODEBATALHA_H_

#include <iostream>

class CampoDeBatalha
{
private:
    int tamanho;
    char **matriz;
    int quantidade_elementos;

public:
    CampoDeBatalha(int tamanho = 14) : tamanho(tamanho),
                                       matriz(0),
                                       quantidade_elementos(0)
    {
        if (tamanho <= 0)
        {
            throw std::string("Tamanho invalido");
        }
        this->tamanho = tamanho;
        try{
            this->matriz = new char *[tamanho];
            for (int i = 0; i < tamanho; i++)
            {
                this->matriz[i] = new char[tamanho];
            }
            resetMatriz();
        }catch(std::bad_alloc&){
            throw std::string("Memoria insuficiente");
        }
    }
    char getMatriz(int linha, int coluna)const{
        if (linha < 0 || linha >= tamanho || coluna < 0 || coluna >= tamanho)
        {
            throw std::string("Posicao invalida");
        }
        return matriz[linha][coluna];
    }
    void setMatriz(int linha, int coluna, char simbolo){
        if (linha < 0 || linha >= tamanho || coluna < 0 || coluna >= tamanho)
        {
            throw std::string("Posicao invalida");
        }
        if (matriz[linha][coluna] != '_'){
            throw std::string("Ja possui um elemento nesta coordenada");
        }
        if (simbolo == '*'){
            --quantidade_elementos;
        }
        ++quantidade_elementos;
        matriz[linha][coluna] = simbolo;
    }
    int getTamanho()const{
        return tamanho;
    }
    int getQuantidadeElementos()const{
        return quantidade_elementos;
    }
    void resetMatriz(){
        if (matriz && tamanho){
            for (int i = 0; i < tamanho; ++i){
                for (int j = 0; j < tamanho; ++j){
                    matriz[i][j] = '_';
                }
            }
        }
        quantidade_elementos = 0;
    }
    void resetMatriz(int tamanho){
        if (tamanho <= 0){
            throw std::string("tamanho invalido");
        }
        if (matriz){
            for (int i = 0; i < this->tamanho; ++i){
                delete[] this->matriz[i];
            }
            delete [] this->matriz;
        }
        try{
            this->tamanho = tamanho;
            matriz = new char*[tamanho];
            for (int i = 0; i < tamanho; ++i){
                matriz[i] = new char[tamanho];
            }
            resetMatriz();
        }catch(std::bad_alloc& e){
            throw std::string("erro ao alocar memoria");
        }
    }
    ~CampoDeBatalha()
    {
        if (matriz && tamanho){
            for (int i = 0; i < tamanho; i++)
            {
                delete[] this->matriz[i];
            }
            delete[] this->matriz;
        }
    }
};

#endif