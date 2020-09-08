//#include <iostream>
//using namespace std;
//
//int N, M;
//char c;
//
//int GCD(int x, int y)
//{
//	while (y != 0)
//	{
//		int r = x % y;
//		x = y;
//		y = r;
//	}
//
//	return x;
//}
//
//int main()
//{
//	cin >> N >> c >> M;
//
//	int ANS = GCD(N, M);
//
//	int NN = N / ANS;
//	int MM = M / ANS;
//
//	cout << NN << c << MM;
//
//	return 0;
//}