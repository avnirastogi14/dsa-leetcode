class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        if(n1>n2) return findMedianSortedArrays(arr2,arr1);

        int n =n1+n2;

        int leftH = (n+1)/2;
        
        int l = 0, h = n1;

        while(l<=h)
        {
            int m1 = (l+h)>>1;
            int m2 = leftH - m1;

            long long l1 = (m1>0)?arr1[m1-1]:LLONG_MIN;
            long long r1 = (m1<n1)?arr1[m1]:LLONG_MAX;
            long long l2 = (m2>0)?arr2[m2-1]:LLONG_MIN;
            long long r2 = (m2<n2)?arr2[m2]:LLONG_MAX;

            if(l1<=r2 && l2<=r1)
            {
                if(n%2!=0) return max(l1,l2);
                else return (max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2) h = m1-1;
            else l = m1+1;
        }
        return 0;
    }
};