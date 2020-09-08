//#include <iostream>
//using namespace std;
//
//int N, K;
//int A[21] = { 0 };
//int B[20] = { 0 };
//
//
//int main()
//{
//	cin >> N >> K;
//
//	char c;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> A[i];
//		if (i != N - 1) cin >> c;
//	}
//
//	for (int i = 0; i < K; i++)
//	{
//		for(int j=0; j<N-1-i; j++)
//			B[j] = A[j + 1] - A[j];
//
//		for (int j = 0; j < N - 1 - i; j++)
//			A[j] = B[j];
//	}
//	
//	for (int i = 0; i < N - K; i++)
//	{
//		cout << A[i];
//		if (i != N - K - 1) cout << c;
//	}
//
//	return 0;
//}