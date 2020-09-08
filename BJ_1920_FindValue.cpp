//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int N, M;
//
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//
//	cin >> N;
//
//	int *A = new int[N]();
//
//	for (int i = 0; i < N; i++)
//		cin >> A[i];
//
//	sort(A, A + N);
//
//	cin >> M;
//	int X = 0;
//	int isFind = 0;
//	for (int i = 0; i < M; i++)
//	{
//		cin >> X;
//		isFind = binary_search(A, A + N, X);
//		cout << isFind << "\n";
//	}
//
//	delete[] A;
//	A = NULL;
//
//	return 0;
//}