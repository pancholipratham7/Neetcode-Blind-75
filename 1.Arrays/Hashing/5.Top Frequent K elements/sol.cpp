#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        
        auto it=freq.begin();
        while(minHeap.size()<k){
            int a=(*it).second;
            int b=(*it).first;
            minHeap.push({a,b});
            it++;
        }
        
        for(auto x=it;x!=freq.end();x++){
            int a=(*x).first;
            int b=(*x).second;
            if(minHeap.top().first<b){
                minHeap.pop();
                minHeap.push({b,a});
            }
        }
       
        while(minHeap.size()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }