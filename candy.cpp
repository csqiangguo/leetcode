#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;
class Solution {
public:
    int candy(vector<int> &ratings) {
        if(ratings.empty())
            return 0;
        vector<int> res(ratings.size(),0);
        res[0]=1;
        for(int i=1;i<ratings.size();i++){
            if(ratings[i-1]<ratings[i])
                res[i]=res[i-1]+1;
            else
                res[i]=1;
        }
        for(int i=ratings.size()-1;0<i;i--){
            if(ratings[i]<ratings[i-1])
                res[i-1]=max(res[i-1],res[i]+1);
        }
        int sum=0;
        for(int i=0;i<res.size();i++){
            sum+=res[i];
        }
        return sum;
    }
    int max(int a,int b){
        return a<b?b:a;
    }
};
int main(){
	Solution s;
	vector<int> ratings(1,0);
	int sum=s.candy(ratings);
	cout<<sum<<endl;
	return 0;
}
