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
void calculateTotal(Student students[],int n)
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
            (*p).grade = 'F';
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
        cout<<"Total: "<<(*p).total<<endl;
        cout<<"Average: "<<(*p).average<<endl;
        cout<<"Grade: "<<(*p).grade<<endl;
    }
}

void findTopper(Student students[],int n){
    if(n==0){
    cout<<"No students available"<<endl;
    return;
    }

    int Topindex=0;
    for(int i=1;i<n;i++) {
        if(students[i].total> students[Topindex].total){
            Topindex=i;
        }
    }

    Student *p= &students[Topindex];
    cout<<"CLASS TOPPER"<<endl;
    cout<<"Roll Number: "<<p->rollNo <<endl;
    cout<< "Name: "<<p->name <<endl;
    cout<< "Total: "<<p->total <<endl;
    cout<< "Average: "<<p->average <<endl;
    cout<< "Grade: " <<p->grade <<endl;
}

void searchStudent(Student students[],int n){
    int Userchoose;
    cout<<"1) Search using Roll Number"<<endl;
    cout<< "2) Search using Name"<<endl;
    cout<<"Enter choice: ";
    cin>>Userchoose;

    if(Userchoose==1) {
    int rollNo;
    bool found=false;
    cout<<"Enter Roll Number: ";
    cin>>rollNo;

    for(int i=0;i<n;i++){
        if(students[i].rollNo==rollNo){
            Student *p= &students[i];

            cout<<"Roll Number: "<<p->rollNo <<endl;
            cout<<"Name: " <<p->name <<endl;
            cout<<"Total: " <<p->total<<endl;
            cout<<"Average: " <<p->average <<endl;
            cout<<"Grade: " <<p->grade <<endl;

            found=true;
            break;
        }
    }
    if(!found) {
        cout<<"Student doesn't exist"<<endl;
    }
}


    else if(Userchoose==2) {
    string name;
    bool found=false;
    cout<<"Enter Name: ";
    cin>>name;

    for(int i=0;i<n;i++){
        if(students[i].name==name){
            Student *p= &students[i];

            cout<<"Roll Number: "<<p->rollNo <<endl;
            cout<<"Name: " <<p->name <<endl;
            cout<<"Total: " <<p->total<<endl;
            cout<<"Average: " <<p->average <<endl;
            cout<<"Grade: " <<p->grade <<endl;

            found=true;
            break;
        }
    }
    if(!found) {
        cout<<"Student doesn't exist"<<endl;
    }
    }
}

int calculateClassTotal(Student students[],int n,int index) {
    if(index==n){
        return 0;
    }
    return students[index].total + calculateClassTotal(students,n,index+1);
}

void displayClassAverage(Student students[],int n){
    if(n==0){
        cout<<"No students available"<<endl;
        return;
    }

    int classTotal= calculateClassTotal(students,n,0);
    float classAverage= classTotal/(n*5.0);

    cout<<"Class Average: "<<classAverage<<endl;
}

void displayAboveClassAverage(Student students[],int n){
    if(n==0) {
        cout<<"No students available"<<endl;
        return;
    }

    int classTotal= calculateClassTotal(students,n,0);
    float classAverage= classTotal/(n*5.0);

    for(int i=0;i<n;i++){
        if(students[i].average>classAverage) {
            Student *p= &students[i];
            cout<<"Roll Number: "<< p->rollNo <<endl;
            cout<<"Name: " <<p->name <<endl;
            cout<<"Average: "<<p->average <<endl;
            cout<<"Grade: "<<p->grade <<endl;
        }
    }
}





int main() {
    Student students[100];
    int n=0;
    int choice;

    while(true) {
        cout<<"\n===== STUDENT PERFORMANCE ANALYZER ====="<<endl;
        cout<<"1. Add Student Details"<<endl;
        cout<<"2. Display All Students"<<endl;
        cout<<"3. Search Student"<<endl;
        cout<<"4. Find Class Topper"<<endl;
        cout<<"5. Calculate Class Average"<<endl;
        cout<<"6. Display Students Above Class Average"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        if(choice==1){
            n=inputStudents(students);
            calculateTotal(students,n);
            calculateGrade(students,n);
        }

        else if(choice==2){
            displayStudents(students,n);
        }
        else if(choice==3){
            searchStudent(students,n);
        }
        else if(choice==4){
            findTopper(students,n);
        }
        else if(choice==5){
            displayClassAverage(students,n);
        }
        else if(choice==6){
            displayAboveClassAverage(students,n);
        }
        else if(choice==7){
            cout<<"Exiting..."<<endl;
            break;
        }
        
        else{
            cout<<"Error: Invalid choice"<<endl;
        }
    }

    return 0;
}