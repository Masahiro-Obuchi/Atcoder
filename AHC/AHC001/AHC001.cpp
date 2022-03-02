#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
/*
struct Edge
{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
*/
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

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

double standardCalcScore(ll r, ll x1, ll y1, ll x2, ll y2)
{
  ll s = (x2 - x1) * (y2 - y1);
  // cerr << "s: " << s << "  r: " << r << endl;
  double score = 1.0 - (1.0 - double(min(r, s)) / double(max(r, s))) * (1.0 - double(min(r, s)) / double(max(r, s)));
  // cerr << "score: " << score << endl;
  return score;
}

double calcScoreLocalMinima(ll r, ll x1, ll y1, ll x2, ll y2, vector<ll> &a, vector<ll> &b, vector<ll> &c, vector<ll> &d, const double &time, const double &TIME_LIMIT)
{
  ll max_x1 = 0, max_y1 = 0, min_x2 = 10000, min_y2 = 10000;
  for (int i = 0; i < (int)a.size(); i++)
  {
    if (max(y1, b[i]) < min(y2, d[i]) && a[i] <= x1)
      max_x1 = max(max_x1, a[i]);
    if (max(x1, a[i]) < min(x2, c[i]) && b[i] <= y1)
      max_y1 = max(max_y1, b[i]);
    if (max(y1, b[i]) < min(y2, d[i]) && c[i] >= x2)
      min_x2 = min(min_x2, c[i]);
    if (max(x1, a[i]) < min(x2, c[i]) && d[i] >= x2)
      min_y2 = min(min_y2, d[i]);
  }

  double penalty = (abs(max_x1 - x1) + abs(max_y1 - y1) + abs(min_x2 - x2) + abs(min_y2 - y2)) / max(1.0, time);
  penalty = 3000 - penalty;
  // cerr << "penalty: " << penalty << endl;
  return penalty;
}

ll calcAllScoreInit(vector<ll> &r, vector<ll> &a, vector<ll> &b, vector<ll> &c, vector<ll> &d, int n)
{
  double allScore = 0.0;
  for (int i = 0; i < n; i++)
  {
    double score = standardCalcScore(r[i], a[i], b[i], c[i], d[i]);
    score /= double(n);
    allScore += score;
  }
  allScore *= 1e9;
  ll finalScore = ll(allScore);
  return finalScore;
}

bool hasIntersect(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4)
{
  return max(x1, x3) < min(x2, x4) && max(y1, y3) < min(y2, y4);
}

bool isLocalMinima(const deque<ll> &oldScore)
{
  int sz = oldScore.size();
  vector<ll> diffScore(sz - 1);

  for (int i = 0; i < sz - 1; i++)
  {
    diffScore[i] = oldScore[i] - oldScore[i + 1];
  }
  double average = 0.0;
  for (auto &it : diffScore)
    average += it;

  average /= (double)sz;
  // cerr << "average: " << average << endl;
  if (abs(average) < 1)
  {
    // std::cerr << "local minima!" << std::endl;
    return true;
  }
  return false;
}

// 選ばれた広告のスコアを最大化するような長方形を全探索
void findRect(vector<tuple<ll, ll, ll, ll>> &tup, vector<ll> &a, vector<ll> &b, vector<ll> &c, vector<ll> &d, vector<ll> &xvec, vector<ll> &yvec, vector<ll> &rvec, int n)
{
  for (int i = 0; i < n; i++)
  {
    int x = get<1>(tup[i]), y = get<2>(tup[i]);
    // ll r = get<0>(tup[i]);
    int idx = get<3>(tup[i]);
    a[idx] = x, b[idx] = y, c[idx] = x + 1, d[idx] = y + 1;
  }
}

