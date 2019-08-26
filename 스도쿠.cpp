#include <iostream>

using namespace std;

pair <int,int> blank[81];
int blankcnt=0;
int print=0;


bool checkrow(int arr[][10], int xpos, int ypos, int val)
{
    for (int i=1; i<10; i++)
    {
        if (arr[i][ypos]==val)
        {
            return 0;
        }
    }
    return 1;
}

bool checkcol(int arr[][10], int xpos, int ypos, int val)
{
    for (int i=1; i<10; i++)
    {
        if (arr[xpos][i]==val)
        {
            return 0;
        }
    }
    return 1;
}

bool checksqr(int arr[][10], int xpos, int ypos, int val)
{
    int x1=(((xpos-1)/3)*3)+1;
    int y1=(((ypos-1)/3)*3)+1;
    
    for (int i=x1; i<x1+3; i++)
    {
        for (int j=y1; j<y1+3; j++)
        {
            if (arr[i][j]==val)
            {
                return 0;
            }
        }
    }
    return 1;
}    

void DFS(int temp, int arr[][10])
{
    int x, y;
    if(temp<blankcnt && print==0)
    {
        for (int i=1; i<10; i++)
        {
            x=blank[temp].first;
            y=blank[temp].second;
            if(checkrow(arr,x,y,i)==1)
            {
                if(checkcol(arr,x,y,i)==1)
                {
                    if(checksqr(arr,x,y,i)==1)
                    {
                        arr[x][y]=i;
                        DFS(temp+1,arr);
                        if(print==1)
                        {
                            break;
                        }
                        arr[x][y]=0;
                    }
                }
            }
        }
    }else{
        print=1;
        for (int i=1; i<10; i++)
        {
            for (int j=1; j<10; j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}


int main(void)
{
    iostream::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int arr[10][10];

    for (int i=1; i<10; i++)
    {
        for (int j=1; j<10; j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]==0)
            {
                blank[blankcnt].first=i;
                blank[blankcnt].second=j;
                blankcnt++;
            }
        }
    }
    
    DFS(0,arr);
   
    return 0;
}