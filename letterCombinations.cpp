/*
Problem: Binary Tree Level Order Traversal  
Method:  recursion/Levelorder Traverse
Author: 'gq' 
*/
#include<iostream>
#include<cstdlib> 
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size()==0)
        {
            res.push_back("");
            return res;
        }
        char next=digits.back();
        digits.pop_back();
        vector<string> left=letterCombinations(digits);
        string letter=getLetters(next);
        for(int i=0;i<letter.size();i++)
        {
            vector<string> temp=left;
            char t=letter[i];
            for(int j=0;j<temp.size();j++)
            {
                temp[j]+=t;
                res.push_back(temp[j]);
            }
        }
        return res;
    }
    string getLetters(char digit)  
    {  
        switch(digit)  
        {  
            case '2':  
                return "abc";  
            case '3':  
                return "def";  
            case '4':  
                return "ghi";  
            case '5':  
                return "jkl";  
            case '6':  
                return "mno";  
            case '7':  
                return "pqrs";  
            case '8':  
                return "tuv";  
            case '9':  
                return "wxyz";  
            case '0':  
                return " ";  
            default:  
                return "";  
    	}
    }
};
class Solution1 {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res(1,"");
        if(digits.size()==0)
        {
            return res;
        }
        for(int k=0;k<digits.size();k++)
        {
        	vector<string> temp=res;
        	res.clear();
        	char t=digits[k];
        	string letters=getLetters(t);
        	for(int i=0;i<letters.size();i++)
        	{
        		char c=letters[i];
        		for(int j=0;j<temp.size();j++)
        		{
        			string str=temp[j]+c;
        			res.push_back(str);
        		}
        	}
        }
        return res;
    }
    string getLetters(char digit)  
    {  
        switch(digit)  
        {  
            case '2':  
                return "abc";  
            case '3':  
                return "def";  
            case '4':  
                return "ghi";  
            case '5':  
                return "jkl";  
            case '6':  
                return "mno";  
            case '7':  
                return "pqrs";  
            case '8':  
                return "tuv";  
            case '9':  
                return "wxyz";  
            case '0':  
                return " ";  
            default:  
                return "";  
    	}
    }
};
int main()
{
	Solution1 s;
	vector<string> res;
	res=s.letterCombinations("23");
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
	cout<<endl;
	cin.get();
	return 0;
} 
