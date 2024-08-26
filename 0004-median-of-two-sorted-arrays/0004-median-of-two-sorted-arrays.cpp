class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        double result;
        if((size1 == 0 || size2 == 0) && (size1 == 1 || size2 == 1)) {
            if(size1 == 1) {
                return nums1.at(size1 - 1);
            }
            else if(size2 == 1) {
                return nums2.at(size2 - 1);
            }
        }
        vector<int> merged;
        for(int i = 0; i < size1; i++) {
            merged.push_back(nums1[i]);
        }
        for(int j = 0; j < size2; j++) {
            merged.push_back(nums2[j]);
        }
        for(int x = 0; x < size1 + size2 - 1; x++) {
            for(int y = 0; y < size1 + size2 - x - 1; y++) {
                if(merged[y] > merged[y+1]) {
                    int temp = merged[y];
                    merged[y] = merged[y+1];
                    merged[y+1] = temp;
                }
            }
        }
        if((size1 + size2) % 2 == 0) {
            int med = (size1 + size2) / 2;
            int med1 = med - 1;
            result = (merged[med] + merged[med1]) / 2.0;
        }
        else {
            int med  = (size1 + size2) / 2;
            result = merged[med];
        }
        return result;
    }
};