#ifndef CAMPODEBATALHA_H_
#define CAMPODEBATALHA_H_

#include <iostream>

class CampoDeBatalha
{
private:
    int tamanho;
    char **matriz;

public:
    CampoDeBatalha(int tamanho = 14) : tamanho(tamanho),
                                       matriz(0)
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
                for (int j = 0; j < tamanho; j++)
                {
                    this->matriz[i][j] = '_';
                }
            }
        }catch(std::bad_alloc&){
            throw std::string("Memoria insuficiente");
        }
    }
    char getMatriz(int linha, int coluna)const{
        if (linha <= 0 || linha >= tamanho || coluna <= 0 || coluna >= tamanho)
        {
            throw std::string("Posicao invalida");
        }
        return matriz[linha][coluna];
    }
    void setMatriz(int linha, int coluna, char simbolo){
        if (linha <= 0 || linha >= tamanho || coluna <= 0 || coluna >= tamanho)
        {
            throw std::string("Posicao invalida");
        }
        matriz[linha][coluna] = simbolo;
    }
    int getTamanho()const{
        return tamanho;
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