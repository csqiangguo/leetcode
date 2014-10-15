/*
Problem: LRU Cache 
Method:  
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(0<mp.count(key))
        {
            moveToEnd(key);
            return mp[key];
        }
        return -1;
    }
    
    void set(int key, int value) {
        if(0<mp.count(key)){
            mp[key]=value;
            moveToEnd(key);
        }
        else if(mp.size()<capacity)
        {
            mp[key]=value;
            l.push_back(key);
            pos[key]=--l.end();
        }
        else
        {
            int delKey=l.front();
            mp.erase(delKey);
            pos.erase(delKey);
            l.pop_front();
            mp[key]=value;
            l.push_back(key);
            pos[key]=--l.end();
        }
    }
    void moveToEnd(int key)
    {
        list<int>::iterator iter=pos[key];
        l.erase(iter);
        l.push_back(key);
        pos[key]=--l.end();
    }
private:
    map<int,int> mp;
    map<int,list<int>::iterator> pos;
    list<int> l;
    int capacity;
};
