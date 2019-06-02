int Solution::solve(string A) {
    int sum = 0;
    for(int i = 0 ; i < A.length() ; i++)
    {
        A[i] = tolower(A[i]);
        //Converting all characters to lowercase
        if(A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u' )
            sum += A.length() - i;
            //Number of substrings starting with the ith letter = A.length() - i
            
    }
    return (sum % 10003);
}
