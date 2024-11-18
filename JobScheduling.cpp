class Solution {
  public:
    static bool comp(Job a, Job b) {
        return a.profit > b.profit;
    }

    vector<int> JobScheduling(Job jobs[], int n) {
        sort(jobs, jobs + n, comp);
        int cnt = 0, profit = 0;
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, jobs[i].deadline);
        }
        vector<int> arr(maxDeadline + 1, -1);
        for (int i = 0; i < n; i++) {
            int k = jobs[i].deadline;
            while (k > 0) {
                if (arr[k] == -1) { 
                    arr[k] = jobs[i].id; 
                    cnt++;        
                    profit += jobs[i].profit;
                    break;         
                }
                k--;
            }
        }
        return {cnt, profit};
    }
};
