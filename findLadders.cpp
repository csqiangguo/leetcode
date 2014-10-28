/*
Problem: Word Ladder II
Method:  
Author: 'gq' 
*/
#include<iostream>
#include<queue>
#include<unorder_set>
using namespace std;
class Solution {
public:
    unordered_multimap<string, string> path_map;
    vector<vector<string> > res;
    unordered_set<string> visited;

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        dict.insert(start);
        dict.insert(end);
        dict.erase(start);
        path_map.clear();

        unordered_set<string> last_layer, curr_layer;
        curr_layer.insert(start);

        while (!last_layer.empty() || !curr_layer.empty())
        {

            for (unordered_set<string>::iterator cit = last_layer.begin(); cit != last_layer.end(); ++cit)
            {
                dict.erase(*cit);
            }
            last_layer.clear();

            for (unordered_set<string>::iterator cit = curr_layer.begin(); cit != curr_layer.end(); ++cit)
            {
                string cur = *cit;

                for (int i = 0; i < cur.size(); ++i)
                {
                    string handle_str = cur;
                    int stop = handle_str[i] - 'a';

                    for (int j = (stop+1)%26; j != stop; j = (j+1)%26)
                    {
                        handle_str[i] = 'a' + j;

                        if (dict.find(handle_str) != dict.end())
                        {
                            last_layer.insert(handle_str);
                            path_map.insert(pair<string, string>(handle_str, cur));
                        }
                    }
                }
            }

            if (last_layer.count(end))
                break;
            curr_layer = last_layer;
        }

        vector<string> path;

        if (!path_map.empty())
            get_path(end, start, path);
        return res;
    }

    void get_path(string curr, string start, vector<string> path)
    {
        if (curr == start)
        {
            path.insert(path.begin(), start);
            res.push_back(path);
            //path.clear();
            return;
        }

        unordered_multimap<string, string>::iterator it;

        pair<unordered_multimap<string, string>::iterator, unordered_multimap<string, string>::iterator> itrangexx = path_map.equal_rang(curr);
        it = itrangexx.first;
        while (true)
        {            
            path.insert(path.begin(), curr);

            if (it != path_map.end() && it != itrangexx.second && visited.find(it->second) != visited.end())
            {    
                ++it;

            }

            if (it == itrangexx.second || it == path_map.end())
                break;
            else
            {
                string prev;

                prev = it->second;
                visited.insert(prev);

                get_path(prev, start, path);

                visited.erase(prev);
                if (!path.empty())
                    path.erase(path.begin());
            }
            ++it;
        }
    }
};
