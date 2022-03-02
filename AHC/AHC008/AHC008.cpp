#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
/*
struct Edge
{
  ll to;
  ll weight;
  Edge(ll t, ll w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
*/
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // 右、下、左、上
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

struct Human
{
    int x;
    int y;
    Human(int x, int y) : x(x), y(y) {}
    Human() : x(0), y(0) {}
};

struct Animal
{
    int x;
    int y;
    int type;
    Animal(int x, int y, int type) : x(x), y(y), type(type) {}
    Animal() : x(0), y(0), type(0) {}
    ~Animal() {}
    // virtual void move() override;
};

struct UnionFind
{
    vector<int> par;

    UnionFind(int n) : par(n, -1) {}

    int root(int x)
    {
        if (par[x] < 0)
            return x;
        else
            return par[x] = root(par[x]);
    }

    bool isSame(int x, int y)
    {
        return root(x) == root(y);
    }

    bool merge(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        if (par[x] > par[y])
            swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x)
    {
        return -par[root(x)];
    }
};

uint64_t get_rand_range(uint64_t min_val, uint64_t max_val)
{
    // 乱数生成器
    static std::mt19937_64 mt64(0);

    // [min_val, max_val] の一様分布整数 (int) の分布生成器
    std::uniform_int_distribution<uint64_t> get_rand_uni_int(min_val, max_val);

    // 乱数を生成
    return get_rand_uni_int(mt64);
}

double get_rand_range_real(double min_val, double max_val)
{
    // 乱数生成器
    static std::mt19937_64 mt64(0);

    // [min_val, max_val] の一様分布整数 (int) の分布生成器
    std::uniform_real_distribution<double> get_rand_real(min_val, max_val);

    // 乱数を生成
    return get_rand_real(mt64);
}

vector<vector<int>> bfs(vector<vector<int>> &fields, int sx, int sy)
{
    vector<vector<int>> res(32, vector<int>(32, -1));
    queue<P> que;
    res[sx][sy] = 0;
    que.push({sx, sy});

    while (!que.empty())
    {
        P p = que.front();
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = p.first + dx[i], ny = p.second + dy[i];
            if (1 <= nx && nx <= 30 && 1 <= ny && ny <= 30 && fields[nx][ny] != 1 && res[nx][ny] == -1)
            {
                res[nx][ny] = res[p.first][p.second] + 1;
                que.push({nx, ny});
            }
        }
    }

    /*
    cerr << "sx: " << sx << "  sy: " << sy << endl;
    for (int i = 1; i <= 30; i++)
    {
      for (int j = 1; j <= 30; j++)
      {
        cerr << res[i][j] << " ";
      }
      cerr << endl;
    }
    */
    return res;
}

// connectedFieldsは事前に用意する
void dfs(vector<vector<int>> &fields, vector<vector<bool>> &connectedFields, vector<vector<bool>> &visited, int sx, int sy)
{
    if (visited[sx][sy])
        return;
    connectedFields[sx][sy] = true;
    visited[sx][sy] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = sx + dx[i], ny = sy + dy[i];

        if (1 <= nx && nx <= 30 && 1 <= ny && ny <= 30 && fields[nx][ny] != 1)
            dfs(fields, connectedFields, visited, nx, ny);
    }

    return;
}

bool checkCatchAllNotDog(vector<vector<int>> &fields, vector<Animal> &pets, Human &human)
{
    vector<vector<bool>> connectedField(32, vector<bool>(32));
    vector<vector<bool>> visited(32, vector<bool>(32));
    dfs(fields, connectedField, visited, human.x, human.y);

    for (auto &animal : pets)
    {
        if (animal.type != 4)
        {
            if (connectedField[animal.x][animal.y])
                return false;
        }
    }
    return true;
}

bool canPutBlock(vector<vector<int>> &field, vector<vector<int>> &prevField, Human &human, char direction)
{
    if (direction == 'u')
    {
        bool ok = !prevField[human.x - 1][human.y];
        ok &= !field[human.x - 1][human.y];
        ok &= (!field[human.x][human.y] || field[human.x][human.y] == 3 || field[human.x][human.y] == 1);
        ok &= (!field[human.x - 2][human.y] || field[human.x - 2][human.y] == 3 || field[human.x - 2][human.y] == 1);
        ok &= (!field[human.x - 1][human.y - 1] || field[human.x - 1][human.y - 1] == 3 || field[human.x - 1][human.y - 1] == 1);
        ok &= (!field[human.x - 1][human.y + 1] || field[human.x - 1][human.y + 1] == 3 || field[human.x - 1][human.y + 1] == 1);
        return ok;
    }
    else if (direction == 'd')
    {
        bool ok = !prevField[human.x + 1][human.y];
        ok &= !field[human.x + 1][human.y];
        ok &= (!field[human.x][human.y] || field[human.x][human.y] == 3 || field[human.x][human.y] == 1);
        ok &= (!field[human.x + 2][human.y] || field[human.x + 2][human.y] == 3 || field[human.x + 2][human.y] == 1);
        ok &= (!field[human.x + 1][human.y - 1] || field[human.x + 1][human.y - 1] == 3 || field[human.x + 1][human.y - 1] == 1);
        ok &= (!field[human.x + 1][human.y + 1] || field[human.x + 1][human.y + 1] == 3 || field[human.x + 1][human.y + 1] == 1);
        return ok;
    }
    else if (direction == 'l')
    {
        bool ok = !prevField[human.x][human.y - 1];
        ok &= !field[human.x][human.y - 1];
        ok &= (!field[human.x][human.y] || field[human.x][human.y] == 3 || field[human.x][human.y] == 1);
        ok &= (!field[human.x][human.y - 2] || field[human.x][human.y - 2] == 3 || field[human.x][human.y - 2] == 1);
        ok &= (!field[human.x + 1][human.y - 1] || field[human.x + 1][human.y - 1] == 3 || field[human.x + 1][human.y - 1] == 1);
        ok &= (!field[human.x - 1][human.y - 1] || field[human.x - 1][human.y - 1] == 3 || field[human.x - 1][human.y - 1] == 1);
        return ok;
    }
    else if (direction == 'r')
    {
        bool ok = !prevField[human.x][human.y + 1];
        ok &= !field[human.x][human.y + 1];
        ok &= (!field[human.x][human.y] || field[human.x][human.y] == 3 || field[human.x][human.y] == 1);
        ok &= (!field[human.x][human.y + 2] || field[human.x][human.y + 2] == 3 || field[human.x][human.y + 2] == 1);
        ok &= (!field[human.x + 1][human.y + 1] || field[human.x + 1][human.y + 1] == 3 || field[human.x + 1][human.y + 1] == 1);
        ok &= (!field[human.x - 1][human.y + 1] || field[human.x - 1][human.y + 1] == 3 || field[human.x - 1][human.y + 1] == 1);
        return ok;
    }
    return false;
}

void updateField(vector<vector<int>> &field, vector<vector<int>> &humanCnts, vector<vector<int>> &animalCnts)
{
    // fieldの更新
    for (int x = 1; x <= 30; x++)
    {
        for (int y = 1; y <= 30; y++)
        {
            if (field[x][y] == 1)
                continue;
            if (humanCnts[x][y] && animalCnts[x][y])
                field[x][y] = 4;
            else if (humanCnts[x][y])
                field[x][y] = 3;
            else if (animalCnts[x][y])
                field[x][y] = 2;
            else if (!humanCnts[x][y] && !animalCnts[x][y])
            {
                field[x][y] = 0;
            }
        }
    }
}

void updateHumanCnts(vector<vector<int>> &humanCnts, Human &human, char direction)
{
    if (direction == 'D')
    {
        humanCnts[human.x][human.y]--;
        human.x++;
        humanCnts[human.x][human.y]++;
    }
    else if (direction == 'R')
    {
        humanCnts[human.x][human.y]--;
        human.y++;
        humanCnts[human.x][human.y]++;
    }
    else if (direction == 'U')
    {
        humanCnts[human.x][human.y]--;
        human.x--;
        humanCnts[human.x][human.y]++;
    }
    else if (direction == 'L')
    {
        humanCnts[human.x][human.y]--;
        human.y--;
        humanCnts[human.x][human.y]++;
    }
}

