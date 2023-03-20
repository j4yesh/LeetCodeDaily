class Solution {
public:
    vector<int>evenstart;
    vector<int>oddstart;
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt=0; int m=flowerbed.size();
        if(m==1){
            if(flowerbed[0]==0)return n<=1;
            if(flowerbed[0]==1)return n==0;
        }
        if(flowerbed[0]==0 &&flowerbed[1]==0){
            flowerbed[0]=1;
                cout<<0<<"i ind\n";
            cnt++;
            }
        for(int i=1;i<m-1;i+=1){
            if(flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0){
                flowerbed[i]=1;
                cout<<i<<"ind\n";
                cnt++;
                }
        }
        int i=m-1;
        if(flowerbed[i]==0 && flowerbed[i-1]==0){
                flowerbed[i]=1;
                cout<<i<<"l ind\n";
                cnt++;
        }
       
        cout<<cnt<<'\n';
        return cnt>=n;
    }
};
