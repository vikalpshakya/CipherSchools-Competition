// TIME COMPLEXITY : O(N), SPACE COMPLEXITY: O(N) 
class Solution{
#define ll long long
    vector<ll> nextSmall(ll arr[], int n){
        stack<ll>s;
        s.push(-1);
        vector<ll>ans(n);
        for(int i = n-1; i >= 0; i--){
            ll curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<ll>prevSmall(ll arr[] , int n){
        stack<ll>s;
        s.push(-1);
        vector<ll>ans(n);
        for(int i = 0; i < n; i++){
            ll curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
                s.pop();
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
 
    public:
    
    long long getMaxArea(long long arr[], int n){
        
        vector<ll>next(n);
        next = nextSmall(arr, n);
        
        vector<ll>prev(n);
        prev = prevSmall(arr,n);
        
        ll area = INT_MIN;
        for(int i = 0; i < n; i++){
            ll length = arr[i];
            if(next[i] == -1)
                next[i] = n;
            ll breath = next[i] - prev[i] -1;
            ll newArea = length * breath;
            area = max(area,newArea); 
        }
        return area;
    }
};
