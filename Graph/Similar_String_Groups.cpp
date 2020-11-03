// https://leetcode.com/problems/similar-string-groups/

#define pb push_back


class disjointset
{
public:
  vector<int> parent, rank, cnt;
  int cnt_comp; // total components

  disjointset(int n)
  {
    parent.resize(n);
    rank.resize(n);
    cnt_comp = n;
    for (int i = 0; i <n; i++)
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
    if (a == b)
      return;
    if (rank[a] == rank[b])
      rank[a]++;
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


bool isSimilar(string &a, string &b){
    int diff = 0;
    for(int i = 0; i<a.size(); i++){
        if(a[i]!= b[i]) diff++;
        if(diff > 2) return false;
    }
    return true;
}



class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        
        vector<string> arr;
        unordered_map<string,int> hash;
        for(int i = 0; i<A.size(); i++){
            if(hash.count(A[i]) == 0){
                arr.pb(A[i]);
                hash[A[i]] = i;
            }
        }
    
        int n = arr.size(); // number of  anagrams
        // LOGIC
        // max size of a word can be (10 - 10000)
        disjointset dsu(n);
        
        // if(arr[0].size() >= n){ // O(N^2 W) Approach
        
        for(int i = 0; i<n-1;i++){ // 1st word
            for(int j = i+1; j<n; j++){ //2nd word
                if(isSimilar(arr[i],arr[j])) dsu.join(i,j);
            }
        }        
        
   // }
        
         /*       else { // O(W^3 N) Approach
        
        for(int i = 0; i<n; i++){ // each string
            int w = arr[i].size();
            for(int j = 0; j<w-1; j++){ // start index of arr[i]
                for(int z = j+1; z<w;z++){ // index being swapped with
                    string temp = arr[i];
                    swap(temp[j],temp[z]);
                    if(hash.count(temp)) dsu.join(hash[temp],i); // join components
                }
            }
        }
            
        }*/
        
        return dsu.cnt_comp;
        
    }
};
