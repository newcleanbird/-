///*
//470����ľ��
//��Ŀ������
//һ��X�׳�����ľ����ľ���и�ɲ�ͬ���ȵ�ľ�ĺ���н��ף����׼۸�Ϊÿ��ľͷ���ȵĳ˻����涨�и���ÿ��ľͷ���ȶ�Ϊ��������Ҳ���Բ��иֱ����������ľ���н��ס����ʷ�ľ����ξ����ٵ��и����ʹ������󻯣�
//
//����������
//ľ�ĵĳ��ȣ�X<=50��
//
//���������
//�����������ʱ�ĸ�����ľ���ȣ��Կո�ָ����������
//
//����˵����
//ʾ��1
//���룺
//10
//�����
//3 3 4
//˵����
//1. һ��2�׳�����ľ����ľ�����иΪ2 * 1���������Ϊ2
//2. һ��4�׳�����ľ����ľ������Ҫ�и�Ϊ2 * 2��ʡȥ�и�ɱ���ֱ��������ľ���ף�Ϊ4 * 1���������Ϊ4
//3. һ��5�׳�����ľ����ľ���и�Ϊ2 * 3���������Ϊ6
//4. һ��10�׳�����ľ����ľ�������и�Ϊ��ʽһ��3��4��3��Ҳ�����и�Ϊ��ʽ����3��2��2��3������ʽ����ľ�����и���һ�Σ������и�ɱ�ȴ����һ���ļ۸���˲������������档
//*/
//
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//struct Wood
//{
//	int price;
//	vector<int> length;
//};
//
//int main()
//{
//	int n;	// ľ�ĵĳ���
//	cin >> n;
//	vector<Wood> vec(n + 1);	// �ӳ���Ϊ0������Ϊn
//
//	// ��ʼ��ÿ�����ȵ�ľ�ļ�ֵ�͵�ǰ�и��ĳ���
//	for (int i = 0; i <= n; i++)
//	{
//		vec[i].price = i;
//		vec[i].length.push_back(i);
//	}
//
//	for (int i = 2; i <= n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			int price = vec[i - j].price * vec[j].price;
//			if (vec[i].price < price || (vec[i].price == price && vec[i].length.size() > vec[i - j].length.size() + vec[j].length.size()))
//			{
//				vec[i].price = price;	// ���¼۸�
//				// �����и��
//				vec[i].length = vec[i - j].length;
//				vec[i].length.insert(vec[i].length.end(), vec[j].length.begin(), vec[j].length.end());
//			}
//		}
//	}
//	sort(vec[n].length.begin(), vec[n].length.end(), less<int>());
//	for (int i = 0; i < vec[n].length.size(); i++)
//	{
//		cout << vec[n].length[i];
//		if (i != vec[n].length.size() - 1)
//		{
//			cout << " ";
//		}
//	}
//	cout << endl;
//	cout << vec[n].price << endl;
//
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
////class Wood {
////public:
////    int profit;
////    std::vector<int> slices;
////};
////
////int main() {
////    int x;  // X�׳�����ľ
////    std::cin >> x;
////
////    std::vector<Wood> dp(x + 1);    // �洢ÿ�����ȵ��������Ͷ�Ӧ���и��
////
////    // ��ʼ��dp,dp[i]��ʾ����Ϊi��ľ�ĵ����������и����
////    for (int i = 0; i <= x; i++) {
////        dp[i].profit = i;
////        dp[i].slices.push_back(i);
////    }
////
////    for (int i = 2; i <= x; i++) {
////        for (int j = 1; j < i; j++) {
////            int profit = dp[j].profit * dp[i - j].profit;   // ���㽫����Ϊj��ľ�ĺͳ���Ϊi-j��ľ���и�������
////
////            if (profit > dp[i].profit || (profit == dp[i].profit && dp[i].slices.size() > dp[j].slices.size() + dp[i - j].slices.size())) { // ����¼����������ڵ�ǰ������󣬻���������ȵ��и��Ķ������٣������dp[i]����Ϣ��
////                dp[i].profit = profit;
////                dp[i].slices.clear();// ����dp[i]���и��
////                dp[i].slices.insert(dp[i].slices.end(), dp[j].slices.begin(), dp[j].slices.end());  // ���볤��Ϊj������и��
////                dp[i].slices.insert(dp[i].slices.end(), dp[i - j].slices.begin(), dp[i - j].slices.end());  // ���볤��Ϊi-j������и��
////            }
////        }
////    }
////
////    std::sort(dp[x].slices.begin(), dp[x].slices.end());
////
////    std::ostringstream oss;
////    for (int slice : dp[x].slices) {
////        oss << slice << " ";
////    }
////
////    std::cout << oss.str() << std::endl;
////
////    return 0;
////}