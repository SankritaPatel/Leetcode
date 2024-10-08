class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1+ n2;
        int i=0, j=0;
        int count = 0;
        int ind2 = n/2;
        int ind1 = n/2-1;
        int indel1 = -1;
        int indel2 = -1;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                if(count == ind1)
                    indel1 = nums1[i];
                if(count ==ind2)
                    indel2 = nums1[i];
                count++;
                i++;
            }
            else{
                if(count==ind1)
                    indel1 = nums2[j];
                if(count ==ind2)
                    indel2 = nums2[j];
                count++;
                j++;
            }
        }
        while(i<n1){
            if(count == ind1)
                    indel1 = nums1[i];
            if(count ==ind2)
                indel2 = nums1[i];
            count++;
            i++;
        }
        while(j<n2){
            if(count==ind1)
                indel1 = nums2[j];
            if(count ==ind2)
                indel2 = nums2[j];
            count++;
            j++;
        }
        
        if(n%2==0){
            return (indel1+indel2)/2.0;
        }else{
            return indel2;
        }
    }
};
