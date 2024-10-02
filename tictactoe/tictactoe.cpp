// tictactoe.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>

using namespace std;

const int b_size = 4;
const int p_size = 2;

void play_game(string board[b_size][b_size], string players[p_size]);



int main()
{

    string board[b_size][b_size];
    string players[p_size];


    std::cout << "Hello User!\n";

    do {

        play_game(board, players);

	} while (true);

}

void draw_board()
{

}

void define_players()
{
  

}

void turn_player()
{

}

void calculate_positions()
{

}

void play_game(string board[b_size][b_size], string players[p_size])
{

    for (int i = 0; i < p_size; i++)
    {
        cout << "Who is the first Player: Bot or Human?" << endl;
        cin >> players[i]; //or cin >> *(players + i) just to know for me
    }

    cout << players[0] << " is playing against " << players[1] << "! Fight!" << endl;

    

}