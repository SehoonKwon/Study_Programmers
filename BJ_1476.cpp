//#include <iostream>
//using namespace std;
//
//int E, S, M;
//int cnt_E = 1, cnt_S = 1, cnt_M = 1;
//
//void Calcul()
//{
//	cnt_E++;
//	if (cnt_E == 16) cnt_E = 1;
//
//	cnt_S++;
//	if (cnt_S == 29) cnt_S = 1;
//
//	cnt_M++;
//	if (cnt_M == 20) cnt_M = 1;
//}
//
//int main()
//{
//	cin >> E >> S >> M;
//
//	int cnt = 1;
//	for (;;)
//	{
//		if (cnt_E == E && cnt_S == S && cnt_M == M) break;
//		else
//		{
//			cnt++;
//			Calcul();
//		}
//	}
//	
//	cout << cnt;
//
//	return 0;
//}