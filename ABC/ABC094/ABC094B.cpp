#include <bits/stdc++.h>
using namespace std;

bool vector_finder(std::vector<int> vec, int number)
{
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance(vec.begin(), itr);
  if (index != vec.size())
  { // 発見できたとき
    return true;
  }
  else
  { // 発見できなかったとき
    return false;
  }
}

int main()
{
  int N, M, X;
  cin >> N >> M >> X;
  vector<int> A(M);
  for (auto &a : A)
  {
    cin >> a;
  }
  int left = 0;
  int right = 0;
  int now = X;
  for (int i = 1; i <= N - X; i++)
  {
    now++;
    if (vector_finder(A, now))
      right++;
  }
  now = X;
  for (int i = 1; i <= X; i++)
  {
    now--;
    if (vector_finder(A, now))
      left++;
  }
  int ans = min(left, right);
  cout << ans << endl;
}
