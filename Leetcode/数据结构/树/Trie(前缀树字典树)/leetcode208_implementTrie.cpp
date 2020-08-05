#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TrieNode
{
    bool isLeaf;
    TrieNode *child[26];
};

class TrieTree
{
    TrieNode *root;

public:
    TrieTree()
    {
        root = new TrieNode();
    }

    // 从根节点的子节点开始，如word的第一个字符进行匹配，一直匹配到前缀链上没有对应的字符
    // 创建新的节点，知道word最后一个节点，并把最后一个节点的isleaf置为true
    void insert(string word)
    {
        if (word.empty())
            return;
        TrieNode *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a';
            if (node->child[index] == NULL)
                node->child[index] = new TrieNode();

            node = node->child[index];
        }
        node->isLeaf = true;
    }

    // 从根节点的子节点开始，一直向下匹配
    bool search(string word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a';
            node = node->child[index];
            if (node == NULL)
                return false;
        }
        return node->isLeaf;
    }

    bool startWtith(string prefix)
    {
        TrieNode *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            int index = prefix[i] - 'a';
            node = node->child[index];
            if (node == NULL)
                return false;
        }
        return true;
    }
};

int main()
{
    TrieTree *trie = new TrieTree();
    trie->insert("apple");
    cout << trie->search("apple") << endl;
    cout << trie->search("app") << endl;
    cout << trie->startWtith("app") << endl;
    trie->insert("app");
    cout << trie->search("app") << endl;

    return 0;
}