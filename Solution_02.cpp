#include <iostream>
using namespace std;
class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == NULL || length <= 0) return;
		int ori_length = 0;//字符串原来长度
		int new_length = 0;//字符串新长度
		int num_blank = 0;//空字符串的个数
		while (str[ori_length] != '\0')
		{
			if (str[ori_length] == ' ')
			{
				num_blank++;
			}
			ori_length++;
		}
		if (num_blank == 0) return;
		new_length = ori_length + 2 * num_blank;
		//必须要将末尾的'\0'也要赋值
		int last = new_length;
		int pre = ori_length;
		while (pre < last && pre >= 0)
		{
			if (str[pre] != ' ')
			{
				str[last--] = str[pre];
			}
			else {
				str[last--] = '0';
				str[last--] = '2';
				str[last--] = '%';
			}
			pre--;
		}

	}
};

int main()
{
	Solution slove;
	char str[15] = " helloworld";
	slove.replaceSpace(str, 100);
	
	return 0;
}
