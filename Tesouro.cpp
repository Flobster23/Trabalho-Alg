#include <iostream>
#include <cmath>
#include <string>

#define rTotais 36

using namespace std;

int main(){
    int i, j, nJogadores, rJogador, D = sqrt(rTotais), mina[D][D];
    string J1, J2, J3, J4;
    cout << "Bem vindos a mina de diamantes do antigo imperador Skar! Vocês foram os escolhidos para encontrar os tesouros perdidos, prestem muita atenção nas pistas e cuidado com as armadilhas, boa sorte." << endl;
    cout << endl << "Escolha a número de jogadores:" << endl;
    cin >> nJogadores;
    rJogador = rTotais / nJogadores;
    cout << endl;

    switch (nJogadores){
    case 2:
        cin.ignore();
        cout << "identifique-se, jogador 1:" << endl;
        getline(cin, J1);
        cout << "identifique-se, jogador 2:" << endl;
        getline(cin, J2);
        J3 = '0';
        J4 = '0';
        break;

    case 3:
        cin.ignore();
        cout << "identifique-se, jogador 1:" << endl;
        getline(cin, J1);
        cout << "identifique-se, jogador 2:" << endl;
        getline(cin, J2);
        cout << "identifique-se, jogador 3:" << endl;
        getline(cin, J3);
        J4 = '0';
        break;

    case 4:
        cin.ignore();
        cout << "identifique-se, jogador 1:" << endl;
        getline(cin, J1);
        cout << "identifique-se, jogador 2:" << endl;
        getline(cin, J2);
        cout << "identifique-se, jogador 3:" << endl;
        getline(cin, J3);
        cout << "identifique-se, jogador 4:" << endl;
        getline(cin, J4);
        break; 
    }

}