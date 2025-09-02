/*
Find a subset of a given set S = {sl, s2,. ,sn} of n positive integers whose sum is equal 
to a given positive integer d. For example, if S= {1, 2, 5, 6, 8} and d = 9 
there aretwo solutions {1,2,6}and{1,8}.A suitable message is to be displayed if the given 
probleminstance doesn’t have a solution. 
*/

#include <iostream>
#include <vector>

using namespace std;

// index -> current index in arr being considered
// sum -> current sum of elements in ans
// ans -> current subset of elements
// K -> target sum
// arr -> input array
bool subsetSum(int,int,vector<int>&,int,vector<int>&);
int main(){

    int n,K;
    vector<int> arr,ans;
    cout<<"\nEnter the number of elements in the set: ";
    cin>>n;
    cout<<"\nEnter the elements of the set: ";
    //read the elements of the set
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout<<"\nEnter the sum: ";
    cin>>K;
    if(!subsetSum(0,0,ans,K,arr)){
        cout<<"\nNo subsets of given set have sum equal to "<<K;
    }
    return 0; 
}
bool subsetSum(int index,int sum,vector<int>& ans,int K,vector<int>& arr){
    if(index>=arr.size()){
        if(sum==K){
            for(int i=0;i<ans.size();i++)
                cout<<ans[i]<<" ";
            cout<<"\n";
            return true;
        }
        return false;
    }
    // Include current element arr[index] in subset
    ans.push_back(arr[index]);
    sum+=arr[index];
    bool x=subsetSum(index+1,sum,ans,K,arr);
    ans.pop_back();
    sum-=arr[index];
    // Exclude current element arr[index] from subset and recurse
    bool y=subsetSum(index+1,sum,ans,K,arr);
    // Return true if any of the two branches found a valid subset
    return x||y;
}

/*
Time complexity: 2^n
Spacec Complexity: O(n)
*/