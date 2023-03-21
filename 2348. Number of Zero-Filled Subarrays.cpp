class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long start,end;
        long long i=0;
        long long cnt=0;
        while(i<nums.size()){
            if(nums[i]==0){
                long long n=0;
                while(i < nums.size() && nums[i] == 0) {
                    i++; 
                    n++;
                }
                cnt+= n*(n+1)/2;
            }
            i++;
        } //O(N) or what 
        return cnt;
    }
};
