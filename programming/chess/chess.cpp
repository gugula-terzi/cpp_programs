#include <iostream>
#include <string.h>
#include <queue>
#include <fstream>
using namespace std;

#define n 8

struct Key {
    int X, Y;
    int currentNumber;
    int chessboard[n][n];
};

int* chess(int arr[n][n])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if ((i + j) % 2 == 0) arr[i][j] = 0;
            else arr[i][j] = 1;
        }

    return *arr;
}

Key* newKey(int number, int parentChessboard[n][n], int posX, int posY)
{
    Key* node = new Key;
    node -> currentNumber = number;
    if(node -> currentNumber == 1) chess(node -> chessboard);
    else memcpy(node -> chessboard, parentChessboard, sizeof(node -> chessboard));
    node -> X = posX; node -> Y = posY; node -> chessboard[node -> X][node -> Y] = 2;
    return node;
}

bool isValid(int arr[n][n], int x, int y)
{
    for (int i = 1; i <= x; i++)
    {
        if((x - i) >= 0 && (y - i) >= 0)
            if(arr[x - i][y - i] == 2) return false;

        if((x - i) >= 0 && (y + i) < n)
            if(arr[x - i][y + i] == 2) return false;
    }

return true;
}

void writeTXT(int arr[n][n])
{
    ofstream fout("rooks.txt");
    fout << n << " rooks on " << n << "*" << n << " chessboard: \n\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            fout << arr[i][j] << ' ';
        fout << '\n';
    }

    fout.close();
}

void solve()
{
    queue<Key*> q;

    Key* root = newKey(1, root->chessboard, 0, 0);
    q.push(root);

    while(!q.empty())
    {
        Key* parent = q.front();
        q.pop();

        if (parent->currentNumber == n) 
        {
            cout << endl;

            writeTXT(parent->chessboard);
            break;
        }
        for(int i = parent -> X; i < n; i++)
            for (int j = parent -> Y; j < n; j++)
            {
                if((parent -> chessboard[i][j] == 0 || parent -> chessboard[i][j] == 1) && isValid(parent->chessboard, i, j)) 
                {
                    Key* child = newKey(parent -> currentNumber + 1, parent -> chessboard, i, j);
                    q.push(child);
                }
            }
    }
}

int main()
{
    cout <<"File \"rooks.txt\" was successfully created...";
    solve();
    return 0;
}