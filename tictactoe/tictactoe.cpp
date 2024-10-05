#include <iostream>

using namespace std;


const int b_size = 4;
const int p_size = 2;

void prepare_game(char board[b_size][b_size], string players[p_size]);
void define_players(string players[]);
void draw_board(char board[b_size][b_size]);
void turn_player(char board[b_size][b_size], string players[], int active);
bool calculate_positions(char board[b_size][b_size]);


int main()
{

    char board[b_size][b_size];
    string players[p_size];
    int active_player = 0;

    
    bool is_over = false;
    string answer = "";

    std::cout << "Hello!\n";

    do {
        int counter = 0; // counter of all turns. 9 means there is no more turn.
        prepare_game(board, players);
        

        // game process
        do {
            draw_board(board);
            active_player = active_player % 2;
            cout << active_player << endl;
            turn_player(board, players, active_player);
            is_over = calculate_positions(board);
            if (is_over == true) {
                cout << players[active_player] << " is our new winner! Congratulations!" << endl;
                draw_board(board);
                break;
            }
            if (counter == 8) {
                cout << "There is no winner in the current game session" << endl;
                break;
            }
            counter++;
            active_player++;

        } while (is_over == false);

        is_over = false;
        cout << "Do you want to play again: Press 'Y' or 'N'" << endl;
        cin >> answer;

    } while (answer != "N");
    cout << "Thank you! See you soon!";

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

void define_players(string players[]) // random definition of the first player
{
    srand(static_cast<unsigned int>(std::time(0)));
    int randomIndex = rand() % 2;

    cout << "Who does play: Bot or Human?" << endl;
    cin >> players[randomIndex];
    cout << "Who does play: Bot or Human?" << endl;
    randomIndex == 0 ? randomIndex++ : randomIndex--;
    cin >> players[randomIndex];
}


void turn_player(char board[b_size][b_size], string players[], int active)
{
    int x, y;
    char sign = ' ';

    if (active % 2 == 0) // Define the sign of the current player
    {
        sign = 'X';
    }
    else
    {
        sign = 'O';
    }
    
    cout << players[active] << ", your turn..." << endl;
    
    if (players[active] == "bot" || players[active] == "Bot")
    {
        
        //Bot plays automatically
        do
        {
            int x = rand() % 3 + 1;
            int y = rand() % 3 + 1;
            if (0 < x && x < 4 && 0 < y && y < 4 && board[x][y] == '.') 
            {
                board[x][y] = sign;
                break;
            }

        } while (true);

    }
    else
    {
        //Human plays manually
        
        do 
        {
            cout << "Type coordinates for your turn, for example, 1 1" << endl;
            cin >> x >> y;
            if (0 < x && x < 4 && 0 < y && y < 4 && board[x][y] == '.') 
            {
                break;
            }
            else 
            {
                cout << x << " and " << y << " are unavailable values. Please, type coordinates in range from 1 to 3" << endl;
            }

            
        } while (true);

        board[x][y] = sign;
        cout << players[active] << " makes turn on " << x << " and " << y << endl;
        
    }
}

bool calculate_positions(char board[b_size][b_size])
{
    for (int row = 1; row < b_size; row++) //horizontal checks
    {
        if (board[row][1] != '.' && (board[row][1] == board[row][2] && board[row][2] == board[row][3])) {
            return true;
        }
    }
    for (int col = 1; col < b_size; col++) // vertical checks
    {
        if (board[1][col] != '.' && (board[1][col] == board[2][col] && board[2][col] == board[3][col])) {
            return true;
        }
    }
    
    if ((board[1][1] != '.' && (board[1][1] == board[2][2] && board[2][2] == board[3][3])) 
        || (board[1][3] != '.' && (board[1][3] == board[2][2] && board[2][2] == board[3][1]))) { // diagonal checks
        return true;
    }

    return false;
}

void prepare_game(char board[b_size][b_size], string players[p_size]) // 
{
    board[0][0] = ' ';
    for (int i = 1; i < b_size; i++)
    {
        board[0][i] = i + '0'; // + 0 is transformation to string type
        board[i][0] = i + '0';
    }

    for (int row = 1; row < b_size; row++) {
        for (int col = 1; col < b_size; col++) {
            board[row][col] = '.';

        }
    }

    define_players(players);
    cout << players[0] << " is playing against " << players[1] << "! Fight!" << endl;

}