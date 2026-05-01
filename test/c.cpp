#include <cstdio>

int sum,i,n;
char x,a[]={'a','p','t','w','z'+1};

int main()
{
    while (scanf("%c",&x)!=EOF)
        if (x>='a') {
            for (i=0; i<4 && x>=a[i+1]; ++i);
            sum+=(x-a[i])%((i&1)+3)+1;
        } else if (x==' ')
            ++sum;
    printf("%d",sum);
    return 0;
}

