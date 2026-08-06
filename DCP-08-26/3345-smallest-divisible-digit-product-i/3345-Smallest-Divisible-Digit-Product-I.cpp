class Solution {
public:
    int help(int n)
    {
        int p = 1;
        while(n)
        {
            p*=n%10;
            n/=10;
        }
        return p;
    }
    int smallestNumber(int n, int t) {
        while(help(n)%t!=0) n++;
        return n;
    }
};