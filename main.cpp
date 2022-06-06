#include <iostream>
#include<stdlib.h>
using namespace std;
int main(){
    setlocale(LC_ALL, "");
    int i,j,submarinos,x;

    // inicio do programa
    cout << "                       BATALHA NAVAL\n";
    cout << "Informe o número de submarinos (de 1 a 20)\n";
    cin >> submarinos;
    while (submarinos<0 || submarinos>20){
        cout << "Número inválido, tente novamente: ";
        cin >> submarinos;
    }
    system("cls");
    system("clear");

    // reset matriz
    int matriz[15][15];
    char caracteres[15][15];
    for (i=1; i<15; i++){
        for (j=1; j<15; j++){
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
    for (x=1; x<15; x++,linha++){
        i=0;
        if (linha<10){
        cout << linha << "  ";
        }else{
            cout << linha << " ";
        }
        while (i<15){
            if (i<9){
                cout << caracteres[x][i] << " ";
            }else{
                cout << caracteres[x][i] << "  ";
            }
            i++;
        }
        cout << "\n";
    }
        cout << "Digite a casa onde deseja colocar um submarino\n";
        cout << "Linha: ";
        cin >> i;
        while (i>14 || i<0){
            cout << "Número inválido, tente novamente: ";
            cin >> i;
        }
        cout << "Coluna: ";
        cin >> j;
        while (j>14 || j<0){
            cout << "Número inválido, tente novamente: ";
            cin >> j;
        }
        matriz[i][j]=1;
        caracteres[i][j]='*';
        submarinos--;
        system("cls");
        system("clear");
    }


return 0;
}
