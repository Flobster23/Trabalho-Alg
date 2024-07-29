#include <iostream>
#include <cmath>
#include <string>
#include <ctime>

#define rTotais 36

using namespace std;

int main(){
    int i, j, nJogadores, rJogador, D = sqrt(rTotais), l, c, pistas, armadi, dima; 
    char P1 = 65, P2 = 49;
    string minaE[D][D], mina[D][D];
    cout << "Bem vindos a mina de diamantes do antigo imperador Skar! Vocês foram os escolhidos para encontrar os tesouros perdidos, prestem muita atenção nas pistas e cuidado com as armadilhas, boa sorte." << endl;
    cout << endl << "Escolha o número de jogadores (de 2 a 4):" << endl;
    cin >> nJogadores;
    string jogadores[nJogadores + 1];
    rJogador = rTotais / nJogadores;
    cout << endl;
    srand(time(NULL));
    pistas = ceil(0.05 * rTotais);
    armadi = ceil(0.1 * rTotais);
    dima = ceil(0.6 * rTotais);

    for(l = 0; l < D; l++){
        for(c = 0; c < D; c++){
            minaE[l][c].append(1,P1);
            minaE[l][c].append(1,P2);
            P2++;
        }
        P2 = 49;
        P1++;
    }

    for(i = 1; i <= nJogadores; i++){
        cout << "Identifique-se, jogador " << i << ":" << endl;
        cin.ignore();
        getline(cin, jogadores[i]);
        cout << endl;
    }

    for(l = 0; l < D; l++){
        for(c = 0; c < D; c++){
            
        }
    }
    

}