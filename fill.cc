/*
	Ibrahim Numanagić
	Introduction to C++ and GDB
	February 04, 2021
*/
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("test.txt", "r", stdin);

  vector<string> lines;
  int r, c;
  cin >> r >> c; cin.ignore();
  for (string l; getline(cin, l);) {
    l.resize(c, ' ');
    lines.push_back(l);
  }

  auto visited = vector<vector<char>>(r, vector<char>(c, 0));
  auto fill = [&](int i, int j) -> pii {
    auto dir = vector<pii>{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int zombie = 0, chick = 0;
    queue<pii> q;
    q.push({i, j});
    visited[i][j] = 1;
    while (!q.empty()) {
      auto f = q.front();
      q.pop();

      if (lines[f.first][f.second] == 'z')
        zombie++;
      if (lines[f.first][f.second] == 'c')
        chick++;

      for (auto &d : dir) {
        int ni = f.first + d.first, nj = f.second + d.second;
        if (ni >= 0 && nj >= 0 && ni < r && nj < c && lines[ni][nj] != '#' &&
            !visited[ni][nj]) {
          q.push({ni, nj});
          visited[ni][nj] = 1;
        }
      }
    }
    return {zombie, chick};
  };

  int zombie = 0, chick = 0, rooms = 0, solved_rooms = 0;
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      if (lines[i][j] != '#' && !visited[i][j]) {
        auto zc = fill(i, j);
        rooms++;
        // printf("%d %d -- %d %d\n", i, j, zc.first, zc.second);
        if (zc.second >= zc.first * 2)
          chick += zc.second, solved_rooms++;
        else
          zombie += zc.first;
      }

  printf("rooms: %d\nzombie: %d, chick: %d\nsuccess: %.2lf%%\n", rooms, zombie,
         chick, 100.0 * solved_rooms / double(rooms));

  return 0;
}
