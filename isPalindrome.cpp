/*
Problem: Palindrome Number 
Method: res=res*10+x%10 
Author: 'gq' 
*/
#include<iostream>
#include<cstdlib>
using namespace std;
//���ǻ��������򷴹���Ҳ����overflow���ʲ�����Խ�� 
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int res=0;
        int cmp=x;
        while(x!=0)
        {
            res=res*10+x%10;
            x=x/10;
        }
        if(res==cmp)
            return true;
        return false;
    }
};
//���п���Խ�紦�����һλ�������� 
class Solution1 {
public:
    bool isPalindrome(int x){
         if(x<0)
            return false;
         int res=0;
         int cmp=x;
         while(10<=cmp)
         {
             int remainder=cmp%10;
             res=res*10+remainder;
             cmp=cmp/10;
         }
         if((res==x/10)&&(cmp==x%10))
             return true;
         return false;
        
    }
};
int main()
{
    cout<<INT_MAX<<endl;
    cout<<INT_MIN<<endl;
    int x;
    Solution s;
    while(cin>>x)
    {
        cout<<s.isPalindrome(x)<<endl;
    }
    cin.get();
    return 0;
}
