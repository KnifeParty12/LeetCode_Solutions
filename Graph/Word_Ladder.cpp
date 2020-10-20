//https://leetcode.com/problems/word-ladder/

class Solution {
public:
    
    bool diffone(string s, string t){
        if(s.length()!= t.length()) return false;
        int cnt = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i] != t[i])cnt++;
        }
        return (cnt == 1) ? true : false;
    }
    
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
     
        // Logic whatya thinking son
        //Seems BFS but how to connect -> 1 LETTER DIFF but should i check again and again
        int n = wordList.size();
        if(n == 0) return 0;
        bool not_present = false;
        unordered_map<string,int> v1;
        unordered_map<string,int> v2;
        for(int i = 0; i<n; i++){
            if(wordList[i] == endWord) not_present = true;
        }
        if(!not_present) return 0;
        v1[beginWord] = 1;
        v2[endWord] = 1;
        
        //BFS logic
        queue<pair<string,int>> pq_1;
        queue<pair<string,int>> pq_2;
        pq_1.push({beginWord,1});
        pq_2.push({endWord,1});
        while(!pq_1.empty() && !pq_2.empty()){
            string s1 = pq_1.front().first;
            int d1 = pq_1.front().second;
            string s2 = pq_2.front().first;
            int d2 = pq_2.front().second;
            pq_1.pop();
            pq_2.pop();
            // pq_1
            for(int i = 0; i<n; i++){
                if(v1.count(wordList[i]) == 0 && diffone(s1,wordList[i])){
                    pq_1.push({wordList[i],d1+1});
                    v1[wordList[i]] = d1+1;
                    
                    if(wordList[i] == endWord) return v1[wordList[i]];
                    
                    if(v2.count(wordList[i])) return d1 + v2[wordList[i]];
                }
            }
            //pq_2
            for(int i = 0; i<n; i++){
                if(v2.count(wordList[i]) == 0 && diffone(s2,wordList[i])){
                    pq_2.push({wordList[i],d2+1});
                    v2[wordList[i]] = d2+1;
                    
                    if(wordList[i] == beginWord) return v2[wordList[i]];
                    if(v1.count(wordList[i])) return d2 + v1[wordList[i]];
                }
            }
        }
        return 0;
    }
};
