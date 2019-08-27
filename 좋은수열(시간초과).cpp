#include <iostream>

using namespace std;
int n;
int arr[81];
int print=0;

bool check(int len)
{
    int c;
    for (int i=1; i<=len; i++)
    {
        for (int j=0; j<=n-(2*i); j++)
        {
            c=0;
            for (int k=j; k<j+i; k++)
            {
                if(arr[k]==arr[k+i])
                {
                    c++;
                }
            }
            if(c==i)
            {
                return 0;
            }
        }
    }
    return 1;
}

void DFS(int temp)
{
    if(temp<n)
    {
        for (int i=1; i<=3; i++)
        {
            if(arr[temp-1]!=i)
            {
                arr[temp]=i;
                DFS(temp+1);
                if (print==1)
                {
                    break;
                }
            }
        }
    }else{
        if(check(n/2)==1)
        {
            for (int i=0; i<n; i++)
            {
                cout<<arr[i];
            }
            print=1;
        }
        
    }
}

int main(void)
{
    cin>>n;
    DFS(0);
    
    return 0;
}