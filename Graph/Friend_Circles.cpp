// https://leetcode.com/problems/friend-circles/submissions/
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

class disjointset
{
public:
  vector<int> parent, rank;
  int cnt_comp; // total components

  disjointset(int n)
  {
    parent.resize(n);
    rank.resize(n);
    cnt_comp = n;
      
    for (int i = 0; i < n; i++)
    {
      parent[i] = i;
      rank[i] = 1;
    }
  }
  void join(int a, int b)
  {
    a = find(a);
    b = find(b);
    if (a != b)
    {
      cnt_comp--;
    }
    if (a == b) return;
    
      if (rank[a] == rank[b]) rank[a]++;
    
      if (rank[a] > rank[b])
    {
      parent[b] = a;

    }
      else if (rank[a] < rank[b])
    {
      parent[a] = b;
    }
  }
  int find(int a)
  {
    return a == parent[a] ? a : parent[a] = find(parent[a]);
  }
  bool check(int a, int b)
  {
    return find(a) == find(b);
  }

};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& arr) {
        
        int n = arr.size();
        disjointset dsu(n);
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(arr[i][j] == 1) dsu.join(i,j);
            }
        }
        
        return dsu.cnt_comp;
    }
};
