#include<stdio.h>
int main()
{
    int i=0,j=0,x,y,a,b,arr[4][3]= {1,0,0,0,1,0,0,0,1,1,0,1},count=0;
    printf("CHOOSE THE ROW AND COLUMN:\t");
    scanf("%d %d",&a,&b);
    x=a,y=b;
    if(x<=3 && y==0)
    {
        if(x!=0)
        {
            --a;
            if(*(*(arr+a)+b) ==0)
                ++count;
        }
        ++b;
        if(*(*(arr+a)+b) ==0)
            count++;

        ++a;
        if(*(*(arr+a)+b) ==0)
            count++;

        if(x>0 && x<3)
        {
            ++a;
            if(*(*(arr+a)+b)==0)
                count++;
        }
        --b;

        if(*(*(arr+a)+b) ==0)
            count++;
    }

    if(x<=3 && y==1)
    {
        if(x!=0)
        {
            --a;
            if(*(*(arr+a)+b)==0)
                count++;
        }
        ++b;
        if(*(*(arr+a)+b) ==0)
            count++;
        ++a;
        if(*(*(arr+a)+b) ==0)
            count++;
        if(x!=0 && x!=3)
        {
            ++a;
            if(*(*(arr+a)+b) ==0)
                count++;
        }
        if(x!=3)
        {
            --b;
            if(*(*(arr+a)+b)==0)
                count++;
            --b;
            if(*(*(arr+a)+b) ==0)
                count++;
        }
        else
        {
            b=b-2;
            if(*(*(arr+a)+b)==0)
                count++;
        }

        --a;
        if(*(*(arr+a)+b) ==0)
            count++;
        if(x!=3 && x!=0)
        {
            --a;
            if(*(*(arr+a)+b) ==0)
                count++;
        }
    }

    if(x<=3 && y==2)
    {
        if(x!=0)
        {
            --a;

            if(*(*(arr+a)+b) ==0)
                count++;
        }
        --b;

        if(*(*(arr+a)+b)==0)
            count++;

        ++a;
        if(*(*(arr+a)+b)==0)
            count++;

        if(x!=0 && x<3)
        {
            ++a;
            if(*(*(arr+a)+b)==0)
                count++;
        }
        if(x!=3)
        {
            ++b;
            if(*(*(arr+a)+b) ==0)
                count++;
        }
    }
    printf("TOTAL NO. OF NEIGHBOURING AND DIAGONAL ZEROES =  %d",count);
}
