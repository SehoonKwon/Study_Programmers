//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <functional>
//using namespace std;
//
////벡터 STL 연습하기 좋은 문제
//
//int X;
//vector<int> v;
//
//int Sum()
//{
//	int S = 0;
//	for (int i = 0; i < v.size(); i++)
//	{
//		S += v[i];
//	}
//
//	return S;
//}
//
//int check()
//{
//	int cnt = 0, S = 0;
//	
//	for (int i = 0; i < v.size(); i++)
//	{
//		if( (S+v[i]) <= X)
//		S += v[i];
//		cnt++;
//		if (S == X) return cnt;
//	}
//
//	return -1;
//}
//
//int main()
//{
//	cin >> X;
//	v.push_back(64);
//
//	int Ans;
//
//	for (int i = 0; i < 10; i++)
//	{
//		int S = Sum();
//		sort(v.begin(), v.end(), greater<int>());
//		if (S > X)
//		{
//			int temp = v.back();
//			v.pop_back();
//			int temp2 = temp / 2;
//			v.push_back(temp2);
//
//			int SX = Sum();
//			if (SX < X) v.push_back(temp2);
//		}
//
//		sort(v.begin(), v.end());
//
//		Ans = check();
//	}
//
//	cout << Ans;
//
//	return 0;
//}