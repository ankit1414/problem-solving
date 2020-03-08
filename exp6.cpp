#include<iostream>
using namespace std;
class Student{
public:
	string name,branch,sex;
	int rollno,age;
	int *marks;
	float percentage;

	Student(){
	}
	void display(){
		cout<<"Name : "<<name<<endl;
		cout<<"branch : "<<branch<<endl;
		cout<<"Age : "<<age<<endl;
		cout<<"rollno : "<<rollno<<endl;
		cout<<"sex : "<<sex<<endl;
	}
};

int main(){
    Student *sPointer = new Student;
    string temp;
    int t;
    cout<<"Enter the data for student : \nName : ";
    getline(cin,temp);
    sPointer->name = temp;
    cout<<"Gender : "; getline(cin, temp);
    sPointer->sex = temp;
    cout<<"Branch : "; getline(cin, temp);
    sPointer->branch = temp;
    cout<<"Age : "; cin>>t;
    sPointer->age = t;
    cout<<"Roll no : "; cin>>t;
    sPointer->rollno = t;
    cout<<"\nDisplaying data >> \n";
    cout<<"______________________________________\n";

    sPointer->display();
    

	return 0;
}