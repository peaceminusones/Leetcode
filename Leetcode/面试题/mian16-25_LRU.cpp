#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

// class LRUCache
// {
//     list<pair<int, int>> cache;
//     unordered_map<int, list<pair<int, int>>::iterator> map;
//     int capacity;

// public:
//     LRUCache(int x) : capacity(x) {}

//     int get(int key)
//     {
//         if (map.find(key) != map.end())
//         {
//             int val = (*map[key]).second;
//             cache.erase(map[key]);
//             cache.push_back({key, val});
//             map[key] = --cache.end();
//             return val;
//         }
//         return -1;
//     }

//     void put(int key, int val)
//     {
//         if (map.find(key) != map.end())
//         {
//             cache.erase(map[key]);
//             cache.push_back({key, val});
//             map[key] = --cache.end();
//         }
//         else
//         {
//             if (cache.size() >= capacity)
//             {
//                 map.erase(cache.front().first);
//                 cache.pop_front();
//             }

//             cache.push_back({key, val});
//             map[key] = --cache.end();
//         }
//     }
// };

class LRUCache
{
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (map.find(key) != map.end())
        {
            auto it = map[key];
            int val = (*it).second;
            cache.erase(it);
            cache.push_front({key, val});
            map[key] = cache.begin();
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (map.find(key) != map.end())
        {
            auto it = map[key];
            cache.erase(it);
            cache.push_front({key, value});
            map[key] = cache.begin();
        }
        else
        {
            if (cache.size() >= capacity)
            {
                map.erase((*(--cache.end())).first);
                cache.pop_back();
            }

            cache.push_front({key, value});
            map[key] = cache.begin();
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
    cache.put(4, 4);
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;

    return 0;
}