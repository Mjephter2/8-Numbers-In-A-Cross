#include<iostream>
#include<cmath>
using namespace std;

void print(int q[]);
void backtrack(int &c);
bool ok(int array[], int c);

int main(){
int answer[8] = {0}, column=0;
	answer[0] = 1;
	while (column >= 0) {
		column++;
		if (column == 8) {
			print(answer);
			backtrack(column);
		}
		else answer[column] = 0;
		while (column >= 0) {
			answer[column]++;
			if (answer[column]>8) backtrack(column);
			else if (ok(answer, column)) break;
			else continue;
		}
	}
	return 0;
}

void backtrack(int &c){
	c--;
	if(c==-1) exit(0);
}

void print(int q[]) {
   static int numSolutions = 0;
   numSolutions++;
   cout << "Solution # " <<  numSolutions<<endl;
   cout<<"  "<<q[1]<<" "<<q[4]<<endl;
   cout<<q[0]<<" "<<q[2]<<" "<<q[5]<<" "<<q[7]<<endl;
   cout<<"  "<<q[3]<<" "<<q[6];
   cout << endl<<endl;
}

bool ok(int ans[], int c){
	for(int i=0;i<c;i++){
		if(ans[i]==ans[c]) return false;
	}
	static int adj_Tab[8][5] = {
    	{-1,0,0,0,0},
        { 0,-1,0,0,0},
        { 0,1,-1,0,0},
        { 0,2,-1,0,0},
        { 1,2,-1,0,0},
        { 1,2,3,4,-1},
        { 2,3,5,-1,0},
        { 4,5,6,-1,0} 
	};
    for(int i=0;adj_Tab[c][i]!=-1;i++){
    	if(abs(ans[c]-ans[adj_Tab[c][i]])==1) return false;
	}
	return true;	
}

