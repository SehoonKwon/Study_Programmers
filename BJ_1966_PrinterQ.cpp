//#include <iostream>
//#include <string.h>
//#include <queue>
//using namespace std;
//
//int T, N, M;
//int Array[101] = { 0 };
//int max_index = 0;
//
//struct point
//{
//	int value;
//	int mark;
//};
//
//queue<point> q;
//
//int my_max()
//{
//	int maxNum = 0;
//
//	for (int i = 0; i < N; i++)
//	{
//		if (maxNum < Array[i])
//		{
//			maxNum = Array[i];
//			max_index = i;
//		}
//	}
//
//	return maxNum;
//}
//
//int main()
//{
//	cin >> T;
//	
//	for (int num = 0; num < T; num++)
//	{
//		while (!q.empty()) q.pop();
//		memset(Array, 0, sizeof(Array));
//
//		cin >> N >> M;
//
//		for (int i = 0; i < N; i++)
//		{
//			cin >> Array[i];
//			if (i == M)
//				q.push({ Array[i], 1 });
//			else q.push({ Array[i],0 });
//		}
//
//		int cnt = 1;
//
//		int maxNum = my_max();
//
//		while (!q.empty())
//		{
//
//			if (q.front().value == maxNum)
//			{
//				if (q.front().mark == 1)
//				{
//					cout << cnt << endl;
//				}
//				q.pop();
//				Array[max_index] = 0;
//				cnt++;
//				maxNum = my_max();
//			}
//
//			else
//			{
//				int tempV = q.front().value;
//				int tempM = q.front().mark;
//				q.pop();
//				q.push({ tempV, tempM });
//			}
//		}
//		
//	}
//
//	return 0;
//}