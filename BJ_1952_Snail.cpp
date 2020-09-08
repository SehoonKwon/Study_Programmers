//#include <iostream>
//using namespace std;
//
//int Array[101][101] = { 0, };
//int visit[101][101] = { 0, };
//int Direction = 4; // 1 2 3 4 -> 상 하 좌 우. 첫 시작은 우측방향
//int cnt = 0;
//
//int M, N;
//
//void Start_snail(int y, int x)
//{
//	visit[y][x] = true;
//	//위쪽 방향
//	if (Direction == 1)
//	{
//		if (visit[y - 1][x] == false && Array[y - 1][x] == 1 && (y - 1) > -1) Start_snail(y - 1, x);
//		else if (visit[y][x + 1] == false && (x + 1 < N))
//		{
//			Direction = 4;
//			cnt++;
//			Start_snail(y, x + 1);
//		}
//	}
//	//아래쪽 방향
//	if (Direction == 2)
//	{
//		if (visit[y + 1][x] == false && Array[y + 1][x] == 1 && (y + 1) < M) Start_snail(y + 1, x);
//		else if (visit[y][x - 1] == false && (x - 1 > -1))
//		{
//			Direction = 3;
//			cnt++;
//			Start_snail(y, x - 1);
//		}
//	}
//	//왼쪽 방향
//	if (Direction == 3)
//	{
//		if (visit[y][x - 1] == false && Array[y][x - 1] == 1 && (x - 1) > -1) Start_snail(y, x - 1);
//		else if (visit[y - 1][x] == false && (y - 1 > -1))
//		{
//			Direction = 1;
//			cnt++;
//			Start_snail(y - 1, x);
//		}
//	}
//	//우쪽 방향
//	if (Direction == 4)
//	{
//		if (visit[y][x + 1] == false && Array[y][x + 1] == 1 && (x + 1) < N) Start_snail(y, x + 1);
//		else if (visit[y + 1][x] == false && (y + 1 < M))
//		{
//			Direction = 2;
//			cnt++;
//			Start_snail(y + 1, x);
//		}
//	}
//}
//
//int main()
//{
//	cin >> M >> N;
//
//	for (int i = 0; i < M; i++)
//		for (int j = 0; j < N; j++)
//			Array[i][j] = 1;
//
//	Start_snail(0, 0);
//
//	cout << cnt;
//
//	return 0;
//}