#include <iostream>
#include <cstdlib>
using namespace std;
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <thread>
#include "game_functions.h"

namespace LOCK {
    const int SIZE = 50;


// Handles Lock, checks if next space is a lock:
    bool check_lock(string x) {
        return (x == "♣ ꗃ" || x == "♠ ꗃ" || x == "♥ ꗃ" || x == "♦ ꗃ");
    }

// Handles key, checks if next space is a key:
    bool check_key(string x) {
        return (x == "♣ ⚷" || x == "♠ ⚷" || x == "♥ ⚷" || x == "♦ ⚷");
    }

//Inputs the players positions, their move input, the maze map, and the STL Map) Checks if move is valid then implements it.
    void move(char input, int &posX, int &posY, vector<vector<string> > &grid, map<string, bool> &locks) {
        int newX = posX, newY = posY;

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
                return;  // Invalid input
        }

        // Check boundaries
        if (newX < 0 || newY < 0 || newX >= grid.size() || newY >= grid[0].size()) {
            return; // Out of bounds move
        }

        string cellContent = grid[newX][newY];

        //Handles empty Space
        if (cellContent == "   ") {
            posX = newX;  // Allow move
            posY = newY;
            return;
        }

        //Handle Lock
        if (check_lock(cellContent)) { // If the next space is a lock
            if (locks[cellContent] == true) {  // If lock is unlocked
                cout << cellContent.substr(0, 3) << " unlocked!" << endl;
                this_thread::sleep_for(std::chrono::seconds(1));
                grid[newX][newY] = "   "; //Makes the lock and empty space and allows move
                posX = newX;  // Allow move
                posY = newY;
            } else {
                cout << cellContent.substr(0, 3) << " Respective key not obtained yet!" << endl;
                this_thread::sleep_for(std::chrono::seconds(1));
            }
        }

        // Handle keys
        if (check_key(cellContent)) {
            string lockKey = cellContent.substr(0, 3) + " ꗃ";
            locks[lockKey] = true;  // Unlock corresponding lock
            cout << cellContent.substr(0, 3) << " key obtained!" << endl;
            this_thread::sleep_for(std::chrono::seconds(1));
            grid[newX][newY] = "   ";  // Remove key from the grid
            posX = newX;  // Allow move
            posY = newY;
        }

    }

//Reads map from txt file then returns it as a vector.
    vector<vector<string> > read_maze(const string &filename) {
        vector<vector<string> > grid;
        ifstream file(filename);
        string line;

        if (!file) {
            cout << "Error in file opening!" << endl;
            throw runtime_error("Failed to open file.");
        }

        while (getline(file, line)) {
            vector<string> row;
            stringstream ss(line);
            string element;

            // Read each quoted element
            while (getline(ss, element, '"')) {
                // Skip empty parts and spaces
                if (!element.empty() && element != " ") {
                    row.push_back(element);
                }
            }
            grid.push_back(row); //Pushes element to vector
        }

        file.close();
        return grid;
    }


    int playLOCK() {
        //Read map from txt file and convert it to 2d vector
        vector<vector<string> > grid = read_maze("map4.txt");

        //Create a map that initally states that all locks are close
        map<string, bool> locks;

        locks["♣ ꗃ"] = false;
        locks["♠ ꗃ"] = false;
        locks["♥ ꗃ"] = false;
        locks["♦ ꗃ"] = false;

        //Shows the character position
        int posX = 0;
        int posY = 0;

        // setting dark or lightmode
        bool darkmode = false;
        char mode;
        cout << "Press (l) for lightmode or (d) for darkmode:" << endl;
        cin >> mode;
        if (mode == 'd') {
            darkmode = true;
        }

        //Makes copy of string
        vector<vector<string> > copy;

        //Starts timer
        auto start = chrono::high_resolution_clock::now();

        //Loop to keep printing maze and updating position until player is at end
        while (posX != 49 || posY != 49) {
            system("clear");

            copy = grid;

            copy[posX][posY] = " ♀ ";

            //light mode play through, print:
            if (!darkmode) {
                for (int i = 0; i < copy.size(); i++) {
                    for (int j = 0; j < copy[1].size(); j++) {
                        cout << copy[i][j];
                    }
                    cout << endl;
                }
            }

                //dark mode play through, print
            else if (darkmode) {
                for (int i = 0; i < copy.size(); i++) {
                    for (int j = 0; j < copy[1].size(); j++) {
                        if (i >= posX - 1 && i <= posX + 1 && j >= posY - 1 && j <= posY + 1) {
                            cout << copy[i][j];
                        } else {
                            cout << "◙◙◙";
                        }
                    }
                    cout << endl;
                }
            }


            //Ask player input and call the move function
            char input;
            cout << "Whats your input (wasd)?" << endl;
            cin >> input;
            move(input, posX, posY, grid, locks);


        }

        //Stop timer and convert it to seconds.
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        double seconds = duration.count();


        cout << "You Won! You took " << seconds << " seconds!" << endl;

    }
}
