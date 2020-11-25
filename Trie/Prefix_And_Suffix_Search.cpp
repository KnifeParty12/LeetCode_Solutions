// https://leetcode.com/problems/prefix-and-suffix-search/submissions/

#define pb push_back

class trienode
{

public:
    char data;
    int index;
    unordered_map<char, trienode *> children;
    bool isTerminal;
    int child_count;

    trienode(char data)
    {
        this->data = data;
        isTerminal = false;
        child_count = 0;
        int index = -1;
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

    void insert(string word, int ind)
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
            child->index = ind;
            child = child->children[word[i]];
        }
        child->isTerminal = true;
        child->index = ind;
        //   cout<<"Done\n";
    }

    int search(string word)
    {

        int n = word.size();

        if (!n)
            return -1; // no empty string can be inserted

        trienode *child = root;

        for (int i = 0; i < n; i++)
        {
            if (child->children.count(word[i]) == 0)
                return -1; // word not found

            child = child->children[word[i]];
        }
        return child->index;
    }

    ~trie()
    {
        delete root;
    }
};


class WordFilter {
public:
    
    trie dict;
    
    WordFilter(vector<string>& words) {
        
        int n = words.size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<=words[i].size(); j++){ // length of  suffix
                string suffix = words[i].substr(words[i].size() - j);
                string temp = suffix + '#' + words[i];
                //cout<<temp<<endl;
                dict.insert(temp,i);
            }
        }
        
    }
    
    int f(string prefix, string suffix) {
        
        // LOGIC
        // prefix and suffix can overlap
        // say we got apple -> #apple , e#apple , le#apple, ple#apple, pple#apple,                  apple#apple
        
        string str = suffix + '#' + prefix;
        return dict.search(str);
        
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
