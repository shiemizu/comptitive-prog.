#include<iostream>

using namespace std;

int main(){
	
	int n;
	while (1){
		
		cout<<"enter num of students: ";
		cin>>n;
		if (n==0) break;
		
		for (int i = n; i>0 ; i--){
			
			if (i%2!=0 && i%3 != 0) { 
			cout<<i<<endl;
			break;
			}
			
			else if (i%2==0 && i%3 == 0) { 
			cout<<i<<endl;
			break;
			}
			//else continue;
		}
		
	}
	return 0;
}
