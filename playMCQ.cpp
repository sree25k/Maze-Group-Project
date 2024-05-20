#include <iostream>
#include <fstream>
#include <vector>
#include "enterMCQ.h"
#include <sstream>
#include "game_functions.h"

using namespace std;

namespace MCQ {

    const int SIZE = 50;

    //print maps
    void printMap(const vector <vector<string> > &map) {
        for (const auto &row: map) {
            for (const auto &cell: row) {
                cout << cell;
            }
            cout << endl;
        }
    }
    //Checks valid move based on if next is empty space
    bool isValidMove(const vector <vector<string> > &map, int x, int y) {
        if (x >= 0 && x < SIZE && y >= 0 && y < SIZE && map[x][y] != "▒▒▒") {
            return true;
        }
        return false;
    }

    //read maze from txt file and returns at vector
    vector <vector<string> > read_maze(const string &filename) {
        vector <vector<string> > grid;
        ifstream file(filename);
        string line;

        if (!file) {
            cout << "Error in file opening!" << endl;
            throw runtime_error("Failed to open file.");
        }

        while (getline(file, line)) {
            vector <string> row;
            stringstream ss(line);
            string element;

            // Read each quoted element
            while (getline(ss, element, '"')) {
                // Skip empty parts and spaces
                if (!element.empty() && element != " ") {
                    row.push_back(element);
                }
            }
            grid.push_back(row);
        }

        file.close();
        return grid;
    }

    void playGame() {
        vector <vector<string> > map = read_maze("map2.txt");

        cout << "Welcome to Map 2!" << endl;

        int posX = 0;
        int posY = 0;

        while (true) {
            system("clear");
            map[posX][posY] = " ♀ ";
            printMap(map);

            char input;
            cout << "Enter your move (W/A/S/D): ";
            cin >> input;

            int newX = posX;
            int newY = posY;

            //changes temp positiion based on input
            switch (input) {
                case 'w':
                    newX--;
                    break;  // Move up
                case 's':
                    newX++;
                    break;  // Move down
                case 'a':
                    newY--;
                    break;  // Move left
                case 'd':
                    newY++;
                    break;  // Move right
                default:
                    cout << "Invalid move. Try again." << endl;
                    continue;
            }

            //updates if it is a valid move
            if (isValidMove(map, newX, newY)) {
                cout << "Player moved ";

                if (input == 'w')
                    cout << "up";
                else if (input == 's')
                    cout << "down";
                else if (input == 'a')
                    cout << "leftward";
                else if (input == 'd')
                    cout << "rightward";

                cout << endl;

                //calls the MCQ function if next space is Q block.
                if (map[newX][newY] == " ? ") {
                    cout << "Entering MCQ..." << endl;
                    if (enterMCQ()) {
                        map[posX][posY] = "   ";

                        posX = newX;
                        posY = newY;
                    } else {
                        cout << "Try Again!";
                    }

                } else if (newX == SIZE - 1 && newY == SIZE - 1) {
                    cout << "Congratulations! You won!" << endl;
                    return;
                } else {
                    map[posX][posY] = "   ";

                    posX = newX;
                    posY = newY;
                }

            } else {
                cout << "Move not valid. Try again." << endl;
            }
        }
    }

    int playMCQ() {
        playGame();
        return 0;
    }
}