void updateAnimalCnts(vector<vector<int>> &animalCnts, vector<vector<int>> &dogCnts, Animal &animal, char direction)
{
    if (direction == 'U')
    {
        animalCnts[animal.x][animal.y]--;
        if (animal.type == 4)
            dogCnts[animal.x][animal.y]--;
        animal.x--;
        animalCnts[animal.x][animal.y]++;
        if (animal.type == 4)
            dogCnts[animal.x][animal.y]++;
    }
    else if (direction == 'D')
    {
        animalCnts[animal.x][animal.y]--;
        if (animal.type == 4)
            dogCnts[animal.x][animal.y]--;
        animal.x++;
        animalCnts[animal.x][animal.y]++;
        if (animal.type == 4)
            dogCnts[animal.x][animal.y]++;
    }
    else if (direction == 'L')
    {
        animalCnts[animal.x][animal.y]--;
        if (animal.type == 4)
            dogCnts[animal.x][animal.y]--;
        animal.y--;
        animalCnts[animal.x][animal.y]++;
        if (animal.type == 4)
            dogCnts[animal.x][animal.y]++;
    }
    else if (direction == 'R')
    {
        animalCnts[animal.x][animal.y]--;
        if (animal.type == 4)
            dogCnts[animal.x][animal.y]--;
        animal.y++;
        animalCnts[animal.x][animal.y]++;
        if (animal.type == 4)
            dogCnts[animal.x][animal.y]++;
    }
}

int checkExistsPetsInside(vector<vector<int>> &animalCnts, int targetFieldSize)
{
    int cnts = 0;
    for (int x = 1; x <= targetFieldSize; x++)
    {
        for (int y = 1; y <= targetFieldSize; y++)
        {
            cnts += animalCnts[x][y];
        }
    }
    return cnts;
}

int checkExistsPetsInside(vector<vector<int>> &animalCnts, vector<vector<bool>> &targetField)
{
    int cnts = 0;
    for (int x = 1; x <= 30; x++)
    {
        for (int y = 1; y <= 30; y++)
        {
            if (!targetField[x][y])
                continue;
            cnts += animalCnts[x][y];
        }
    }
    return cnts;
}

int theMostTopAnimalPosition(vector<vector<int>> &animalCnts)
{
    int xTop = 30;
    for (int x = 30; x >= 1; x--)
    {
        for (int y = 1; y <= 30; y++)
        {
            if (animalCnts[x][y] > 0)
                xTop = min(xTop, x);
        }
    }
    return xTop;
}

int theMostRightAnimalPosition(vector<vector<int>> &animalCnts)
{
    int yRight = 1;
    for (int x = 1; x <= 30; x++)
    {
        for (int y = 1; y <= 30; y++)
        {
            if (animalCnts[x][y] > 0)
                yRight = max(yRight, y);
        }
    }
    return yRight;
}

int theMostBottomAnimalPosition(vector<vector<int>> &animalCnts)
{
    int xBottom = 1;
    for (int x = 1; x <= 30; x++)
    {
        for (int y = 1; y <= 30; y++)
        {
            if (animalCnts[x][y] > 0)
                xBottom = max(xBottom, x);
        }
    }
    return xBottom;
}

int theMostLeftAnimalPosition(vector<vector<int>> &animalCnts)
{
    int yLeft = 30;
    for (int x = 1; x <= 30; x++)
    {
        for (int y = 30; y >= 1; y--)
        {
            if (animalCnts[x][y] > 0)
                yLeft = min(yLeft, y);
        }
    }
    return yLeft;
}

bool checkFinishedHorizontal(vector<vector<int>> &field, int xTarget, int yStart, int yEnd)
{
    for (int y = yStart; y <= yEnd; y++)
    {
        if (field[xTarget][y] != 1)
            return false;
    }
    return true;
}

bool checkFinishedVertical(vector<vector<int>> &field, int yTarget, int xStart, int xEnd)
{
    for (int x = xStart; x <= xEnd; x++)
    {
        if (field[x][yTarget] != 1)
            return false;
    }
    return true;
}

void moveHuman(vector<vector<int>> &field, vector<vector<vector<int>>> &dists, vector<vector<int>> &distsHumanAndAnimal, vector<P> &idxTarget, vector<vector<int>> &humanCnts, vector<Animal> &pets, vector<Human> &human, string &ans, vector<bool> &reachedTargetPoints, int humanIdx, int N)
{
    // field, dists, distsHumanAndAnimal, idxTarget, humanCnts, human, ans, reachedTargetPoints
    dists[humanIdx] = bfs(field, idxTarget[humanIdx].first, idxTarget[humanIdx].second);
    // 各動物と人間の距離を求めている
    for (int j = 0; j < N; j++)
    {
        distsHumanAndAnimal[humanIdx][j] = dists[humanIdx][pets[j].x][pets[j].y];
    }
    int nextIdx = 4, nowDist = dists[humanIdx][human[humanIdx].x][human[humanIdx].y];
    for (int j = 0; j < 4; j++)
    {
        int nx = human[humanIdx].x + dx[j], ny = human[humanIdx].y + dy[j];
        if (nx < 1 || nx > 30 || ny < 1 || ny > 30 || field[nx][ny] == 1)
            continue;
        if (dists[humanIdx][nx][ny] < nowDist)
        {
            nowDist = dists[humanIdx][nx][ny];
            nextIdx = j;
        }
    }
    if (nextIdx == 0)
    {
        ans += "D";
        updateHumanCnts(humanCnts, human[humanIdx], 'D');
    }
    else if (nextIdx == 1)
    {
        ans += "R";
        updateHumanCnts(humanCnts, human[humanIdx], 'R');
    }
    else if (nextIdx == 2)
    {
        ans += "U";
        updateHumanCnts(humanCnts, human[humanIdx], 'U');
    }
    else if (nextIdx == 3)
    {
        ans += "L";
        updateHumanCnts(humanCnts, human[humanIdx], 'L');
    }
    else
        ans += ".";
    if (human[humanIdx].x == idxTarget[humanIdx].first && human[humanIdx].y == idxTarget[humanIdx].second)
    {
        reachedTargetPoints[humanIdx] = true;
    }
}

bool checkAllVerticalBlock(vector<bool> &placedVerticalBlock, int humanIdx)
{
    bool placedAllVerticalBlock = true;
    for (int b = 0; b < 10; b++)
        if (!placedVerticalBlock[b])
            placedAllVerticalBlock = false;

    static bool firstPlacedAllVerticalBlock = false;
    if (humanIdx == 0 && placedAllVerticalBlock)
        firstPlacedAllVerticalBlock = true;

    // cerr << "placedAllVerticalBlock: " << placedAllVerticalBlock << "  firstPlacedAllVerticalBlock: " << firstPlacedAllVerticalBlock << endl;
    return placedAllVerticalBlock && firstPlacedAllVerticalBlock;
}

void cntPetsNumInsideTargetArea(vector<vector<int>> &dogCnts, vector<int> &petsNumInsideTargetArea, vector<vector<int>> &animalCnts, vector<int> &blockMaxAndMin, bool catchAllAnimalsNotDog)
{
    for (int area = 0; area < 20; area++)
    {
        if (area < 10)
        {
            if (area == 9)
            {
                for (int x = blockMaxAndMin[area]; x <= 13; x++)
                {
                    for (int y = 28; y <= 30; y++)
                    {
                        petsNumInsideTargetArea[area] += animalCnts[x][y];
                        if (!catchAllAnimalsNotDog)
                            petsNumInsideTargetArea[area] -= dogCnts[x][y];
                    }
                }
            }
            else
            {
                for (int x = blockMaxAndMin[area]; x <= 13; x++)
                {
                    for (int y = 3 * area + 1; y <= 3 * area + 2; y++)
                    {
                        petsNumInsideTargetArea[area] += animalCnts[x][y];
                        if (!catchAllAnimalsNotDog)
                            petsNumInsideTargetArea[area] -= dogCnts[x][y];
                    }
                }
            }
        }
        else
        {
            if (area == 19)
            {
                for (int x = 18; x <= blockMaxAndMin[area]; x++)
                {
                    for (int y = 28; y <= 30; y++)
                    {
                        petsNumInsideTargetArea[area] += animalCnts[x][y];
                        if (!catchAllAnimalsNotDog)
                            petsNumInsideTargetArea[area] -= dogCnts[x][y];
                    }
                }
            }
            else
            {
                for (int x = 18; x <= blockMaxAndMin[area]; x++)
                {
                    for (int y = 3 * (area - 10) + 1; y <= 3 * (area - 10) + 2; y++)
                    {
                        petsNumInsideTargetArea[area] += animalCnts[x][y];
                        if (!catchAllAnimalsNotDog)
                            petsNumInsideTargetArea[area] -= dogCnts[x][y];
                    }
                }
            }
        }
    }
}

