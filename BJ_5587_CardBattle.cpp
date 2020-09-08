//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int N;
//int Card[201] = { 0 };
//
//int main()
//{
//	cin >> N;
//
//	int *S = new int[N];
//	int *K = new int[N];
//
//	for (int i = 1; i < 2 * N + 1; i++)
//	{
//		Card[i] = i;
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		cin >> S[i];
//		Card[S[i]] = 0;
//	}
//
//	int K_cnt = 0;
//	for (int i = 1; i < 2 * N + 1; i++)
//	{
//		if (Card[i] != 0)
//		{
//			K[K_cnt] = Card[i];
//			K_cnt++;
//		}
//		if (K_cnt == N) break;
//	}
//
//	sort(S, S + N);
//	sort(K, K + N);
//
//	//Game Start
//	int table_card = 0;
//	int S_cnt = N;
//
//	//첫 시작은 상근이
//	table_card = S[0];
//	S[0] = 0;
//	S_cnt--;
//	int flag = 1; //flag 1 근상이 차례
//
//	//상근이 카드 수 확인
//	if (S_cnt == 0)
//	{
//		cout << K_cnt << endl << S_cnt;
//		delete[] S;
//		delete[] K;
//		return 0;
//	}
//
//	while (1)
//	{
//		if (flag == 1)
//		{		//2번째 근상이 카드 제출
//			for (int i = 0; i < N; i++)
//			{
//				if (K[i] > table_card)
//				{
//					table_card = K[i];
//					K[i] = 0;
//					K_cnt--;
//					flag = 0; //상근이 차례
//					break;
//				}
//
//				//근상이 차례인데 낼 카드가 없는경우
//				if (i == N - 1 && flag == 1)
//				{
//					flag = 0; //상근이 차례로
//					table_card = 0;
//				}
//			}
//
//			//근상이 카드 수 확인
//			if (K_cnt == 0)
//			{
//				cout << K_cnt << endl << S_cnt;
//				delete[] S;
//				delete[] K;
//				return 0;
//			}
//		}
//
//		else //3번째 다시 상근이 차례
//		{
//			for (int i = 0; i < N; i++)
//			{
//				if (S[i] > table_card)
//				{
//					table_card = S[i];
//					S[i] = 0;
//					S_cnt--;
//					flag = 1; //근상이 차례
//					break;
//				}
//
//				//상근이가 낼 카드가 없는경우
//				if (i == N - 1 && flag == 0)
//				{
//					flag = 1; // 상근이 차례로 턴 넘김
//					table_card = 0;
//				}
//			}
//
//			//상근이 카드 수 확인
//			if (S_cnt == 0)
//			{
//				cout << K_cnt << endl << S_cnt;
//				delete[] S;
//				delete[] K;
//				return 0;
//			}
//		}
//	}
//	return 0;
//}