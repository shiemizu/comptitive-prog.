#include <iostream>
#include<fstream>
#include <sstream>
#include<string>
#include <iterator>


using namespace std;

int findmax(int e[],int ps,int pl){
	int total=0,index;
	
	for (int j = 0; j<ps; j++){ //each passenger
		int max = e[0];
		for (int i =0; i<pl;i++){ //will buy the most expensive ticket
			if (max<=e[i]){
			 max =e[i];
			 index=i;}
			}
			
	total =total +max;
	e[index]-=1;   //then empty seats decrease
    }
    
  return total;
}

int findmin(int e[],int ps,int pl){
	int total=0,index;
	
		for (int j = 0; j<ps; j++){ //each passenger
		int min = e[0];
		
		for (int i =0; i<pl;i++){ //will buy the cheapest ticket 
			if (min>=e[i] && e[i]!=0){
			 min =e[i];
			 index=i;}
			}
			
	total =total +min;
	e[index]-=1;   //then empty seats decrease
    }
    
  return total;
	
}
int main(){
	ifstream in;
	ofstream out;
	in.open("in.txt");
	out.open("out.txt");
	
	string line;
	getline(in,line);
	int test = stoi(line);
	
	for (int i = 0; i<test ; i++){
		
		int psngr,pln;
		
		getline(in,line);
		istringstream iss(line);
		
		iss>>psngr>>pln;
		int empty[pln],cparr[pln];   
	
		
		getline(in,line);
		istringstream elo(line);
		
		for (int i =0;i<pln;i++){
			elo>>empty[i];
		}                          //until hear is insertion
		copy(empty, empty+pln,cparr); //copy the array because next function will chane it's values
		
		int max=findmax(empty,psngr,pln);
		cout<<max<<endl;
		
		int min= findmin(cparr,psngr,pln);
		cout<<min;
		
		
	}
	
	return 0;
}
