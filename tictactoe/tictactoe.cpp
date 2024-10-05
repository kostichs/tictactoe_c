#include <iostream>

using namespace std;


const int b_size = 4;
const int p_size = 2;

void prepare_game(char board[][b_size], string players[p_size]);
void draw_board(char board[][b_size]);
void turn_player(char board[b_size][b_size], string players[], int active);
void calculate_positions(int x, int y);


int main()
{

    char board[b_size][b_size];
    string players[p_size];
    int active_player = 0;

    std::cout << "Hello User!\n";

    do {

        prepare_game(board, players);
        

        // game process
        do {
            draw_board(board);
            active_player = active_player % 2;
            cout << active_player << endl;
            turn_player(board, players, active_player);
            active_player++;

        } while (true);



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

void turn_player(char board[b_size][b_size], string players[], int active)
{
    cout << active << " makes a turn;" << endl;

    if (players[active] == "bot" || players[active] == "Bot")
    {
        //Bot plays automatically

    }
    else
    {
        int x, y;
        //Human plays manually
        char sign = ' ';
        do 
        {
            cout << "Type coordinates for your turn, for example, 1 1" << endl;
            cin >> x >> y;
            if (0 < x && x < 4 && 0 < y && y < 4 && board[x][y] == '.') {

                cout << "Your coordinates are " << x << " and " << y << endl;
                if (active % 2 == 0)
                {
                    sign = 'X';
                }
                else
                {
                    sign = 'O';
                }
                board[x][y] = sign;
                break;
            }
            else 
            {
                cout << x << " and " << y << " are unavailable values. Please, type coordinates in range from 1 to 3" << endl;
            }

            
        } while (true);



        calculate_positions(x, y);


    }
}

void calculate_positions(int x, int y)
{
    
}

void prepare_game(char board[b_size][b_size], string players[p_size])
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