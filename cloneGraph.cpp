/*
Problem: Clone Graph
Method: 
Author: 'gq' 
*/
#include<iostream>
#include<string> 
using namespace std;
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        map<int, UndirectedGraphNode*> marks;
        return dfs(node,marks);
    }
    UndirectedGraphNode *dfs(UndirectedGraphNode *node,map<int,UndirectedGraphNode*> &marks){
        if(NULL==node)
            return NULL;
        UndirectedGraphNode *newNode=new UndirectedGraphNode(node->label);
        marks[newNode->label]=newNode;
        for(int i=0;i<node->neighbors.size();i++){
            if(0<marks.count(node->neighbors[i]->label)){
                newNode->neighbors.push_back(marks[node->neighbors[i]->label]);
            }
            else{
                UndirectedGraphNode *p=dfs(node->neighbors[i],marks);
                if(p){
                    newNode->neighbors.push_back(p);
                }
            }
        }
        return newNode;
    }
};
