// tictactoe.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>

using namespace std;

void play_game();


int main()
{
    std::cout << "Hello User!\n";

    do {

        play_game();

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

void play_game()
{
    string players[2];
    for (int i = 0; i < 2; i++)
    {
        cout << "Who is the first Player: Bot or Human?" << endl;
        cin >> players[i];
    }

    cout << players[0] << " is playing against " << players[1] << "! Fight!" << endl;
}