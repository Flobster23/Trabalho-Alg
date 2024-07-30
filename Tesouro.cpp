#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include <iomanip>

#define rTotais 36

using namespace std;

int main(){
    int i, j, nJogadores, rJogador, D = sqrt(rTotais), l, c, pistas, armadi, dima, num1, num2, auxR, numA; 
    char P1 = 65, P2 = 49, mina[D][D];
    string minaE[D][D], quadro;
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
    auxR = rTotais;

    for(l = 0; l < D; l++){
        for(c = 0; c < D; c++){
            minaE[l][c].append(1,P1);
            minaE[l][c].append(1,P2);
            P2++;
        }
        P2 = 49;
        P1++;
    }
    
    for(l = 0; l < D; l++){
        for(c = 0; c < D; c++){
            mina[l][c] = '0';
        }
    }
    
    while(pistas > 0){
        num1 = rand() % D;
        num2 = rand() % D;
        if(mina[num1][num2] == '0'){
           mina[num1][num2] = 'P';
           pistas --;
        }
    }
    
    while(armadi > 0){
        num1 = rand() % D;
        num2 = rand() % D;
        if(mina[num1][num2] == '0'){
            numA = rand() % 3;
            switch(numA){
                case 0:
                    mina[num1][num2] = '!';
                    break;
                case 1:
                    mina[num1][num2] = '-';
                    break;
                case 2:
                    mina[num1][num2] = 'X';
                    break;
            }
            armadi --;
        }
    }
    
    while(dima > 0){
        num1 = rand() % D;
        num2 = rand() % D;
        if(mina[num1][num2] == '0'){
           mina[num1][num2] = 'D';
           dima --;
        }
    }
    
    cin.ignore();

    for(i = 1; i <= nJogadores; i++){
        cout << "Identifique-se, jogador " << i << ":" << endl;
        getline(cin, jogadores[i]);
    }
    
    while(auxR > 0){
        for(i = 1; i <= nJogadores; i++){
            cout << "Escolha um quadro, " << jogadores[i] << "." << endl;
            cin >> quadro;
            for(l = 0; l < D; l++){
                for(c = 0; c < D; c++){
                    if(minaE[l][c] == quadro){
                        minaE[l][c] = mina[l][c];
                        for(l = 0; l < D; l++){
                            for(c = 0; c < D; c++){
                            cout << setw(3) << minaE[l][c];
                            }
                            cout << endl;
                        }
                        cout << endl;
                        switch(mina[l][c]){
                            
                        }
                    }
                }
            }
        }
        auxR = auxR - nJogadores;
    }
    
    return 0;
    
}
