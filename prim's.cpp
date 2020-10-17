// Implementation of Prim's Algorithm
#include<bits/stdc++.h>
using namespace std;
#define v 5



int min_index(int g[v][v],bool mstset[v],int dist[v])// this function is to return the node which has min distance from parent
{
	int min = INT_MAX,index;

	for(int i=0;i<v;i++)
	{
		if(mstset[i]==false&&dist[i]<min)
		{
			min = dist[i];
			index =i;
		}
	}

	return index;

}

void printmst(int dist[], int parent[])
{
	cout<<"Edge"<<"\t"<<"weight"<<endl;
	for(int counter=1;counter<v;counter++)
	{	
		cout<<parent[counter]<<" - "<<counter<<"\t"<<dist[counter]<<endl;
	}
}


void prims(int g[v][v]){

	int dist[v];
	int parent[v];

	bool mstset[v];

	for(int i=0;i<v;i++)
	{
		mstset[i]=false;
		dist[i]=INT_MAX;
	}

	dist[0]=0;
	parent[0]=-1;//root node

	for(int i=0;i<v;i++)
	{
	
		int u = min_index(g,mstset,dist);

		mstset[u]=true;

		for(int j=0;j<v;j++)//loop to update the dist of adjacent nodes of selected node
		{
			if(g[u][j]&&mstset[j]==false&&g[u][j]<dist[j])
			{
				dist[j]=g[u][j];
				parent[j]=u;
			}
		}


	}

	printmst(dist,parent);

}






int main()
{
	int graph[v][v] = { { 0, 2, 0, 6, 0 }, 
                        { 2, 0, 3, 8, 5 }, 
                        { 0, 3, 0, 0, 7 }, 
                        { 6, 8, 0, 0, 9 }, 
                        { 0, 5, 7, 9, 0 } };
	prims(graph);
	return 0;
}
//This Program Ends here..
