/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

#define MAX 2005
#define pb push_back

vector<int> adj[MAX];

class Solution
{
public:
    int getImportance(vector<Employee *> emp, int id)
    {

        map<int, Employee *> hash;
        for (auto it : emp)
            hash[it->id] = it;

        int ans = 0;
        set<int> pq;
        pq.insert(id);

        while (!pq.empty())
        {
            int curr = *pq.begin();
            pq.erase(pq.begin());
            ans += hash[curr]->importance;

            for (auto it : hash[curr]->subordinates)
                pq.insert(it);
        }
        return ans;
    }
};