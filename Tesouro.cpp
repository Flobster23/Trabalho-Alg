#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include <iomanip>

#define D 6

using namespace std;

int l, c;
string minaE[D][D];
char mina[D][D];

void imprimirMinaE(){
    for(int l = 0; l < D; l++){
        for(int c = 0; c < D; c++){
            cout << setw(3) << minaE[l][c];
        }
    cout << endl;
    }
}

int main(){
    int i, j, nJogadores, rTotais = D * D, rJogador, pistas, armadi, dima, num1, num2, numA, num3; 
    char P1 = 65, P2 = 49, escolha;
    string quadro;
    cout << "Bem vindos a mina de diamantes do antigo imperador Skar! Vocês foram os escolhidos para encontrar os tesouros perdidos, prestem muita atenção nas pistas e cuidado com as armadilhas, boa sorte." << endl;
    cout << endl << "Escolha o número de jogadores (de 2 a 4):" << endl;
    cin >> nJogadores;
    int placar[nJogadores + 1] = {0};
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
           mina[num1][num2] = 'X';
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
    
    for(int l = 0; l < D; l++){
        for(int c = 0; c < D; c++){
            cout << setw(3) << mina[l][c];
        }
    cout << endl;
    }
    
    cin.ignore();

    for(i = 1; i <= nJogadores; i++){
        cout << "Identifique-se, jogador " << i << ":" << endl;
        getline(cin, jogadores[i]);
    }
    
    imprimirMinaE();
    
    while(rTotais > 0){
        for(i = 1; i <= nJogadores; i++){
            cout << "Escolha um quadro, " << jogadores[i] << "." << endl;
            cin >> quadro;
            l = (int) quadro[0] - 65;
            c = (int) quadro[1] - 49;
            minaE[l][c] = mina[l][c];
            imprimirMinaE();
            switch(mina[l][c]){
                case 'D':
                    num1 = (rand() % 10) + 1;
                    cout << "Parabéns, você achou um diamante de " << num1 << " quilates!" << endl;
                    num2 = rand() % 10;
                    if(num2 == 5){
                        cout << endl;
                        cout << "Assim que você pegou o diamante nas mãos, um mago apareceu, ele tem uma proposta para te oferecer:" << endl;
                        cout << "Olá explorador, você está afim de duplicar esse diamante? Eu posso realizar uma magia, porém, existe a chance de você perde-lo, e aí, o que acha?" << endl;
                        cout << "Faça sua escolha (apenas S ou N): " << endl;
                        cin >> escolha;
                        if(escolha == 'S'){
                            num3 = rand() % 2;
                            if(num3 = 0){
                                num1 *= 2;
                                cout << "Consegui duplicar seu diamante, você está com sorte." << endl;
                            }else{
                                cout << "Putz! A magia deu errado, você sentou na graxa veia!" << endl;
                            }
                        }
                    }
                    placar[i] += num1;
                    break;
                    
                case 'P':
                    cout << "Você encontrou uma pista!" << endl;
                    num1 = 0;
                    num2 = 0;
                    if(l-1 >= 0 && l != 0){
                        if(mina[l-1][c] == 'D'){
                            num1++;
                        }
                        if(mina[l-1][c] == 'X'){
                            num2++;
                        }
                    }
                    
                    if(l+1 >= 0 && l < D-1){
                        if(mina[l+1][c] == 'D'){
                            num1++;
                        }
                        if(mina[l+1][c] == 'X'){
                            num2++;
                        }
                    }
                    if(c-1 >= 0 && c != 0){
                        if(mina[l][c-1] == 'D'){
                            num1++;
                        }
                        if(mina[l][c-1] == 'X'){
                            num2++;
                        }
                    }
                    if(c+1 >= 0 && c < D-1){
                        if(mina[l][c+1] == 'D'){
                            num1++;
                        }
                        if(mina[l][c+1] == 'X'){
                            num2++;
                        }
                    }
                    if(num1 == 0){
                        cout << "É melhor não procurar diamantes por aqui ";
                    }
                    if(num1 == 1){
                        cout << "Não há muita coisa por aqui ";
                    }
                    if(num1 == 2){
                        cout << "Tem alguns diamantes pela área ";
                    }
                    if(num1 == 3 || num1 == 4){
                        cout << "Você está no lugar certo ";
                    }
                    if(num2 == 0){
                        cout << "e este lugar é seguro." << endl;
                    }
                    if(num2 > 0){
                        cout << "e este lugar é perigoso." << endl;
                    }
            }
        }
        rTotais = rTotais - nJogadores;
    }
    
    return 0;
    
}
