//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int N;
//char Array[50][5][7] = { { {0}, } };
//int cnt = 0;
//int minimum = 1000;
//int index1 = 0;
//int index2 = 0;
//
//void Diff_cnt(int x)
//{
//	for (int i = x + 1; i < N; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			for (int k = 0; k < 7; k++)
//			{
//				if (Array[x][j][k] != Array[i][j][k])
//				{
//					cnt++;
//				}
//			}
//		}
//
//		if (minimum > cnt)
//		{
//			minimum = cnt;
//			index1 = x+1;
//			index2 = i+1;
//		}
//		cnt = 0;
//	}
//}
//
//int main()
//{
//	cin >> N;
//
//	//입력
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < 5; j++)
//			for (int k = 0; k < 7; k++)
//				cin >> Array[i][j][k];
//	}
//
//
//	//다른 칸 수 계산
//	for (int i = 0; i < N; i++)
//	{
//		Diff_cnt(i);
//	}
//
//	cout << index1 << " " << index2;
//
//	return 0;
//}