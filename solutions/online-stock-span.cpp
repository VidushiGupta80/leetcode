class StockSpanner {
    stack<pair<int, int> > myStk;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int ans = 1;
        while(!myStk.empty() && myStk.top().first <= price){
            ans += myStk.top().second;
            myStk.pop();
        }
        myStk.push({price, ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */