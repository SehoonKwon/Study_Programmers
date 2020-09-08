//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector<int> v;
//int N;
//
//int main()
//{
//	cin >> N;
//
//	for (int i = 0; i < N; i++)
//		v.push_back(i + 1);
//
//	vector<int>::iterator iter;
//
//	while (v.size() != 1)
//	{
//		iter = v.begin();
//		cout << v.front() << " ";
//		v.erase(iter);
//
//		int temp = v.front();
//		v.push_back(temp);
//		iter = v.begin();
//		v.erase(iter);
//	}
//
//	cout << v.front();
//
//	return 0;
//}