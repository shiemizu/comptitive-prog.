#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include <sstream>  
#define MAX 20

using namespace std;


typedef struct{
	string color;
	int rad;
}cups;


void sorting(cups *cup,int top){ 
	
	ofstream out;
	out.open("out.txt",ios::app);
	
	int temp;
	string tempColor;
	
	for(int i=0;i<=top;i++){
		for(int j=i+1;j<=top;j++){
			if(cup[j].rad<cup[i].rad){
				temp=cup[i].rad;
				tempColor=cup[i].color;
				cup[i].rad=cup[j].rad;
				cup[i].color=cup[j].color;
				cup[j].rad=temp;
				cup[j].color=tempColor;
			}
		}
	} 
	
	//after sorting, assign to output file
	cout<<"sorted: "<<endl;
	for(int i=0;i<=top;i++){
		out<<cup[i].color<<"\n";
		cout<<cup[i].color<<endl;
	}
	
		
out.close();

}
int main(){
	
	
	int top=-1;
	cups cup[MAX];
	
	ifstream in;
	ofstream out;
	
	in.open("cups.txt");
//	out.open("cups.out");
if (in.is_open())
  {
    cout << "File successfully open";
   
  }
  else
  {
    cout << "Error opening file";
  }
	int N;
	string line;
	getline(in, line); //get number of lines
	cout<<line<<endl;
	N=stoi(line); 

	while(getline(in, line)){
	top++;

	istringstream iss(line); //it acts like a pointer to that line
	if (isdigit(line[0])==true){
		
	iss>>cup[top].rad>>cup[top].color;
	cup[top].rad /=2;
	}
	else
	iss>>cup[top].color>>cup[top].rad;
	
	if(top==N-1){ 
		for (int i=0;i<=top;i++){ // for display if you want to check
		cout<<cup[i].color<<"  "<<cup[i].rad<<endl;
     }
     
//	sort(cup,cup+N,radcompare); 
	sorting(cup, top);
	
//	for (int i=0;i<=top;i++){ // for display if you want to check
	//	cout<<cup[i].color<<"  "<<cup[i].rad<<endl;
    // }
     cout<<endl;
	getline(in, line);
	N=stoi(line);
	top=-1;
		}
	}
		

		
	in.close();
	

	return 0;
}
