
/*******************************************************************************************************
问题描述：字符串中查找连续最长的数字字符串

思路分析：1.首先遍历判断某字符是否为数字字符
          2.若为数字字符，则继续探测下一个字符，定义两个字符串变量max_sub,cur_sub分别表示
          最大连续数字子串和当前连续数字子串。
              cur_sub用于探索连续数字子串，max_sub用于存储最长连续数字子串
              每当cur_sub探索到连续数字子串时，与max_sub进行比较，确保，max_sub为最长。
*******************************************************************************************************/

#include<iostream>
#include<string>

using namespace std;

string  SearchLongSubStr(string str)
{
    string max_sub = "";
    string cur_sub = "";
    size_t size = str.size();
    for (int i = 0;i <= size; i++)
    {
        if (str[i] >= '0'&&str[i] <= '9')
        {
            cur_sub.insert(cur_sub.end(),str[i]);
            continue;
        }
        cur_sub.insert(cur_sub.end(), '\0');
        if (max_sub.size() < cur_sub.size())
        {
            max_sub = cur_sub;
        }
        cur_sub.clear();
    }
    return max_sub;
}

int main()
{
    string str;
    cin >> str;
    string ret=SearchLongSubStr(str);
    cout << ret << endl;
    /*char *str = (char *)malloc(100);
    strcpy(str, "hello");
    free(str);
    if (str!=NULL)
    {
        strcpy(str, "world");
        printf("%s", str);
    }*/

	system("pause");
	return 0;
}