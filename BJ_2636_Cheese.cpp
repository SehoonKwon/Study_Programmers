//#include <iostream>
//#include <cstring>
//#include <queue>
//#include <vector>
//using namespace std;
//
////2638번 문제와는 다르게 한 칸이라도 접촉시 제거
//
//int N, M;
//int Array[101][101];
//int visit[101][101];
//int dx[] = { 0,0,-1,1 };
//int dy[] = { 1,-1,0,0 };
//int time = 0;
//int cnt = 0, r_cnt = 0;
//
//struct point
//{
//	int x, y;
//};
//
//void input()
//{
//	cin >> N >> M;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			cin >> Array[i][j];
//			if (Array[i][j] == 1) cnt++;
//		}
//	}
//}
//
//bool Finish()
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//			if (Array[i][j] == 1) return false;
//	}
//
//	return true;
//}
//
////치즈 내부 체크 => 단지붙이기 생각! 대신 바깥 공기인 곳을 묶어버린다고 생각하자. 내부공기는 치즈에 둘러쌓여서 접근못함
//void in_check()
//{
//	visit[0][0] = true;
//	queue<point> q;
//	q.push({ 0, 0 });
//
//	while (!q.empty())
//	{
//		int X = q.front().x;
//		int Y = q.front().y;
//		q.pop();
//
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = X + dx[i];
//			int ny = Y + dy[i];
//
//			if (nx > -1 && nx < M && ny > -1 && ny < N)
//			{
//				if (visit[ny][nx] == false)
//				{
//					if (Array[ny][nx] == 0)
//					{
//						visit[ny][nx] = true;
//						Array[ny][nx] = -1;
//						q.push({ nx, ny });
//					}
//
//					else if (Array[ny][nx] > 0)
//					{
//						Array[ny][nx]++;
//					}
//				}
//			}
//		}
//	}
//
//	return;
//}
//
////마지막 바로 전 치즈 개수를 위해 void -> int 형으로 바꿔줌
//int remove()
//{
//	int kill = 0;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			if (Array[i][j] > 1)
//			{
//				Array[i][j] = -1;
//				r_cnt++;
//				kill++;
//			}
//		}
//	}
//
//	return kill;
//}
//
//void recovery()
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			if (Array[i][j] == -1) Array[i][j] = 0;
////			else if (Array[i][j] > 0) Array[i][j] = 1;
//		}
//	}
//}
//
//void solve()
//{
//	// 종료조건 체크 -> 치즈 외부체크 + 접촉면 체크 -> 접촉면 제거 -> 반복
//	
//	int kill = 0;
//	while (1)
//	{
//		if (r_cnt == cnt)
//		{
//			cout << time << endl;
//			cout << kill << endl;
//			return;
//		}
//
//		memset(visit, 0, sizeof(visit));
//		in_check();
//		kill = remove();
//		recovery();
//		time++;
//	}
//}
//
//int main()
//{
//	std::ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	input();
//
//	solve();
//
//	return 0;
//}