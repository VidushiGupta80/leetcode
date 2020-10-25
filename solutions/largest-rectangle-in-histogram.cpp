//Largest Rectangle in Histogram -> 05/27/2020 11:44
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        if(len == 0)
            return 0;
        else if(len == 1)
            return heights[0];
        // else if(len == 2)
        // {
        //     if(heights[0] < heights[1])
        //         return 2 * heights[0];
        //     return 2 * heights[1];
        // }
        vector<int> left(len), right(len);
        stack <int> stk1;
        int area = 0;
        int i;
        stk1.push(0);
        
        for(i = 1; i < len; i++)
        {
            while(!stk1.empty() && heights[i] < heights[stk1.top()] )
            {
                right[stk1.top()] = i;
                stk1.pop();
            }
            stk1.push(i);
        }
        while(!stk1.empty())
          {
            right[stk1.top()] = len;
            stk1.pop();
          }
        stk1.push(len - 1);
        for(i = len - 2; i >= 0; i--)
         {
            while(!stk1.empty() && heights[i] < heights[stk1.top()] )
            {
                left[stk1.top()] = i;
                stk1.pop();
            }
            stk1.push(i);
        }
        while(!stk1.empty())
          {
            left[stk1.top()] = -1;
            stk1.pop();
          }
         
                  
        for(i = 0; i < len; i++)
          {
              int width = right[i] - left[i] - 1;
              area = max(area, heights[i] * width);
          }
        return area;
    }
};
