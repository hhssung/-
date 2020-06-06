#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int N;
    string arr[50];
    char pattern[50];
    cin>>N;
    for (int i=0; i<N; i++)
    {
        cin>>arr[i];
    }
    
    char compare;
    int flag;
    
    for (int i=0; i<arr[0].length(); i++)
    {
        compare=arr[0][i];
        flag=0;
        for (int j=1; j<N; j++)
        {
            if(compare!=arr[j][i])
            {
                pattern[i]='?';
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            pattern[i]=compare;
        }
    }
    
    for(int i=0; i<arr[0].length(); i++)
    {
        cout<<pattern[i];
    }
    
    return 0;
}