#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> 
#include <ctime>

using namespace std;

void showTable(vector<vector<string>> table) {
    cout << endl;
    for (size_t x = 0; x <= table.size()-1; x++){
        for (size_t y = 0; y <= table[x].size()-1; y++) {
            cout << table[x][y];
        };
        cout << endl;
    }
}

int main() {
    // initial values
    vector<vector<string>> table = {
        {"[ ]", "[ ]", "[ ]"},
        {"[ ]", "[ ]", "[ ]"},
        {"[ ]", "[ ]", "[ ]"}
    };

    srand(time(0));

    bool jogando = true;
    bool velha = false;
    int partida = 0;
    string ins;

    int ins_x;
    int ins_y;

    showTable(table);

    while (jogando) {
        // player's turn
        if (partida % 2 == 0){        
            cout << "Qual coluna? ";
            cin >> ins_x;
            
            cout << "Qual linha? ";
            cin >> ins_y;

            ins = 'X';

            if (ins_y > 2 || ins_y < 0 || ins_x > 2 || ins_x < 0) {
                cout << "Espaço inválido, insira apenas valores entre 0 e 2.\n\n";
                continue;
            }

        // machine's turn
        } else {
            ins_x = (rand() % 3);
            ins_y = (rand() % 3);
            ins = 'O';
        }

        if (table[ins_y][ins_x] != "[ ]") { 
            cout << "Lugar já ocupado.\n\n";
            partida--;
        }
        else {
            table[ins_y][ins_x] = '['+ins+']';
        }
        if (partida%2!=0) {
            showTable(table);
        }

        // victory check
        for( int i = 0; i < 3; i++) {
            // horizontal
            if( table[i][0] != "[ ]" && table[i][0] == table[i][1] && table[i][1] == table[i][2] ){
                jogando = false;
            }
            // vertical
            if(table[0][i] != "[ ]" && table[0][i] == table[1][i] && table[1][i] == table[2][i] ){
                jogando = false;
            };
        }

        // diagonal
        if (table[1][1] != "[ ]" && 
            (table[0][0] == table[1][1] && table[1][1] == table[2][2] ||
            table[0][2] == table[1][1] && table[1][1] == table[2][0])) {
                jogando = false;
            }
        
        velha = true;
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                if (table[x][y] == "[ ]") {
                    velha = false;
                    break;
                }
            }
            if (!velha) break;
        }

        if (jogando == false) {
                showTable(table);
                jogando = false;
                cout << endl << ins << " ganhou!!\n";
                break;
        }

        if (velha) {
            showTable(table);
            jogando = false;
            cout << "Deu Véia!\n";
            break;
        }
    
        partida++;
    }
}