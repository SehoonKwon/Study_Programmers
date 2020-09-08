//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//#define endl "\n"
//
////하나씩 비교하지말고 전체 틀을 만들어서 틀을 이용하기
//
//char Array[51][51];
//int N, M;
//int MIN = 99999;
//
//struct comp
//{
//	char Wcase[8][8] = { {'W','B','W','B', 'W','B', 'W','B'},{ 'B','W','B','W','B', 'W','B', 'W' },
//	{ 'W','B','W','B','W','B', 'W','B' },	{ 'B','W','B', 'W','B', 'W','B', 'W' },
//	{ 'W','B','W','B', 'W','B', 'W','B' },	{ 'B','W','B', 'W','B', 'W','B', 'W' },
//	{ 'W','B','W','B', 'W','B', 'W','B' },	{ 'B','W','B', 'W','B', 'W','B', 'W' } };
//
//	char Bcase[8][8] = { { 'B','W','B', 'W','B', 'W','B', 'W' }, { 'W','B','W','B', 'W','B', 'W','B' },	
//	{ 'B','W','B', 'W','B', 'W','B', 'W' },	{ 'W','B','W','B', 'W','B', 'W','B' },
//	{ 'B','W','B', 'W','B', 'W','B', 'W' }, { 'W','B','W','B', 'W','B', 'W','B' },
//	{ 'B','W','B', 'W','B', 'W','B', 'W' },{ 'W','B','W','B', 'W','B', 'W','B' } };
//};
//
//comp c;
//
//void input()
//{
//	cin >> N >> M;
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//			cin >> Array[i][j];
//}
//
//int counting(int x, int y)
//{
//	int cnt1 = 0, cnt2 = 0;
//	
//	for (int i = 0; i < 8; i++)
//		for (int j = 0; j < 8; j++)
//			if (Array[i + y][j + x] != c.Wcase[i][j]) cnt1++;
//
//	for (int i = 0; i < 8; i++)
//		for (int j = 0; j < 8; j++)
//			if (Array[i + y][j + x] != c.Bcase[i][j]) cnt2++;
//
//	return min(cnt1, cnt2);
//}
//
//void solve()
//{
//	for (int i = 0; i + 7 < N; i++)
//	{
//		for (int j = 0; j + 7 < M; j++)
//		{
//			MIN = min(MIN, counting(j, i));
//		}
//	}
//
//	cout << MIN << endl;
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