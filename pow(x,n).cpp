#include<cstdlib>
#include<iostream>
using namespace std;
//���ַ� 
class Solution {
public:
    double pow(double x, int n) {
        if(n==0)
        	return 1.0;
        if(n==1)
        	return x;
        double haff=pow(x,abs(n/2));
        if(n>0)
        {
        	if(n&1)
        		return haff*haff*x;
        	else
        		return haff*haff;
        }
        else
        {
        	if(n&1)
        		return 1/(haff*haff*x);
        	else
        		return 1/(haff*haff);
        	
        }
    }
};
//������Ϊ����λ���� 
class Solution1 {
public:
    double pow(double x, int n) {
    	//����nȡֵINT_MINʱ��-n������INT_MAX����ʱ��Ҫ����С�ġ�
    	if(n==INT_MIN)
    		return 1.0/(pow(x,INT_MAX)*x);
        double result=1.0;
        int m=abs(n);
        while(m!=0)
        {
        	if(m&1)
        	{
        		result=result*x;
        	}
        	x=x*x;
        	m=m>>1;
        }
        return n>=0?result:1/result;
    }
};
int main()
{
	double x=4;
	Solution1 s;
	cout<<s.pow(x,-2)<<endl;
	cout<<INT_MAX<<endl;
	cout<<INT_MIN<<endl;
	cin.get();
	return 0;
} 
