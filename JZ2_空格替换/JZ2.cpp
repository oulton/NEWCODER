#include <iostream>
#include <string>

using namespace std;

void replaceSpace(char *str, int length) 
{
	string s = "";
	for (size_t i = 0; i < length; i++)
	{
		if (str[i] != ' ')
			s += str[i];
		else
			s += "%20";
	}
	////cout << s << endl;
	//strcpy(str, s.c_str());   //ֱ��copy������Խ��,�������ύ�ɹ�
}

int main()
{
	char* str = "We are happy.";
	replaceSpace(str, strlen(str));
	cout << str << endl;
	system("pause");
	return 0;
}