// to do: 焼きなましの修正 使いまわせる計算は使いまわす
// 他の長方形との位置関係を考慮できるように
void simulatedAnnealing(vector<tuple<ll, ll, ll, ll>> &tup, vector<ll> &a, vector<ll> &b, vector<ll> &c, vector<ll> &d, vector<ll> &best_a, vector<ll> &best_b, vector<ll> &best_c, vector<ll> &best_d, int n, ll &bestScore)
{
  const double TIME_LIMIT = 4.8;
  auto startTime = chrono::system_clock::now();
  double start_temp = 5000, end_temp = 100;
  double time = 0.0;

  int idx = get_rand_range(0, n - 1);
  double mx1 = 22 * (n - 50) / 150 + 3, mx2 = 44 * (n - 50) / 150 + 6;
  // cerr << "mx1: " << mx1 << "  mx2: " << mx2 << endl;
  bool localMinima = false;
  ll nowScore = bestScore;
  deque<ll> oldScore;
  int shrinkCnt = 0;
  int shrinkMax = 4 * n; // 調整
  double maxPenalty = 0.0;

  while (time < TIME_LIMIT)
  {
    // 局所最適解に陥っている場合
    if (localMinima)
    {
      while (shrinkCnt < shrinkMax)
      {
        int areaIdx = get<3>(tup[idx]);
        int r = get<0>(tup[idx]);
        const double progressRatio = time / TIME_LIMIT;
        const double temp = start_temp + (end_temp - start_temp) * progressRatio;

        double deltaScore = 0.0;
        int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
        int cnt = 0;
        int x = get<1>(tup[idx]), y = get<2>(tup[idx]);
        double max_sm = 80. + (5. - 80.) / 200. * n;
        while (true)
        {
          cnt++;
          if (cnt == 100)
          {
            x1 = a[areaIdx], y1 = b[areaIdx], x2 = c[areaIdx], y2 = d[areaIdx];
            break;
          }

          int sm = max_sm + (1 - max_sm) * (time / TIME_LIMIT) + 0.001;
          x1 = get_rand_range(a[areaIdx], min(a[areaIdx] + sm, 10000LL));
          y1 = get_rand_range(b[areaIdx], min(b[areaIdx] + sm, 10000LL));
          x2 = get_rand_range(max(0LL, c[areaIdx] - sm), c[areaIdx]);
          y2 = get_rand_range(max(0LL, d[areaIdx] - sm), d[areaIdx]);

          // 各点は含まなければならない
          if (!((x1 <= x && x < x2) && (y1 <= y && y < y2)))
            continue;

          break;
        }
        maxPenalty = max(maxPenalty, calcScoreLocalMinima(r, x1, y1, x2, y2, a, b, c, d, time, TIME_LIMIT));
        deltaScore += calcScoreLocalMinima(r, x1, y1, x2, y2, a, b, c, d, time, TIME_LIMIT);
        // cerr << "deltaScore: " << deltaScore << endl;
        double prob = exp(deltaScore / temp);
        // cerr << "prob:  " << prob << endl;

        if (prob > get_rand_range_real(0.0, 1.0))
        {
          // cerr << "accept" << endl;
          // 更新
          double scoreDiff = standardCalcScore(r, x1, y1, x2, y2);
          scoreDiff -= standardCalcScore(r, a[areaIdx], b[areaIdx], c[areaIdx], d[areaIdx]);
          scoreDiff /= (double)n;
          scoreDiff *= 1e9;
          ll scoreDiffLL = scoreDiff;
          nowScore += scoreDiffLL;
          a[areaIdx] = x1, b[areaIdx] = y1, c[areaIdx] = x2, d[areaIdx] = y2;
        }
        else
        {
          // 棄却
          // cerr << "reject" << endl;
        }
        idx = get_rand_range(0, n - 1);
        shrinkCnt++;
      }
      localMinima = false;
      shrinkCnt = 0;
      oldScore.clear();
      time = (chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now() - startTime).count() * 1e-6);
      idx = get_rand_range(0, n - 1);
    }

    int areaIdx = get<3>(tup[idx]);
    int r = get<0>(tup[idx]);
    int s = (c[areaIdx] - a[areaIdx]) * (d[areaIdx] - b[areaIdx]);
    double areaAspect = double(s) / double(r);
    // 許容量を時間によって変化させる
    // 0.4から0.1くらいで遷移確率を変化
    if (areaAspect < 1.05 && areaAspect >= 0.95)
    {
      if (get_rand_range_real(0.0, 1.0) > 0.7 + (0.1 - 0.7) * (time / TIME_LIMIT))
      {
        idx = get_rand_range(0, n - 1);
        continue;
      }
    }

    const double progressRatio = time / TIME_LIMIT;
    const double temp = start_temp + (end_temp - start_temp) * progressRatio;

    // rからx1, y1, x2, y2の範囲を絞ったうえで近傍に動かす．
    double deltaScore = 0.0;
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    int cnt = 0;
    int x = get<1>(tup[idx]), y = get<2>(tup[idx]);
    while (true)
    {
      cnt++;
      if (cnt == 20)
      {
        x1 = a[areaIdx], y1 = b[areaIdx], x2 = c[areaIdx], y2 = d[areaIdx];
        break;
      }

      // nによって40とか20を変える
      // 200 -> 50と25 50 5と3で線形補完
      int lg = mx2 + (1 - mx2) * (time / TIME_LIMIT) + 0.001, sm = mx1 + (1 - mx1) * (time / TIME_LIMIT) + 0.001;
      lg = max(2, lg);
      // cerr << "lg: " << lg << "  sm: " << sm << endl;
      // 変動幅は時間によっていじるようにする？
      if (areaAspect > 1.0)
      {
        x1 = get_rand_range(max(0LL, a[areaIdx] - sm), min(a[areaIdx] + lg, 10000LL));
        y1 = get_rand_range(max(0LL, b[areaIdx] - sm), min(b[areaIdx] + lg, 10000LL));
        x2 = get_rand_range(max(0LL, c[areaIdx] - lg), min(c[areaIdx] + sm, 10000LL));
        y2 = get_rand_range(max(0LL, d[areaIdx] - lg), min(d[areaIdx] + sm, 10000LL));
      }
      else
      {
        x1 = get_rand_range(max(0LL, a[areaIdx] - lg), min(a[areaIdx] + sm, 10000LL));
        y1 = get_rand_range(max(0LL, b[areaIdx] - lg), min(b[areaIdx] + sm, 10000LL));
        x2 = get_rand_range(max(0LL, c[areaIdx] - sm), min(c[areaIdx] + lg, 10000LL));
        y2 = get_rand_range(max(0LL, d[areaIdx] - sm), min(d[areaIdx] + lg, 10000LL));
      }

      // 各点は含まなければならない
      if (!((x1 <= x && x < x2) && (y1 <= y && y < y2)))
        continue;

      bool intersect = false;
      // 全ての長方形と交差がないかをチェック
      // 仮にぶつかってしまった場合にぶつかったやつを小さくすることで無理やりよしとするのを確率的に組み込む
      for (int i = 0; i < n; i++)
      {
        if (i != areaIdx)
          intersect |= hasIntersect(x1, y1, x2, y2, a[i], b[i], c[i], d[i]);
        if (intersect)
          break;
      }
      if (!intersect)
        break;
    }
    deltaScore -= standardCalcScore(r, a[areaIdx], b[areaIdx], c[areaIdx], d[areaIdx]);
    deltaScore += standardCalcScore(r, x1, y1, x2, y2);
    deltaScore *= 10e5;
    // cerr << "deltaScore: " << deltaScore << endl;
    double prob = exp(deltaScore / temp);
    // cerr << "prob:  " << prob << endl;

    if (prob > get_rand_range_real(0.0, 1.0))
    {
      // 更新
      double scoreDiff = standardCalcScore(r, x1, y1, x2, y2);
      scoreDiff -= standardCalcScore(r, a[areaIdx], b[areaIdx], c[areaIdx], d[areaIdx]);
      scoreDiff /= (double)n;
      scoreDiff *= 1e9;
      ll scoreDiffLL = scoreDiff;
      nowScore += scoreDiffLL;
      a[areaIdx] = x1, b[areaIdx] = y1, c[areaIdx] = x2, d[areaIdx] = y2;
      if (bestScore < nowScore)
      {
        best_a = a, best_b = b, best_c = c, best_d = d; // ボトルネックかも
        bestScore = nowScore;
      }
      oldScore.push_front(nowScore);
      if ((int)oldScore.size() > 10)
        oldScore.pop_back();
      if (isLocalMinima(oldScore) && (int)oldScore.size() == 10)
        localMinima = true;
    }
    else
    {
      // 棄却
      // cerr << "reject" << endl;
    }
    time = (chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now() - startTime).count() * 1e-6);
    idx = get_rand_range(0, n - 1);
  }
  // cerr << "max penalty: " << maxPenalty << endl;
  return;
}