int cntUncatchedPetsNum(vector<vector<int>> &field, vector<Human> &human, vector<vector<int>> &animalCnts, int humanIdx)
{
    int uncatchedPetsNum = 0;
    vector<vector<bool>> connectedField(32, vector<bool>(32));
    vector<vector<bool>> visited(32, vector<bool>(32));
    dfs(field, connectedField, visited, human[humanIdx].x, human[humanIdx].y);
    for (int x = 1; x <= 30; x++)
    {
        for (int y = 1; y <= 30; y++)
        {
            if (connectedField[x][y])
                uncatchedPetsNum += animalCnts[x][y];
        }
    }

    return uncatchedPetsNum;
}

// あとは多分これだけ 2022/02/24
// 一番近い人が取りに行けば捕まえられるはず
void decideNextTargetAreaToClose(vector<vector<int>> &field, vector<bool> &ifClosedTargetArea, vector<int> &targetAreaToClose, vector<int> &petsNumInsideTargetArea, vector<Human> &human, vector<bool> &reachedTargetPoints, vector<P> &idxTarget, vector<bool> &seekingNextTargetArea, vector<bool> &placedVerticalBlock, string &ans, int M, int humanIdx)
{
    // ifClosedTargetArea, targetAreaToClose, petsNumInsideTargetArea, human, reachedTargetArea, ans
    int dist = INT_INF;
    int nextTargetArea = -1;

    vector<int> candidate;
    for (int area = 0; area < 20; area++)
    {
        // area と placedVerticalBlockに使うidxの変換
        if (area % 2 != 0)
        {
            if (!placedVerticalBlock[area / 2])
                continue;
        }
        else
        {
            if (area == 0)
            {
                if (!placedVerticalBlock[area])
                    continue;
            }
            else if (area == 10)
            {
                if (!placedVerticalBlock[area / 2])
                    continue;
            }
            else
            {
                if (!placedVerticalBlock[area / 2 - 1] || !placedVerticalBlock[area / 2])
                    continue;
            }
        }

        if (ifClosedTargetArea[area] || petsNumInsideTargetArea[area] == 0)
            continue;
        else
            candidate.push_back(area);

        /*
            bool isSame = false;
            for (int h = 0; h < M; h++)
            {
              if (targetAreaToClose[h] == area)
                isSame = true;
            }
            if (isSame)
              continue;
              */

        /*
        if (petsNumInsideTargetArea[area] > 0)
        {
          if (area < 10)
          {
            if (abs(human[humanIdx].y - area * 3) < dist)
            {
              dist = abs(human[humanIdx].y - area * 3);
              nextTargetArea = area;
            }
          }
          else
          {
            if (abs(human[humanIdx].y - (area - 10) * 3) < dist)
            {
              dist = abs(human[humanIdx].y - (area - 10) * 3);
              nextTargetArea = area;
            }
          }
        }
        */
    }
    // cerr << "nextTargetArea: " << nextTargetArea << endl;

    if (humanIdx == 0 || humanIdx == 5)
    {
        for (auto it : candidate)
        {
            if (it == 0 || it == 1 || it == 10 || it == 11)
            {
                nextTargetArea = it;
                break;
            }
        }
    }
    else if (humanIdx == 1 || humanIdx == 6)
    {
        for (auto it : candidate)
        {
            if (it == 2 || it == 3 || it == 12 || it == 13)
            {
                nextTargetArea = it;
                break;
            }
        }
    }
    else if (humanIdx == 2 || humanIdx == 7)
    {
        for (auto it : candidate)
        {
            if (it == 4 || it == 5 || it == 14 || it == 15)
            {
                nextTargetArea = it;
                break;
            }
        }
    }
    else if (humanIdx == 3 || humanIdx == 8)
    {
        for (auto it : candidate)
        {
            if (it == 6 || it == 7 || it == 16 || it == 17)
            {
                nextTargetArea = it;
                break;
            }
        }
    }
    else
    {
        for (auto it : candidate)
        {
            if (it == 8 || it == 9 || it == 18 || it == 19)
            {
                nextTargetArea = it;
                break;
            }
        }
    }

    /*
    int candidateSize = candidate.size();
    if (candidateSize > 0)
    {
      int idx = get_rand_range(0, candidateSize - 1);
      nextTargetArea = candidate[idx];
    }
    */

    if (nextTargetArea != -1)
    {
        targetAreaToClose[humanIdx] = nextTargetArea;
        seekingNextTargetArea[humanIdx] = false;
        if (targetAreaToClose[humanIdx] < 10)
        {
            idxTarget[humanIdx] = {15, targetAreaToClose[humanIdx] * 3 + 1};
            reachedTargetPoints[humanIdx] = false;
        }
        else
        {
            idxTarget[humanIdx] = {16, (targetAreaToClose[humanIdx] - 10) * 3 + 1};
            reachedTargetPoints[humanIdx] = false;
        }
    }
}

