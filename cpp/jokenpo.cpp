#include <iostream>
#include <string>

int main() {
    std::cout << "==== Pedra, Papel, ou Tesoura! (JoKenPo) ====" << std::endl;
    int score_one = 0;
    int score_two = 0;
    
    int prev_score_one;
    int prev_score_two;

    bool jogando = true;

    std::string option_one;
    std::string option_two;

    int partidas = 1;

    std:: cout << "Melhor de quantas? ";
    std::cin >> partidas;

    while (partidas >= 1) {
        prev_score_one = score_one;
        prev_score_two = score_two;

        std::cout << "\nPrimeiro jogador: ";
        std::cin >> option_one;
        
        std::cout << "Segundo jogador: ";
        std::cin >> option_two;

        if (option_one == option_two) {
            std::cout << "Empate. Ninguém ganha pontos." << std::endl;
            continue;
        }
        else if (option_one == "pedra") {
            if (option_two == "papel") score_two++;
            else if (option_two == "tesoura") score_one++;
        }
        else if (option_one == "papel") {
            if (option_two == "tesoura") score_two++;
            else if (option_two == "pedra") score_one++;
        }
        else if (option_one == "tesoura") {
            if (option_two == "papel") score_one++;
            else if (option_two == "pedra") score_two++;
        }

        std::cout << ((prev_score_one != score_one) ? "Jogador UM venceu!" : "Jogador DOIS venceu!") << std::endl;

        partidas--;
    }
    std::cout << "\nPontuação Total: \n Jogador UM:" << score_one << " \n Jogador DOIS:" << score_two <<" \n" << 
                 "Vencedor mestre: " << ((score_one > score_two) ? "Jogador UM !!" : "Jogador DOIS !!");
}