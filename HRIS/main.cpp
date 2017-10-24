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
    int Status;//1.regular 2.probation 3.terminated 4.Contract
public:
    Employee();
    virtual ~Employee();
    void setEmployee(string,string,string,int,string,int);
    string printEmployee();
    int getId();
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
Employee::~Employee(){
    
}
void Employee::setEmployee(string name, string gender, string dateofHire, int salary, string title, int status){
    Name=name;
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
int Employee::getId(){
    return Id;
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
class Contract : public Employee{

};

void changeStatusM(vector<Regular>* emps);
void addRecordM(vector<Regular>* remps,vector<Contract>* cemps);

int main(int argc, const char * argv[]) {
    int c;
    vector<Regular> remps;
    vector<Contract> cemps;
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
            cout<<"Regular Employee records\n";
            for (vector<Employee>::iterator it=remps.begin(); it!=remps.end(); it++) {
                Employee emp=*it;
                cout<<emp.printEmployee();
            }
            cout<<"\n";
            cout<<"Contract Employee records\n";
            for (vector<Employee>::iterator it=cemps.begin(); it!=cemps.end(); it++) {
                Employee emp=*it;
                cout<<emp.printEmployee();
            }
            cout<<"\n\n";
        }else if (c==2){
            changeStatusM(&remps);
        }else if (c==3){
            addRecordM(&remps,&cemps);
        }
        
    }while (c!=4);
    
    return 0;
}

void changeStatusM(vector<Regular>* remps){
    int id;
    cout<<"Which Employee you want to Update\n Id=\n";
    cin>>id;
    //cout<<"emps size:"<<emps->size()<<"\n";
    if(id>=curId||id<=0){
        cout<<"out of range of employee records\n";
        return;
    }
    bool found=false;
    Regular* remp=0;
    for (vector<Regular>::iterator it=remps->begin(); it!=remps->end(); it++) {
        Regular emp=*it;
        if (emp.getId()==id) {
            remp=&emp;
            found=true;
        }
        //cout<<emp.printEmployee();
    }
    //Regular* emp=dynamic_cast<Regular*>(&(emps->at(id-1)));
    //cout<<typeid(emps->at(id-1)).name()<<"\n";
    //cout<<emps->at(id-1).printEmployee()<<"\n";
    if (!found||remp==0) {
        cout<<"This employee's status can't be changed or not found\n";
        return;
    }
    //cout<<"getremp:"<<remp->printEmployee()<<"\n";
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
            remp->changeSalary(salary);
        }else if (c2==2){
            string title;
            cout<<"What's the new Title\n";
            cin>>title;
            remp->changeTitle(title);
        }else if (c2==3){
            int status;
            cout<<"What's the new Status?\n";
            cout<<"1.regular\n";
            cout<<"2.probation\n";
            cout<<"3.terminated\n";
            cin>>status;
            remp->changeStatus(status);
        }
        
        
    }while (c2!=4);
}
void addRecordM(vector<Regular>* remps,vector<Contract>* cemps){
    int c3;
    cout<<"Type of Employee\n";
    cout<<"-----------------\n";
    cout<<"1.Regular\n";
    cout<<"2.Contract\n";
    cin>>c3;
    if (c3==1) {
        Regular emp;
        string Name;
        string Gender;
        string DateofHire;
        int Salary;
        string Title;
        int Status;
        cout<<"What's the name?\n";
        cin>>Name;
        cout<<"What's the Gender?\n";
        cin>>Gender;
        cout<<"What's the Date of Hire?\n";
        cin>>DateofHire;
        cout<<"What's the Salary?\n";
        cin>>Salary;
        cout<<"What's the Status?\n";
        cout<<"1.regular\n";
        cout<<"2.probation\n";
        cin>>Status;
        emp.setEmployee(Name, Gender, DateofHire, Salary, Title, Status);
        remps->push_back(emp);
        
       // cout<<typeid(emp).name()<<"\n";
        
    }else if (c3==2){
        Contract emp;
        string Name;
        string Gender;
        string DateofHire;
        int Salary;
        string Title;
        int Status;
        cout<<"What's the name?\n";
        cin>>Name;
        cout<<"What's the Gender?\n";
        cin>>Gender;
        cout<<"What's the Date of Hire?\n";
        cin>>DateofHire;
        cout<<"What's the Salary?\n";
        cin>>Salary;
        Status=4;
        emp.setEmployee(Name, Gender, DateofHire, Salary, Title, Status);
        cemps->push_back(emp);
    }
}

