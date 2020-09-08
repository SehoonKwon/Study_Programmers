//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <utility>
//#include <tuple>
//using namespace std;
//
//int U, N;
//string str[100001];
//tuple<int, int, string> T[100001];
////tuple은 C++ 11에서 지원 그냥 C++하면 컴파일에러
//
//int main()
//{
//	cin >> U >> N;
//
//	int *U_Arr = new int[U+1]();
//	int x[100001] = { 0 };
//
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> str[i] >> x[i];
//		U_Arr[x[i]]++;
//	}
//
//	for (int i = 1; i <= N; i++)
//	{
//		T[i] = make_tuple(U_Arr[x[i]], x[i], str[i]);
//	}
//
//	sort(T, T + N + 1);
//
//	for (int i = 1; i <= N; i++)
//	{
//		if (get<0>(T[i]) != 0)
//		{
//			cout << get<2>(T[i]) << " " << get<1>(T[i]);
//			break;
//		}
//	}
//
//	delete[] U_Arr;
//
//	return 0;
//}