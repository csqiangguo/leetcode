/*
Problem: Reverse Integer
Method: res=res*10+x%10 
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        if(x==INT_MIN)
            return INT_MIN;
        int res=0;
        bool isneg=false;
        if(x<10)
        {
           isneg=true;
           x=-1*x;
        }
        //��Ϊǰn-1λ�������Խ�磬�����ȴ���ǰn-1λ�����һλ�������� 
        while(x>=10)
        {
            int remainder=x%10;
            res=res*10+remainder;
            x=x/10;
        }
        if(res<INT_MAX/10)
            res=res*10+x%10;
        else if(INT_MAX/10<res)
        {
            res=INT_MAX;
        }
        else
        {
            if(x>INT_MAX%10)
                res=INT_MAX;
            else
                res=res*10+x%10;
        }
        if(isneg)
           res=-1*res;
        return res;
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
        cout<<s.reverse(x)<<endl;
    }
    cin.get();
    return 0;
}
