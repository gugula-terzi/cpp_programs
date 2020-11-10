#include <iostream>
#include <vector>

using namespace std;

const int rows = 5;
const int columns = 5;
int path
int start_x, start_y, finish_x, finish_y;
string labyrinth[rows][columns] = {
                 {"-1", "-1", "-1", "-1", "-1"},
                 {"-1",  "s", "-1",  "f", "-1"},
                 {"-1",  "0", "-1",  "0", "-1"},
                 {"-1",  "0",  "0",  "0", "-1"},
                 {"-1", "-1", "-1", "-1", "-1"}
                };


void lee()
{
    start = labyrinth[start_x][start_y];
    do
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (labyrinth[i][j-1] == "0") // left cell
                {
                    labyrinth[i][j-1] = start + 1;
                }
                if (labyrinth[i][j+1] == "0") // right cell
                {
                    labyrinth[i][j+1] = start + 1;
                }
                if (labyrinth[i-1][j] == "0") // up cell
                {
                    labyrinth[i-1][j] = start + 1;
                }
                if (labyrinth[i+1][j] == "0") // down cell
                {
                    labyrinth[i+1][j] = start + 1;
                }
            }
        }
        start++;
    } while (!labyrinth[finish_x][finish_y] && labyrinth[i][j] != "-1");

    if (!finish_x.empty() and !finish_y.empty())
    {

        return path;
    }
    else
    {
        return 0;
    }
    
}

int main()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (labyrinth[i][j] == "s")
            {
                start_x = i;
                start_y = j;
                labyrinth[i][j] = "0";
            }
            if (labyrinth[i][j] == "f")
            {
                finish_x = i;
                finish_y = j;
                labyrinth[i][j] = "0";
            }
        }
    }
    
    cout << "start: " << start_x << " " << start_y << endl;
    cout << "finish: " << finish_x << " " << finish_y << endl;

    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            cout << labyrinth[i][j] << " ";
        }
        cout << endl;
    }
    
}