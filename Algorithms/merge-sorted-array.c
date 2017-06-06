// https://leetcode.com/problems/merge-sorted-array/#/description
void merge(int* nums1, int m, int* nums2, int n) 
{
    int a = m - 1, b = n - 1, ind = m + n - 1;
        while(b > -1)
            nums1[ ind-- ] = a > -1 && nums1[a] > nums2[b] ? nums1[a--] : nums2[b--];
}
