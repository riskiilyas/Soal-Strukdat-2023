#include <iostream>
#define S 10
using namespace std;
int mat[S][S], visited[S][S], minArea=101;

void traverse(int i, int j, int* ctr) {
    if(i<0||j<0||i>=S||j>=S) return;
    if(!visited[i][j] && mat[i][j]==1) {
        visited[i][j]=1;
        (*ctr)++;
        traverse(i, j+1, ctr);
        traverse(i, j-1, ctr);
        traverse(i+1, j, ctr);
        traverse(i-1, j, ctr);
		traverse(i+1, j+1, ctr);
        traverse(i-1, j+1, ctr);
		traverse(i+1, j-1, ctr);
        traverse(i-1, j-1, ctr);
    }
    return;
}

int main()
{
    for(int i=0; i<S; i++) {
        for(int j=0 ; j<S; j++) {
            scanf("%d", &mat[i][j]);
            visited[i][j] = 0;
        }
    }
    
    for(int i=0; i<S; i++) {
        for(int j=0; j<S; j++) {
            if(visited[i][j]) continue;
            if(mat[i][j]==1) {
              int temp=0;
              traverse(i,j, &temp);
              if(temp<minArea) minArea=temp;
            }
            visited[i][j]=1;
        }
    }
    
	if(minArea==101)printf("There is no island!");
    else printf("Smallest island is: %d km^2", minArea);
    return 0;
}

/*
	Input:
	1 1 1 1 1 0 0 0 0 0 
	1 1 1 0 0 1 0 0 0 0 
	1 1 1 0 0 0 0 0 0 0 
	1 1 0 0 0 0 0 0 0 0 
	0 0 0 0 1 1 0 0 0 0 
	0 0 0 1 1 0 1 0 0 0 
	0 0 0 1 1 1 0 0 0 1 
	0 0 0 0 0 0 0 0 1 1 
	0 0 0 0 0 0 0 1 1 1 
	0 0 0 0 0 1 1 1 1 1 

	Output:
	Largest island is: 14 km^2


	Input:
	1 0 0 0 0 0 0 0 0 1 
	0 1 0 0 0 0 0 0 1 0 
	0 0 1 0 0 0 0 1 0 0 
	0 0 0 1 0 0 1 0 0 0 
	1 0 0 0 1 1 0 0 0 1 
	1 0 0 0 1 1 0 0 0 1 
	0 0 0 1 0 0 1 0 0 0 
	0 0 1 0 0 0 0 1 0 0 
	0 1 0 0 0 0 0 0 1 0 
	1 0 0 0 0 0 0 0 0 1 

	Output:
	Largest island is: 20 km^2
	
	Input:
	0 1 1 1 1 1 1 1 1 0 
	1 0 0 0 0 0 0 0 0 1 
	1 0 1 0 0 0 0 1 0 1 
	1 0 0 1 0 0 1 0 0 1 
	1 0 0 0 1 1 0 0 0 1 
	1 0 0 0 1 1 0 0 0 1 
	1 0 0 1 0 0 1 0 0 1 
	1 0 1 0 0 0 0 1 0 1 
	1 0 0 0 0 0 0 0 0 1 
	0 1 1 1 1 1 1 1 1 0 

	Output:
	Largest island is: 32 km^2
	
	Input:
	0 1 1 1 1 1 1 1 1 0 
	1 0 0 0 0 0 0 0 0 1 
	1 0 1 1 1 1 1 1 0 1 
	1 0 1 1 1 1 1 1 0 1 
	1 0 1 1 1 1 1 1 0 1 
	1 0 1 1 1 1 1 1 0 1 
	1 0 1 1 1 1 1 1 0 1 
	1 0 1 1 1 1 1 1 0 1 
	1 0 0 0 0 0 0 0 0 1 
	0 1 1 1 1 1 1 1 1 0 

	Output:
	Largest island is: 36 km^2
	
	Input:
	1 1 1 1 1 1 1 1 1 1 
	1 1 1 1 1 1 1 1 1 1 
	1 1 1 1 1 1 1 1 1 1 
	1 1 1 1 1 1 1 1 1 1 
	1 1 1 1 1 1 1 1 1 1 
	1 1 1 1 1 1 1 1 1 1 
	1 1 1 1 1 1 1 1 1 1 
	1 1 1 1 1 1 1 1 1 1 
	1 1 1 1 1 1 1 1 1 1 
	1 1 1 1 1 1 1 1 1 1 

	Output:
	Largest island is: 100 km^2
	
	Input:
	1 0 1 0 1 0 1 0 1 0 
	0 1 0 1 0 1 0 1 0 1 
	1 0 1 0 1 0 1 0 1 0 
	0 1 0 1 0 1 0 1 0 1 
	1 0 1 0 1 0 1 0 1 0 
	0 1 0 1 0 1 0 1 0 1 
	1 0 1 0 1 0 1 0 1 0 
	0 1 0 1 0 1 0 1 0 1 
	1 0 1 0 1 0 1 0 1 0 
	0 1 0 1 0 1 0 1 0 1 

	Output:
	Largest island is: 50 km^2
	
	Input:
	0 0 0 0 0 0 0 0 0 0 
	0 0 0 0 0 0 0 0 0 0 
	0 0 0 0 0 0 0 0 0 0 
	0 0 0 0 0 0 0 0 0 0 
	0 0 0 0 0 0 0 0 0 0 
	0 0 0 0 0 0 0 0 0 0 
	0 0 0 0 0 0 0 0 0 0 
	0 0 0 0 0 0 0 0 0 0 
	0 0 0 0 0 0 0 0 0 0 
	0 0 0 0 0 0 0 0 0 0 

	Output:
	There is no island!	
*/