/*
void secondCheck(ll r, ll x, ll y, ll &a, ll &b, ll &c, ll &d, vector<ll> &avec, vector<ll> &bvec, vector<ll> &cvec, vector<ll> &dvec, vector<ll> &xvec, vector<ll> &yvec, vector<ll> &rvec)
{
}
*/

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<ll> x(n), y(n), r(n);
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i] >> r[i];

  vector<tuple<ll, ll, ll, ll>> tup(n);
  for (int i = 0; i < n; i++)
    tup[i] = make_tuple(r[i], x[i], y[i], i);

  // sort(tup.begin(), tup.end(), greater<tuple<ll, ll, ll, ll>>());
  vector<ll> a(n, -1), b(n, -1), c(n, -1), d(n, -1); // 答え格納

  findRect(tup, a, b, c, d, x, y, r, n);
  ll bestScore = calcAllScoreInit(r, a, b, c, d, n); // 初期化
  // 焼きなまし
  vector<ll> best_a(n, 0), best_b(n, 0), best_c(n, 0), best_d(n, 0);
  simulatedAnnealing(tup, a, b, c, d, best_a, best_b, best_c, best_d, n, bestScore);

  // デバッグ用スコア計算
  double allScore = 0;
  for (int i = 0; i < n; i++)
  {
    double score = standardCalcScore(r[i], best_a[i], best_b[i], best_c[i], best_d[i]);
    score /= double(n);
    allScore += score;
  }
  allScore *= 1e9;
  ll finalScore = ll(allScore);
  cerr << "final score: " << finalScore << endl;

  cerr << endl;
  for (int i = 0; i < n; i++)
  {
    cout << best_a[i] << " " << best_b[i] << " " << best_c[i] << " " << best_d[i] << endl;
  }
  return 0;
}
// 使用している場所管理
// 既にある長方形の中に含まれるかどうか
// 大前提としてある長方形は他の点を含んでいてはいけない
// tuple xでソート 上から並べられるだけ並べていく
