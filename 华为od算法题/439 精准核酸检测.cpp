///*
//��Ŀ������
//Ϊ�˴ﵽ�¹����龫׼���ص���Ҫ��Ϊ�˱���ȫԱ������������˷ѣ���Ҫ��׼Ȧ�����ܱ���Ⱦ����Ⱥ��
//���ڸ��ݴ�Ⱦ�������Լ������ݷ������õ���ÿ����֮����ʱ�䡢�ռ����Ƿ���ڹ켣�Ľ��档
//���ڸ���һ��ȷ����Ա��ţ�X1, X2, X3, ....Xn��, �������˵��У��ҳ���Щ����Ҫ���к����⣬�����Ҫ���к��������������ע�⣺ȷ�ﲡ��������Ҫ���������⣩
//��Ҫ���к�������ˣ��ǲ������������ϵ�������Ա�����п���ͨ��ȷ�ﲡ�����ܴ������������ˡ�
//���磺A��ȷ�ﲡ����A��B�нӴ���B��C�нӴ���C��D�нӴ���D��E�нӴ�����ôB\C\D\E������Ҫ���к�������ˡ�
//
//����������
//��һ��Ϊ������N
//�ڶ���Ϊȷ�ﲡ����Ա��ţ�ȷ�ﲡ����Ա���� < N�����ö��ŷָ�
//�����п�ʼ��Ϊһ��N* N�ľ��󣬱�ʾÿ����Ա֮���Ƿ��нӴ���0��ʾû�нӴ���1��ʾ�нӴ���
//
//���������
//��������Ҫ�������������
//
//����˵����
//��Ա��Ŵ�0��ʼ
//0 < N < 100
//
//ʾ��1
//���룺
//5
//1,2
//1,1,0,1,0
//1,1,0,0,0
//0,0,1,0,1
//1,0,0,1,0
//0,0,1,0,1
//
//�����
//3
//
//˵����
//���Ϊ1��2�ŵ���Ա��Ϊȷ�ﲡ����
//1����0���нӴ���0����3���нӴ���
//2����4���нӴ���
//���ԣ���Ҫ�������������0�š�3�š�4�ţ��ܼ�3����Ҫ���к����⡣
//
//˼·���Ӳ��˳����������ҵ����нӴ�����
//*/
//#include<iostream>
//#include<vector>
//#include<string>
//#include<sstream>
//
//using namespace std;
//
////struct Edge
////{
////	int x, y, w; // ���� x,y ȨֵΪw
////
////};
//
//class unionFind
//{
//private:
//	vector<int> root;
//	vector<int> rank;
//
//public:
//	unionFind(int n) : root(n), rank(n, 0)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			root[i] = i;
//		}
//	}
//
//	int find(int x)
//	{
//		if (x != root[x])
//		{
//			root[x] = find(root[x]);
//		}
//		return root[x];
//	}
//
//	void merge(int x, int y)
//	{
//		int rx = find(x);
//		int ry = find(y);
//		if (rx != ry)
//		{
//			if (rank[rx] < rank[ry])
//			{
//				swap(rx, ry);
//			}
//			root[ry] = rx;
//			rank[rx]++;
//		}
//	}
//
//	bool conneted(int x, int y)
//	{
//		return find(x) == find(y);
//	}
//};
//
//int main()
//{
//	// ����
//	int n;	// ������N
//	cin >> n;
//	cin.get();
//		
//	// ��Ҫ�����ݽṹ
//	vector<int> sicks;
//	unionFind uf(n);
//
//	string str;	// ����ȷ�ﲡ����Ա���
//	getline(cin, str);
//	istringstream iss(str);
//	string tmp;
//	while (getline(iss, tmp, ','))
//	{
//		sicks.push_back(stoi(tmp));
//	}
//	// �����в���merge
//	for (int i = 1; i < sicks.size(); i++)
//	{
//		uf.merge(sicks[i], sicks[i - 1]);
//	}
//
//	// ����������
//	for (int i = 0; i < n; i++)
//	{
//		getline(cin, str);
//		istringstream iss(str);
//		for (int j = 0; j < n; j++)
//		{
//			getline(iss, tmp, ',');
//			if (tmp[0] == '1')
//			{
//				uf.merge(i, j);
//			}
//		}
//	}
//
//	// ��ѯ������
//	int res = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (uf.conneted(i, sicks[0]))
//		{
//			res++;
//		}
//	}
//	cout << res - sicks.size() << endl;
//
//}