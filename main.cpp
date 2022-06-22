#include <iostream>
#include<stdlib.h>
using namespace std;
int main(){
    setlocale(LC_ALL, "");
    int i,j,submarinos,x,contarnavios=0,menu,nVa,lampada=0;

    // inicio do programa, ler quantos submarinos terá
// INICIO ADM / SETGAME
    cout << "\tBATALHA NAVAL\n";
    cout << "\t 1-JOGAR\n";
    cout << "\t 2-CRÉDITOS\n";
    cout << "\t 3-SAIR\n";
    cin >> menu;
    switch (menu){
    case 1:
        system("cls");
        system("clear");
        cout << "Informe o número de submarinos (de 0 a 20)\n";
        cin >> submarinos;
        while (submarinos<0 || submarinos>20){
            cout << "Número inválido, tente novamente: ";
            cin >> submarinos;
        }
        if (submarinos==0){
            lampada++;
        }
        break;
    case 2:
        cout << "Aluno: Pedro Henrique B S Miranda\n";
        return 0;
        break;
    default:
        return 0;
    }
    system("cls");
    system("clear");

    // reset matriz
    int matriz[14][14];
    char caracteres[14][14];
    for (i=0; i<14; i++){
        for (j=0; j<14; j++){
            matriz[i][j]=0;
            caracteres[i][j]='_';
        }
    }
// Ler linhas e colunas submarino
    while (submarinos>0){
//Desenha os números de linhas e colunas da matriz.
    // colunas
    for (x=1; x<=14; x++){
        if (x==1){
            cout << "   " << x << " ";
        }else{
            if (x<14){
                cout << x << " ";
        }else{
            cout << x << "\n";
            }
        }
    }
    // linhas
    int linha=1;
    for (x=0; x<14; x++){
        i=0;
        if (linha<10){
        cout << linha << "  ";
        }else{
            cout << linha << " ";
        }
        while (i<14){
            if (i<9){
                cout << caracteres[x][i] << " ";
            }else{
                cout << caracteres[x][i] << "  ";
            }
            i++;
        }
        cout << "\n";
        linha++;
    }
// insert usuario
        do{
            nVa=1;
            cout << "Digite a casa onde deseja colocar um submarino\n";
            cout << "Linha: ";
            cin >> i;
            while (i>14 || i<=0){
                cout << "Número inválido, tente novamente: ";
                cin >> i;
            }
            cout << "Coluna: ";
            cin >> j;
            while (j>14 || j<=0){
                cout << "Número inválido, tente novamente: ";
                cin >> j;
            }
            if (matriz[i-1][j-1]!=0){
                cout << "Essa coordenada já está com um navio alocado, deseja sobrepor?\n";
                cout << "1-SIM\n";
                cout << "2-NÃO, DIGITAR COORDENADA NOVAMENTE\n";
                cin >> nVa;
                if (nVa==1){
                    contarnavios++;
                    matriz[i-1][j-1]=1;
                    caracteres[i-1][j-1]='s';
                    submarinos--;
                    system("cls");
                    system("clear");
                }
            }else{
                contarnavios++;
                matriz[i-1][j-1]=1;
                caracteres[i-1][j-1]='s';
                submarinos--;
                system("cls");
                system("clear");
            }
        }while(nVa!=1);
}
// ler linhas e colunas destroyer
    int destroyer;
    cout << "Insira destroyer (de 0 a 20) ";
    cin >> destroyer;
    while (destroyer<0 || destroyer>20){
        cout << "Número incorreto, tente novamente: ";
        cin >> destroyer;
    }
    if (destroyer==0){
            lampada++;
        }
    system("cls");
    system("clear");
// Ler linhas e colunas destroyer
    while (destroyer>0){
//Desenha os números de linhas e colunas da matriz.
    // colunas
    int casas=0;
    while (casas<2){
    for (x=1; x<=14; x++){
        if (x==1){
            cout << "   " << x << " ";
        }else{
            if (x<14){
                cout << x << " ";
        }else{
            cout << x << "\n";
            }
        }
    }
    // linhas
    int linha=1;
    for (x=0; x<14; x++){
        i=0;
        if (linha<10){
        cout << linha << "  ";
        }else{
            cout << linha << " ";
        }
        while (i<14){
            if (i<9){
                cout << caracteres[x][i] << " ";
            }else{
                cout << caracteres[x][i] << "  ";
            }
            i++;
        }
        cout << "\n";
        linha++;
    }
// insert usuario
    do{
        nVa=1;
        cout << "Digite a casa onde deseja colocar um destroyer(lembrando que 1 destroyer ocupa 2 casas)\n";
        cout << "Linha: ";
        cin >> i;
        while (i>14 || i<=0){
            cout << "Número inválido, tente novamente: ";
            cin >> i;
        }
        cout << "Coluna: ";
        cin >> j;
        while (j>14 || j<=0){
            cout << "Número inválido, tente novamente: ";
            cin >> j;
        }
        if (matriz[i-1][j-1]!=0){
                cout << "Essa coordenada já está com um navio alocado, deseja sobrepor?\n";
                cout << "1-SIM\n";
                cout << "2-NÃO, DIGITAR COORDENADA NOVAMENTE\n";
                cin >> nVa;
                if (nVa==1){
                    contarnavios++;
                    matriz[i-1][j-1]=2;
                    caracteres[i-1][j-1]='d';
                    system("cls");
                    system("clear");
                    casas++;
                }
            }else{
                contarnavios++;
                matriz[i-1][j-1]=2;
                caracteres[i-1][j-1]='d';
                system("cls");
                system("clear");
                casas++;
            }
    }while (nVa!=1);
    }
    destroyer--;
    }
    // ler linhas e colunas cruzador
    int cruzador;
    cout << "Insira cruzador (de 0 a 20) ";
    cin >> cruzador;
    while (cruzador<0 || cruzador>20){
        cout << "Número incorreto, tente novamente: ";
        cin >> cruzador;
    }
    if (cruzador==0){
            lampada++;
        }
    system("cls");
    system("clear");
// Ler linhas e colunas cruzador
    while (cruzador>0){
//Desenha os números de linhas e colunas da matriz.
    // colunas
    int casas=0;
    while (casas<4){
    for (x=1; x<=14; x++){
        if (x==1){
            cout << "   " << x << " ";
        }else{
            if (x<14){
                cout << x << " ";
        }else{
            cout << x << "\n";
            }
        }
    }
    // linhas
    int linha=1;
    for (x=0; x<14; x++){
        i=0;
        if (linha<10){
        cout << linha << "  ";
        }else{
            cout << linha << " ";
        }
        while (i<14){
            if (i<9){
                cout << caracteres[x][i] << " ";
            }else{
                cout << caracteres[x][i] << "  ";
            }
            i++;
        }
        cout << "\n";
        linha++;
    }
// insert usuario
    do {
        nVa=1;
        cout << "Digite a casa onde deseja colocar um cruzador (lembrando que 1 cruzador ocupa 4 casas)\n";
            cout << "Linha: ";
            cin >> i;
            while (i>14 || i<=0){
                cout << "Número inválido, tente novamente: ";
                cin >> i;
            }
            cout << "Coluna: ";
            cin >> j;
            while (j>14 || j<=0){
                cout << "Número inválido, tente novamente: ";
                cin >> j;
            }
            if (matriz[i-1][j-1]!=0){
                cout << "Essa coordenada já está com um navio alocado, deseja sobrepor?\n";
                cout << "1-SIM\n";
                cout << "2-NÃO, DIGITAR COORDENADA NOVAMENTE\n";
                cin >> nVa;
                if (nVa==1){
                    contarnavios++;
                    matriz[i-1][j-1]=4;
                    caracteres[i-1][j-1]='c';
                    system("cls");
                    system("clear");
                    casas++;
                }
            }else{
                contarnavios++;
                matriz[i-1][j-1]=4;
                caracteres[i-1][j-1]='c';
                system("cls");
                system("clear");
                casas++;
            }
    }while (nVa!=1);
        }
        cruzador--;
    }

// INICIO JOGO PLAYER 1

    cout << "    BOM JOGO!\n";
// reset matriz
    for (i=0; i<14; i++){
        for (j=0; j<14; j++){
            caracteres[i][j]='_';
        }
    }
// começa o gameplay
int contarjogadas=0;
while(contarjogadas < contarnavios && i>0 && j>0){
//Desenha os números de linhas e colunas da matriz.
    // colunas
    for (x=1; x<=14; x++){
        if (x==1){
            cout << "   " << x << " ";
        }else{
            if (x<14){
                cout << x << " ";
        }else{
            cout << x << "\n";
            }
        }
    }
    // linhas
    int linha=1;
    for (x=0; x<14; x++){
        i=0;
        if (linha<10){
        cout << linha << "  ";
        }else{
            cout << linha << " ";
        }
        while (i<14){
            if (i<9){
                cout << caracteres[x][i] << " ";
            }else{
                cout << caracteres[x][i] << "  ";
            }
            i++;
        }
        cout << "\n";
        linha++;
    }
    // insert usuario
        cout << "Digite a casa onde deseja jogar uma bomba\n";
            cout << "Linha: ";
            cin >> i;
            while (i>14){
                cout << "Número inválido, tente novamente: ";
                cin >> i;
            }
            cout << "Coluna: ";
            cin >> j;
            while (j>14){
                cout << "Número inválido, tente novamente: ";
                cin >> j;
            }
            system("cls");
            system("clear");

            if (matriz[i-1][j-1]==0){
                caracteres[i-1][j-1]='*';
                cout << "   ÁGUA\n";
            }
            if (matriz[i-1][j-1]==1){
                caracteres[i-1][j-1]='s';
                cout << "   VOCÊ ACERTOU UM SUBMARINO!\n";
                contarjogadas++;
            }
            if (matriz[i-1][j-1]==2){
                caracteres[i-1][j-1]='d';
                cout << "   VOCÊ ACERTOU UM DESTROYER!\n";
                contarjogadas++;
            }
            if (matriz[i-1][j-1]==4){
                caracteres[i-1][j-1]='c';
                cout << "   VOCÊ ACERTOU UM CRUZADOR!\n";
                contarjogadas++;
            }
}
    system("cls");
    system("clear");
if (i>0 && j>0 && lampada!=3){
    cout << "PARABÉNS, VOCÊ ACERTOU TODOS OS INIMIGOS!!\nESSA É A MATRIZ FINAL: \n";
//Desenha os números de linhas e colunas da matriz.
// colunas
    for (x=1; x<=14; x++){
        if (x==1){
            cout << "   " << x << " ";
        }else{
            if (x<14){
                cout << x << " ";
        }else{
            cout << x << "\n";
            }
        }
    }
    // linhas
    int linha=1;
    for (x=0; x<14; x++){
        i=0;
        if (linha<10){
        cout << linha << "  ";
        }else{
            cout << linha << " ";
        }
        while (i<14){
            if (i<9){
                cout << caracteres[x][i] << " ";
            }else{
                cout << caracteres[x][i] << "  ";
            }
            i++;
        }
        cout << "\n";
        linha++;
    }
}else{
    if (lampada==3){
        return 0;
    }else{
            cout << "DESISTIU SOLDADO? ESSAS ERAM AS COORDENADAS CORRETAS: \n";
    // matriz correta
        for (i=0; i<14; i++){
            for (j=0; j<14; j++){
                if (matriz[i][j]==0){
                    caracteres[i][j]='_';
                }
                if (matriz[i][j]==1){
                    caracteres[i][j]='s';
                }
                if (matriz[i][j]==2){
                    caracteres[i][j]='d';
                }
                if (matriz[i][j]==4){
                    caracteres[i][j]='c';
                }
            }
        }
    //


        //Desenha os números de linhas e colunas da matriz.
    // colunas
        for (x=1; x<=14; x++){
            if (x==1){
                cout << "   " << x << " ";
            }else{
                if (x<14){
                    cout << x << " ";
            }else{
                cout << x << "\n";
                }
            }
        }
        // linhas
        int linha=1;
        for (x=0; x<14; x++){
            i=0;
            if (linha<10){
            cout << linha << "  ";
            }else{
                cout << linha << " ";
            }
            while (i<14){
                if (i<9){
                    cout << caracteres[x][i] << " ";
                }else{
                    cout << caracteres[x][i] << "  ";
                }
                i++;
            }
            cout << "\n";
            linha++;
        }
    }
}
return 0;
}
