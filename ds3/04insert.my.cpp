void sort(int *a,int n){
    int i,j,temp,p;
    for(i=1;i<n;i++){
        for(j=0;j<i;j++)
            if(a[i]<a[j])
                break;
        if(j==i)continue;
        temp=a[i];
        for(p=i-j;p>0;p--)
            a[p]=a[p-1];
        a[p]=temp;
    }
}
