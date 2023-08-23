#include <iostream>
#include<thread>
using namespace std;
int p = 250;
int a{}, b{}, c{};


void pt1() {
    while(p>1){
        cout << " работа 1 кассира идет " << endl;
        this_thread::sleep_for(chrono::milliseconds(120));
        --p;
        a++;
    } 
    cout << "КОНЕЦ, 1м кассиром обслужено " << a << " покупателей, за " << (a * 120) / 60. << " минут" << endl;;
}
//
void pt2() {
    while (p > 2) {
        cout << " работа 2 кассира идет" << endl;
        this_thread::sleep_for(chrono::milliseconds(150));
        --p;
        b++;
    }  
    cout << "КОНЕЦ, 2м кассиром обслужено " << b << " покупателей, за " << (b * 150) / 60. << " минут" << endl;;
}

void pt3() {
    while (p >4) {
        cout << " работа 3 кассира идет" << endl;
        this_thread::sleep_for(chrono::milliseconds(168));
        --p;
        c++;
    }  
    cout << "КОНЕЦ, 3м кассиром обслужено " << c<< " покупателей, за " << (c * 168) / 60. << " минут" << endl;;
}



int main()
{
    setlocale(LC_ALL, "RUS");
    thread p1(pt1);
    thread p2(pt2);
    thread p3(pt3);
    p1.join();
    p2.join();
    p3.join();
    int y = ((c * 168) / 60.) + ((b * 150) / 60.) + ((a * 120) / 60.);
    if (y > 45) {
        y = y + ((y / 45.) * 10);
                cout << "рабочий день длился " << y/60. << " часов" << endl;
    }



}






/*Creating a fully functional chess game with a beautiful interface requires more advanced graphics libraries and a more complex implementation. However, I can provide you with an example of a basic chess game with a simple text-based interface:

cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define the chess board as a 2D array
char board[8][8] = {
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
};

// Function to display the chess board
void displayBoard() {
    cout << "   a b c d e f g h" << endl;
    cout << "  -----------------" << endl;
    for (int i = 0; i < 8; i++) {
        cout << 8 - i << " |";
        for (int j = 0; j < 8; j++) {
            cout << board[i][j] << "|";
        }
        cout << " " << 8 - i << endl;
        cout << "  -----------------" << endl;
    }
    cout << "   a b c d e f g h" << endl;
}

// Function to move a chess piece
void movePiece(int startRow, int startCol, int endRow, int endCol) {
    board[endRow][endCol] = board[startRow][startCol];
    board[startRow][startCol] = ' ';
}

// Function to convert user input to board coordinates
bool convertInput(string input, int& row, int& col) {
    if (input.length() != 2) {
        return false;
    }
    col = input[0] - 'a';
    row = 8 - (input[1] - '0');
    return col >= 0 && col < 8 && row >= 0 && row < 8;
}

int main() {
    int startRow, startCol, endRow, endCol;
    string startInput, endInput;

    // Display the initial chess board
    displayBoard();

    while (true) {
        // Get input from the user
        cout << "Enter the starting position (e.g. a2): ";
        cin >> startInput;
        if (!convertInput(startInput, startRow, startCol)) {
            cout << "Invalid input. Try again." << endl;
            continue;
        }

        cout << "Enter the ending position (e.g. a4): ";
        cin >> endInput;
        if (!convertInput(endInput, endRow, endCol)) {
            cout << "Invalid input. Try again." << endl;
            continue;
        }

        // Move the chess piece
        movePiece(startRow, startCol, endRow, endCol);

        // Display the updated chess board
        displayBoard();
    }

    return 0;
}


This implementation uses a text-based interface to display the chess board and allows the user to enter the starting and ending positions of a chess piece to move it on the board. It includes basic input validation and converts user input into board coordinates. The game continues in an infinite loop until the program is terminated.
*/