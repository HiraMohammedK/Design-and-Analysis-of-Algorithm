#include<iostream>
#define INFINITY 999
using namespace std;
void dijkstra(int n,int source,int cost[10][10],int distance[])
{
    int i,v,u,visited[10],min,count=2;
    for(i=1;i<=n;i++)
    visited[i]=0,distance[i]=cost[source][i];
    while(count<=n)
    {
        min=INFINITY;
        for(u=1;u<=n;u++)
        if(distance[u]<min && !visited[u])
            min=distance[u],v=u;
            visited[v]=1;
            count++;
        for(u=1;u<=n;u++)
        if((distance[v]+cost[v][u]<distance[u]) && !visited[u])
            distance[u]=distance[v]+cost[v][u];
    }
}
int main()
{
    int n,source,i,j,cost[10][10],distance[10];
    cout<<"\t\tDijkstra\t\t\n\n";
    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout<<"Enter the matrix with cost :\n";
    for(i=1;i<=n;i++)
    
    for(j=1;j<=n;j++)
    {
        cin>>cost[i][j];
        if(cost[i][j]==0) cost[i][j]=INFINITY;
    }
    cout<<"Enter the source : ";
    cin>>source;
    dijkstra(n,source,cost,distance);
    cout<<"From source :\n";
    for(i=1;i<=n;i++)
        if(i!=source)
            cout<<source<<" to "<<i<<" : cost = "<<distance[i]<<endl;
    
    return 0;
}