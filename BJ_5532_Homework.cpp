//#include <iostream>
//using namespace std;
//
//int L, A, B, C, D;
//
//int main()
//{
//	cin >> L >> A >> B >> C >> D;
//
//	int Korean = A, Math = B, cnt = 0;
//	while (!(Korean == 0 && Math == 0))
//	{
//		if (Korean > 0)
//		{
//			Korean -= C;
//			if (Korean < 0) Korean = 0;
//		}
//
//		if (Math > 0)
//		{
//			Math -= D;
//			if (Math < 0) Math = 0;
//		}
//		cnt++;
//	}
//
//	cout << L - cnt;
//
//	return 0;
//}