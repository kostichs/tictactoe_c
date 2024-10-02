#include <iostream>

using namespace std;


const int b_size = 4;
const int p_size = 2;

void play_game(char board[][b_size], string players[p_size]);
void draw_board(char board[][b_size]);


int main()
{

    char board[b_size][b_size];
    string players[p_size];


    std::cout << "Hello User!\n";

    do {

        play_game(board, players);
        draw_board(board);



	} while (true);

    return 0;
}

void draw_board(char board[b_size][b_size])
{
    for (int row = 0; row < b_size; row++) {
        for (int col = 0; col < b_size; col++) {
            cout << board[row][col] << ' ';

        }
        cout << endl;
    }
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

void play_game(char board[b_size][b_size], string players[p_size])
{
    board[0][0] = ' ';
    for (int i = 1; i < b_size; i++)
    {
        board[0][i] = i + '0';
        board[i][0] = i + '0';
    }

    for (int row = 1; row < b_size; row++) {
        for (int col = 1; col < b_size; col++) {
            board[row][col] = '.';

        }
    }

    for (int i = 0; i < p_size; i++)
    {
        cout << "Who is the first Player: Bot or Human?" << endl;
        cin >> players[i]; //or cin >> *(players + i) just to know for me
    }

    cout << players[0] << " is playing against " << players[1] << "! Fight!" << endl;

    

}