/..................................../
Given a positive integer k, you need to find the length of the smallest positive integer n such that n is divisible by k, and n only contains the digit 1.

Return the length of n. If there is no such n, return -1.

Note: n may not fit in a 64-bit signed integer.
/..................................../
 
int smallestRepunitDivByK(int k) {
    if(k%2==0)
        return -1;
    int c=0;
    for(int i=0; i<=k; i++){
        c = (c*10)%k + 1%k;
        if(c%k==0)
            return i+1;
    }
    return -1;
}
