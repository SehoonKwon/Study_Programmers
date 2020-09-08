//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string str;
//	cin >> str;
//
//	int cnt = 0;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] == 'c' && (str[i + 1] == '=' || str[i + 1] == '-'))
//		{
//			cnt++;
//			continue;
//		}
//
//		else if (str[i] == 'd' && (str[i + 1] == '-' || (str[i + 1] == 'z' && str[i + 2] == '=')))
//		{
//			cnt++;
//			continue;
//		}
//		else if (i > 0 && str[i] == 'j' && (str[i - 1] == 'n' || str[i - 1] == 'l'))
//		{
//			cnt++;
//			continue;
//		}
//		else if (i > 0 && str[i] == '=' && (str[i - 1] == 's' || str[i - 1] == 'z'))
//		{
//			cnt++;
//			continue;
//		}
//	}
//
//	cout << str.size() - cnt;
//
//	return 0;
//}