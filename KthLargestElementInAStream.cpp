#include <bits/stdc++.h> 
class Kthlargest {
    priority_queue<int, vector<int>, greater<int> > pq;
    int len;
public:
    Kthlargest(int k, vector<int> &arr) {
       len = k;
       for(int i=0;i<arr.size();i++){
           pq.push(arr[i]);
           if(pq.size()>k){
               pq.pop();
           }
       }
    }

    void add(int num) {
        pq.push(num);
        if(pq.size()>len){
            pq.pop();
        }
    }

    int getKthLargest() { 
       return pq.top();
    }

};
