/*
Program: two player each player choose a number from 1 to 9 and the number that is picked cannot picked again
         and the first player to pick three number there sum = 15 he will win else it will be draw

Author: mohamed adel kamal el sheikh (20230342)

Version: 2.0

Date: 1-3-2024
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// function to check winner
bool checkWin(vector<int>& player) {
    for (size_t i = 0; i < player.size(); ++i) {
        for (size_t j = i + 1; j < player.size(); ++j) {
            for (size_t k = j + 1; k < player.size(); ++k) {
                if (player[i] + player[j] + player[k] == 15) {
                    return true;
                }
            }
        }
    }
    return false;
}

void numberScrabble() {
    // set numbers
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> player1;
    vector<int> player2;

    // welcome message
    cout << "Welcome to the number_scrabble game\n";
    cout << "Each player will choose a number between 1 and 9\n";
    cout << "The first player to reach a sum of 15 wins\n";

    // game playing
    for (int round = 0; round < 100; ++round) {
        int pick1, pick2;

        cout << "Player 1: Please choose a number from 1 to 9: ";
        cin >> pick1;
        while (find(numbers.begin(), numbers.end(), pick1) == numbers.end()) {
            cout << "Player 1: Please enter a valid number: ";
            cin >> pick1;
        }
        player1.push_back(pick1);
        numbers.erase(remove(numbers.begin(), numbers.end(), pick1), numbers.end());

        if (checkWin(player1)) {
            cout << "Player 1 wins\n";
            return;
        }

        cout << "Player 2: Please choose a number from 1 to 9: ";
        cin >> pick2;
        while (find(numbers.begin(), numbers.end(), pick2) == numbers.end()) {
            cout << "Player 2: Please enter a valid number: ";
            cin >> pick2;
        }
        player2.push_back(pick2);
        numbers.erase(remove(numbers.begin(), numbers.end(), pick2), numbers.end());

        if (checkWin(player2)) {
            cout << "Player 2 wins\n";
            return;
        }

        if (numbers.empty()) {
            cout << "It's a draw\n";
            return;
        }
    }
}

int main() {
    numberScrabble();
    return 0;
}
