#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

//빈 공간을 기준으로 찾기
//배열 테이블 전체를 돌려버리기

int Array[51][51], tArray[51][51];
int visit[51][51], tvisit[51][51];
int dx[] = {0, 0,1,-1 };
int dy[] = {1,-1,0, 0 };
int S = 0; //게임판 길이
int ans = 0;

struct point
{
    int x;
    int y;
};
vector<point> tv, cv;
int flag = 0;

void DFS(int x, int y, int cnt, int ox, int oy, int type)
{
    if (type == 1)
    {
        tv.push_back({ x - ox, y - oy });
        visit[y][x] = true;
    }
    else
    {
        cv.push_back({x - ox, y - oy});
        tvisit[y][x] = true;
    }

    if (cnt > 6)
    {
        flag = 1;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx > -1 && nx < S && ny > -1 && ny < S)
        {
            if (type == 1 && visit[ny][nx] == false && Array[ny][nx] == 0)
            {
                DFS(nx, ny, cnt + 1, ox, oy, type);
                if (flag) return;
            }
            else if (type == 2 && tvisit[ny][nx] == false && tArray[ny][nx] == 1)
            {
                DFS(nx, ny, cnt + 1, ox, oy, type);
                if (flag) return;
            }
        }
    }
}

void my_rotate()
{
    int temp[51][51];
    memcpy(temp, tArray, sizeof(tArray));
    for (int k = 0; k < S / 2; k++)
    {
        vector<int> u, r, d, l;
        for (int i = k; i < S - 2 * k; i++)
        {
            for (int j = k; j < S - 2 * k; j++)
            {
                //u
                tArray[i][j] = temp[S-1-j][i];

                //r
                tArray[j][S - 1 - i] = temp[i][j];

                //d
                tArray[S - 1 - i][j] = temp[S - 1 - j][S - 1 - i];

                //l
                tArray[j][i] = temp[S - 1 - i][j];
            }
        }
    }
}

bool cmp(const point& u, const point& v)
{
    if (u.x < v.x) return true;
    else if (u.x == v.x)
    {
        if (u.y < v.y) return true;
        else return false;
    }
    else return false;
}

int check()
{
    memset(tvisit, 0, sizeof(tvisit));
    for (int i = 0; i < S; i++)
    {
        for (int j = 0; j < S; j++)
        {
            if (tvisit[i][j] == false && tArray[i][j] == 1)
            {
                cv.clear();
                DFS(j, i, 1, j, i, 2);
                if (tv.size() == cv.size())
                {
                    sort(tv.begin(), tv.end(), cmp);
                    sort(cv.begin(), cv.end(), cmp);

                    int cflag = 0;
                    for (int k = 0; k < tv.size(); k++)
                    {
                        if (tv[k].x == cv[k].x && tv[k].y == cv[k].y) continue;
                        else
                        {
                            cflag = 1;
                            break;
                        }
                    }
                    if (cflag) continue;

                    for (int k = 0; k < cv.size(); k++)
                    {
                        int nx = j + cv[k].x;
                        int ny = i + cv[k].y;
                        tArray[ny][nx] = 0;
                        ans++;
                    }
                    return 1;
                }
            }
        }
    }
    return 0;
}


int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = -1;
    S = game_board.size();

    //초기 보드판 전역변수로 복사
    for (int i = 0; i < S; i++)
        for (int j = 0; j < S; j++)
        {
            Array[i][j] = game_board[i][j];
            tArray[i][j] = table[i][j];
        }

    for (int i = 0; i < S; i++)
    {
        for (int j = 0; j < S; j++)
        {
            if (visit[i][j] == false && game_board[i][j] == 0)
            {
                tv.clear();
                flag = 0;
                DFS(j, i, 1, j, i, 1);
                if (!flag)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int c = check();
                        if (c) break;
                        my_rotate();
                    }
                }

            }
        }
    }

    answer = ans;
    return answer;
}

int main()
{
    vector<vector<int>> game_board = { {1, 1, 0, 0, 1, 0}, {0, 0, 1, 0, 1, 0}, {0, 1, 1, 0, 0, 1}, {1, 1, 0, 1, 1, 1}, {1, 0, 0, 0, 1, 0}, {0, 1, 1, 1, 0, 0} };
    vector<vector<int>> table = { {1, 0, 0, 1, 1, 0}, {1, 0, 1, 0, 1, 0}, {0, 1, 1, 0, 1, 1}, {0, 0, 1, 0, 0, 0}, {1, 1, 0, 1, 1, 0}, {0, 1, 0, 0, 0, 0} };
    solution(game_board, table);
    return 0;
}