void closeAreaInsideAnimal(vector<vector<int>> &field, vector<vector<int>> &prevField, vector<int> &targetAreaToClose, vector<Human> &human, vector<P> &idxTarget, vector<bool> &reachedTargetPoints, vector<int> &blockMaxAndMin, vector<bool> &ifClosedTargetArea, vector<int> &petsNumInsideTargetArea, vector<bool> &seekingNextTargetArea, vector<bool> &placedVerticalBlock, string &ans, int humanIdx, int M)
{ // すでにtargetArea内にanimalがいなかったら閉じるのやめてseekingNextTargetAreaをONに
    cerr << "targetAreaToClose: " << targetAreaToClose[humanIdx] << endl;
    if (petsNumInsideTargetArea[targetAreaToClose[humanIdx]] == 0)
    {
        seekingNextTargetArea[humanIdx] = true;
        ans += ".";
        return;
    }

    if (targetAreaToClose[humanIdx] < 10)
    {
        if (targetAreaToClose[humanIdx] == 9)
        {
            int targetCol = targetAreaToClose[humanIdx] * 3 + 1;
            if (field[human[humanIdx].x - 1][targetCol] != 1 && canPutBlock(field, prevField, human[humanIdx], 'u'))
            {
                ans += "u";
                field[human[humanIdx].x - 1][targetCol] = 1;
                idxTarget[humanIdx].second++;
                reachedTargetPoints[humanIdx] = false;
            }
            else if (field[human[humanIdx].x - 1][targetCol + 1] != 1 && canPutBlock(field, prevField, human[humanIdx], 'u'))
            {
                ans += "u";
                field[human[humanIdx].x - 1][targetCol + 1] = 1;
                idxTarget[humanIdx].second++;
                reachedTargetPoints[humanIdx] = false;
            }
            else if (canPutBlock(field, prevField, human[humanIdx], 'u'))
            {
                ans += "u";
                field[human[humanIdx].x - 1][targetCol + 2] = 1;
                blockMaxAndMin[targetAreaToClose[humanIdx]] = 14;
                ifClosedTargetArea[targetAreaToClose[humanIdx]] = true;
                // ここから次の処理
                seekingNextTargetArea[humanIdx] = true;
                for (int h = 0; h < M; h++)
                {
                    if (targetAreaToClose[h] == -1)
                        continue;
                    if (ifClosedTargetArea[targetAreaToClose[h]])
                        seekingNextTargetArea[h] = true;
                }
                decideNextTargetAreaToClose(field, ifClosedTargetArea, targetAreaToClose, petsNumInsideTargetArea, human, reachedTargetPoints, idxTarget, seekingNextTargetArea, placedVerticalBlock, ans, M, humanIdx);
            }
            else
            {
                ans += ".";
                return;
            }
        }
        else
        {
            int targetCol = targetAreaToClose[humanIdx] * 3 + 1;
            if (field[human[humanIdx].x - 1][targetCol] != 1 && canPutBlock(field, prevField, human[humanIdx], 'u'))
            {
                ans += "u";
                field[human[humanIdx].x - 1][targetCol] = 1;
                idxTarget[humanIdx].second++;
                reachedTargetPoints[humanIdx] = false;
            }
            else if (field[human[humanIdx].x - 1][targetCol + 1] != 1 && canPutBlock(field, prevField, human[humanIdx], 'u'))
            {
                ans += "u";
                field[human[humanIdx].x - 1][targetCol + 1] = 1;
                blockMaxAndMin[targetAreaToClose[humanIdx]] = 14;
                ifClosedTargetArea[targetAreaToClose[humanIdx]] = true;
                // ここから次の処理
                seekingNextTargetArea[humanIdx] = true;
                for (int h = 0; h < M; h++)
                {
                    if (targetAreaToClose[h] == -1)
                        continue;

                    if (ifClosedTargetArea[targetAreaToClose[h]])
                        seekingNextTargetArea[h] = true;
                }
                decideNextTargetAreaToClose(field, ifClosedTargetArea, targetAreaToClose, petsNumInsideTargetArea, human, reachedTargetPoints, idxTarget, seekingNextTargetArea, placedVerticalBlock, ans, M, humanIdx);
            }
            else
            {
                ans += ".";
                return;
            }
        }
    }
    else
    {
        if (targetAreaToClose[humanIdx] == 19)
        {
            int targetCol = (targetAreaToClose[humanIdx] - 10) * 3 + 1;
            if (field[human[humanIdx].x + 1][targetCol] != 1 && canPutBlock(field, prevField, human[humanIdx], 'd'))
            {
                ans += "d";
                field[human[humanIdx].x + 1][targetCol] = 1;
                idxTarget[humanIdx].second++;
                reachedTargetPoints[humanIdx] = false;
            }
            else if (field[human[humanIdx].x + 1][targetCol + 1] != 1 && canPutBlock(field, prevField, human[humanIdx], 'd'))
            {
                ans += "d";
                field[human[humanIdx].x + 1][targetCol + 1] = 1;
                idxTarget[humanIdx].second++;
                reachedTargetPoints[humanIdx] = false;
            }
            else if (canPutBlock(field, prevField, human[humanIdx], 'd'))
            {
                ans += "d";
                field[human[humanIdx].x + 1][targetCol + 2] = 1;
                blockMaxAndMin[targetAreaToClose[humanIdx]] = 17;
                ifClosedTargetArea[targetAreaToClose[humanIdx]] = true;
                // ここから次の処理
                seekingNextTargetArea[humanIdx] = true;
                for (int h = 0; h < M; h++)
                {
                    if (targetAreaToClose[h] == -1)
                        continue;

                    if (ifClosedTargetArea[targetAreaToClose[h]])
                        seekingNextTargetArea[h] = true;
                }
                decideNextTargetAreaToClose(field, ifClosedTargetArea, targetAreaToClose, petsNumInsideTargetArea, human, reachedTargetPoints, idxTarget, seekingNextTargetArea, placedVerticalBlock, ans, M, humanIdx);
            }
            else
            {
                ans += ".";
                return;
            }
        }
        else
        {
            int targetCol = (targetAreaToClose[humanIdx] - 10) * 3 + 1;
            if (field[human[humanIdx].x + 1][targetCol] != 1 && canPutBlock(field, prevField, human[humanIdx], 'd'))
            {
                ans += "d";
                field[human[humanIdx].x + 1][targetCol] = 1;
                idxTarget[humanIdx].second++;
                reachedTargetPoints[humanIdx] = false;
            }
            else if (field[human[humanIdx].x + 1][targetCol + 1] != 1 && canPutBlock(field, prevField, human[humanIdx], 'd'))
            {
                ans += "d";
                field[human[humanIdx].x + 1][targetCol + 1] = 1;
                blockMaxAndMin[targetAreaToClose[humanIdx]] = 17;
                ifClosedTargetArea[targetAreaToClose[humanIdx]] = true;
                // ここから次の処理
                seekingNextTargetArea[humanIdx] = true;
                for (int h = 0; h < M; h++)
                {
                    if (targetAreaToClose[h] == -1)
                        continue;

                    if (ifClosedTargetArea[targetAreaToClose[h]])
                        seekingNextTargetArea[h] = true;
                }
                decideNextTargetAreaToClose(field, ifClosedTargetArea, targetAreaToClose, petsNumInsideTargetArea, human, reachedTargetPoints, idxTarget, seekingNextTargetArea, placedVerticalBlock, ans, M, humanIdx);
            }
            else
            {
                ans += ".";
                return;
            }
        }
    }
}

void transitStateAfterVerticalBlock(vector<vector<int>> &field, vector<int> &initialCol, vector<int> &targetAreaOfHuman, vector<bool> &placedVerticalBlock, vector<P> &idxTarget, vector<bool> &reachedTargetPoints, int humanIdx, int M, bool processDog)
{
    // verticalBlockを置き終わったかをチェック、置き終わっていたら状態を遷移させる　TODO
    bool checkFinishedVerticalBlock = true;
    static int finishedCol = 0;
    if (targetAreaOfHuman[humanIdx] < 5)
    {
        if (targetAreaOfHuman[humanIdx] == 4)
        {
            if (processDog)
            {
                for (int x = 4; x <= 13; x++)
                {
                    if (field[x][initialCol[humanIdx] - 1] != 1)
                        checkFinishedVerticalBlock = false;
                }
            }
            else
            {
                for (int x = 1; x <= 13; x++)
                {
                    if (field[x][initialCol[humanIdx] - 1] != 1)
                        checkFinishedVerticalBlock = false;
                }
            }
        }
        else
        {
            for (int x = 1; x <= 13; x++)
            {
                if (field[x][initialCol[humanIdx] - 1] != 1 || field[x][initialCol[humanIdx] + 2] != 1)
                    checkFinishedVerticalBlock = false;
            }
        }
    }
    else
    {
        if (targetAreaOfHuman[humanIdx] == 9)
        {
            for (int x = 18; x <= 30; x++)
            {
                if (field[x][initialCol[humanIdx] - 1] != 1)
                    checkFinishedVerticalBlock = false;
            }
        }
        else
        {
            for (int x = 18; x <= 30; x++)
            {
                if (field[x][initialCol[humanIdx] - 1] != 1 || field[x][initialCol[humanIdx] + 2] != 1)
                    checkFinishedVerticalBlock = false;
            }
        }
    }

    // cerr << "checkFinishedVerticalBlock: " << checkFinishedVerticalBlock << endl;
    if (checkFinishedVerticalBlock)
    {
        finishedCol++;
        // cerr << "finishedCol: " << finishedCol << endl;
        placedVerticalBlock[targetAreaOfHuman[humanIdx]] = true;
        set<int> candidateTargetArea;
        for (int c = 0; c < 10; c++)
            if (!placedVerticalBlock[c])
                candidateTargetArea.insert(c);

        for (int h = 0; h < M; h++)
        {
            if (candidateTargetArea.find(targetAreaOfHuman[h]) != candidateTargetArea.end())
                candidateTargetArea.erase(targetAreaOfHuman[h]);
        }

        int nextTargetArea = -1;
        if (candidateTargetArea.size() > 0)
        {
            nextTargetArea = *candidateTargetArea.begin();
            targetAreaOfHuman[humanIdx] = nextTargetArea;
            // idxTargetの更新、reachedTargetPointsの更新
            if (nextTargetArea < 5)
            {
                if (nextTargetArea == 4)
                {
                    idxTarget[humanIdx] = {1, 28};
                    initialCol[humanIdx] = 28;
                    reachedTargetPoints[humanIdx] = false;
                }
                else
                {
                    idxTarget[humanIdx] = {1, 6 * nextTargetArea + 4};
                    initialCol[humanIdx] = 6 * nextTargetArea + 4;
                    reachedTargetPoints[humanIdx] = false;
                }
            }
            else
            {
                if (nextTargetArea == 9)
                {
                    idxTarget[humanIdx] = {30, 28};
                    initialCol[humanIdx] = 28;
                    reachedTargetPoints[humanIdx] = false;
                }
                else
                {
                    idxTarget[humanIdx] = {30, 6 * (nextTargetArea - 5) + 4};
                    initialCol[humanIdx] = 6 * (nextTargetArea - 5) + 4;
                    reachedTargetPoints[humanIdx] = false;
                }
            }
        }

        // cerr << "nextTargetArea: " << nextTargetArea << endl;
    }
}

