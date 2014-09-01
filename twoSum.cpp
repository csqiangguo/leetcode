#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;
struct node{
       int value;
       int index;
};
bool cmp(const node& n1,const node& n2)
{
     return n1.value<n2.value;
}
class Solution {
public:
    
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int>result;
        vector<node>temp;
        for(int i=0;i<numbers.size();++i)
        {
            node newnode={numbers[i],i+1};
            temp.push_back(newnode);
        }
        sort(temp.begin(),temp.end(),cmp);
        vector<node>::iterator iter1=temp.begin();
        vector<node>::iterator iter2=--temp.end();
        while(iter1<iter2)
        {
            int curR=iter1->value+iter2->value;
            if(curR==target)
            {
               if(iter1->index>iter2->index)
               {
                  result.push_back(iter2->index);
                  result.push_back(iter1->index);
               }
               else
               {
                  result.push_back(iter1->index);
                  result.push_back(iter2->index);
               }
               return result;
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
};
class Solution1{
public:
    
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int>result;
        hash_map<int,int>temp;
        for(int i=0;i<numbers.size();++i)
        {
            temp[numbers[i]]=i+1;
        }
        for(hash_map<int,int>::iterator iter=temp.begin();iter!=temp.end();iter++)
		{
			hash_map<int,int>::iterator iter1;
			iter1=temp.find(target-iter->first);
			if(iter!=temp.end())
			{
				if(iter1->second>iter->second)
				{
					result.push_back(iter->second);
					result.push_back(iter1->second);
					return result;
				}
				else
				{
					result.push_back(iter1->second);
					result.push_back(iter->second);
					return result;
				}
			}
		}
        return result;
    }
};
int main()
{
    vector<int> numbers;
    numbers.push_back(2);
    numbers.push_back(12);
    numbers.push_back(7);
    numbers.push_back(15);
    Solution s;
    vector<int> result;
    result=s.twoSum(numbers,14);
    cout<<result[0]<<' '<<result[1]<<endl;
    cin.get();
    return 0;
}
