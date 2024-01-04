#ifndef BATALHANAVAL_H_
#define BATALHANAVAL_H_

#include "campodebatalha.h"

class BatalhaNaval{
private:
    CampoDeBatalha *campo;
    int submarinos;
    int destroyers;
    int cruzares;
public:
    BatalhaNaval(int tamanho = 14) : submarinos(0), destroyers(0), cruzares(0){
        try{
            campo = new CampoDeBatalha(tamanho);
        }catch(std::bad_alloc&){
            throw std::string("Memoria insuficiente");
        }
    }
    ~BatalhaNaval(){
        if (campo){
            delete campo;
        }
    }
    void limparConsole(){
        system("clear");
    }
    void desenharMenu(){
        limparConsole();
        std::cout << "\tBatalha Naval" << std::endl;
        std::cout << "\t1 - Iniciar" << std::endl;
        std::cout << "\t2 - Creditos" << std::endl;
        std::cout << "\t3 - Sair" << std::endl;
    }
    void iniciar(){
        limparConsole();
        std::cout << "Digite o numero de submarinos: ";
        std::cin >> submarinos;
        std::cout << "Digite o numero de destroyers: ";
        std::cin >> destroyers;
        std::cout << "Digite o numero de cruzares: ";
        std::cin >> cruzares;
        int linha, coluna;
        char simbolo;
        for (int i = 0; i < submarinos; i++){
            limparConsole();
            desenharMatriz();
            std::cout << "Digite a posicao do submarino " << i + 1 << ": ";
            std::cin >> linha >> coluna;
            campo->setMatriz(linha, coluna, 'S');
        }
        for (int i = 0; i < destroyers; i++){
            limparConsole();
            desenharMatriz();
            std::cout << "Digite a posicao do destroyer " << i + 1 << ": ";
            std::cin >> linha >> coluna;
            campo->setMatriz(linha, coluna, 'D');
        }
        for (int i = 0; i < cruzares; i++){
            limparConsole();
            desenharMatriz();
            std::cout << "Digite a posicao do cruzares " << i + 1 << ": ";
            std::cin >> linha >> coluna;
            campo->setMatriz(linha, coluna, 'C');
        }
        limparConsole();
        desenharMatriz();

    }
    void creditos(){
        std::cout << "Desenvolvido por: \n\tPedro Henrique Brito da Silva Miranda" << std::endl;
    }
    void start(){
        desenharMenu();
        int opcao;
        std::cout << "Digite a opcao: ";
        std::cin >> opcao;
        switch (opcao){
            case 1:
                iniciar();
                break;
            case 2:
                creditos();
                break;
            default:
                break;
        }
    }
    void desenharMatriz()const{
        if (!campo){
            throw std::string("Campo de batalha nao existe");
        }
        for(int i = 0; i < campo->getTamanho(); i++){
            std::cout << "Linha " << i + 1 << "\t";
            for(int j = 0; j < campo->getTamanho(); j++){
                std::cout << campo->getMatriz(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }
};

#endif