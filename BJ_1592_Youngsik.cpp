//#include <iostream>
//using namespace std;
//
//int N, M, L;
//int cnt[1001] = { 0 };
//int Totalcnt = 0;
//
//void Start(int x)
//{
//	cnt[x] = cnt[x] + 1;
//	if (cnt[x] == M)
//	{
//		cout << Totalcnt;
//		return;
//	}
//
//	//던지기 전에 종료해야 수가 알맞은 논리
//	Totalcnt++;
//
//	//홀수면
//	if ((cnt[x] % 2) == 1)
//	{
//		if (x + L <= N)
//			Start(x + L);
//		else
//			Start(x + L - N);
//	}
//	//짝수면
//	else
//	{
//		if (x - L > 0)
//			Start(x - L);
//		else
//			Start(N + x - L);
//	}
//}
//
//
//int main()
//{
//	cin >> N >> M >> L;
//
//	Start(1);
//
//	return 0;
//}