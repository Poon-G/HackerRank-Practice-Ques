#include <vector>
#include<iostream>
using namespace std;

int DFS(vector<vector<int>>&visited,vector<vector<int>>matrix,int i,int j,int m,int n){
	static int count=0;
	if((!visited[i][j]) && i >= 0 && i<=m && j>=0 && j <=n && matrix[i][j]==1){
		count++;
		  visited[i][j]=1;
			DFS(visited,matrix,i,j-1,m,n);
			DFS(visited,matrix,i,j+1,m,n);
			DFS(visited,matrix,i-1,j,m,n);
			DFS(visited,matrix,i+1,j,m,n);
	}
	return count;
}
vector<int> riverSizes(vector<vector<int>> matrix) {
 // bool visited[matrix.size()][matrix[0].size()];
	int rows = matrix.size();
	int cols = matrix[0].size();
		cout<<rows<<" "<<cols<<"\n";
	vector<vector<int>> visited(matrix.size(),vector<int>(matrix[0].size(),0));


	// for(int i=0;i<rows;i++)
	//  for(int j=0;j<cols;j++)
	//  	visited[i][j]=0;
	vector<int>result;
	int count=0;

	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(!visited[i][j] && matrix[i][j]==1){
				int x = DFS(visited,matrix,i,j,rows-1,cols-1);
				result.push_back(x);
			}
		}
	}
	return result;
}
