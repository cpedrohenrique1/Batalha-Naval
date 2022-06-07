#include <iostream>
#include<stdlib.h>
using namespace std;
int main(){
    setlocale(LC_ALL, "");
    int i,j,submarinos,x;

    // inicio do programa, ler quantos submarinos terá
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
        matriz[i-1][j-1]=1;
        caracteres[i-1][j-1]='*';
        submarinos--;
        system("cls");
        system("clear");
    }


return 0;
}
