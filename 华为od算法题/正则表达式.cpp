///*
//ע�⣺
//1.C++�У�������д������ʽ��������Ҫ��ת���ַ��ĵط�����Ҫ������
//2.����ʹ��R"(��׼������ʽ)"s
//*/
//
//#include<iostream>
//#include<string>
//#include<regex>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	//// ƥ��
//	//string str = "-1-2-3-4+5*5+99";
//	//string str = "+1";
//	//regex r(R"(^[+\-]?(\d+[+\-*])+\d+$)")
//	//	;
//	//if (regex_match(str, r)) {
//	//	cout << "ƥ��ɹ�";
//	//}
//	//else {
//	//	cout << "ƥ��ʧ��";
//	//}
//
//	// ����������
//	std::string input = "I have 3 cats and 4 dogs.";
//	std::regex pattern("\\d+"); // ƥ��һ����������
//
//	// ʹ��sregex_iterator����ƥ����
//	for (std::sregex_iterator it(input.begin(), input.end(), pattern); it != std::sregex_iterator(); ++it) {
//		std::cout << "Matched: " << it->str() << std::endl;
//	}
//}