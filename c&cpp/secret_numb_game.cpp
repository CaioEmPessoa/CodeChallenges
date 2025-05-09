#include <iostream>
#include <cstdlib> 
#include <ctime>

int main() {
    int secretNum;
    int chooseNum;
    
    std::cout << "Tente adivinhar um número secreto de 1 a 100!\n";

    srand(time(0));
    secretNum = (std::rand() % 100) + 1;

    while (chooseNum != secretNum) {
        std::cin >> chooseNum;
        if (chooseNum > secretNum) std::cout << "O número é menor.\n";
        else if (chooseNum < secretNum) std::cout << "O numero é maior.\n";
    }

    std::cout << "Parabens! o número era \"" << secretNum << "\"\n";

}