///*
//481 �ļ�����ϵͳ
//��Ŀ������
//�����һ���ļ�����ϵͳ�����ļ�����ϵͳ����ָ����������ֵ����λΪ�ֽڣ���
//�ļ�����ϵͳ�����ֲ������洢�ļ�(put)�Ͷ�ȡ�ļ�(get)
//��������Ϊput fileName fileSize����get fileName
//�洢�ļ��ǰ��ļ������ļ�����ϵͳ�У���ȡ�ļ��Ǵ��ļ�����ϵͳ�з����Ѵ��ڵ��ļ�������ļ������ڣ������κβ�����
//������ռ䲻���Դ���µ��ļ�ʱ�����ݹ���ɾ���ļ���ֱ��ʣ��ռ������µ��ļ���СΪֹ���ٴ�����ļ���
//�����ɾ������Ϊ��
//�ļ����ʹ��󣬻�����ļ����������ʱ����ܵķ��ʴ����������治��ʱ�����յ�һ����˳��Ϊ���ʴ������ٵ��࣬�ڶ�˳��Ϊʱ����ϵ��µķ�ʽ��ɾ���ļ���
//
//����������
//��һ��Ϊ�������ֵm(������ȡֵ��ΧΪ0 < m <= 52428800)��
//�ڶ���Ϊ�ļ��������и���n(0 <= n <= 300000
//�ӵ�������Ϊ�ļ��������У�ÿ�����е���һ��
//�ļ���������Ϊ"op file_namefile_size"
//file_name���ļ�����file_size���ļ���С
//
//���������
//�����ǰ�ļ������е��ļ����б��ļ�����Ӣ�Ķ��ŷָ������ֵ�˳������
//�磺
//a,c
//����ļ�������û���ļ��������NONE
//����˵����
//1.  ������ļ����ļ������ļ����������е��ļ�����ͬ���򲻻���ڻ�����
//2.  �µ��ļ���һ�δ��뵽�ļ�������ʱ���ļ����ܷ��ʴ�������仯���ļ����������ʱ�����µ�����ʱ��
//3.  ÿ���ļ����ʺ��ܷ��ʴ�����1���������ʱ����µ�����ʱ��
//4.  �κ������ļ����������ʱ�䲻���ظ�
//5.  �ļ�������Ϊ�գ���ΪСд��ĸ����󳤶�Ϊ10��
//6.  ����ռ䲻��ʱ�����ܴ�����ļ�
//7.  ÿ���ļ���С���Ǵ���0������
//
//ʾ��1
//���룺
//50
//6
//put a 10
//put b 20
//get a
//get a
//get b
//put c 30
//�����
//a,c
//˵����
//
//ʾ��2
//���룺
//50
//1
//get file
//�����
//NONE
//˵����
//*/
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <sstream>
//#include <unordered_map>
//#include <chrono>
//#include <algorithm>
//
//using namespace std;
//
//struct file
//{
//public:
//	string fileName;
//	int fileSize;
//	int accessCount;	// ���ʴ���
//	chrono::time_point<std::chrono::system_clock> lastAccessTime;	// �������ʱ��
//	// Ĭ�Ϲ��캯��
//	file()
//	{
//
//	}
//	// ���캯��
//	file(string name, int size, int count, chrono::time_point<std::chrono::system_clock> time) : fileName(name), fileSize(size), accessCount(count), lastAccessTime(time)
//	{
//
//	}
//	//// �������캯��
//	//file(const file& other) : fileName(other.fileName), fileSize(other.fileSize), accessCount(other.accessCount), lastAccessTime(other.lastAccessTime)
//	//{
//
//	//}
//	//// ���������
//	//file& operator=(const file& other)
//	//{
//	//	// ��ֹ���Ҹ�ֵ
//	//	if (this != &other) {
//	//		// ��������߼��ϵ��������������Ա���ǿ���ǳ�����ģ�
//	//		fileName = other.fileName;
//	//		fileSize = other.fileSize;
//	//		accessCount = other.accessCount;
//	//		lastAccessTime = other.lastAccessTime;
//	//	}
//	//	return *this; // ���ص�ǰ��������ã�������ʽ��ֵ�� a = b = c;
//	//}
//};
//class compare {
//public:
//	bool operator()(const pair<string, file >& a, const pair<string, file >& b) const
//	{
//		if (a.second.accessCount != b.second.accessCount)
//			return a.second.accessCount > b.second.accessCount;	// �����ʴ�������
//		return b.second.lastAccessTime > b.second.lastAccessTime;     // ������ʱ������
//	}
//};
//
//class FileCacheSystem
//{
//private:
//	int maxSize;
//	int currentSize = 0;
//	unordered_map<string, file> files;
//
//
//public:
//	FileCacheSystem(int max_file) : maxSize(max_file)
//	{
//
//	}
//
//	void put(string name, int size)
//	{
//		if (files.find(name) != files.end())	// ����ļ��Ѿ����뻺�棬������
//		{
//			return;
//		}
//
//		if (size > maxSize) return;	// �洢���ļ���С�����ܻ���,ɾ�������ļ�Ҳû����
//		if(size + currentSize > maxSize)
//		{
//			int nowSize = size + currentSize;
//			evict(nowSize);	// ɾ���ļ�ֱ�����㵱ǰ����Ļ����С
//		}
//		// �����ļ�
//		std::chrono::time_point<std::chrono::system_clock> current_time  = chrono::system_clock::now();
//		file newfile(name, size, 0, current_time);
//		files.insert({ name, newfile });
//		currentSize += size;
//		//files[name] = newfile;
//	}
//
//	void get(string name)
//	{
//		if (files.find(name) != files.end()) {
//			files[name].accessCount++;
//			files[name].lastAccessTime = chrono::system_clock::now();
//		}
//	}
//
//	void evict(int nowSize)
//	{
//		vector<pair<string, file>> sorted_files(files.begin(), files.end());
//		sort(sorted_files.begin(), sorted_files.end(), compare());
//		size_t pos = sorted_files.size() - 1;
//		while (nowSize > maxSize)
//		{
//			nowSize -= sorted_files[pos].second.fileSize;
//			files.erase(sorted_files[pos].first);
//			pos--;
//		}
//	}
//
//	string listFiles() {
//		if (files.empty()) return "NONE";
//		vector<string> sorted_files;
//		for (auto& [name, _] : files) sorted_files.push_back(name);
//		sort(sorted_files.begin(), sorted_files.end(), less<string>());
//		string result;
//		for (int i = 0; i < sorted_files.size(); i++)
//		{
//			result += sorted_files[i];
//			if (i != sorted_files.size() - 1) result += ',';
//		}
//		return result;
//	}
//
//};
//
//int main()
//{
//	// ����
//	int m;	// �������ֵm
//	cin >> m;
//	int n;
//	cin >> n; // �ļ��������и���n
//	cin.get(); // ��������з�
//	vector<string> orders(n);
//	string str;
//	for (int i = 0; i < n; i++)
//	{
//		getline(cin, orders[i]);
//	}
//
//	// ��������
//	FileCacheSystem fc(m);
//
//	for (auto& i : orders)
//	{
//		istringstream  iss(i);
//		string token;
//		vector<string> order;
//		while (getline(iss, token, ' '))
//		{
//			order.push_back(token);
//		}
//		if (order[0] == "put")
//		{
//			fc.put(order[1], stoi(order[2]));
//		}
//		else if (order[0] == "get")
//		{
//			fc.get(order[1]);
//		}
//	}
//	string res = fc.listFiles();
//	cout << res;
//
//}