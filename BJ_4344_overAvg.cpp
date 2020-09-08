//#include <iostream>
//using namespace std;
//
//int T;
//double N;
//int Student[1001] = { 0 };
//
//int main()
//{
//	cin >> T;
//	for (int num = 0; num < T; num++)
//	{
//		cin >> N;
//		for (int i = 0; i < N; i++)
//		{
//			cin >> Student[i];
//		}
//
//		int Sum = 0;
//		for (int i = 0; i < N; i++)
//			Sum += Student[i];
//
//		int Avg = Sum / N;
//		double cnt = 0;
//
//		for (int i = 0; i < N; i++)
//		{
//			if (Avg < Student[i]) cnt++;
//		}
//
//		double ans = 0;
//		ans = (cnt / N) * 100;
//
//		cout << fixed;
//		cout.precision(3);
//		cout << ans << "%"<<"\n";
//	}
//
//	return 0;
//}