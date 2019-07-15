//https://www.interviewbit.com/problems/merge-overlapping-intervals/


bool comp(Interval a, Interval b)
{
    bool t = false;
    if(a.start < b.start)
        t = true;
    else if(a.start == b.start && a.end < b.end)
        t = true;
    return t;
}
vector<Interval> Solution::merge(vector<Interval> &A) {
    sort(A.begin(), A.end(), comp);
   
    Interval x1;
    int i = 0;
    
    stack<int>q1, q2;
    q1.push(A[0].start);
    q2.push(A[0].end);
    
    for(i = 1; i < A.size(); i++)
    {
        if(A[i].start == A[i].end && A[i].start <= q2.top())
            continue;
        if(A[i].start < q2.top())
        {
            if(A[i].end >= q2.top())
            {
                q2.pop();
                q2.push(A[i].end);
            }
        }
        else
        {
            q1.push(A[i].start);
            q2.push(A[i].end);
        }
    }
    A.clear();
    while(!q1.empty())
    {
        x1.start = q1.top();
        q1.pop();
        x1.end = q2.top();
        q2.pop();
        
        A.push_back(x1);
    }
    reverse(A.begin(), A.end());
    return A;
}
