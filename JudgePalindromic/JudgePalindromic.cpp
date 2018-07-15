/***********************************************************************************************
问题描述：给定一个字符串，问是否能通过添加一个字母将其变为回文串

思路分析：既然能通过增加一个字符变成回文串，那一定也可以通过删除一个字符变成回文串。
          用一个循环，每次循环依次删掉一个字符，然后检查新串是否是回文串，看起来简单方便许多。
***********************************************************************************************/

#include<iostream>
using namespace std;
#include<string>

bool IsPalindromic(string s)
{
    int size = s.length()-1;
    for (int i = 0; i<size / 2; i++)
    {
        if (s[i] != s[size - 1 - i])
        {
            return false;
        }
    }
    return true;
}

bool Judge(string s)
{
    int size = s.length();
    int i, j;
    for (i = 0; i < size; i++)
    {
        string tmp(s);
        for (j = i; j< size; j++)
        {
            tmp[j] = tmp[j + 1];
        }
        if (IsPalindromic(tmp))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string s;
    cin >> s;
    if (Judge(s))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    system("pause");
    return 0;
}