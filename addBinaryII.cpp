/*
Problem: Add Binary 
Method:  string 
Author: 'gq' 
*/
#include<iostream>
#include<cstdlib>
#include<string> 
#include<algorithm>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
           if(a.empty())
               return b;
           if(b.empty())
               return a;
           string res;
           int carry=0,digit=0;
           int i=a.size()-1,j=b.size()-1; 
           while(0<=i&&0<=j)
           {    
               int sum=a[i]-'0'+b[j]-'0'+carry;
               digit=sum%2;
               carry=sum/2;
               res+=digit+'0'; 
               i--;
               j--;
           }
           while(0<=i)
           {
	          int sum=a[i]-'0'+carry;
              digit=sum%2;
              carry=sum/2;
              res+=digit+'0';
              i--;
           }  
           while(0<=j)
           {
              int sum=b[j]-'0'+carry;
              digit=sum%2;
              carry=sum/2;
              res+=digit+'0';
              j--;
		   }      
           if(carry==1)
              res+=carry+'0';
           reverse(res.begin(),res.end()); 
           return res;        
    }
};
int main()
{
    Solution s;
    string a="1011";;
    string b="1010";
    cout<<s.addBinary(a,b)<<endl;
    
    cin.get();
    return 0;
}