int checkBlockmaxAndMin(vector<vector<int>> &field, vector<int> &targetAreaOfHuman, vector<int> &initialCol, int humanIdx)
{
    int blockMaxAndMin = (targetAreaOfHuman[humanIdx] < 5) ? 0 : 31;
    if (targetAreaOfHuman[humanIdx] < 5)
    {
        if (targetAreaOfHuman[humanIdx] == 4)
        {
            for (int x = blockMaxAndMin + 1; x <= 13; x++)
            {
                if (field[x][initialCol[humanIdx]] == 1 && field[x][initialCol[humanIdx] + 1] == 1 && field[x][initialCol[humanIdx] + 1] == 1)
                    blockMaxAndMin = x;
            }
        }
        else
        {
            for (int x = blockMaxAndMin + 1; x <= 13; x++)
            {
                if (field[x][initialCol[humanIdx]] == 1 && field[x][initialCol[humanIdx] + 1] == 1)
                    blockMaxAndMin = x;
            }
        }
    }
    else
    {
        if (targetAreaOfHuman[humanIdx] == 9)
        {
            for (int x = blockMaxAndMin - 1; x >= 18; x--)
            {
                if (field[x][initialCol[humanIdx]] == 1 && field[x][initialCol[humanIdx] + 1] == 1 && field[x][initialCol[humanIdx] + 2] == 1)
                    blockMaxAndMin = x;
            }
        }
        else
        {
            for (int x = blockMaxAndMin - 1; x >= 18; x--)
            {
                if (field[x][initialCol[humanIdx]] == 1 && field[x][initialCol[humanIdx] + 1] == 1)
                    blockMaxAndMin = x;
            }
        }
    }
    return blockMaxAndMin;
}

int countAnimalInsideBlocks(vector<vector<int>> &animalCnts, vector<int> &targetAreaOfHuman, vector<Human> &human, vector<int> &initialCol, int humanIdx, int &blockMaxOrMin)
{
    int animalCntsInsideBlocks = 0;
    if (targetAreaOfHuman[humanIdx] < 5)
    {
        if (targetAreaOfHuman[humanIdx] == 4)
        {
            for (int x = blockMaxOrMin + 1; x < human[humanIdx].x - 1; x++)
            {
                for (int y = initialCol[humanIdx]; y <= initialCol[humanIdx] + 2; y++)
                {
                    animalCntsInsideBlocks += animalCnts[x][y];
                }
            }
        }
        else
        {
            for (int x = blockMaxOrMin + 1; x < human[humanIdx].x - 1; x++)
            {
                for (int y = initialCol[humanIdx]; y <= initialCol[humanIdx] + 1; y++)
                {
                    animalCntsInsideBlocks += animalCnts[x][y];
                }
            }
        }
    }
    else
    {
        if (targetAreaOfHuman[humanIdx] == 9)
        {
            for (int x = blockMaxOrMin - 1; x > human[humanIdx].x + 1; x--)
            {
                for (int y = initialCol[humanIdx]; y <= initialCol[humanIdx] + 2; y++)
                {
                    animalCntsInsideBlocks += animalCnts[x][y];
                }
            }
        }
        else
        {
            for (int x = blockMaxOrMin - 1; x > human[humanIdx].x + 1; x--)
            {
                for (int y = initialCol[humanIdx]; y <= initialCol[humanIdx] + 1; y++)
                {
                    animalCntsInsideBlocks += animalCnts[x][y];
                }
            }
        }
    }
    return animalCntsInsideBlocks;
}

void putBlockDuringVertical(vector<vector<int>> &field, vector<vector<int>> &prevField, vector<int> &targetAreaOfHuman, vector<Human> &human, vector<bool> &puttingBlock, vector<int> &initialCol, vector<P> &idxTarget, vector<int> &blockMaxAndMin, vector<bool> &reachedTargetPoints, string &ans, int humanIdx)
{
    if (targetAreaOfHuman[humanIdx] < 5)
    {
        if (targetAreaOfHuman[humanIdx] == 4)
        {
            if (canPutBlock(field, prevField, human[humanIdx], 'u'))
            {
                ans += "u";
                field[human[humanIdx].x - 1][human[humanIdx].y] = 1;
                puttingBlock[humanIdx] = true;
                if (human[humanIdx].y == initialCol[humanIdx])
                {
                    idxTarget[humanIdx].second++;
                }
                else if (human[humanIdx].y == initialCol[humanIdx] + 1)
                {
                    idxTarget[humanIdx].second++;
                }
                else
                {
                    // idxTarget[i].first++;
                    idxTarget[humanIdx].second = initialCol[humanIdx];
                    blockMaxAndMin[9] = human[humanIdx].x - 1;
                    puttingBlock[humanIdx] = false;
                }
                reachedTargetPoints[humanIdx] = false;
                return; // 置けたら次の人に移る
            }
            else
            {
                ans += ".";
                return;
            }
        }
        else
        {
            if (canPutBlock(field, prevField, human[humanIdx], 'u'))
            {
                ans += "u";
                field[human[humanIdx].x - 1][human[humanIdx].y] = 1;
                puttingBlock[humanIdx] = true;
                if (human[humanIdx].y == initialCol[humanIdx])
                {
                    if (field[human[humanIdx].x - 1][human[humanIdx].y + 1] == 1)
                    {
                        // idxTarget[i].first++;
                        if (field[human[humanIdx].x][human[humanIdx].y - 1] == 1 && field[human[humanIdx].x][human[humanIdx].y + 2] != 1)
                            idxTarget[humanIdx].second++;
                        int processedCol = (initialCol[humanIdx] / 6 + 1) * 2 - 1;
                        blockMaxAndMin[processedCol] = human[humanIdx].x - 1;
                        puttingBlock[humanIdx] = false;
                    }
                    else
                        idxTarget[humanIdx].second++;
                }
                else
                {
                    if (field[human[humanIdx].x - 1][human[humanIdx].y - 1] == 1)
                    {
                        // idxTarget[i].first++;
                        if (field[human[humanIdx].x][human[humanIdx].y - 2] != 1 && field[human[humanIdx].x][human[humanIdx].y + 1] == 1)
                            idxTarget[humanIdx].second--;
                        int processedCol = (initialCol[humanIdx] / 6 + 1) * 2 - 1;
                        blockMaxAndMin[processedCol] = human[humanIdx].x - 1;
                        puttingBlock[humanIdx] = false;
                    }
                    else
                        idxTarget[humanIdx].second--;
                }
                reachedTargetPoints[humanIdx] = false;
                return; // 置けたら次の人に移る
            }
            else
            {
                ans += ".";
                return;
            }
        }
    }
    else
    {
        if (targetAreaOfHuman[humanIdx] == 9)
        {
            if (canPutBlock(field, prevField, human[humanIdx], 'd'))
            {
                ans += "d";
                field[human[humanIdx].x + 1][human[humanIdx].y] = 1;
                puttingBlock[humanIdx] = true;
                if (human[humanIdx].y == initialCol[humanIdx])
                {
                    idxTarget[humanIdx].second++;
                }
                else if (human[humanIdx].y == initialCol[humanIdx] + 1)
                {
                    idxTarget[humanIdx].second++;
                }
                else
                {
                    // idxTarget[i].first--;
                    idxTarget[humanIdx].second = initialCol[humanIdx];
                    blockMaxAndMin[19] = human[humanIdx].x + 1;
                    puttingBlock[humanIdx] = false;
                }
                reachedTargetPoints[humanIdx] = false;
                return; // 置けたら次の人に移る
            }
            else
            {
                ans += ".";
                return;
            }
        }
        else
        {
            if (canPutBlock(field, prevField, human[humanIdx], 'd'))
            {
                ans += "d";
                field[human[humanIdx].x + 1][human[humanIdx].y] = 1;
                puttingBlock[humanIdx] = true;
                if (human[humanIdx].y == initialCol[humanIdx])
                {
                    if (field[human[humanIdx].x + 1][human[humanIdx].y + 1] == 1)
                    {
                        // idxTarget[i].first--;
                        if (field[human[humanIdx].x][human[humanIdx].y - 1] == 1 && field[human[humanIdx].x][human[humanIdx].y + 2] != 1)
                            idxTarget[humanIdx].second++;
                        int processedCol = (initialCol[humanIdx] / 6 + 1) * 2 - 1;
                        processedCol += 10;
                        blockMaxAndMin[processedCol] = human[humanIdx].x + 1;
                        puttingBlock[humanIdx] = false;
                    }
                    else
                        idxTarget[humanIdx].second++;
                }
                else
                {
                    if (field[human[humanIdx].x + 1][human[humanIdx].y - 1] == 1)
                    {
                        // idxTarget[i].first--;
                        if (field[human[humanIdx].x][human[humanIdx].y - 2] != 1 && field[human[humanIdx].x][human[humanIdx].y + 1] == 1)
                            idxTarget[humanIdx].second--;
                        int processedCol = (initialCol[humanIdx] / 6 + 1) * 2 - 1;

                        processedCol += 10;
                        blockMaxAndMin[processedCol] = human[humanIdx].x + 1;
                        puttingBlock[humanIdx] = false;
                    }
                    else
                        idxTarget[humanIdx].second--;
                }
                reachedTargetPoints[humanIdx] = false;
                return; // 置けたら次の人に移る
            }
            else
            {
                ans += ".";
                return;
            }
        }
    }
}

