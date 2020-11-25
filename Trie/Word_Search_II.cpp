// https://leetcode.com/submissions/detail/423573360/

#define pb push_back

class trienode
{

public:
    char data;
    unordered_map<char, trienode *> children;
    bool isTerminal;
    int child_count;

    trienode(char data)
    {
        this->data = data;
        isTerminal = false;
        child_count = 0;
    }
};

class trie
{

public:
    trienode *root;

    trie()
    {
        root = new trienode('\0');
    }

    void insert(string word)
    {

        int n = word.size();
        if (n == 0)
            return;

        trienode *child = root;

        for (int i = 0; i < n; i++)
        {
            if (child->children.count(word[i]) == 0)
            {
                trienode *temp = new trienode(word[i]);
                child->children[word[i]] = temp; // connection
                child->child_count++;
            }
            child = child->children[word[i]];
        }
        child->isTerminal = true;
    }

    bool search(string word)
    {

        int n = word.size();

        if (!n)
            return false; // no empty string can be inserted

        trienode *child = root;

        for (int i = 0; i < n; i++)
        {
            if (child->children.count(word[i]) == 0)
                return false; // word not found

            child = child->children[word[i]];
        }
        
        return child->isTerminal;
    }

    ~trie()
    {
        delete root;
    }
};




class Solution {
public:

    int m,n;
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    vector<string> res;
    
    
    void dfs(int x, int y, string str, vector<vector<char>>& board, 
            trienode *t,vector<vector<bool>> &visited){
        
        if(t->isTerminal){
            res.pb(str);
            t->isTerminal = false; // mark it false to prevent redundant calls
        }        
        
        for(int i = 0; i<4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx >= 0 && nx < m && ny >=0 && ny < n &&
               !visited[nx][ny] && t->children.find(board[nx][ny]) != t->children.end()){
                
                visited[nx][ny] = 1;
                str.pb(board[nx][ny]);
                dfs(nx,ny,str,board,t->children[board[nx][ny]],visited);
                str.pop_back(); // backtrack
                visited[nx][ny] = 0; // backtrack
            }
        }
    }

    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
         m = board.size();
         n = board[0].size();
        
        int sz = words.size();
        trie dict;
        for(int i = 0; i<sz; i++) dict.insert(words[i]); // insert into trie
        
        res.clear();  // empty the vector
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        
        // LOGIC
        // start dfs from each point and check for possible string
        
        
        string curr;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(dict.root->children.find(board[i][j]) != dict.root->children.end()){
                    curr.pb(board[i][j]);
                    visited[i][j] = 1; // mark visited
                    dfs(i,j,curr,board,dict.root->children[board[i][j]],visited);
                    curr.pop_back(); // backtrack
                    visited[i][j] = 0; // backtrack
                }
            }
        }
        return res;   
    }
};
