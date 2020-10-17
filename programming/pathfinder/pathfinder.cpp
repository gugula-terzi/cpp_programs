#include <iostream>
#include <fstream>
#include <stack>
#include <windows.h>

using namespace std;

ifstream in("labirinth.in");
int N, M;
char **MAP;
int startX, startY;
int finishX, finishY;

struct point
{
    int value;
    bool isMarked = false;
};

struct coords {
    int x;
    int y;
};

void readFile()
{
    in >> N;
    in >> M;
    MAP = new char*[N+2];
    for(int i = 0; i < N+2; i++)
        MAP[i] = new char[M+2];
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            in >> MAP[i][j];
            if(MAP[i][j] == 'A')
            {
                startX = i;
                startY = j;
            }
            if(MAP[i][j] == 'B')
            {
                finishX = i;
                finishY = j;
            }
        }
    }
}

void doBorder()
{
    for(int i = 0; i < N+2; i++)
    {
        MAP[i][0] = 'x';
        MAP[i][M+1] = 'x';
    }
    for(int j = 0; j < M+2; j++)
    {
        MAP[0][j] = 'x';
        MAP[N+1][j] = 'x';
    }
}

void Lee(int x, int y, point **points)
{
    bool up = false, down = false, right = false, left = false;
    points[x][y].isMarked = true;
    if(x != 1)
        if((points[x-1][y].value != 1 && !points[x-1][y].isMarked) ||
                (points[x-1][y].value != 1 && points[x-1][y].value > points[x][y].value+1))
        {
            points[x-1][y].value = points[x][y].value+1;
            points[x-1][y].isMarked = true;
            up = true;
        }

    if(x != N+1)
        if((points[x+1][y].value != 1 && !points[x+1][y].isMarked) ||
                (points[x+1][y].value != 1 && points[x+1][y].value > points[x][y].value+1))
        {
            points[x+1][y].value = points[x][y].value+1;
            points[x+1][y].isMarked = true;
            down = true;
        }

    if(y != 1)
        if((points[x][y-1].value != 1 && !points[x][y-1].isMarked) ||
                (points[x][y-1].value != 1 && points[x][y-1].value > points[x][y].value+1))
        {
            points[x][y-1].value = points[x][y].value+1;
            points[x][y-1].isMarked = true;
            left = true;
        }

    if(y != M+1)
        if((points[x][y+1].value != 1 && !points[x][y+1].isMarked) ||
                (points[x][y+1].value != 1 && points[x][y+1].value > points[x][y].value+1))
        {
            points[x][y+1].value = points[x][y].value+1;
            points[x][y+1].isMarked = true;
            right = true;
        }

    if(up)
        Lee(x-1, y, points);

    if(down)
        Lee(x+1, y, points);

    if(right)
        Lee(x, y+1, points);

    if(left)
        Lee(x, y-1, points);
}

point **createPointsMap()
{
    point **nMap = new point*[N+2];
    for(int i = 0; i < N+2; i++)
        nMap[i] = new point[M+2];

    for(int i = 0; i <= N+1; i++)
    {
        for(int j = 0; j <= M+1; j++)
        {
            if(MAP[i][j] == 'x')
            {
                nMap[i][j].value = 1;
            }
            else
            {
                nMap[i][j].value = 0;
            }
        }
    }
    return nMap;
}

void outResult(stack<coords> path) {
    ofstream out("path.out");
    out << "Coordinates of path: " << endl;
    while(!path.empty()) {
        out << path.top().x << ", " << path.top().y << endl;
        system("cls");
        for(int i = 0; i < N+2; i++) {
        for(int j = 0; j < M+2; j++) {
            if(MAP[i][j] == 'x')
                cout << char(219);
            else
            if(i == path.top().x && j == path.top().y) {
                cout << 'X';
            } else if(i == finishX && j == finishY) {
                cout << 'F';
            } else cout << ' ';
        }
        cout << endl;
        }
        path.pop();
        Sleep(500);
    }
}

int main()
{
    readFile();
    doBorder();
    point **path = createPointsMap();
    Lee(startX, startY, path);
    
    int x = finishX;
    int y = finishY;
    stack<coords> result;
    coords P;
    P.x = x;
    P.y = y;
    result.push(P);
    while(x != startX || y != startY)
    {
        if(path[x][y].value == path[x-1][y].value+1)
        {
            x -= 1;
        }
        else
        {
            if(path[x][y].value == path[x+1][y].value+1)
            {
                x += 1;
            }
            else
            {
                if(path[x][y].value == path[x][y-1].value+1)
                {
                    y -= 1;
                }
                else
                {
                    if(path[x][y].value == path[x][y+1].value+1)
                    {
                        y += 1;
                    }
                }
            }
        }
        P.x = x;
        P.y = y;
        result.push(P);
    }

    outResult(result);
}
