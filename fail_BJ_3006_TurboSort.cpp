//#include <iostream>
//using namespace std;
//
////세그먼트 트리로 푸는 문제인데 뭔지 모르겠음. 그냥 구현하면 시간초과
//
//#define endl "\n"
//
//int N;
//int Array[100001];
//int dest1, dest2;
//
//void input()
//{
//	cin >> N;
//	for (int i = 0; i < N; i++)
//		cin >> Array[i];
//}
//
//int turbosort(int x)
//{
//	int idx;
//	int cnt = 0;
//
//	//홀수
//	if ((x % 2) == 1)
//	{
//		for (int i = 0; i < N; i++)
//		{
//			if (Array[i] == dest1)
//			{
//				idx = i;
//				dest1++;
//				break;
//			}
//		}
//
//		for (int i = idx; i > 0; i--)
//		{
//			if (Array[i] < Array[i - 1])
//			{
//				swap(Array[i], Array[i - 1]);
//				cnt++;
//			}
//		}
//	}
//
//	//짝수
//	else
//	{
//		for (int i = 0; i < N; i++)
//		{
//			if (Array[i] == dest2)
//			{
//				idx = i;
//				dest2--;
//				break;
//			}
//		}
//
//		for (int i = idx; i < N - 1; i++)
//		{
//			if (Array[i] > Array[i + 1])
//			{
//				swap(Array[i], Array[i + 1]);
//				cnt++;
//			}
//		}
//	}
//
//	return cnt;
//}
//
//void solve()
//{
//	dest1 = 1;
//	dest2 = N;
//
//	for (int i = 1; i < N + 1; i++)
//	{
//		int cnt = turbosort(i);
//		cout << cnt << endl;
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