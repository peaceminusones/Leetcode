unordered_map<int, int> count;
        for (auto si : s)
            count[si]++;

        int single = 0;
        int res = 0;
        for (auto c : count)
        {
            if (c.second % 2 == 0)
            {
                res += c.second;
            }
            else
            {
                single = max(single, c.second);
            }
        }
        return res + single;