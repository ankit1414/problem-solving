#include <iostream>
using namespace std;

class Time {

    private:
    int hours;
    int minutes;
    int seconds;

    public:
    Time(int hours , int minutes, int seconds){
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;

    }
    void add(Time t2){
        int eminutes = 0;
        seconds += t2.seconds;
        if(seconds >=60){
            seconds %= 60;
            eminutes = seconds/60;

        }
        minutes += t2.minutes;
        minutes += eminutes;
        if(minutes >=60){
            hours = hours + minutes/60;
            minutes %= 60;
        }
        hours += t2.hours;

    }
    void display(){

        cout<<hours<<" hours, "<<minutes<<" minutes and "<<seconds<<" seconds\n";

    }

};
int main(){
    int hour1,min1,sec1;
    int hour2,min2,sec2;
    cout<<"Enter time #1:\nhours : "; 
    cin>>hour1;
    cout<<"minutes : ";
    cin>>min1;
    cout<<"seconds : ";
    cin>>sec1;
    cout<<"\nEnter time #2:\nhours : ";
    cin>>hour2;
    cout<<"minutes : ";
    cin>>min2;
    cout<<"seconds : ";
    cin>>sec2;

    Time t1(hour1,min1,sec1); // time 1
    Time t2(hour2,min2,sec2); // time 2
    t1.add(t2); // adding time 2 into time1
    cout<<"\nTime after adding time2 in time1\n";
    t1.display(); // displaying updated time1


    return 0;
}