#include <iostream>
#include <queue>

using namespace std;

queue <pair<int, int>> q;
int arr[101][101];
int ways=0;

void next(int x, int y, int k)
{
    if(arr[x+1][y]==1)
    {
        arr[x+1][y]+=k;
        q.push(make_pair(x+1,y));
    }
    if(arr[x][y+1]==1)
    {
        arr[x][y+1]+=k;
        q.push(make_pair(x,y+1));
    }
    if(arr[x-1][y]==1)
    {
        arr[x-1][y]+=k;
        q.push(make_pair(x-1,y));
    }
    if(arr[x][y-1]==1)
    {
        arr[x][y-1]+=k;
        q.push(make_pair(x,y-1));
    }
    
}

int main(void)
{
    int N, M;
    cin>>N>>M;
    
    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=M; j++)
        {
           scanf("%1d", &arr[i][j]);
        }
    }
    
    q.push(make_pair(1,1));
    arr[1][1]=2;    //visited
    int x,y;
    while(!q.empty())
    {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        next(x,y,arr[x][y]);
        if(x==N && y==M)
        {
            break;
        }
    }
    cout<<arr[N][M]-1<<endl;
    
     return 0;
}