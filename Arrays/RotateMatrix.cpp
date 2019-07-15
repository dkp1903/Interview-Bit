// https://www.interviewbit.com/problems/rotate-matrix/

void Solution::rotate(vector<vector<int> > &A)
{
    int i, j, k;
    int n = A.size();
    
    //Taking transpose
    for(i = 0; i < n; i++)
        for(j = i ; j < n; j++)
            swap(A[i][j], A[j][i]);
    
    //Swapping ith columns from front and back for all rows
    for(i = 0; i < n; i++)
    {
        j = 0;
        k = n - 1;
        while(j < k)
            swap(A[i][j++], A[i][k--]);
    }
    
}
