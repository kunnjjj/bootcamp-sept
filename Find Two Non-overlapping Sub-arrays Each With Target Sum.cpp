// https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
// both O(NlogN) and O(N) approaches shared
class Solution {
public:
//  space O(n) 
//  time  O(NlogN)
    int minSumOfLengths(vector<int>& A, int target) {
        int inf=1e9;
        int n=A.size();
        vector<int> aux(n,inf);
        int ans=inf;
        vector<int> prefix(n);
        for(int i=0;i<n;i++)
        {
            prefix[i]=(i-1>=0?prefix[i-1]:0) + A[i];
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<prefix[i]<<" ";
        // }
        
        for(int i=0;i<n;i++)
        {
            int s=0,e=i;
            int idx=-1;
            
            while(s<=e)
            {
                int mid=(s+e)/2;
                // sum from A[mid]....A[i]>target
                int sum=prefix[i]-(mid-1>=0?prefix[mid-1]:0);
                // cout<<"sum is "<<sum<<endl;
                if(sum > target) // i have taken extra elemnts
                {
                    s=mid+1;
                }
                else if(sum < target)
                {
                    e=mid-1;
                }
                else
                {
                    idx=mid;
                    break;
                }     
            }
            // cout<<idx<<endl;
            aux[i]=min(aux[i],(i-1>=0?aux[i-1]:inf));
            if(idx!=-1)
            {
                int ye_wala_sub=i-idx+1;
                aux[i]=min(ye_wala_sub,aux[i]);
                ans=min(ans,ye_wala_sub + (idx-1>=0?aux[idx-1]:inf));
            }
        }
        if(ans==inf) return -1;
        return ans;
    }
};
class Solution {
public:
    int minSumOfLengths(vector<int>& A, int target) {
        int inf=1e9;
        int ans=inf;
        int n=A.size();
        // vector<int> prefix(n);
        // for(int i=0;i<n;i++)
        // {
        //     prefix[i]=(i-1>=0?prefix[i-1]:0) + A[i];
        // }
        int sum=0;
        int j=0;
        vector<int> first_sub(n,inf);
        for(int i=0;i<n;i++)
        {
            int s=0,e=i;
            int idx=-1;
            sum+=A[i];
            while(sum>target)
            {
                sum-=A[j];
                j++;
            }
            if(sum==target)
            {
                idx=j;
            }
            if(idx!=-1)
            {
                ans=min(ans,(idx-1>=0?first_sub[idx-1]:inf) + (i-idx+1));
                first_sub[i]=min(first_sub[i],i-idx+1);
            }
            first_sub[i]=min(first_sub[i],(i-1>=0?first_sub[i-1]:inf));   
        }
        if(ans==inf) return -1;
        return ans;
    }
};