//Minimum Index Sum of Two Lists -> 05/01/2020 12:37
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> match;
        vector<string> answer;
        int min = list1.size() + list2.size() + 1;
        for(int i = 0; i < list1.size(); i++)
        {
            match.insert(make_pair(list1[i], i));
        }
        for(int i = 0; i < list2.size(); i++)
        {
            if(match.count(list2[i]) > 0)
            {
                int sum = i + match[list2[i]];
                if(sum < min)
                {
                    min = sum;
                    answer.clear();
                    answer.push_back(list2[i]);
                }
                else if(sum == min)
                {
                    answer.push_back(list2[i]);
                }
            }
        }
        return answer;
    }
};
