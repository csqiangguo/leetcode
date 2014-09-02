#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;
class Solution {
public:   
    int twoSumClosest(vector<int>::iterator begin, vector<int>::iterator end,int target) {
    	vector<vector<int>>result;
    	if((end-begin)<2)
    		return result;
        vector<int>::iterator iter1=begin;
        vector<int>::iterator iter2=--end;
        while(iter1<iter2)
        {
            int curR=*iter1+*iter2;
            if(curR==target)
            {
            	vector<int> temp;
                temp.push_back(*iter1);
            	temp.push_back(*iter2);
                result.push_back(temp);
                while(iter1<iter2&&*iter1==temp[0])//循环内循环注意同样要保持外循环的条件，否则易出错 
                	iter1++;
                while(iter1<iter2&&*iter2==temp[1])
                	iter2--;
            }
            else if(curR>target)
            {
                 iter2--;
            }
            else
            {
                iter1++;
            }
        }
        return result;
    }
    int threeSumClosest(vector<int> &num, int target) {
    	sort(num.begin(),num.end());
    	vector<vector<int>> result;
    	if(num.size()<3)
    		return result;
    	vector<int>::iterator iter1=num.begin(),iter2=iter1;
    	while(iter1<num.end()-2)
    	{
    		vector<vector<int>> tempResult;
    		int target=-*iter1;
    		tempResult=twoSum(++iter2,num.end(),target);
    		if(!tempResult.empty())
    		{
    			for(vector<vector<int>>::iterator iter=tempResult.begin();iter!=tempResult.end();iter++)
    			{
    				vector<int> temp;
    				temp.push_back(*iter1);
    				temp.push_back((*iter)[0]);
    				temp.push_back((*iter)[1]);
    				result.push_back(temp);
    			}
    		}
    		int key=*iter1;
    		while(iter1<num.end()-2&&*iter1==key)//循环内循环注意同样要保持外循环的条件，否则易出错 
    			iter1++;
    		iter2=iter1;
    	}
    	return result;   
    }
};
int main()
{
    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(-2);
    numbers.push_back(-1);
    //numbers.push_back(2);
    //numbers.push_back(-1);
   // numbers.push_back(-4);
    sort(numbers.begin(),numbers.end());
    Solution s;
    vector<vector<int>> result;
    result=s.threeSum(numbers);
    for(vector<vector<int>>::iterator iter=result.begin();iter!=result.end();iter++)
    {
    	cout<<(*iter)[0]<<' '<<(*iter)[1]<<' '<<(*iter)[2]<<endl;
    }
    cin.get();
    return 0;
}

