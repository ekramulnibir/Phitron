#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);

    for(int i=1; i<=t; i++)
    {
        int n;
        scanf("%d",&n);

        int ar[n];

        for(int i=0; i<n; i++)
        {
            scanf("%d",&ar[i]);
        }

        int flag = 0,to_search;
        scanf("%d",&to_search);


        printf("Case %d: ",i);
        for(int i=0; i<n; i++)
        {
            if(ar[i]==to_search)
            {
                flag++;
                printf("%d\n",i+1);
                break;
            }
        }

        if(flag == 0){printf("Not found\n");}

    }

}