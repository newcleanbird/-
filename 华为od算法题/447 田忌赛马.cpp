///*
//447 �������
//��Ŀ������
//��������ֻ�������ֵ�����a��b���������� a �������ֵ�˳��ʹ�þ����ܶ�� a[i] > b[i]������  a�� b �е����ָ�����ͬ��
//������п��Դﵽ���Ž���� a ���������
//
//����������
//����ĵ�һ�������� a �е����֣�����ֻ�������֣�ÿ��������֮�����һ���ո�a �����С������ 10
//����ĵڶ��������� b �е����֣�����ֻ�������֣�ÿ��������֮�����һ���ո�b�����С������ 10
//
//���������
//������п��Դﵽ���Ž���� a ��������
//
//ʾ��1��
//���룺
//11 8 20
//10 13 7
//
//�����
//˵����
//���Ž��ֻ��һ���� a =[11,20,8]������� 1
//
//ʾ��2��
//���룺
//11 12 20
//10 13 7
//
//�����
//˵���������� a ��������п��Դﵽ���Ž�� [12,20,11]��11,20,12] ������� 2��
//
//˼·��ȫ���У�C++��STL��ʵ�ʵĺ�����next_permutation()
//*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int count_win(vector<int>& a, vector<int>& b)
//{
//	int count = 0;
//	for (int i = 0; i < a.size(); i++)
//	{
//		if (a[i] > b[i])
//		{
//			count++;
//		}
//	}
//	return count;
//}
//
//int main()
//{
//	// ����
//	vector<int> a, b;
//	int tmp;
//	while (cin >> tmp)
//	{
//		a.push_back(tmp);
//		if (cin.get() == '\n') break;
//	}
//	while (cin >> tmp)
//	{
//		b.push_back(tmp);
//		if (cin.get() == '\n') break;
//	}
//
//	// ����
//	int max_count = 0;
//	int res = 0;
//	sort(a.begin(), a.end());
//	do {
//		int count = count_win(a, b);
//		if (count > max_count)
//		{
//			max_count = count;
//			res = 1;
//		}
//		else if (count == max_count)
//		{
//			res++;
//		}
//	} while (next_permutation(a.begin(), a.end()));
//
//	cout << res;
//}