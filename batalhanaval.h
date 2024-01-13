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
        if (campo_player){
            delete campo_player;
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
            std::cout << char(10);
        }
    }
    void desistir(){
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
        return coordenada - 1;
    }
    void setSubmarinos(int submarino)
    {
        if (!campo_setado){
            throw std::string("campo nao existe");
        }
        if (submarino < 0)
        {
            throw std::string("Nao pode ser negativo");
        }
        if (submarino > campo_setado->getTamanho() * campo_setado->getTamanho()){
            throw std::string("Nao pode ser maior que a quantidade de slots possiveis");
        }
        if (campo_setado->getTamanho() <= campo_setado->getQuantidadeElementos()){
            throw std::string("Nao pode mais ser submetido submarinos, ja esta cheio");
        }
        this->submarinos = submarino;
    }
    void setDestroyers(int destroyer)
    {
        if (!campo_setado){
            throw std::string("campo nao existe");
        }
        if (destroyer < 0)
        {
            throw std::string("Nao pode ser negativo");
        }
        if (destroyer > campo_setado->getTamanho() * campo_setado->getTamanho()){
            throw std::string("Nao pode ser maior que a quantidade de slots possiveis");
        }
        if (campo_setado->getTamanho() <= campo_setado->getQuantidadeElementos()){
            throw std::string("Nao pode ser submetido destroyers, ja esta cheio");
        }
        this->destroyers = destroyer;
    }
    void setCruzares(int cruzados)
    {
        if (!campo_setado){
            throw std::string("Nao existe campo");
        }
        if (cruzados < 0)
        {
            throw std::string("Nao pode ser negativo");
        }
        if (cruzados > campo_setado->getTamanho() * campo_setado->getTamanho()){
            throw std::string("Nao pode ser maior que a quantidade de slots possiveis");
        }
        if (campo_setado->getTamanho() <= campo_setado->getQuantidadeElementos()){
            throw std::string("Nao pode ser submetido mais cruzares, ja esta cheio");
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
            campo_setado->setMatriz(linha, coluna, simbolo);
        }
    }
    void finalizar(){
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
        if (campo_setado->getQuantidadeElementos() != 0){
            campo_setado->resetMatriz();
        }
        limparConsole();
        setSubmarinos(lerQuantidade("Submarinos"));
        setDestroyers(lerQuantidade("Destroyers"));
        setCruzares(lerQuantidade("Cruzares"));
        inserirMapa("Submarinos", submarinos, 'S');
        inserirMapa("Destroyers", destroyers, 'D');
        inserirMapa("Cruzares", cruzares, 'C');
        if (campo_setado->getQuantidadeElementos() == 0){
            throw std::string("Quantidade de elementos 0, jogo nao iniciado");
        }
        limparConsole();
        try{
            if (campo_player){
                delete campo_player;
            }
            campo_player = new CampoDeBatalha(campo_setado->getTamanho());
            while (campo_player->getQuantidadeElementos() != campo_setado->getQuantidadeElementos()){
                limparConsole();
                std::cout << "Bom jogo!" << char(10);
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
                ++tentativas;
                char simbolo = campo_setado->getMatriz(linha, coluna);
                try{
                    if (simbolo == '_'){
                        campo_player->setMatriz(linha, coluna, '*');
                    }else{
                        campo_player->setMatriz(linha, coluna, simbolo);
                    }
                }catch(std::string& e){
                    std::cout << e << char(10);
                }
            }
            finalizar();
        }catch(std::bad_alloc& e){
            throw std::string("nao foi possivel alocar memoria");
        }
    }
    void creditos()
    {
        std::cout << "Desenvolvido por: \n\tPedro Henrique B S Miranda" << std::endl;
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