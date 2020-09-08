//#include <iostream>
//using namespace std;
//
//int Array[3] = { 1, 2, 3 };
//
//int index(int X)
//{
//	for (int i = 0; i < 3; i++)
//		if (X == Array[i]) return i;
//	return 0;
//}
//
//int main()
//{
//	int M;
//	cin >> M;
//
//	int X, Y;
//	for (int i = 0; i < M; i++)
//	{
//		cin >> X >> Y;
//		int index_X = index(X);
//		int index_Y = index(Y);
//		int tempX = Array[index_X];
//
//		Array[index_X] = Array[index_Y];
//		Array[index_Y] = tempX;
//
//	}
//
//	cout << Array[0];
//
//	return 0;
//}