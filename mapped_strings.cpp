#include<iostream>
using namespace std;
char arr[27];
void putMapped(string num , string &s,int start, int end){

	for(int i=start; i<=end; i++){
		string digit = digit + num[i];
		s += arr[int(stoi(digit))];
	}
}
void printAll(string num ,char *output, int n, int i,int j,int digit){
	//cout<<"called\n";
	//base case
	if(digit == 1 && i>=n){
		output[j]='\0';
		//cout<<"reached end\n";
		cout<<output<<endl;
		return ;
	}
	else if(digit == 2 && i>=n-1){
		output[j]='\0';	
		if(i<=n-1)
			 	cout<<output<<endl;
		return ;
	}


	if(digit == 1){
		
		output[j] = arr[stoi(num.substr(i,1))]; 
	} else if(digit == 2){
		int number = stoi(num.substr(i,2));
		if(number<=26){
			output[j] = arr[number];
		} else {
			
			output[j++] = arr[stoi(num.substr(i,1))];
		
			output[j] = arr[stoi(num.substr(i+1,1))];
		}
	}
	//cout<<output[j]<<endl;

	if(digit == 1)
		printAll(num,output,n,i+1,j+1,digit);
	else if(digit == 2)
		printAll(num,output,n,i+2,j+1,digit);
	digit = 2;
	printAll(num,output,n,i+1,j+1,digit);


}

int main(){

	for(int i=1; i<=26; i++){
		arr[i]= 'A'+i-1;
		// cout<<arr[i]<<", ";
	}
	string num;
	char output[num.length()];
	getline(cin,num);
	printAll(num,output,num.length(),0,0,1);




	return 0;
}