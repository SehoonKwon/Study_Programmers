//#include <iostream>
//#include <queue>
//using namespace std;
//
////구현법은 쉬우나 card1문제처럼 벡터로 구현하면 시간초과.
////이건 인덱스를 지우면 앞으로 다 땡겨야 되므로 O(N)이 추가적으로 걸려서 문제인가봄
////따라서 큐를 이용해서 바로바로 밀어주면 해결 가능. FIFO형태가 필요하면 큐를 이용하자
//
//int N;
//queue<int> q;
//
//int main()
//{
//	cin >> N;
//
//	for (int i = 1; i < N+1; i++)
//		q.push(i);
//
//	while ((q.size() != 1))
//	{
//		q.pop();
//		int temp;
//		temp = q.front();
//		q.pop();
//		q.push(temp);
//	}
//
//	cout << q.front();
//
//	return 0;
//}