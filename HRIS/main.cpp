//
//  main.cpp
//  HRIS
//
//  Created by lucky on 10/23/17.
//  Copyright © 2017 luck. All rights reserved.
//

#include <iostream>
using namespace std;
int curId=1;

int main(int argc, const char * argv[]) {
    
    
    return 0;
}

class Employee {
private:
    string Name;
    int Id;
    string Gender;
    string DateofHire;
    int Salary;
    string Title;
    int Status;
private:
    Employee();
    void setEmployee(string,int,string,string,int,string,int);
    void changeSalary(int curSalary);
    void changeTitle(string curtitle);
    void changeStatus(int curStatus);//1.regular 2.probation 3.terminal
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
void Employee::changeStatus(int curStatus){

}
class Regular : public Employee{

};
class Contractor : public Employee{

};

