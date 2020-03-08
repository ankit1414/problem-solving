#include<iostream>
using namespace std;
class Student{
	string name,branch,sex;
	int rollno,age;
	int *marks;
	float percentage;

public:
	Student(){
	}
	void setdata(string n,string b , int roll, int a ,string s, int *m){
		name = n;
		branch = b; 
		rollno = roll;
		age = a;
		sex = s;
		marks = m;
		percentage = calcPercentage();
	}
	float calcPercentage(){
		float p = 0;
		for(int i=0; i<5; i++){
			p += marks[i];	
		}
		p /= 5;
		return p;
	}
	float getPercentage(){
		return percentage;
	}

	void display(){
		cout<<"Name : "<<name<<"  ::::  ";
		cout<<"percentage : "<<percentage<<endl;
	}
};
void display(Student *array,int size){
	cout<<"_____________________________________________\n";
	cout<<"Displaying Students having marks > 70%\n";
	bool isThere = false;
	for(int i=0;i<size; i++){
		if(array[i].getPercentage()>70){
			cout<<i+1<<") ";
			array[i].display();
			isThere = true;
		}
	}
	if(isThere == false){
		cout<<"No record! \n";
	}
}
int main(){
	int n=4;
	Student StudentArray[n];
	for(int i=0; i<n; i++){
		cout<<">> Enter the Data for Student #"<<i+1<<endl;
		string name,gender,branch;
		int age,rollno;
		int *marks;
		marks = new int[5];
		cout<<"Student name: "; getline(cin , name);
		cout<<"Branch : "; getline(cin , branch);
		cout<<"Age : "; cin>>age;
		cout<<"rollno : "; cin>>rollno;
		cout<<"Gender : "; cin>>gender;
		cout<<"Enter Marks in 5 subjects : ";
		for(int j=0; j<5; j++){
			cin>>marks[j];
		}
		StudentArray[i].setdata(name , branch , age , rollno,gender,marks);
		cin.ignore();
		cout<<endl;
	}
	display(StudentArray,n);
	return 0;
}