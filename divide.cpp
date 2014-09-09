/*
Problem: Divide Two Integers
Method:  numerical calculation  
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
    	long long a=dividend;
    	long long b=divisor;
        a=abs(a);
        b=abs(b);
        long long i=0;
        long long res=0;
        while(b<=a)
        {
        	b=b<<1;
        	i++;
        }
        while(0<=i)
        {
        	if(b<=a)
        	{
        		a=a-b;
        		res=res+(1<<i);
        	}
        	i--;
        	b=b>>1;
        }
        return (dividend>0)^(divisor>0)?-res:res;
    }
};
int main()
{
	Solution s;
	cout<<s.divide(INT_MIN,1)<<endl;
	cout<<s.divide(INT_MAX,1)<<endl;
	cout<<s.divide(5,4)<<endl;
	cin.get();
	return 0;
}
