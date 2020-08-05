#include <iostream>
using namespace std;

struct TrieNode
{
    TrieNode *child[26];
    int val;
    int end;
};

class MapSum
{
    TrieNode *root;

public:
    MapSum()
    {
        root = new TrieNode();
    }

    void insert(string key, int val)
    {
        TrieNode *node = root;
        for (char ch : key)
        {
            if (node->child[ch - 'a'] == NULL)
                node->child[ch - 'a'] = new TrieNode();
            node = node->child[ch - 'a'];
        }
        node->val = val;
        node->end = true;
    }

    int sum(string prefix)
    {
        TrieNode *node = root;
        for (char ch : prefix) // 找到前缀字符串的最后一个节点
        {
            if (node->child[ch - 'a'] == NULL)
                return 0;
            node = node->child[ch - 'a'];
        }
        return dfs(node);
    }

    int dfs(TrieNode *node)
    {
        if (node == NULL) // 如果当前访问的TrieNode为空，则直接返回0
            return 0;

        int res = 0;
        if (node->end) // 若当前节点不为空且isEnd，则加上其值
            res += node->val;
        for (TrieNode *cur : node->child) // 再遍历当前节点的child数组中所有的MapSum
        {
            res += dfs(cur);
        }
        return res;
    }
};

int main()
{
    MapSum *map = new MapSum();
    map->insert("apple", 3);
    cout << map->sum("ap") << endl;
    map->insert("app", 2);
    cout << map->sum("ap") << endl;

    return 0;
}