void putVerticalBlockSeries(vector<vector<int>> &field, vector<vector<int>> &prevField, vector<int> &targetAreaOfHuman, vector<Human> &human, vector<int> &initialCol, vector<bool> &reachedTargetPoints, vector<P> &idxTarget, string &ans, int humanIdx)
{
    if (targetAreaOfHuman[humanIdx] < 5)
    {
        if (targetAreaOfHuman[humanIdx] == 4)
        {
            if (canPutBlock(field, prevField, human[humanIdx], 'l'))
            {
                ans += "l";
                field[human[humanIdx].x][human[humanIdx].y - 1] = 1;
                idxTarget[humanIdx].first++;
                reachedTargetPoints[humanIdx] = false;
            }
            else if (field[human[humanIdx].x][human[humanIdx].y - 1] == 1)
            {
                ans += ".";
                idxTarget[humanIdx].first++;
                reachedTargetPoints[humanIdx] = false;
            }
            else
            {
                ans += ".";
                return;
            }
        }
        else
        {
            if (human[humanIdx].y == initialCol[humanIdx])
            {
                if (canPutBlock(field, prevField, human[humanIdx], 'l'))
                {
                    ans += "l";
                    field[human[humanIdx].x][human[humanIdx].y - 1] = 1;
                    if (field[human[humanIdx].x][human[humanIdx].y + 2] == 1)
                    {
                        idxTarget[humanIdx].first++;
                    }
                    else
                    {
                        idxTarget[humanIdx].second++;
                    }
                    reachedTargetPoints[humanIdx] = false;
                }
                else if (field[human[humanIdx].x][human[humanIdx].y - 1] == 1)
                {
                    ans += ".";
                    if (field[human[humanIdx].x][human[humanIdx].y + 2] == 1)
                    {
                        idxTarget[humanIdx].first++;
                    }
                    else
                    {
                        idxTarget[humanIdx].second++;
                    }
                    reachedTargetPoints[humanIdx] = false;
                }
                else
                {
                    ans += ".";
                    return;
                }
            }
            else
            {
                if (canPutBlock(field, prevField, human[humanIdx], 'r'))
                {
                    ans += "r";
                    field[human[humanIdx].x][human[humanIdx].y + 1] = 1;
                    if (field[human[humanIdx].x][human[humanIdx].y - 2] == 1)
                    {
                        idxTarget[humanIdx].first++;
                    }
                    else
                    {
                        idxTarget[humanIdx].second--;
                    }
                    reachedTargetPoints[humanIdx] = false;
                }
                else if (field[human[humanIdx].x][human[humanIdx].y + 1] == 1)
                {
                    ans += ".";
                    if (field[human[humanIdx].x][human[humanIdx].y - 2] == 1)
                    {
                        idxTarget[humanIdx].first++;
                    }
                    else
                    {
                        idxTarget[humanIdx].second--;
                    }
                    reachedTargetPoints[humanIdx] = false;
                }
                else
                {
                    ans += ".";
                    return;
                }
            }
        }
    }
    else
    {
        if (targetAreaOfHuman[humanIdx] == 9)
        {
            if (canPutBlock(field, prevField, human[humanIdx], 'l'))
            {
                ans += "l";
                field[human[humanIdx].x][human[humanIdx].y - 1] = 1;
                idxTarget[humanIdx].first--;
                reachedTargetPoints[humanIdx] = false;
            }
            else if (field[human[humanIdx].x][human[humanIdx].y - 1] == 1)
            {
                ans += ".";
                idxTarget[humanIdx].first--;
                reachedTargetPoints[humanIdx] = false;
            }
            else
            {
                ans += ".";
                return;
            }
        }
        else
        {
            if (human[humanIdx].y == initialCol[humanIdx])
            {
                if (canPutBlock(field, prevField, human[humanIdx], 'l'))
                {
                    ans += "l";
                    field[human[humanIdx].x][human[humanIdx].y - 1] = 1;
                    if (field[human[humanIdx].x][human[humanIdx].y + 2] == 1)
                    {
                        idxTarget[humanIdx].first--;
                    }
                    else
                    {
                        idxTarget[humanIdx].second++;
                    }
                    reachedTargetPoints[humanIdx] = false;
                }
                else if (field[human[humanIdx].x][human[humanIdx].y - 1] == 1)
                {
                    ans += ".";
                    if (field[human[humanIdx].x][human[humanIdx].y + 2] == 1)
                    {
                        idxTarget[humanIdx].first--;
                    }
                    else
                    {
                        idxTarget[humanIdx].second++;
                    }
                    reachedTargetPoints[humanIdx] = false;
                }
                else
                {
                    ans += ".";
                    return;
                }
            }
            else
            {
                if (canPutBlock(field, prevField, human[humanIdx], 'r'))
                {
                    ans += "r";
                    field[human[humanIdx].x][human[humanIdx].y + 1] = 1;
                    if (field[human[humanIdx].x][human[humanIdx].y - 2] == 1)
                    {
                        idxTarget[humanIdx].first--;
                    }
                    else
                    {
                        idxTarget[humanIdx].second--;
                    }
                    reachedTargetPoints[humanIdx] = false;
                }
                else if (field[human[humanIdx].x][human[humanIdx].y + 1] == 1)
                {
                    ans += ".";
                    if (field[human[humanIdx].x][human[humanIdx].y - 2] == 1)
                    {
                        idxTarget[humanIdx].first--;
                    }
                    else
                    {
                        idxTarget[humanIdx].second--;
                    }
                    reachedTargetPoints[humanIdx] = false;
                }
                else
                {
                    ans += ".";
                    return;
                }
            }
        }
    }
}

