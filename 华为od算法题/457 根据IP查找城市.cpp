///*
//457������IP���ҳ���
//��Ŀ������
//ĳҵ����Ҫ�����ն˵�IP��ַ��ȡ���ն˹����ĳ��У����Ը��ݹ�����IP��ַ����Ϣ��ѯ�������С���ַ�ظ�ʽ���³�����=��ʼIP,����IP����ʼ�ͽ�����ַ����Ӣ�Ķ��ŷָ��������ַ�β���Ӣ�ķֺŷָ���
//����City1=1.1.1.1,1.1.1.2;City1=1.1.1.11,1.1.1.16;City2=3.3.3.3,4.4.4.4;City3=2.2.2.2,6.6.6.6��
//һ�����п����ж��IP�Σ�����City1��2��IP�Ρ����м�Ҳ���ܴ��ڰ�����ϵ����City3��IP�η�Χ����City2��IP�η�Χ������Ҫ���������IP�б��������ƥ��ĳ����б�
//ע�����ƥ�伴��������ѯIP�ҳ�����С��IP�Σ�����������3.4.4.4���ƥ����City2=3.3.3.3,4.4.4.4��5.5.5.5�����ƥ����City3=2.2.2.2,6.6.6.6��
//
//����������
//���빲2�С�
//��һ��Ϊ���е�IP���б����IP�β���Ӣ�ķֺ�';'�ָ���IP���б���󲻳���500000����������ֻ����Ӣ����ĸ�����ֺ��»��ߣ���಻����100000����IP�ΰ�����ϵ�����ж�㣬��������100�㡣
//�ڶ���Ϊ��ѯ��IP�б����IP����Ӣ�Ķ��š�,���ָ�����಻����10000����
//
//���������
//���ƥ��ĳ������б�����Ӣ�Ķ��š�,���ָ��������б���Ӧ�ø���ѯ��IP�б���һ�¡�
//����˵����
//1�������Ƿ�鵽ƥ��������Ҫ����ָ�������������������IP�б�ΪIPa,IPb����IP��δ��ƥ����У���ʱ���Ϊ��,������ֻ��һ�����ŷָ������������о�Ϊ�գ�
//2�����Լٶ������е�����������Ϸ���IP��ַ��Ϊ�Ϸ���ipv4��ַ�����㣨1~255��.��0~255��.��0~255��.��0~255���ĸ�ʽ���ҿ��Լٶ������в�������鲥�͹㲥��ַ��
//
//ʾ��1
//���룺
//City1=1.1.1.1,1.1.1.2;City1=1.1.1.11,1.1.1.16;City2=3.3.3.3,4.4.4.4;City3=2.2.2.2,6.6.6.6
//1.1.1.15,3.3.3.5,2.2.2.3
//�����
//City1,City2,City3
//˵����
//1��City1��2��IP�Σ�City3��IP�ΰ���City2��IP�Σ�
//2��1.1.1.15��ƥ��City1=1.1.1.11,1.1.1.16������City1�������ƥ�䣻2.2.2.3��ƥ��City3=2.2.2.2,6.6.6.6������City3�����ƥ�䣻3.3.3.5ͬʱƥ��ΪCity2=3.3.3.3,4.4.4.4��City3=2.2.2.2,6.6.6.6������City3=2.2.2.2,6.6.6.6��IP�η�Χ��С������City3Ϊ���ƥ�䣻
//*/
//#include<iostream>
//#include<vector>
//#include<string>
//#include<sstream>
//#include<limits>
//
//using namespace std;
//
//struct city
//{
//	string name;
//	unsigned long start;
//	unsigned long end;
//
//	city(string name, long start, long end) : name(name), start(start), end(end)
//	{
//
//	}
//};
//
//unsigned long ipToUl(string ip)
//{
//	istringstream iss(ip);
//	unsigned long ulip = 0;
//	string token;
//	while (getline(iss, token, '.'))
//	{
//		ulip += stoul(token);
//	}
//	return ulip;
//}
//
//int main()
//{
//	// ����
//	string str_city;	// ���е�IP���б�
//	getline(cin, str_city);
//	string str_query;   // ��ѯ��IP�б�
//	getline(cin, str_query);
//
//
//	vector<city> cities;
//	vector<unsigned long> quiries;
//
//	// ������������
//	istringstream iss1(str_city);
//	string s_city;
//	while (getline(iss1, s_city, ';'))
//	{
//		size_t pos1 = s_city.find('=');
//		size_t pos2 = s_city.find(',');
//
//		string name = s_city.substr(0, pos1);
//		string ip1 = s_city.substr(pos1 + 1, pos2 - pos1);
//		string ip2 = s_city.substr(pos2 + 1);
//
//		city c1(name, ipToUl(ip1), ipToUl(ip2));
//		cities.push_back(c1);
//	}
//
//	istringstream iss2(str_query);
//	string s_ip;
//	while(getline(iss2, s_ip, ','))
//	{
//		quiries.push_back(ipToUl(s_ip));
//	}
//
//	// ��ʼ��ѯ
//	vector<string> res;
//	for (auto& i : quiries)
//	{
//		string name;
//		unsigned long gap = numeric_limits<unsigned long>::max();
//		for (auto& j : cities)
//		{
//			if (i >= j.start && i <= j.end)
//			{
//				if (j.end - j.start < gap)
//				{
//					name = j.name;
//					gap = j.end - j.start;
//				}
//			}
//		}
//		res.push_back(name);
//	}
//
//	for (int i = 0; i < res.size(); i++)
//	{
//		cout << res[i];
//		if (i != res.size() - 1)
//		{
//			cout << ',';
//		}
//	}
//}