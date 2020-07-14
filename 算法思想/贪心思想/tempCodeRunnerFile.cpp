int cnt = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] > nums[i])
            {
                if (i + 1 < nums.size() && i - 2 >= 0 && nums[i + 1] < nums[i - 1] && nums[i - 2] > nums[i] && i - 2 >= 0)
                    return false;
                cnt++;
            }
        }
        return cnt <= 1;