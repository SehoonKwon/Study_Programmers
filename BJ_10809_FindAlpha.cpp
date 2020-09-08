//#include <iostream>
//#include <string>
//using namespace std;
//
//char Alphabet[26] = { 0 };
//
//int main()
//{
//	for (int i = 0; i < 26; i++)
//		Alphabet[i] = 'a' + i;
//
//	string str;
//	cin >> str;
//
//	int flag = 0;
//	for (int i = 0; i < 26; i++)
//	{
//		flag = 0;
//		for (int j = 0; j < str.size(); j++)
//		{
//			if (Alphabet[i] == str[j])
//			{
//				cout << j << " ";
//				flag = 1;
//				Alphabet[i] = NULL;
//				continue;
//			}
//			if (j == str.size()- 1 && flag == 0) cout << "-1" << " ";
//		}
//	}
//
//	return 0;
//}