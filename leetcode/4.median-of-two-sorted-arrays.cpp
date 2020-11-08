#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),  m = nums2.size();
        // I want n<m
        if(n>m){
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int lt = 0, rt = n;
        while(lt<=rt){
            int partX = (lt + rt)/2; // elements in 1st half of X
            int partY = (n + m + 1)/2 - partX;
            
            int maxLeftX = (partX!=0) ? nums1[partX-1] : INT_MIN;
            int minRightX = (partX!=n) ? nums1[partX] : INT_MAX;
            
            int maxLeftY = (partY!=0) ? nums2[partY-1] : INT_MIN;
            int minRightY = (partY!=m) ? nums2[partY]  :INT_MAX;
            
            if(maxLeftX<=minRightY && maxLeftY<=minRightX){
                if((n+m)%2){
                    return max(maxLeftX, maxLeftY);
                }else{
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2.0;
                }
            }else if(maxLeftX>minRightY){
                rt = partX-1;
            }else{
                lt = partX+1;
            }
        }
        
        return -1;
    }
};

class Solution {
    vector<int> nums1, nums2;
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1, this->nums2 = nums2;
        int n = nums1.size(), m = nums2.size();
        if(n==0){
            double sum = nums2[m/2] + nums2[(m-1)/2];
            return sum/2;
        }
        if(m==0){
            double sum = nums1[n/2] + nums1[(n-1)/2];
            return sum/2;   
        }
        
        int tot = n+m;
        double sum = find_kth(tot/2);
        if(tot%2==0){
            sum+=find_kth((tot-1)/2);
            sum/=2;
        }
        return sum;        
    }
    
    int find_kth(int k){
        int lt = min(nums1[0], nums2[0])-1,
            rt = max(nums1.back(), nums2.back()) + 1,
            ans = 1e9;
        while(1+lt<rt){
            int mid = lt + (rt-lt)/2;
            if(canbeKth(mid, k)){
                ans = mid, rt = mid;
            }else 
                lt = mid;
        }
        return ans;
    }
    
    bool canbeKth(int val, int K){
        int cnt1 = distance(nums1.begin(), upper_bound(nums1.begin(), nums1.end(), val));
        int cnt2 = distance(nums2.begin(), upper_bound(nums2.begin(), nums2.end(), val));
        return (cnt1+cnt2>K);
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}