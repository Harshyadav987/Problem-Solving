class Solution {
public:
    int gcdOfOddEvenSums(int n) {
    int sumOdd=0;
    int sumEven=0;
    int countEven=0;
    int countOdd=0;
    for(int i=1;countOdd < n || countEven < n;i++){
        if(i%2==1){
            sumOdd+=i;
            countOdd++;
        }
        
        if(i%2==0){
            sumEven+=i;
            countEven++;
        }
    }


        return gcd(sumOdd,sumEven);
    }
};