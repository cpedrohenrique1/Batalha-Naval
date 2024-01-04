#ifndef BATALHANAVAL_H_
#define BATALHANAVAL_H_

#include "campodebatalha.h"

class BatalhaNaval
{
private:
    CampoDeBatalha *campo_setado;
    CampoDeBatalha *campo_player;
    int submarinos;
    int destroyers;
    int cruzares;
    int tentativas;
public:
    BatalhaNaval(int tamanho = 14) : submarinos(0),
                                     destroyers(0),
                                     cruzares(0),
                                     campo_player(0),
                                     campo_setado(0),
                                     tentativas(0)
    {
        try
        {
            campo_setado = new CampoDeBatalha(tamanho);
        }
        catch (std::bad_alloc &)
        {
            throw std::string("Memoria insuficiente");
        }
    }
    ~BatalhaNaval()
    {
        if (campo_setado)
        {
            delete campo_setado;
        }
    }
    void limparConsole()
    {
        system("clear");
    }
    void desenharMenu()
    {
        limparConsole();
        std::cout << "\tBatalha Naval" << std::endl;
        std::cout << "\t1 - Jogar" << std::endl;
        std::cout << "\t2 - Creditos" << std::endl;
        std::cout << "\t3 - Sair" << std::endl;
    }
    void desenharMatriz(CampoDeBatalha* campo) const
    {
        if (!campo)
        {
            throw std::string("Campo de batalha nao existe");
        }
        for (int i = 0; i < campo->getTamanho(); i++)
        {
            std::cout << "Linha " << i + 1 << "\t";
            for (int j = 0; j < campo->getTamanho(); j++)
            {
                std::cout << campo->getMatriz(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }
    void desistir(){
        if (!campo_player || !campo_setado){
            throw std::string("campos nao setados");
        }
        limparConsole();
        std::cout << "Desistiu? Essas foram as suas tentativas: " << tentativas << '\n';
        std::cout << "esse era o campo de batalha perfeito\n";
        desenharMatriz(campo_setado);
        std::cout << "Esse foi seu jogo:\n";
        desenharMatriz(campo_player);
    }
    int lerQuantidade(std::string entrada)
    {
        std::cout << "Insira a quantidade de " + entrada << ": ";
        int variavel;
        std::cin >> variavel;
        return variavel;
    }
    int lerCoordenadas()
    {
        int coordenada;
        std::cin >> coordenada;
        if (coordenada <= 0 || coordenada > campo_setado->getTamanho())
        {
            throw std::string("Linha invalida");
        }
        return coordenada;
    }
    void setSubmarinos(int submarino)
    {
        if (submarino < 0)
        {
            throw std::string("Nao pode ser negativo");
        }
        this->submarinos = submarino;
    }
    void setDestroyers(int destroyer)
    {
        if (destroyer < 0)
        {
            throw std::string("Nao pode ser negativo");
        }
        this->destroyers = destroyer;
    }
    void setCruzares(int cruzados)
    {
        if (cruzados < 0)
        {
            throw std::string("Nao pode ser negativo");
        }
        this->cruzares = cruzados;
    }
    void inserirMapa(std::string entrada, int quantidade, char simbolo){
        if (!campo_setado){
            throw std::string("campo nao setado");
        }
        int linha, coluna;
        for (int i = 0; i < quantidade; ++i){
            limparConsole();
            desenharMatriz(campo_setado);
            std::cout << "Insira a linha do " << entrada << ' ' << i + 1 << ": ";
            linha = lerCoordenadas();
            std::cout << "Insira a coluna do " << entrada << ' ' << i + 1 << ": ";
            coluna = lerCoordenadas();
            --linha;
            --coluna;
            campo_setado->setMatriz(linha, coluna, simbolo);
        }
    }
    void finalizar(){
        if (!campo_player || !campo_setado){
            throw std::string("campos nao setados");
        }
        limparConsole();
        std::cout << "Parabens!\nVoce finalizou o game!\n";
        std::cout << "Essas foram suas tentativas: " << tentativas << '\n';
        std::cout << "Esse foi seu jogo:\n";
        desenharMatriz(campo_player);
        std::cout << "Esse seria o jogo perfeito:\n";
        desenharMatriz(campo_setado);
    }
    void jogar()
    {
        if (!campo_setado){
            throw std::string("Campo nao foi setado");
        }
        campo_setado->resetMatriz();
        limparConsole();
        setSubmarinos(lerQuantidade("Submarinos"));
        setDestroyers(lerQuantidade("Destroyers"));
        setCruzares(lerQuantidade("Cruzares"));
        inserirMapa("Submarinos", submarinos, 'S');
        inserirMapa("Destroyers", destroyers, 'D');
        inserirMapa("Cruzares", cruzares, 'C');
        if (campo_setado->getQuantidadeElementos() == 0){
            throw std::string("quantidade de elementos 0, jogo nao iniciado");
        }
        limparConsole();
        std::cout << "Bom jogo!\n";
        try{
            if (campo_player){
                delete campo_player;
            }
            campo_player = new CampoDeBatalha(campo_setado->getTamanho());
            for (int i = 0; i < campo_setado->getTamanho() * campo_setado->getTamanho() && campo_player->getQuantidadeElementos() < campo_setado->getQuantidadeElementos(); ++i){
                limparConsole();
                desenharMatriz(campo_player);
                std::cout << "Escolha uma coordenada para lancar uma bomba:\n";
                std::cout << "Linha: ";
                int linha, coluna;
                try{
                    linha = lerCoordenadas();
                }catch(std::string& e){
                    desistir();
                    return;
                }
                std::cout << "Coluna: ";
                try{
                    coluna = lerCoordenadas();
                }catch(std::string& e){
                    desistir();
                    return;
                }
                --linha;
                --coluna;
                ++tentativas;
                char simbolo = campo_setado->getMatriz(linha, coluna);
                if (simbolo == '_'){
                    campo_player->setMatriz(linha, coluna, '*');
                }else{
                    campo_player->setMatriz(linha, coluna, simbolo);
                }
            }
            finalizar();
        }catch(std::bad_alloc& e){
            throw std::string("nao foi possivel alocar memoria");
        }
    }
    void creditos()
    {
        std::cout << "Desenvolvido por: \n\tPedro Henrique Brito da Silva Miranda" << std::endl;
    }
    void start()
    {
        desenharMenu();
        int opcao;
        std::cout << "Digite a opcao: ";
        std::cin >> opcao;
        switch (opcao)
        {
        case 1:
            jogar();
            break;
        case 2:
            creditos();
            break;
        default:
            break;
        }
    }
};

#endif