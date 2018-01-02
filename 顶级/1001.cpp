#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int parent[10];
int n,m;


struct edge{
	int u,v,w;
}edges[10];


void UFset(){
	for(int i=1;i<=n;i++){
		parent[i] = -1;
	}
}

int find(int loc){
	int temp;
	for(temp=loc;parent[temp] >= 0;temp = parent[temp]);
	int x = loc;
	while(temp != x){
		int t = parent[i];
		parent[x] = temp;
		x = t;
	}
	return temp;
}

void merge(int a,int b){
	int r1 = find(a);
	int r2 = find(b);
	int tmp = parent[r1] + parent[r2];
	if(parent[r1] > parent[r2]){
		parent[r1] = r2;
		parent[r2] = tmp;
	}else{
		parent[r2] = r1;
		parent[r1] = tmp;
	}
}


void kruskal(){
	int sumWeight = 0;
	int num = 0;
	int u,v;
	UFset();
	for(int i=0;i<m;i++){
		u = edges[i].u;
		v = edges[i].v;
		if(find(u) != find(v)){
			printf("%d %d:  %d",u,v,edges[i].w);
			sumWeight += edges[i].w;
			num++;
			merge(u,v);
		}
	}
	printf("MST is %d",sumWeight);
}

int cmp(const void *a, const void *b){
	edge *e1 = (edge *)a;
	edge *e2 = (edge *)b;
	return e1->w - e2->w;
}

int main(){
	n=7;
	m=9;
    int  arr[] ={1,2,28,1,6,10,2,3,16,2,7,14,3,4,12,4,5,22,4,7,18,5,6,25,5,7,24};
    for(int i=0;i<n;i++){
    	int u = arr[i*3];
    	int v = arr[i*3+1];
    	int cost = arr[i*3+2];
    	cout<<u<<","<<v<<","<<cost<<endl;
    }
}