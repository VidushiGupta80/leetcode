
bool sortCol2(vector<int>& x, vector<int>& y)
{
    return x[1] < y[1];
}
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {    
        int start = 0;
        sort(courses.begin(), courses.end(), sortCol2);
        priority_queue<int> duration;
        for(int i = 0; i < courses.size(); i++)
        {
            start += courses[i][0];
            duration.push(courses[i][0]);
            if(start > courses[i][1])
            {
                start -= duration.top();
                duration.pop();
            }
        }
        return duration.size();
    }
};
