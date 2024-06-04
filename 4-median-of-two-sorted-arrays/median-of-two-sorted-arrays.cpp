class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int a = nums1.size();
        int b = nums2.size();
        if(a > b){
            return findMedianSortedArrays(nums2, nums1);
        }

        int low = 0;
        int high = a;
        int total = (a + b + 1)/2;
        int n = (a+b);
        while(low <= high){
            int mid1 = (low + high)/2;
            int mid2 = total - mid1;
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;

            if(mid1 < a){
                r1 = nums1[mid1];
            } 

            if(mid2 < b){
                r2 = nums2[mid2];
            }

            if(mid1 - 1 >= 0){
                l1 = nums1[mid1 - 1];
            }

            if(mid2 - 1 >= 0){
                l2 = nums2[mid2 - 1];
            }

            if(l1 <= r2 && l2 <= r1){
                if(n%2 == 0){
                    return ((double)(max(l1, l2) + min(r1, r2)))/2.0;
                } else {
                    return (double)(max(l1, l2));
                }
            } else if(l1 > r2){
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
        }
        return 0;
    }
};