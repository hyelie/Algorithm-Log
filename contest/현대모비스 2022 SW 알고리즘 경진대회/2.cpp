#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
int W, H;
int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};
int ar[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int ac[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int getDangerPoint(pii cur_point, vector<string> board)
{
	int point = 0;
	if (board[cur_point.first][cur_point.second] == 'P')
		point = -3;
	for (int i = 0; i < 8; i++)
	{
		pii np = {cur_point.first + ar[i], cur_point.second + ac[i]};
		if (0 <= np.first && np.first < W && 0 <= np.second && np.second < H && board[np.first][np.second] == 'P')
		{
			point++;
		}
	}
	return point;
}
struct cmp
{
	bool operator()(const vector<int> &a, const vector<int> &b) const
	{
		if (a[0] == b[0])
		{
			if (a[1] == b[1])
			{
				return a[2] > b[2];
			}
			else
				return a[1] > b[1];
		}
		else
			return a[0] > b[0];
	}
};
int main()
{
	cin >> W >> H;
	string input_str;
	vector<string> board(W);
	pii start_point;
	set<pii> pposition;
	for (int i = 0; i < W; i++)
	{
		cin >> board[i];
		for (int j = 0; j < board[i].length(); j++)
		{
			if (board[i][j] == 'S')
				start_point = {i, j};
			if (board[i][j] == 'P')
				pposition.insert({i, j});
		}
	}
	priority_queue<vector<int>, vector<vector<int>>, cmp> q; // [0] : 우선순위 작은 게 높음, [1] : row, [2] : col, [3] : 점수
	q.push({0, start_point.first, start_point.second, 0});
	vector<vector<bool>> visited(W, vector<bool>(H, false));
	visited[start_point.first][start_point.second] = true;
	while (!q.empty())
	{
		pii cur_point = {q.top()[1], q.top()[2]};
		int cur_danger = q.top()[3];
		q.pop();
		if (board[cur_point.first][cur_point.second] == 'E')
		{
			cur_danger = max(0, cur_danger);
			cout << cur_danger;
			break;
		} // 다음 점의 후보 찾기
		for (int i = 0; i < 4; i++)
		{
			pii next_point = {cur_point.first + dr[i], cur_point.second + dc[i]};
			if (0 <= next_point.first && next_point.first < W && 0 <= next_point.second && next_point.second < H && visited[next_point.first][next_point.second] == false)
			{
				visited[next_point.first][next_point.second] = true;
				char next_char = board[next_point.first][next_point.second];
				int priority;
				if (next_char == 'E')
				{
					priority = 0;
				}
				else if (next_char == 'P')
				{
					priority = 1;
				}
				else
				{
					priority = 2;
				}
				int next_danger_point = getDangerPoint(next_point, board);
				if (board[next_point.first][next_point.second] == 'E')
					next_danger_point = 0;
				q.push({priority, next_point.first, next_point.second, cur_danger + next_danger_point});
			}
		} // E, P, 일반 점 순으로 우선순위 정렬
	}
	return 0;
} /* s점 to e점 BFS E - P - 일반점 우선순위로. 우선순위 같으면 r값 작은 것이 우선, 같으면 c값 작은 것이 우선 위험점수 - 일반점 : 주변 3by3 내의 P점 개수만큼 위험 점수 증가 - P점 : 위 값의 -3만큼 증가. */