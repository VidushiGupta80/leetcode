//Distribute Candies to People -> 08/17/2020 22:26

int roots(float a, float b, float c)
{
    // cout << a << " " << b << " " << c << endl;
    float x1 = (-1.00 * b + sqrt(b * b - 4.00 * a * c)) / (2.00 * a);
    float x2 = (-1.00 * b - sqrt(b * b - 4.00 * a * c)) / (2.00 * a);
    // cout << x1 << " " << x2 << endl;
    return (int)max(x1, x2);
}
class Solution {
    
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int n = num_people;
        int c = candies;
        int x = roots((float)(n * n), (float)n, (float)-2* c);
        // cout << x;
        int remaining = c - (x * n * (x * n + 1)) / 2;
        vector<int> ans(n);
        for(int i = 0; i < n; i++)
        {
            ans[i] = (i + 1) * x + ( n * (x - 1) * x) / 2;
        }
        for(int i = 0; i < n && remaining > 0; i++)
        {
            ans[i] += min(x * n + i + 1, remaining);
            remaining -= x * n + i + 1;
        }
        return ans;
    }
};