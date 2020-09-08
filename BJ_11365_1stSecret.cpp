//#include <iostream>
//#include <string>
//#include <cstring>
//using namespace std;
//
//int main()
//{
//	string str;
//
//	for (;;)
//	{
//		//cin >> str; //공백때문에 cin 안되고 getline
//		getline(cin, str);
//		if (str == "END") break;
//
//		for (int i = str.size()-1; i > -1; i--) //마지막 엔터가 str에 들어가있어서 str.size() 시작하면 한 칸 띄고 시작 됌. 따라서 하나 더 빼주자
//			cout << str[i];
//		cout << "\n";
//	}
//
//	return 0;
//}