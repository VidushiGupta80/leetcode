class Solution {
// bool sortCol(pair<int, int> x, pair<int, int> y)
//     return x.second < y.second;
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king)     {
        vector<vector<int> > res;
        vector<pair<int, int> > row;
        vector<pair<int, int> > column;
        vector<pair<int, int> > sum;
        vector<pair<int, int> > diff;
        int i = king[0];
        int j = king[1];
        for(int k = 0; k < queens.size(); k++)
        {
            if(queens[k][0] == i)
                row.push_back({queens[k][0], queens[k][1]});
            else if(queens[k][1] == j)
                column.push_back({queens[k][0], queens[k][1]});
            else if(queens[k][0] - queens[k][1] == i - j)
                diff.push_back({queens[k][0], queens[k][1]});
            else if(queens[k][0] + queens[k][1] == i + j)
                sum.push_back({queens[k][0], queens[k][1]});
        }
        // sort(row.begin(), row.end(), sortCol);
        // sort(column.begin(), column.end());
        // sort(diff.begin(), diff.end());
        // sort(sum.begin(), sum.end());
        int left = 8, right = 8, up = 8, down = 8, ne = 8, nw = 8, se = 8, sw = 8; 
        pair<int, int> l, r, u, d, NE, NW, SE, SW;
        for(int k = 0; k < row.size(); k++)
        {
            if(j - row[k].second < left && j - row[k].second > 0)
            {
                left = j - row[k].second;
                l = {row[k].first, row[k].second};
            }
            if(row[k].second - j < right && row[k].second - j > 0)
            {
                right = row[k].second- j;
                r = {row[k].first, row[k].second};
            }
        }
        for(int k = 0; k < column.size(); k++)
        {
            if(i - column[k].first < up && i - column[k].first > 0)
            {
                up = i - column[k].first;
                u = {column[k].first, column[k].second};
            }
            if(column[k].first - i < down && column[k].first - i > 0)
            {
                down = column[k].first - i;
                d = {column[k].first, column[k].second};
            }
        }
        for(int k = 0; k < diff.size(); k++)
        {
            if(i - diff[k].first < ne && i - diff[k].first > 0)
            {
                ne = i - diff[k].first;
                NE = {diff[k].first, diff[k].second};
            }
            if(diff[k].first - i < sw && diff[k].first - i > 0)
            {
                sw = diff[k].first - i;
                SW = {diff[k].first, diff[k].second};
            }
        }
        for(int k = 0; k < sum.size(); k++)
        {
            if(i - sum[k].first < nw && i - sum[k].first > 0)
            {
                nw = i - sum[k].first;
                NW = {sum[k].first, sum[k].second};
            }
            if(sum[k].first - i < se && sum[k].first  - i > 0)
            {
                se = sum[k].first  - i;
                SE = {sum[k].first , sum[k].second};
            }
        }
        if(left != 8)
        {
            vector<int> temp(2);
            temp[0] = l.first;
            temp[1] = l.second;
            res.push_back(temp);
        }
        if(right != 8)
        {
            vector<int> temp(2);
            temp[0] = r.first;
            temp[1] = r.second;
            res.push_back(temp);
        }
        if(up != 8)
        {
            vector<int> temp(2);
            temp[0] = u.first;
            temp[1] = u.second;
            res.push_back(temp);
        }
        if(down != 8)
        {
            vector<int> temp(2);
            temp[0] = d.first;
            temp[1] = d.second;
            res.push_back(temp);
        }
        if(ne != 8)
        {
            vector<int> temp(2);
            temp[0] = NE.first;
            temp[1] = NE.second;
            res.push_back(temp);
        }
        if(nw != 8)
        {
            vector<int> temp(2);
            temp[0] = NW.first;
            temp[1] = NW.second;
            res.push_back(temp);
        }
        if(se != 8)
        {
            vector<int> temp(2);
            temp[0] = SE.first;
            temp[1] = SE.second;
            res.push_back(temp);
        }
        if(sw != 8)
        {
            vector<int> temp(2);
            temp[0] = SW.first;
            temp[1] = SW.second;
            res.push_back(temp);
        }
        return res;
    }
};