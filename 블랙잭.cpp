#include <iostream>

using namespace std;

int main(void)
{
    int N;
    int M;
    int arr[100];
    cin>>N>>M;
    
    for (int i=0; i<N; i++)
    {
        cin>>arr[i];
    }
    
    int sum;
    int val;
    int s=987654321;
    
    for (int i=0; i<N-2; i++)
    {
        for (int j=i+1; j<N-1; j++)
        {
            for (int k=j+1; k<N; k++)
            {
                sum=arr[i]+arr[j]+arr[k];
                if (sum<=M && M-sum<s)
                {
                    s=M-sum;
                    val=sum;
                }
            }
        }
       
    }
    cout<<val<<endl;
        
    return 0;
}