void placeVerticalBlocks(vector<vector<int>> &field, vector<vector<int>> &prevField, vector<int> &targetAreaOfHuman, vector<int> &initialCol, vector<Human> &human, vector<vector<int>> &animalCnts, vector<bool> &puttingBlock, vector<P> &idxTarget, vector<int> &blockMaxAndMin, vector<bool> &reachedTargetPoints, vector<bool> &placedVerticalBlock, string &ans, int M, int humanIdx, bool processDog)
{
    // メインパート、ブロックを置きながら動物を捕獲していく

    // 壁があるところを調べる
    int blockMaxOrMin = checkBlockmaxAndMin(field, targetAreaOfHuman, initialCol, humanIdx);
    // int blockMaxOrMin = blockMaxAndMin[targetAreaOfHuman[humanIdx]];

    // 探索範囲に動物がいるかをチェックする
    int animalCntsInsideBlocks = countAnimalInsideBlocks(animalCnts, targetAreaOfHuman, human, initialCol, humanIdx, blockMaxOrMin);

    if (!(processDog && (targetAreaOfHuman[humanIdx] == 4 || targetAreaOfHuman[humanIdx] == 9)) && (animalCntsInsideBlocks > 0 || puttingBlock[humanIdx]))
    {
        putBlockDuringVertical(field, prevField, targetAreaOfHuman, human, puttingBlock, initialCol, idxTarget, blockMaxAndMin, reachedTargetPoints, ans, humanIdx);
        transitStateAfterVerticalBlock(field, initialCol, targetAreaOfHuman, placedVerticalBlock, idxTarget, reachedTargetPoints, humanIdx, M, processDog);
        return;
    }

    putVerticalBlockSeries(field, prevField, targetAreaOfHuman, human, initialCol, reachedTargetPoints, idxTarget, ans, humanIdx);
    transitStateAfterVerticalBlock(field, initialCol, targetAreaOfHuman, placedVerticalBlock, idxTarget, reachedTargetPoints, humanIdx, M, processDog);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> field(32, vector<int>(32)); // 0が床、1が壁あり、2がペット、3が人、4が人とペット
    UnionFind connectedWall(32 * 32);
    for (int j = 0; j < 32; j++)
    {
        field[0][j] = 1;
        field[31][j] = 1;
        connectedWall.merge(0, 0 * 32 + j);
        connectedWall.merge(0, 31 * 32 + j);
    }
    for (int i = 0; i < 32; i++)
    {
        field[i][0] = 1;
        field[i][31] = 1;
        connectedWall.merge(0, i * 32 + 0);
        connectedWall.merge(0, i * 32 + 31);
    }

    vector<vector<int>> humanCnts(32, vector<int>(32));
    vector<vector<int>> animalCnts(32, vector<int>(32));
    vector<vector<int>> dogCnts(32, vector<int>(32));

    int N;
    cin >> N;
    int notDog = 0;
    vector<Animal> pets(N);
    vector<int> targetHumanIdx(N);
    vector<P> targetSquare(N);
    vector<bool> isDog(N);
    vector<bool> isCat(N);

    bool existDog = false;
    for (int i = 0; i < N; i++)
    {
        int px, py, pt;
        cin >> px >> py >> pt;
        pets[i] = {px, py, pt};
        animalCnts[px][py]++;
        if (pt == 4)
        {
            dogCnts[px][py]++;
            existDog = true;
        }
        else
            notDog++;
    }

    int M;
    cin >> M;
    cerr << "M: " << M << endl;
    vector<Human> human(M);
    for (int i = 0; i < M; i++)
    {
        int hx, hy;
        cin >> hx >> hy;
        human[i] = {hx, hy};
        humanCnts[hx][hy]++;
    }

    // cerr << "b" << endl;
    for (int x = 1; x <= 30; x++)
    {
        for (int y = 1; y <= 30; y++)
        {
            if (humanCnts[x][y] && animalCnts[x][y])
                field[x][y] = 4;
            else if (humanCnts[x][y] && !animalCnts[x][y])
                field[x][y] = 3;
            else if (!humanCnts[x][y] && animalCnts[x][y])
                field[x][y] = 2;
        }
    }
    // cerr << "c" << endl;

    // 5以上の人の初期位置をパラメータにすればいい、高得点のものを採用する
    vector<P> idxTarget(M);
    vector<int> initialCol(M);
    vector<int> targetAreaOfHuman(M);
    bool processDogs = false;
    if (!existDog)
    {
        for (int h = 0; h < M; h++)
        {
            targetAreaOfHuman[h] = h;
            if (h < 5)
            {
                if (h == 4)
                {
                    idxTarget[h] = {1, 28};
                    initialCol[h] = 28;
                }
                else
                {
                    idxTarget[h] = {1, 6 * h + 4};
                    initialCol[h] = 6 * h + 4;
                }
            }
            else
            {
                if (h == 9)
                {
                    idxTarget[h] = {30, 28};
                    initialCol[h] = 28;
                }
                else
                {
                    idxTarget[h] = {30, 6 * (h - 5) + 4};
                    initialCol[h] = 6 * (h - 5) + 4;
                }
            }
        }
    }
    else
    {
        processDogs = true;
        idxTarget[0] = {3, 24};
        idxTarget[1] = {7, 28};
        for (int h = 2; h < M; h++)
        {
            idxTarget[h] = {1, 30};
        }
    }

    vector<bool> placedVerticalBlock(10); // blockを置かれている途中か？
    vector<bool> reachedTargetPoints(M, false);

    vector<vector<int>> prevField = field;

    vector<int> targetAreaToClose(M, -1); // targetAreaToCloseが被らないようにする
    vector<bool> ifClosedTargetArea(20);  // targetAreaが閉じられているかどうか

    vector<int> blockMaxAndMin(20);
    for (int area = 10; area < 20; area++)
        blockMaxAndMin[area] = 30;

    vector<bool> puttingBlock(M);

    vector<bool> seekingNextTargetArea(M, true);

    bool catchAllDogs = false;

    // 犬捕獲用の変数
    bool phasePutInitBlock = true;
    bool phasePutSecondBlock = true;
    bool phasePutThirdBlock = false;
    bool phaseComeAllDogs = false;
    bool phaseComeAllDogs2 = false; // 犬の動きが安定するまで待つ
    bool phasePutLastBlock = false;

    bool startPutLastBlock = false;
    bool canPutLastBlock = false;
    int catchNumberOfPets = 0;
    for (int turn = 0; turn < 300; turn++)
    {
        // cerr << "turn: " << turn << endl;
        string ans;

        vector<vector<vector<int>>> dists(M);
        vector<vector<int>> distsHumanAndAnimal(M, vector<int>(N));
        for (int i = 0; i < M; i++)
        {
            if (!reachedTargetPoints[i])
            {
                moveHuman(field, dists, distsHumanAndAnimal, idxTarget, humanCnts, pets, human, ans, reachedTargetPoints, i, N);
            }
            else
            {
                if (existDog && !catchAllDogs)
                {
                    // 犬を捕まえていきパート 犬を捕まえたらいつもの初期状態を設定する
                    if (phasePutInitBlock && i == 0)
                    {
                        if (canPutBlock(field, prevField, human[i], 'u'))
                        {
                            ans += "u";
                            field[human[i].x - 1][human[i].y] = 1;
                            if (human[i].y != 27)
                                idxTarget[i].second++;
                            else
                            {
                                idxTarget[i] = {2, 28};
                                phasePutInitBlock = false;
                            }
                            reachedTargetPoints[i] = false;
                        }
                        else
                            ans += ".";

                        if (!phasePutInitBlock && !phasePutSecondBlock)
                        {
                            phasePutThirdBlock = true;
                            phasePutInitBlock = false;
                            phasePutSecondBlock = false;
                        }
                    }
                    else if (phasePutSecondBlock && i == 1)
                    {
                        if (canPutBlock(field, prevField, human[i], 'r'))
                        {
                            ans += "r";
                            field[human[i].x][human[i].y + 1] = 1;
                            if (human[i].x != 4)
                                idxTarget[i].first--;
                            else
                            {
                                idxTarget[i] = {2, 29};
                                phasePutSecondBlock = false;
                            }
                            reachedTargetPoints[i] = false;
                        }
                        else
                            ans += ".";

                        if (!phasePutInitBlock && !phasePutSecondBlock)
                        {
                            phasePutThirdBlock = true;
                            phasePutInitBlock = false;
                            phasePutSecondBlock = false;
                        }
                    }
                    else if (phasePutThirdBlock)
                    {
                        if (i == 0 && canPutBlock(field, prevField, human[i], 'd'))
                        {
                            ans += "d";
                            field[human[i].x + 1][human[i].y] = 1;
                            idxTarget[i] = {2, 29};
                            reachedTargetPoints[i] = false;
                        }
                        else
                        {
                            ans += ".";
                        }
                        if (field[3][28] == 1)
                        {
                            phasePutThirdBlock = false;
                            phaseComeAllDogs = true;
                        }
                    }
                    else if (phaseComeAllDogs)
                    {
                        // 人が全員揃っているか&犬が全員揃っているかをチェック
                        bool ok = true;
                        if (human[0].x != 2 || human[0].y != 29 || human[1].x != 2 || human[1].y != 29)
                            ok = false;
                        for (int h = 2; h < M; h++)
                        {
                            if (!(human[h].x == 1 && human[h].y == 30))
                                ok = false;
                        }

                        for (int a = 0; a < N; a++)
                        {
                            if (pets[a].type != 4)
                                continue;
                            if (!((pets[a].x == 1 && pets[a].y == 29) || (pets[a].x == 2 && pets[a].y == 29) || (pets[a].x == 1 && pets[a].y == 30) || (pets[a].x == 2 && pets[a].y == 30)))
                                ok = false;
                        }

                        if (i != M - 1)
                            ok = false;

                        if (ok)
                        {
                            phaseComeAllDogs = false;
                            phaseComeAllDogs2 = true;
                            for (int h = 0; h < 2; h++)
                            {
                                idxTarget[h] = {1, 24};
                                reachedTargetPoints[h] = false;
                            }
                            for (int h = 2; h < M; h++)
                            {
                                idxTarget[h] = {7, 30};
                                reachedTargetPoints[h] = false;
                            }
                        }
                        ans += ".";
                    }
                    else if (phaseComeAllDogs2)
                    {
                        bool ok = true;
                        if (!startPutLastBlock && (human[0].x != 1 || human[0].y != 24 || human[1].x != 1 || human[1].y != 24))
                            ok = false;
                        for (int h = 2; h < M; h++)
                        {
                            if (!startPutLastBlock && !(human[h].x == 7 && human[h].y == 30))
                                ok = false;
                        }

                        for (int a = 0; a < N; a++)
                        {
                            if (pets[a].type != 4)
                                continue;

                            if (!((pets[a].x == 1 && pets[a].y == 28) || (pets[a].x == 2 && pets[a].y == 28) || (pets[a].x == 1 && pets[a].y == 29) || (pets[a].x == 2 && pets[a].y == 29) || (pets[a].x == 1 && pets[a].y == 30) || (pets[a].x == 2 && pets[a].y == 30) || (pets[a].x == 3 && pets[a].y == 29) || (pets[a].x == 3 && pets[a].y == 30)))
                                ok = false;
                        }

                        if (i == 0 && ok)
                            startPutLastBlock = true;

                        if (ok && startPutLastBlock)
                        {
                            if (i == M - 1)
                            {
                                phaseComeAllDogs2 = false;
                                phasePutLastBlock = true;
                            }
                            if (i == 0 || i == 1)
                            {
                                idxTarget[i].second--;
                                reachedTargetPoints[i] = false;
                                moveHuman(field, dists, distsHumanAndAnimal, idxTarget, humanCnts, pets, human, ans, reachedTargetPoints, i, N);
                            }
                            else
                            {
                                idxTarget[i].first++;
                                reachedTargetPoints[i] = false;
                                moveHuman(field, dists, distsHumanAndAnimal, idxTarget, humanCnts, pets, human, ans, reachedTargetPoints, i, N);
                            }
                        }
                        else
                            ans += ".";
                    }
                    else if (phasePutLastBlock)
                    {
                        bool ok = true;
                        if (human[0].x != 1 || human[0].y != 23 || human[1].x != 1 || human[1].y != 23)
                            ok = false;
                        for (int h = 2; h < M; h++)
                        {
                            if (!(human[h].x == 8 && human[h].y == 30))
                                ok = false;
                        }

                        bool ok2 = false;
                        if (canPutBlock(field, prevField, human[0], 'r') && canPutBlock(field, prevField, human[2], 'u'))
                            ok2 = true;

                        if (i == 0 && ok && ok2)
                            canPutLastBlock = true;

                        if (canPutLastBlock)
                        {
                            // cerr << "ok && ok2" << endl;
                            if (i == 0)
                            {
                                ans += "r";
                                field[human[i].x][human[i].y + 1] = 1;
                            }
                            else if (i == 2)
                            {
                                ans += "u";
                                field[human[i].x - 1][human[i].y] = 1;
                            }
                            else
                            {
                                ans += ".";
                            }

                            // ここでいつもの戦略に戻
                            if (i == M - 1)
                            {
                                catchAllDogs = true;
                                for (int h = 0; h < M; h++)
                                {
                                    targetAreaOfHuman[h] = h;
                                    if (h < 5)
                                    {
                                        if (h == 4)
                                        {
                                            idxTarget[h] = {4, 28};
                                            initialCol[h] = 28;
                                        }
                                        else
                                        {
                                            idxTarget[h] = {1, 6 * h + 4};
                                            initialCol[h] = 6 * h + 4;
                                        }
                                    }
                                    else
                                    {
                                        if (h == 9)
                                        {
                                            idxTarget[h] = {30, 28};
                                            initialCol[h] = 28;
                                        }
                                        else
                                        {
                                            idxTarget[h] = {30, 6 * (h - 5) + 4};
                                            initialCol[h] = 6 * (h - 5) + 4;
                                        }
                                    }
                                    reachedTargetPoints[h] = false;
                                }
                            }
                        }
                        else
                        {
                            if (i == M - 1)
                            {
                                // cerr << "putting failed" << endl;
                                startPutLastBlock = false;
                                phaseComeAllDogs2 = true;
                                phasePutLastBlock = false;
                                for (int h = 0; h < 2; h++)
                                {
                                    idxTarget[h] = {1, 24};
                                    reachedTargetPoints[h] = false;
                                }
                                for (int h = 2; h < M; h++)
                                {
                                    idxTarget[h] = {7, 30};
                                    reachedTargetPoints[h] = false;
                                }
                            }
                            ans += ".";
                        }
                    }
                    else
                    {
                        ans += ".";
                    }
                }
                else
                {
                    if (placedVerticalBlock[targetAreaOfHuman[i]] || checkAllVerticalBlock(placedVerticalBlock, i))
                    {
                        // TODO: ここの中にバグあり、修正する
                        int uncatchedPetsNum = cntUncatchedPetsNum(field, human, animalCnts, i);
                        // cerr << "uncatchedPetsNum: " << uncatchedPetsNum << endl;
                        if (uncatchedPetsNum == 0)
                        {
                            ans += ".";
                            continue;
                        }
                        else
                        {
                            // メインパート2、動物が入ったことを観測したら閉じ込める
                            // 各エリアを調べて動物が入っているかどうかを調べる
                            // blockMinやblockMaxからの範囲に動物が入っているか、入っていたら一番近い人が捕まえに行く
                            vector<int> petsNumInsideTargetArea(20);
                            bool catchAllAnimalsNotDog = checkCatchAllNotDog(field, pets, human[i]);
                            cntPetsNumInsideTargetArea(dogCnts, petsNumInsideTargetArea, animalCnts, blockMaxAndMin, catchAllAnimalsNotDog);

                            if (targetAreaToClose[i] == -1 || seekingNextTargetArea[i])
                            {
                                decideNextTargetAreaToClose(field, ifClosedTargetArea, targetAreaToClose, petsNumInsideTargetArea, human, reachedTargetPoints, idxTarget, seekingNextTargetArea, placedVerticalBlock, ans, M, i);
                                ans += ".";
                                continue;
                            }
                            else
                            {
                                cerr << "a" << endl;
                                closeAreaInsideAnimal(field, prevField, targetAreaToClose, human, idxTarget, reachedTargetPoints, blockMaxAndMin, ifClosedTargetArea, petsNumInsideTargetArea, seekingNextTargetArea, placedVerticalBlock, ans, i, M);
                                cerr << "aa" << endl;
                            }
                        }
                    }
                    else
                    {
                        if (!placedVerticalBlock[targetAreaOfHuman[i]])
                        {
                            placeVerticalBlocks(field, prevField, targetAreaOfHuman, initialCol, human, animalCnts, puttingBlock, idxTarget, blockMaxAndMin, reachedTargetPoints, placedVerticalBlock, ans, M, i, processDogs);
                        }
                        else
                        {
                            // 動ける方向にランダムに徘徊
                            // iによって待機位置を変更する
                            idxTarget[i] = {15, 1 + 30 / M * i};
                            ans += ".";
                            continue;
                        }
                    }
                }
            }
            // cerr << "i: " << i << endl;
            // cerr << "ans: " << ans << endl;
            // cerr << "before update field" << endl;
            updateField(field, humanCnts, animalCnts);
        }

        cerr << "turn: " << turn << "  ans: " << ans << endl;
        cout << ans << endl;

        vector<string> next(N);
        for (int s = 0; s < N; s++)
        {
            cin >> next[s];
            for (int c = 0; c < (int)next[s].size(); c++)
            {
                updateAnimalCnts(animalCnts, dogCnts, pets[s], next[s][c]);
            }
            // animalの反映
        }

        updateField(field, humanCnts, animalCnts);

        prevField = field;
    }

    return 0;
}
// 1箇所に集める、その区画の中に入らないのが見込めたら一気に封鎖をかける？
// 犬と猫がいる時は場合分け、犬は一人が一挙に引き受ける、猫は壁外に出てくれるのを待つ
// 犬がいない場合、最初に縦に半分分割する壁を作成する、その後動物が壁内に入ってこないことが推定できたら、全員で一気に壁を作成する、そのために最後は人を一列に並べておく
// TODO: 仕切りを置く予定の場所の隣接4マスに動物がいないことをチェックする関数、置けるかどうかをチェックする関数を書く
// TODO: もっと関数にまとめられるはず
// ただ横に区切るだけのやつと、区切った上でいい感じに閉じ込めるやつはとりあえず実装する、で動物と人間の数や種類によって切り替える
// 火曜日までにこれのデバッグ、リファクタリング、渦巻きの作成をする
// 水曜日と木曜日でシミュレーションを完成させる
// processedColが間違ってそう　改めてチェック 直した
// 次のtargetAreaの更新を直す
// targetが被ってしまっているからそれを解消、閉じ込められていないところを直す
// VericalBlockを置いたあと均等に並ぶようにする
// 犬に惑わされて他の動物がおろそかになっているから、犬以外の動物の数を数えて全て捕まえるまでは犬は無視
// 犬が150ターン以内に捕まえられなかったら強制的に状態を遷移させる
// 近いやつに近づける
// 4分割法を無理やり実装する
