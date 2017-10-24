//
//  main.cpp
//  HRIS
//
//  Created by lucky on 10/23/17.
//  Copyright © 2017 luck. All rights reserved.
//

#include <iostream>
#include <sstream>
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
    int Status;//1.regular 2.probation 3.terminal
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
int main(int argc, const char * argv[]) {
    int c1;
    do{
    cout<<"Welcome to CS13 HRIS\n";
    cout<<"-----------------------\n";
    cout<<"1.View Employee Records\n";
    cout<<"2.Updata Employee Records\n";
    //cout<<"3.Delete Employee Records\n";
    cout<<"3.Add an Employee Record\n";
    cout<<"4.quit\n";
    cout<<"\n";
    cin>>c1;
    
        if (c1==1) {
            
        }else if (c1==2){
            
        }else if (c1==3){
            
        }
        
    }while (c1!=4);
    
    return 0;
}

