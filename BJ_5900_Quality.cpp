//#include <iostream>	
//using namespace std;
//
//int Quality[301] = { 0 };
//int a, b, c;
//int R[1001] = { 0 };
//int X[1001] = { 0 };
//int Y[1001] = { 0 };
//int Z[1001] = { 0 };
//
//int main()
//{
//	cin >> a >> b >> c;
//	
//	for (int i = 1; i < a + b + c + 1; i++)
//		Quality[i] = -1;
//
//	int N;
//	cin >> N;
//
//	int x, y, z, r;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> x >> y >> z >> r;
//		X[i] = x;
//		Y[i] = y;
//		Z[i] = z;
//		R[i] = r;
//
//		if (r == 1)
//		{
//			Quality[x] = 1;
//			Quality[y] = 1;
//			Quality[z] = 1;
//		}
//	}
//
//	//모든 입력이 끝난 뒤 다시 체크
//	for (int i = 0; i < N; i++)
//	{
//		if (R[i] == 1)
//		{
//			continue;
//		}
//
//		else
//		{
//			//두개 정상인경우
//			if (Quality[X[i]] == 1 && Quality[Y[i]] == 1)
//			{
//				Quality[Z[i]] = 0;
//				continue;
//			}
//			else if (Quality[X[i]] == 1 && Quality[Z[i]] == 1)
//			{
//				Quality[Y[i]] = 0;
//				continue;
//			}
//			else if (Quality[Y[i]] == 1 && Quality[Z[i]] == 1)
//			{
//				Quality[X[i]] = 0;
//				continue;
//			}
//
//			//한개 정상인경우
//			if (Quality[X[i]] == 1)
//			{
//				if (Quality[Y[i]] == -1) Quality[Y[i]] = 2;
//				if (Quality[Z[i]] == -1) Quality[Z[i]] = 2;
//				continue;
//			}
//			else if (Quality[Y[i]] == 1)
//			{
//				if (Quality[X[i]] == -1) Quality[X[i]] = 2;
//				if (Quality[Z[i]] == -1) Quality[Z[i]] = 2;
//				continue;
//			}
//			else if (Quality[Z[i]] == 1)
//			{
//				if (Quality[Y[i]] == -1) Quality[Y[i]] = 2;
//				if (Quality[X[i]] == -1) Quality[X[i]] = 2;
//				continue;
//			}
//		}
//	}
//
//	for (int i = 1; i < a + b + c + 1; i++)
//	{
//		if (Quality[i] == -1) Quality[i] = 2;
//		cout << Quality[i] << endl;
//	}
//	return 0;
//}