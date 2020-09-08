//#include <iostream>
//#include <string>
//#include <deque>
//using namespace std;
//
////양 옆에 아무 문자나 붙일 수 있다 -> 차이가 항상 0 -> 따라서 차이의 최솟값은 초기 상태에서 가장 작은 최솟값
//
//string A, B;
//
//int main()
//{
//	cin >> A >> B;
//	
//	int N = B.size() - A.size();
//	int AN = A.size();
//
//	int min = 99999;
//	int cnt = 0;
//
//	for (int j = 0; j < N + 1; j++)
//	{
//		cnt = 0;
//		for (int i = 0; i < AN; i++)
//		{
//			if (A[i] != B[j+i]) cnt++;
//		}
//
//		if (min > cnt) min = cnt;
//	}
//
//	cout << min;
//
//	return 0;
//}