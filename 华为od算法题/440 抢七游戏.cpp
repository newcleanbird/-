///*
//440��������Ϸ
//��Ŀ������
//A��B����������7��Ϸ����Ϸ����ΪA�ȱ�һ����ʼ����X(10<��ʼ����<10000)��B����һ������Y(X-Y<3),A�ٱ�һ������Z(Y-Z<3)���Դ����ƣ�ֱ������һ������7������7��Ϊʤ�ߣ���BӮ�ñ���������£�һ���ж�������ϣ�
//
//����������
//��ʼ����M����100��10<=M<=10000
//
//���������
//B��Ӯ�ñ�������ϴ���
//
//����˵����
//ʾ��1
//���룺
//10
//�����
//1
//
//˼·��
//ÿ�ε���Ϊ0~2
//*/
//#include<iostream>
//#include<vector>
//#include<map>
//
//using namespace std;
//
//map<pair<int, bool>, int> memo; // map�洢��ʼλ�ú�˭���ִ� �Լ���Ӧ�����������Ϣ
//
//int countWaysToWin(int start, bool isATurn) {
//    if (start == 7 && !isATurn) return 1;   // ��7��ʼ��B���ִΣ���ʱB��һ��Ӯ����ϡ�
//    if (start == 7 && isATurn) return 0;    // ��7��ʼ��A���ִΣ���ʱB������Ӯ��
//    if (start < 7) return 0;
//
//    auto key = make_pair(start, isATurn);
//    if (memo.find(key) != memo.end()) {
//        return memo[key];
//    }
//
//    int waysToWin = 0;
//    for (int nextMove = 1; nextMove <= 2; nextMove++) {
//        if (isATurn) {
//            waysToWin += countWaysToWin(start - nextMove, false);
//        }
//        else {
//            waysToWin += countWaysToWin(start - nextMove, true);
//        }
//    }
//
//    memo[key] = waysToWin;
//    return waysToWin;
//}
//
//int main()
//{
//	int M;  // ��ʼ����
//	cin >> M;
//    int res = countWaysToWin(M, true);
//    cout << res;
//}
//
//
