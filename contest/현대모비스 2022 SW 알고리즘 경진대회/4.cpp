#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> board(N, vector<int>(M));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}
	vector<vector<pii>> sections;
	vector<vector<bool>> visited(N, vector<bool>(M, false));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visited[i][j] || board[i][j] == 1)
				continue;
			vector<pii> section;
			queue<pii> q;
			q.push({i, j});
			visited[i][j] = true;
			while (!q.empty())
			{
				pii cur_p = q.front();
				q.pop();
				section.push_back(cur_p);
				for (int i = 0; i < 4; i++)
				{
					pii next_p = {cur_p.first + dr[i], cur_p.second + dc[i]};
					if (0 <= next_p.first && next_p.first < N && 0 <= next_p.second && next_p.second < M && visited[next_p.first][next_p.second] == false && board[next_p.first][next_p.second] != 1)
					{
						visited[next_p.first][next_p.second] = true;
						q.push(next_p);
					}
				}
			}
			sections.push_back(section);
		}
	}
	int answer = -1;
	for (vector<pii> section : sections)
	{
		int cur_section_point = 0;
		for (pii p : section)
		{
			cur_section_point += board[p.first][p.second] == 2 ? -2 : 1;
		}
		answer = max(answer, cur_section_point);
	}
	cout << max(answer, 0);
	return 0;
}