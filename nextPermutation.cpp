#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution{
public:
	void nextPermutation(vector<int> &num){
		int i=num.size()-1;
		for(;0<i;i--)
		{
			if(num[i-1]<num[i])
				break;
		}
		i=i-1;
		if(i<0)
		{
			reverse(num.begin(),num.end());
			return ;
		}
		int j=i+1;
		for(;j<num.size();j++)
		{
			if(num[j]<=num[i])
			{
				break;
			}
		}
		j=j-1;
		swap(*(num.begin()+i),*(num.begin()+j));
		reverse(num.begin()+i+1,num.end());
	}
};
int main()
{
	int a[9]={1,2,3,4,5,6,7,8,9};
	vector<int> num(a,a+9);
	reverse(num.begin(),num.end());
	Solution s;
	s.nextPermutation(num);
	for(int i=0;i<num.size();i++)
		cout<<num[i]<<' ';
	cout<<endl;
	return 0;
}

