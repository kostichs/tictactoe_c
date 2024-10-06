#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//This const is used often in for-loops in some functions, so I decided to declare them globally
const int b_size = 4; // size of the board. 

void prepare_game(char board[b_size][b_size], string players[]); // preparing board game array, player list and a queue for playing
void define_players(string players[]); // random definition of the queue for playing
void draw_board(char board[b_size][b_size]); // displaying the board game
void turn_player(char board[b_size][b_size], string players[], int active); // bot and human turns
bool calculate_positions(char board[b_size][b_size]); // calculation whether the current game is over, return boolean

int main()
{
    const int p_size = 2; // size of count of players
    int active_player; // number of active player
    char board[b_size][b_size]; // array of chars
    string players[p_size]; // array of players
    string answer; // var for answer whether the app should be broken
    bool is_over;
    cout << "Hello!\n";

    do 
    {
        int counter = 1; // counter of all turns. 9 means there is no more turn.
        is_over = false; // var for definition whether the session is over
        active_player = 0;
        prepare_game(board, players);

        // game session
        do 
        {
            active_player = active_player % 2; // number of the current player is either 0 or 1
            draw_board(board);
            cout << "\n";
            turn_player(board, players, active_player);
            is_over = calculate_positions(board);

            if (is_over) 
            {
                cout << players[active_player] << " is our new winner! Congratulations!\n" << endl;
                draw_board(board);
                break;
            }

            if (counter == 9) 
            {
                draw_board(board);
                cout << "\nThere is no winner in the current game session" << endl;
                break;
            }
            counter++;
            active_player++;

        } while (!is_over);

        cout << "\nDo you want to play again: Press 'Y' or 'N'" << endl;
        cin >> answer;

    } while (answer != "N");
    cout << "\nThank you! See you soon!";

    return 0;
}

void draw_board(char board[b_size][b_size]) // Displaying of the current board game
{
    for (int row = 0; row < b_size; row++) {
        for (int col = 0; col < b_size; col++) {
            cout << board[row][col] << ' ';
        }
        cout << endl;
    }
}

void turn_player(char board[b_size][b_size], string players[], int active)
{
    int x, y;
    char sign = (active % 2 == 0) ? 'X' : 'O'; // Assigning sign based on the player
    cout << players[active] << ", your turn..." << endl;

    if (players[active] == "bot" || players[active] == "Bot") 
    {
        // Bot plays automatically and randomly
        do 
        {
            x = rand() % 3 + 1;
            y = rand() % 3 + 1;
            if (board[x][y] == '.') { // random positions on the cells with '.'
                board[x][y] = sign;
                break;
            }
        } while (true);
    }
    else 
    {
        // Human plays manually
        do 
        {
            cout << "Type coordinates for your turn (1-3 for both x and y), e.g., 1 1" << endl;
            cin >> x >> y;
            if (x >= 1 && x <= 3 && y >= 1 && y <= 3 && board[x][y] == '.') // 1-based user input, 0-based board
            { 
                board[x][y] = sign;
                break;
            }
            else 
            {
                cout << "Invalid coordinates. Please try again." << endl;
            }
        } while (true);

        cout << players[active] << " made a move at " << x << " " << y << endl;
    }
}

bool calculate_positions(char board[b_size][b_size])
{
    // Horizontal checks
    for (int row = 1; row < b_size; row++) 
    {
        if (board[row][1] != '.' && board[row][1] == board[row][2] && board[row][2] == board[row][3]) 
        {
            return true;
        }
    }
    // Vertical checks
    for (int col = 1; col < b_size; col++) 
    {
        if (board[1][col] != '.' && board[1][col] == board[2][col] && board[2][col] == board[3][col]) 
        {
            return true;
        }
    }
    // Diagonal checks
    if ((board[1][1] != '.' && board[1][1] == board[2][2] && board[2][2] == board[3][3]) ||
        (board[1][3] != '.' && board[1][3] == board[2][2] && board[2][2] == board[3][1])) 
    {
        return true;
    }
    return false;
}

void prepare_game(char board[b_size][b_size], string players[])
{
    // Set up the board headers
    board[0][0] = ' ';
    for (int i = 1; i < b_size; i++) 
    {
        board[0][i] = '0' + i; // Set headers
        board[i][0] = '0' + i;
    }

    // Reset all cells to '.'
    for (int row = 1; row < b_size; row++) {
        for (int col = 1; col < b_size; col++) {
            board[row][col] = '.';
        }
    }

    define_players(players);
    cout << players[0] << " is playing against " << players[1] << "! Let the game begin!" << endl;
}

void define_players(string players[])
{
    srand(static_cast<unsigned int>(std::time(0))); // Randomize player order
    int randomIndex = rand() % 2;
    cout << "Who does play: Bot or Human?" << endl;
    cin >> players[randomIndex];
    cout << "Who does play: Bot or Human?" << endl;
    randomIndex = (randomIndex == 0) ? 1 : 0; // Assign the other player
    cin >> players[randomIndex];
}
