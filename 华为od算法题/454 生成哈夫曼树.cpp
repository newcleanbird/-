///*
//��Ŀ������
//��������Ϊn��������������飬ÿ�����ִ����������Ҷ�ӽڵ��Ȩֵ�����������ֵ�����ڵ���1�������һ������������������������飬���ɹ�������������������������������������
//Ϊ�˱�֤����Ķ���������������ͳһ�������������ƣ��������ڵ��У���ڵ�ȨֵС�ڵ����ҽڵ�Ȩֵ�����ڵ�ȨֵΪ���ҽڵ�Ȩֵ֮�͡������ҽڵ�Ȩֵ��ͬʱ���������߶ȸ߶�С�ڵ�����������
//ע�⣺����������֤��Ч���������ɹ���������
//
//���ѣ����������ֳ����Ŷ���������һ�ִ�Ȩ·��������̵Ķ���������ν���Ĵ�Ȩ·�����ȣ������������е�Ҷ����Ȩֵ�����䵽������·�����ȣ��������Ϊ0�㣬Ҷ��㵽������·������ΪҶ���Ĳ�������
//���磺
//��Ҷ�ӽڵ�5 15 40 30 10���ɵ����Ŷ���������ͼ��ʾ����������̴�Ȩ·������Ϊ40*1+30*2+15*3+5*4+10*4=205��
//
//����������
//��һ������Ϊ���鳤�ȣ���ΪN��1<=N<=1000���ڶ�������������ֵ���飬�Կո�ָ��ֵ�����ڵ���1��С��100000
//
//���������
//���һ������������������������飬��ֵ���Կո�ָ�
//
//����˵����
//ʾ��1
//���룺
//5
//5 15 40 30 10
//�����
//40 100 30 60 15 30 5 15 10
//˵����
//�������룬���ɹ�����������������������ء����нڵ��У���ڵ�ȨֵС�ڵ����ҽڵ�Ȩֵ�����ڵ�ȨֵΪ���ҽڵ�Ȩֵ֮�͡������ҽڵ�Ȩֵ��ͬʱ���������߶ȸ߶�С�ڵ��������������
//*/
//
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//
//using namespace std;
//
//struct Node
//{
//	// int data;	// data
//	int freq;	// �ڵ��Ƶ��
//	Node* left;	// ������
//	Node* right;// ������
//
//	Node(int freq) : freq(freq), left(nullptr), right(nullptr)
//	{
//
//	}
//	Node(int freq, Node* left, Node* right) : freq(freq), left(left), right(right)
//	{
//
//	}
//};
//
//int getHeight(Node* root) {
//	if (root == NULL) {
//		return 0;
//	}
//	int leftHeight = getHeight(root->left);
//	int rightHeight = getHeight(root->right);
//	return max(leftHeight, rightHeight) + 1;
//}
//
//struct Compare {
//	bool operator()(Node* l, Node* r) {
//		if (l->freq == r->freq)
//		{
//			return getHeight(l) > getHeight(r);
//		}
//		else {
//			return l->freq > r->freq;
//		}
//	}
//};
//
//class HuffmanTree
//{
//private:
//	Node* root;
//	priority_queue<Node*, vector<Node*>, Compare> q;
//	void buildTree()
//	{
//		while (q.size() != 1)
//		{
//			Node* left = q.top(); q.pop();
//			Node* right = q.top(); q.pop();
//			Node* cur = new Node(left->freq + right->freq, left, right);
//			q.push(cur);
//		}
//		root = q.top();
//	}
//	int treeHeight()
//	{
//
//	}
//	void inOrderTraversal(Node* cur)
//	{
//		if (cur == nullptr) return;
//		inOrderTraversal(cur->left);
//		cout << cur->freq << " ";
//		inOrderTraversal(cur->right);
//	}
//
//public:
//	HuffmanTree(vector<int>& freqs)
//	{
//		for (auto i : freqs)
//		{
//			q.push(new Node(i));
//		}
//		buildTree();
//	}
//	void getInOrderTraversal()
//	{
//		inOrderTraversal(root);
//	}
//};
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> freqs(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> freqs[i];
//	}
//	HuffmanTree ht(freqs);
//	ht.getInOrderTraversal();
//
//}