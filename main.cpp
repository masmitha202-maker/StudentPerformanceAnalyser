#include<iostream>
#include<string>
using namespace std;
struct Student
{
    int rollNo;
    string name;
    int marks[5];
    int total;
    float average;
    char grade;
};
int inputStudents(Student students[])
{
    int n;
    cout<<"Enter number of students: ";
    cin>>n;
    for(int i=0;i<n;i++){
        Student *p;
        p=&students[i];
        cout<<"\nEnter details of student "<<i+1<<endl;
        cout<<"Enter roll number: ";
        cin>>(*p).rollNo;
        cout<<"Enter name: ";
        cin>>(*p).name;
        for(int j=0;j<5;j++){
            cout<<"Enter marks "<<j+1<<": ";
            cin>>(*p).marks[j];
            while((*p).marks[j]<0 || (*p).marks[j]>100){
                cout<<"Invalid mark. Enter mark between 0 and 100: ";
                cin>>(*p).marks[j];
            }
        }
    }
    return n;
}
void calculateTotal(Student student[],int n)
{
    for(int i=0;i<n;i++){
        Student *p;
        p = &students[i];
        (*p).total = 0;
        for(int j=0;j<5;j++){
            (*p).total =(*p).total + (*p).marks[j];
        }
        (*p).average = (*p).total/5.0;
    }
}
void calculateGrade(Student students[], int n)
{
    for(int i=0;i<n;i++){
        Student *p;
        p=&students[i];
        if((*p).average >=90){
            (*p).grade = 'A';
        }
        else if((*p).average >=75){
            (*p).grade = 'B';
        }
        else if((*p).average >= 60){
            (*p).grade ='C';
        }
        else if((*p).average >= 50){
            (*p).grade = 'D';
        }
        else{
            (*P).grade = 'F';
        }
    }
}
void displayStudents(Student students[],int n)
{
    for(int i=0;i<n;i++){
        Student *p;
        p= &students[i];
        cout<<"\nStudent "<<i+1<<endl;
        cout<<"Roll Number: "<<(*p).rollNo<<endl;
        cout<<"Name: "<<(*p).name<<endl;
        cout<<"Marks: ";
        for(int j=0;j<5;j++){
            cout<<(*p).marks[j]<<" ";
        }
        cout<<endl;
        cout<<"Total: "(*p).total<<endl;
        cout<<"Average: "(*p).average<<endl;
        cout<<"Grade: "(*p).grade<<endl;
    }
}