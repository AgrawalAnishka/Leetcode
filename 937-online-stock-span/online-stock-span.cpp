class StockSpanner {
public:
    stack<pair<int,int>> s;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int temp =1;

        while(!s.empty() && s.top().first <=price ){
            auto [node, ctr] = s.top();
            s.pop();
            temp+= ctr;

        } 
        s.push({price ,  temp});
        return temp  ; 
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */