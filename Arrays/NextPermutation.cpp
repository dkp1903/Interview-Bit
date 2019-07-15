void Solution::nextPermutation(vector<int> &A)
{
    if(A.size() <= 2)
    {
        reverse(A.begin(), A.end());
        return ;
    }
    int i, j = A.size() - 2;
    
    while(A[j] > A[j + 1] && j >= 0)
        j--;
    int min = A[j + 1];
    int index = j + 1;
    for(i = j + 1; i < A.size(); i++)
    {
        if(A[i] > A[j] && A[i] < A[index])
        {
            min = A[i];
            index = i;
        }
    }
    swap(A[j], A[index]);
    sort(A.begin() + (j + 1), A.end());
}
