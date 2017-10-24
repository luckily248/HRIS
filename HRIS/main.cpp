//
//  main.cpp
//  HRIS
//
//  Created by lucky on 10/23/17.
//  Copyright © 2017 luck. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
using namespace std;
int curId=1;



class Employee {
protected:
    string Name;
    int Id;
    string Gender;
    string DateofHire;
    int Salary;
    string Title;
    int Status;//1.regular 2.probation 3.terminal 4.contract
public:
    Employee();
    void setEmployee(string,int,string,string,int,string,int);
    string printEmployee();
};
Employee::Employee(){
    Name="";
    Id=curId;
    curId++;
    Gender="";
    DateofHire="";
    Salary=-1;
    Title="";
    Status=-1;
}
void Employee::setEmployee(string name,int id, string gender, string dateofHire, int salary, string title, int status){
    Name=name;
    Id=id;
    Gender=gender;
    DateofHire=dateofHire;
    Salary=salary;
    Title=title;
    Status=status;
}
string Employee::printEmployee(){
    stringstream ss;
    ss<<Id<<"."<<Name<<" "<<Gender<<" "<<DateofHire<<" "<<Salary<<" "<<Title<<" "<<Status<<"\n";
    return ss.str();
}

class Regular : public Employee{
public:
    void changeSalary(int curSalary);
    void changeTitle(string curtitle);
    void changeStatus(int curStatus);//1.regular 2.probation 3.terminal
};
void Regular::changeSalary(int curSalary){
    Salary=curSalary;
}
void Regular::changeTitle(string curtitle){
    Title=curtitle;
}
void Regular::changeStatus(int curStatus){
    Status=curStatus;
}
class Contractor : public Employee{

};

void changeStatusM(vector<Employee> emps);

int main(int argc, const char * argv[]) {
    int c;
    vector<Employee> emps;
    do{
    cout<<"Welcome to CS13 HRIS\n";
    cout<<"-----------------------\n";
    cout<<"1.View Employee Records\n";
    cout<<"2.Updata Employee Records\n";
    //cout<<"3.Delete Employee Records\n";
    cout<<"3.Add an Employee Record\n";
    cout<<"4.quit\n";
    cout<<"\n";
    cin>>c;
    
        if (c==1) {
            for (vector<Employee>::iterator it=emps.begin(); it!=emps.end(); it++) {
                Employee emp=*it;
                cout<<emp.printEmployee();
            }
        }else if (c==2){
            
        }else if (c==3){
            
        }
        
    }while (c!=4);
    
    return 0;
}

void changeStatusM(vector<Employee> emps){
    int id;
    cout<<"Which Employee you want to Update\n Id=\n";
    cin>>id;
    Regular* emp=dynamic_cast<Regular*>(&(emps.at(id-1));
    if (emp==0) {
        cout<<"This employee's status can't be changed\n";
        return;
    }
    
    int c2;
    do{
        cout<<"Update Employee Records\n";
        cout<<"------------------------\n";
        cout<<"1.Change Salary\n";
        cout<<"2.Change Title\n";
        cout<<"3.Change Status\n";
        cout<<"4.Quit\n";
        cin>>c2;
        
        if (c2==1) {
            int salary;
            cout<<"How much Salary\n";
            cin>>salary;
        }else if (c2==2){
            
        }else if (c2==3){
            
        }
        
        
    }while (c2!=4);
}
