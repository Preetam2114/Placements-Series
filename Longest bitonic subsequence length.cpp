int Solution::longestSubsequenceLength(const vector<int> &a) {
    //vector<int>a=A;
    if(a.size()==0)
    return 0;
    int i,j,ans=0;
    int l[a.size()],r[a.size()];
    //store incresing subsequenece length
    for(i=0;i<a.size();i++)
    {
        l[i]=1;
        for(j=0;j<i;j++)
        if(a[j]<a[i])
        l[i]=max(l[i],l[j]+1);
    }
    //stroe decreasing subsequence length 
    for(i=a.size()-1;i>=0;i--)
    {
        r[i]=1;
        for(j=i+1;j<a.size();j++)
        if(a[i]>a[j])
        r[i]=max(r[i],r[j]+1);
    }
    //update ans value
    for(i=0;i<a.size();i++)
    {
        ans=max(ans,(l[i]+r[i]-1));
    }
    return ans;

}
