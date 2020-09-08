//#include <iostream>
//using namespace std;
//
//int A, B, C;
//int Array[3] = { 0 };
//int cnt[4] = { 0 };
//
//int main()
//{
//	cin >> A >> B >> C;
//
//	int x, y;
//	int Truck[3][2];
//
//	for (int i = 0; i < 3; i++)
//	{
//		cin >> x >> y;
//		Truck[i][0] = x;
//		Truck[i][1] = y;
//	}
//
//	for (int i = 1; i < 101; i++)
//	{
//		int T_Size = 0;
//		cnt[0] = cnt[0] + 1;
//		if (Truck[0][0] == cnt[0]) Array[0] = 1;
//		if (Truck[1][0] == cnt[0]) Array[1] = 1;
//		if (Truck[2][0] == cnt[0]) Array[2] = 1;
//
//		if (Truck[0][1] == cnt[0]) Array[0] = 0;
//		if (Truck[1][1] == cnt[0]) Array[1] = 0;
//		if (Truck[2][1] == cnt[0]) Array[2] = 0;
//
//		for (int j = 0; j < 3; j++)
//		{
//			if (Array[j] == 1) T_Size++;
//		}
//
//		if (T_Size == 1) cnt[1]++;
//		else if (T_Size == 2) cnt[2]++;
//		else if (T_Size == 3) cnt[3]++;
//	}
//
//	int S = 0;
//
//	S = A*cnt[1] + B*cnt[2]*2 + C*cnt[3]*3;
//	
//	cout << S;
//
//	return 0;
//}