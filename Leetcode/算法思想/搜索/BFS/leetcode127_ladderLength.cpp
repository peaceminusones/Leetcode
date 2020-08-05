#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    /**
     * 【广度优先搜索】BFS ===========================================================================
    */
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        // 把起始单词放入list中
        wordList.push_back(beginWord);

        // 如果endWorld不在wordList中，则返回0
        vector<string>::iterator it = find(wordList.begin(), wordList.end(), endWord);
        if (it == wordList.end())
            return 0;

        // 创建无向无权图，graph[str]中存储了与str只差1个字母的单词
        unordered_map<string, vector<string>> graph;
        build_graph(wordList, graph);

        // 一个marked数组，如果没被访问过，则为false，被访问过为true
        unordered_map<string, bool> marked;
        for (int i = 0; i < wordList.size(); i++)
            marked[wordList[i]] = false;
        marked[beginWord] = true;

        // 创建队列
        queue<string> que;
        que.push(beginWord);

        int level = 0;
        while (!que.empty())
        {
            level++;
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                string cur = que.front();
                que.pop();
                vector<string> neighbors = graph[cur]; // 拿出与cur只差1个字母的单词
                for (int j = 0; j < neighbors.size(); j++)
                {
                    if (marked[neighbors[j]] == true) // 如果被访问过了，则跳过
                        continue;
                    if (neighbors[j] == endWord) // 如果刚好是endword，则返回
                        return level + 1;

                    marked[neighbors[j]] = true;
                    que.push(neighbors[j]);
                }
            }
        }
        return 0;
    }

    /*
     * 和上面思路一样，只是少了创建无权图，但是超时了
     * 超时 ============================================================================
    */
    int ladderLength_1(string beginWord, string endWord, vector<string> &wordList)
    {
        // 把起始单词放入list中
        wordList.push_back(beginWord);

        // 如果endWorld不在wordList中，则返回0
        vector<string>::iterator it = find(wordList.begin(), wordList.end(), endWord);
        if (it == wordList.end())
            return 0;

        // 一个marked数组，没访问过的为false，访问过的为true
        unordered_map<string, bool> marked;
        for (int i = 0; i < wordList.size(); i++)
            marked[wordList[i]] = false;
        marked[beginWord] = true;

        // 创建队列
        queue<string> que;
        que.push(beginWord);

        int level = 0;
        while (!que.empty())
        {
            level++;
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                string cur = que.front();
                que.pop();
                for (int j = 0; j < wordList.size(); j++) // 和上面的不同在这里
                {
                    if (marked[wordList[j]] == true || similarity(cur, wordList[j]) == false)
                        continue;
                    if (wordList[j] == endWord)
                        return level + 1;

                    marked[wordList[j]] = true;
                    que.push(wordList[j]);
                }
            }
        }
        return 0;
    }

    // 判断两个string是否只有一个字母不同
    int similarity(string &a, string &b)
    {
        int count = 0;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size())
        {
            if (a[i++] != b[j++])
                count++;
            if (count > 1)
                return false;
        }
        return true;
    }

    // 创建无向无权图
    void build_graph(vector<string> &wordList, unordered_map<string, vector<string>> &graph)
    {
        for (int i = 0; i < wordList.size(); i++)
        {
            for (int j = i + 1; j < wordList.size(); j++)
            {
                if (similarity(wordList[i], wordList[j]))
                {
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }
    }

    /***
     * 双向bfs ====================================================================================
     * 一个que1存储从begin开始的遍历结果
     * 一个que2存储从end开始的遍历结果
     * 
     * 结束条件：找到一个单词被两边搜索都访问过了
     */
    int ladderLength_double(string beginWord, string endWord, vector<string> &wordList)
    {
        // 把起始单词放入list中
        wordList.push_back(beginWord);

        // 如果endWorld不在wordList中，则返回0
        vector<string>::iterator it = find(wordList.begin(), wordList.end(), endWord);
        if (it == wordList.end())
            return 0;

        // 两个marked数组
        unordered_map<string, bool> marked1;
        marked1[beginWord] = true;
        unordered_map<string, bool> marked2;
        marked2[endWord] = true;

        // 创建两个队列
        queue<string> que1;
        que1.push(beginWord);
        queue<string> que2;
        que2.push(endWord);

        int level = 0;
        while (!que1.empty() && !que2.empty())
        {
            level++;
            if (que1.size() > que2.size()) // 小tips，每次从节点数更少的一端遍历
            {
                swap(que1, que2);
                swap(marked1, marked2);
            }
            int size = que1.size();
            for (int i = 0; i < size; i++)
            {
                string cur = que1.front();
                que1.pop();
                for (int j = 0; j < wordList.size(); j++)
                {
                    // 如果wordlist[j]已经被访问过了
                    if (marked1.find(wordList[j]) != marked1.end())
                        continue;
                    // 如果cur与wordList[j]相差的字母不止一个
                    if (similarity(cur, wordList[j]) == false)
                        continue;
                    // 如果wordlist[j]已经被另一部分访问过了，则直接返回
                    if (marked2.find(wordList[j]) != marked2.end())
                        return level + 1;
                    // wordList[j]与cur相差字母只有一个，且均没有被两部分访问过
                    que1.push(wordList[j]);
                    marked1[wordList[j]] = true;
                }
            }
        }
        return 0;
    }

    // 判断两个string是否只有一个字母不同
    int similarity(string &a, string &b)
    {
        int count = 0;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size())
        {
            if (a[i++] != b[j++])
                count++;
            if (count > 1)
                return false;
        }
        return true;
    }
};

int main()
{
    string beginWorld;
    cin >> beginWorld;
    string endWorld;
    cin >> endWorld;
    vector<string> wordList;
    string item;
    cin >> item;
    while (item != "#")
    {
        wordList.push_back(item);
        cin >> item;
    }

    Solution s;
    int res = s.ladderLength_double(beginWorld, endWorld, wordList);
    cout << res << endl;

    return 0;
}