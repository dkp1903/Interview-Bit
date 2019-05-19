int Solution::solve(vector<int> &A) {
    int n = A.size(), ans = -1, i = 0;
    
    if(!n){
        return ans;
    }
    
    sort(A.begin(), A.end());
    
    while(i < n){
        while(i+1 < n && A[i] == A[i+1]){
            i++;
        }
        //Since the array is sorted, A[i+1]>= A[i] always
        //We break out of the inner while loop when A[i]!=A[i+1], that is, we see a different element upcoming.
        //hence, we need to check if A[i] is noble, which is done using the if statement below.
        
        if(n - (i+1) == A[i])//i +1 refers to the number of elements we have traversed so far, including the element we are on.
            //hence n-(i+1) refers to the number of elements after the one we are checking.
            //So if that count is equal to A[i], test for nobility is satisfied
        {
            ans = 1;
            break;
        }
        
        i++;
    }
    
    return ans;
}
