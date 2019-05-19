// https://www.interviewbit.com/problems/spiral-order-matrix-ii/
/*
vector<vector<int> > Solution::generateMatrix(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<int> >sol(A, vector<int>(A, 0));
    
    int left = 0;
    int right = A-1;
    int top = 0;
    int bottom = A-1;
    int dir = 0;
    int number = 1;
    int i, j;
    
    LOOP:while((left <= right) && (top <= bottom)){
        if(dir == 0){
            for(j = left; j <= right; j++){
                sol[top][j] = number;
                number++;
            }
            top++;
            dir = 1;
            goto LOOP;
        }
        else if(dir == 1){
            for(i = top; i <= bottom; i++){
                sol[i][right] = number;
                number++;
            }
            right--;
            dir = 2;
            goto LOOP;
        }
        else if(dir == 2){
            for(j = right; j >= left; j--){
                sol[bottom][j] = number;
                number++;
            }
            bottom--;
            dir = 3;
            goto LOOP;
        }
        else if(dir == 3){
            for(i = bottom; i >= top; i--){
                sol[i][left] = number;
                number++;
            }
            left++;
            dir = 0;
            goto LOOP;
        }
    }
    
    return sol;
    
}
*/

//////////////////////////////////////////////////////////////////////////////////



//This is a solution that works



vector<vector<int> > Solution::generateMatrix(int A)
    {
    int t = 0,l = 0, r = A - 1 ,b = A - 1;
    int d = 0 , count = 1;
    vector<vector<int> >a(A,vector<int>(A));
    while(t <= b && l <= r){
        if(d == 0){
            for(int i = l;i <= r;i++){
                a[t][i]=count;
                count++;
            }
            d=1;
            t++;
        }
        else if(d==1){
            for(int i=t;i<=b;i++){
                a[i][r]=count;
                count++;
            }
            d=2;
            r--;
        }
        else if(d==2){
            for(int i=r;i>=l;i--){
                a[b][i]=count;
                count++;
            }
            d=3;
            b--;
        }
        else if(d==3){
            for(int i=b;i>=t;i--){
                a[i][l]=count;
                count++;
            }
            d=0;
            l++;
        }
    }
    return a;
    
}
