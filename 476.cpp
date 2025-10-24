class Solution {
  public:


bool isPossible(vector<int>& arr, int k) {
    
    auto comp = [](pair<int,int> a, pair<int,int> b) {
        if(a.first == b.first)
        
        // smaller length has higher priority
            return a.second > b.second; 
            
        // smaller number has higher priority
        return a.first > b.first;       
    };
    
    // Min-heap stores pairs:
    //{number, length of subsequence ending with this number}
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);

    int i = 0;
    while(i < arr.size()) {
        if(pq.empty()) {
            
            // If heap is empty, start a new subsequence
            pq.push({arr[i], 1});
            i++;
        }
        else {
            auto top = pq.top();
            if(arr[i] == top.first) {
                
                // If current number same as top, 
                //start a new subsequence
                pq.push({arr[i], 1});
                i++;
            }
            else if(arr[i] == top.first + 1) {
                
                // If current number is consecutive, 
                //extend the subsequence
                pq.pop();
                pq.push({arr[i], top.second + 1});
                i++;
            }
            else {
                
                // If current number is not 
                //consecutive, check if the top subsequence is valid
                if(top.second < k) return false;
                pq.pop();
            }
        }
    }

    // After processing all numbers, 
    //ensure all subsequences have length >= k
    while(!pq.empty()) {
        if(pq.top().second < k) return false;
        pq.pop();
    }

    return true;
}


};
