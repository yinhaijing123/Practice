/***************************************************************************************************
问题描述：You are given two linked lists representing two non-negative numbers. 
		  The digits are stored in reverse order and each of their nodes contain a single digit.
		  Add the two numbers and return it as a linked list.
Example：
		  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
		  Output: 7 -> 0 -> 8
思路分析：首先，将两条链表转换为数字，
		  然后，将得到的数字相加
		  最后，将得到的结果用链式结构存储
***************************************************************************************************/
#include<iostream>
using namespce std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int OriginNum(ListNode *l)
{
    int num = 0;
    ListNode* cur = l;

    for (size_t i = 1; cur != NULL; cur = cur->next, i *= 10)
    {
        num += cur->val*i;
    }
    return num;
}

ListNode *StoredNum(int num)
{
    ListNode *head = new ListNode(num % 10);
    ListNode *cur = head;
    num /= 10;
    while (num)
    {
        ListNode *Node = new ListNode(num % 10);
        cur->next = Node;
        cur = Node;
        num /= 10;
    }
    return head;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int num1 = OriginNum(l1);
    int num2 = OriginNum(l2);
    int sum = num1 + num2;
    ListNode *head = StoredNum(sum);
    return head;
}

void Test()
{
    ListNode *l1 = new ListNode(9);
    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(9);
   
    ListNode *head = addTwoNumbers(l1, l2);
    ListNode *cur=head;
	while(cur!=NULL)
	{
		cout<<(cur->val)<<"->";
		cur=cur->next;
	}
	cout<<"NULL"<<endl;
}
int main()
{   
    Test();
   
	system("pause");
	return 0;
}