class Solution {
public:
    int setBits(int x){
        int count = 0;
        while(x){
            if(x&1) count++;
            x >>= 1;
        }
        return count;
    }
    int minBitFlips(int start, int goal) {
        return setBits(start ^ goal);
    }
};