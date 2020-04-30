#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  int hours, minutes, seconds;
  hours = N / 3600;
  minutes = (N - hours * 3600) / 60;
  seconds = N - (hours * 3600 + minutes * 60);
  cout << setfill('0') << right << setw(2) << hours << ":" << setfill('0') << right << setw(2) << minutes << ":" << setfill('0') << right << setw(2) << seconds << endl;
  return 0;
}
