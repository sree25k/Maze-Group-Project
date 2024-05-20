#include "game_functions.h"
#include <iostream>

int main() {
    int choice;

    std::cout << "Enter 1 to play MCQ game, 2 to play LOCK, 3 to play MONSTER: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            MCQ::playMCQ();
            break;
        case 2:
            LOCK::playLOCK();
            break;
        case 3:
            MONSTER::playMONSTER();
            break;
        default:
            std::cout << "Invalid choice!\n";
            break;
    }

    return 0;
}
