#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache
{
    list<pair<int, int>> List;                              // 用于存储key和value
    unordered_map<int, list<pair<int, int>>::iterator> map; // 用于存储key和该值在链表中的位置
    int capacity;                                           // LRU缓存的大小

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key)
    {
        // 如果key在map中存储有索引
        if (map.find(key) != map.end())
        {
            // 则根据索引，可以在链表中取出需要的值
            int res = (*map[key]).second;
            // 因为这个数据用到了，所以要重新放到队尾
            List.erase(map[key]);
            List.push_back({key, res});
            map[key] = (--List.end());
            // 最后返回结果
            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // 如果当前key已经存在了
        if (map.find(key) != map.end())
        {
            // map[key]表示链表中的位置
            // 删除这个旧位置，插入到链表结尾这个新位置
            List.erase(map[key]);
            List.push_back({key, value});
            map[key] = (--List.end());
        }
        else // 如果key不存在，则需要添加
        {
            // 如果List大小已经到达了容量的上线
            if (List.size() >= capacity)
            {
                // 先删除链表头，和相应map中存储的索引
                map.erase(List.front().first);
                List.pop_front();
            }
            // 然后把新信息插入到List中，并在map中存储索引
            List.push_back({key, value});
            map[key] = (--List.end());
        }
    }
};

int main()
{
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    cout << cache.get(2) << endl;

    return 0;
}