#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int cnt=0;

class Employee   //创建Employee类
{
protected:
    string name;         // 员工姓名
    double BasicWage;  // 员工的基本工资
public:
    bool flag;           // 0表示不存在,不可以访问; 1表示存在,可以访问

    Employee();         //无参数的构造函数
    Employee(string name, double BasicWage); //带有参数的构造函数
    virtual ~Employee();   //析构函数

    double getBasicSalary();  //显示基本工资函数
    string getName();  //显示名字函数
    void setName(string name);  //修改名字函数
	void setBasicWage(double wage);
	
    virtual void show();   //输出对应职工的属性
    virtual void showCount();  //输出对应职工的人数
    virtual void showSalary();  //输出对应职工的总工资、平均工资
};

Employee::Employee()
{
}

Employee::Employee(string name, double BasicWage)
{
    this->name = name;
    this->BasicWage = BasicWage;
}

Employee::~Employee() {
}

double Employee::getBasicSalary()
{
    return BasicWage;
}

string Employee::getName()
{
    return name;
}

void Employee::setName(string name)
{
    this->name = name;
}

void Employee::setBasicWage(double wage){
	this->BasicWage=wage;
}

void Employee::show() {
}

void Employee::showCount() {
}

void Employee::showSalary(){
}


class TemporaryEmployee : public Employee //创建临时员工类,继承Employee类
{
private:
    double bonus;               // 奖金
    double realSalary;          // 实发工资
    static int tempCount;       // 静态数据类型: 临时员工总人数
    static double totalSalary;  // 静态数据类型: 临时员工总工资
public:
    TemporaryEmployee();
    TemporaryEmployee(string name, double BasicWage, double bonus);
    virtual ~TemporaryEmployee();
	
    double getBonus();
    double getRealSalary();    // 获得临时工的实发工资

    void show();               // 输出临时工的姓名、基本工资、所得税、实发工资
    void showCount();   // 输出临时员工的总数
    void showSalary();  // 输出临时员工的总工资、平均工资
    
    void setbonus(double bon);
    void setrealSalary();
};

int TemporaryEmployee::tempCount = 0; //定义临时员工的人数赋初值为0

double TemporaryEmployee::totalSalary = 0;// 定义临时员工的总工资赋初值为0

TemporaryEmployee::TemporaryEmployee()
{
    this->bonus = 0;
    this->realSalary = getBasicSalary();
    tempCount++;               // 临时员工个数加1
    totalSalary += 0;
}

TemporaryEmployee::TemporaryEmployee(string name, double BasicWage, double bonus) : Employee(name, BasicWage)
{
    this->bonus = bonus;
    this->realSalary = getBasicSalary() + bonus;
    tempCount++;
    totalSalary += realSalary;
}

TemporaryEmployee::~TemporaryEmployee()
{
    tempCount--;               // 临时员工个数减1
    totalSalary -= realSalary;
}

double TemporaryEmployee::getBonus()
{
    return bonus;
}

double TemporaryEmployee::getRealSalary()
{
    return realSalary;
}

void TemporaryEmployee::show()
{
    cout << getName() << "\t" << getBasicSalary() << "\t" << getBonus() << "\t" << getRealSalary() << endl;
}

void TemporaryEmployee::showCount()
{
    cout << "临时职工的总人数为: " << tempCount << endl;
}

void TemporaryEmployee::showSalary()
{
    cout << "临时职工的总工资为: " << totalSalary << endl;
    cout << "临时职工的平均工资为: " << totalSalary / tempCount << endl << endl;
}


ostream& operator<<(ostream& cout, TemporaryEmployee& t) //重载左移运算符 (用于输出一个对象的信息)
{
    cout << t.getName()  << "\t" << t.getBasicSalary() << "\t"
         << t.getBonus() << "\t" << t.getRealSalary() << endl;
    return cout;
}

void TemporaryEmployee::setbonus(double bon){
	this->bonus=bon;
}

void TemporaryEmployee::setrealSalary(){
	this->realSalary=this->BasicWage+this->bonus;
}

class RegularEmployees : public Employee
{
private:
    double tax;                 // 税收
    double realSalary;          // 实发工资
    static int formalCount;     // 静态数据类型: 正式职工总人数
    static double totalSalary;  // 静态数据类型: 正式职工总工资、平均工资
public:
    RegularEmployees();
    RegularEmployees(string name, double BasicWage, double tax);
    virtual ~RegularEmployees();

    double getTax();
    double getRealSalary();

    void show();                // 输出正式职工的姓名、基本工资、所得税、实发工资
    void showCount();    // 输出正式职工的总数
    void showSalary();   // 输出正式职工的总工资、平均工资
    
    void settax(double tax);
    void setrealSalary();
};

int RegularEmployees::formalCount = 0;  // 定义临时员工的人数赋初值为0
double RegularEmployees::totalSalary = 0;  //定义临时员工的总工资赋初值为0

RegularEmployees::RegularEmployees()
{
    this->tax = 0;
    this->realSalary = getBasicSalary();
    formalCount++;
    totalSalary += 0;
}

RegularEmployees::RegularEmployees(string name, double BasicWage, double tax) : Employee(name, BasicWage)
{
    this->tax = tax;
    this->realSalary = getBasicSalary() - tax;
    formalCount++;
    totalSalary += realSalary;
}

RegularEmployees::~RegularEmployees()
{
    formalCount--;
    totalSalary -= realSalary;
}

double RegularEmployees::getRealSalary()
{
    return realSalary;
}

double RegularEmployees::getTax()
{
    return tax;
}

void RegularEmployees::show()
{
    cout << getName() << "\t" << getBasicSalary() << "\t" << getTax() << "\t" << getRealSalary() << endl;
}

void RegularEmployees::showCount()
{
    cout << "正式职工的总人数为: " << formalCount << endl;
}

void RegularEmployees::showSalary()
{
    cout << "正式职工的总工资为: " << totalSalary << endl;
    cout << "正式职工的平均工资为: " << totalSalary / formalCount << endl << endl;
}


ostream& operator<<(ostream& cout, RegularEmployees& f)  //重载左移运算符 (用于输出一个对象的信息)
{
    cout << f.getName() << "\t" << f.getBasicSalary() << "\t"
         << f.getTax()  << "\t" << f.getRealSalary()  << endl;
    return cout;
}

void RegularEmployees::settax(double tax){
	this->tax=tax;
}

void RegularEmployees::setrealSalary(){
	this->realSalary=this->BasicWage-this->tax;
}

const int MAX = 100;                                     // 职工的最大人数

void Menu();                                                // 菜单
void output(Employee* pEmployee[], int num);               // 输出员工工资信息
void queryEmployeeByName(Employee* pEmployee[], int num);    // 根据姓名来查找员工信息
void modifyEmployeeByName(Employee* pEmployee[], int num);   // 根据姓名来修改员工信息
void clearEmployeeByName(Employee* pEmployee[], int& num);   // 根据姓名来删除员工信息
void deleteAllEmployee(Employee* pEmployee[], int num);      // 用循环来删除指针数组
void showEmployeeNum(Employee* pEmployee[], int num);        // 显示两种员工的人数
void showEmployeeSalary(Employee* pEmployee[], int num);     // 显示员工总的实发工资、平均实发工资
void input(Employee* pEmployee[], int n);					//添加数据 
void Init(Employee* pEmployee[]);							//读取文件 
void write(Employee* pEmployee[]);							//写入文件 
int main()
{
    int n;
    cout<<"------尊贵的经理,欢迎来到员工工资信息管理系统------"<<endl;

    Employee* pEmployee[MAX];
    memset(pEmployee,0,MAX); // 将pEmployee的现有元素个数调至num个, 其值为0
	Init(pEmployee);
    int ch;
    while (true)
    {

    	Menu();
        cout << "\n\n------------------------------------------------";
        cout << "\n请选择您需要的操作（参考如上菜单）: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
			cout<<"请输入要添加员工的人数:"<<endl;
        	cin>>n;
            input(pEmployee, n);
            break;
        case 2:
            modifyEmployeeByName(pEmployee, cnt);
            break;
        case 3:
            queryEmployeeByName(pEmployee, cnt);
            system("pause");
            break;
        case 4:
            clearEmployeeByName(pEmployee, cnt);
            break;
        case 5:
            output(pEmployee, cnt);
            break;
        case 6:
            Menu();
            break;
        case 7:
            showEmployeeNum(pEmployee, cnt);
            break;
        case 8:
            showEmployeeSalary(pEmployee, cnt);
            break;
        case 0:
		 write(pEmployee) ;
           deleteAllEmployee(pEmployee, cnt);  // 退出程序

            cout << "成功退出系统" << endl;
            return 0;
        default:
            cout << "您的输入有误, 请重新输入" << endl;
            break;
        }
    }
	
    return 0;
}

void Init(Employee* pEmployee[]){   //输入流函数
	ifstream in;
	in.open("data.txt",ios::in);
	int flag;
	string name;
	double BasicWage,other;
	while(!(in.eof())){
		in>>flag>>name>>BasicWage>>other;
		if(flag){
			pEmployee[cnt]=new RegularEmployees(name,BasicWage,other);
		}else{
			pEmployee[cnt]=new TemporaryEmployee(name,BasicWage,other);
		}
		pEmployee[cnt]->flag=1;
		cnt++;
	}
	in.close();
}

void write(Employee* pEmployee[]){ //写数据函数
	ofstream out;
	out.open("data.txt",ios::out);
	for(int i=0;i<cnt;i++){
		if (pEmployee[i]->flag)
        {
            RegularEmployees* p1 = dynamic_cast<RegularEmployees*>(pEmployee[i]);
            TemporaryEmployee* p2 = dynamic_cast<TemporaryEmployee*>(pEmployee[i]);
            if (p1 != NULL && p2 == NULL)
            {
                out<<1<<" "<<p1->getName()<<" "<<p1->getBasicSalary()<<" "<<p1->getTax();
            }
            else if (p1 == NULL && p2 != NULL)
            {
                out<<0<<" "<<p2->getName()<<" "<<p2->getBasicSalary()<<" "<<p2->getBonus();
            }
            else
            {
                cout << "写入文件失败" << endl;
                exit(1);
            }
            out<<endl;
        }
	}
}


void Menu()  //提示菜单
{
    cout << endl << endl;
    cout << "*************尊贵的经理,如下是系统的基本操作************************" << endl;
    cout << "*     *输入1 增加员工信息            	*输入2 修改员工信息        *" << endl;
    cout << "*     *输入3 查找员工信息            	*输入4 删除员工信息        *" << endl;
    cout << "*     *输入5 显示员工记录            	*输入6 显示菜单            *" << endl;
    cout << "*     *输入7 统计员工数量           	*输入8 统计总发放工资      *" << endl;
    cout << "*     *输入0 退出系统                                              *" << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**" << endl;
}

void input(Employee* pEmployee[], int n)    //输入员工信息
{
    string name;        // 员工姓名
    double BasicWage; // 员工基本工资
    double tax;         // 员工税收
    double bonus;       // 员工奖金
    char choice;

    cout << "请正确输入员工的类型 0表示临时员工、1表示正式员工（）: \n" << endl;

    for (int i = cnt; i < cnt+n; i++)
    {
        cin >> choice;
        if (choice == '1')
        {
            cin >> name >> BasicWage >> tax;
            pEmployee[i] = new RegularEmployees(name, BasicWage, tax);
        }
        else if (choice == '0')
        {
            cin >> name >> BasicWage >> bonus;
            pEmployee[i] = new TemporaryEmployee(name, BasicWage, bonus);
        }
        else
        {
            cout << "您的输入有误!!!" << endl;
            pEmployee[i] = new TemporaryEmployee();
        }
        pEmployee[i]->flag = true;   // 可以访问
    }
    cnt+=n;
}

void output(Employee* pEmployee[], int num)  // 输出员工信息
{
    cout << endl << endl;
    cout << "姓名  基本工资 税收或奖金 实际工资" << endl;
    for (int i = 0; i < num; i++)
    {
        if (pEmployee[i]->flag)
        {
            RegularEmployees* p1 = dynamic_cast<RegularEmployees*>(pEmployee[i]);
            TemporaryEmployee* p2 = dynamic_cast<TemporaryEmployee*>(pEmployee[i]);
            if (p1 != NULL && p2 == NULL)
            {
                cout << *p1;
            }
            else if (p1 == NULL && p2 != NULL)
            {
                cout << *p2;
            }
            else
            {
                cout << "输出错误！" << endl;
                exit(1);
            }
        }
    }
}


void queryEmployeeByName(Employee* pEmployee[], int num) //根据姓名来查找员工信息
{
    string queryName;
    cout << "\n请输入要查询的员工的姓名: " << endl;
    cin >> queryName;

    for (int i = 0; i < num; i++)
    {
        if (pEmployee[i]->getName() == queryName && pEmployee[i]->flag)
        {
            cout << "员工姓名为: " << queryName << ", 员工基本工资是: " << pEmployee[i]->getBasicSalary() << endl;
            return; // 查找成功
        }
    }

    cout << "查找失败 !!!" << endl;
}


void modifyEmployeeByName(Employee* pEmployee[], int num)     // 根据姓名来修改员工信息
{
    string queryName, newName;
    cout << "\n请输入要修改的员工的姓名: " << endl;
    cin >> queryName;
	int flag;
    for (int i = 0; i < num; i++)
    {
        if (pEmployee[i]->getName() == queryName && pEmployee[i]->flag)              // 查找成功
        {
            RegularEmployees* p1 = dynamic_cast<RegularEmployees*>(pEmployee[i]);
            TemporaryEmployee* p2 = dynamic_cast<TemporaryEmployee*>(pEmployee[i]);
            if (p1 != NULL && p2 == NULL)
            {
                cout << endl << endl;
    			cout << "********************************************" << endl;
    			cout << "*     		*输入1 修改名字		   *" << endl;
    			cout << "*     		*输入2 修改基础工资	   *" << endl;
    			cout << "*     		*输入3 修改所得税	   *" << endl;
    			cout << "*     		*输入0 退出系统		   *" << endl;
    			cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**" << endl;
    			cin>>flag;
    			string name;
    			double basewage;
    			double tax;
    			switch(flag){
    				case 1:
    					cout<<"请输入新的名字"<<endl;
						cin>>name;
						p1->setName(name);
						break;
					case 2:
						cout<<"请输入新的基本工资"<<endl;
						cin>>basewage;
						p1->setBasicWage(basewage);
						p1->setrealSalary();
						break;
					case 3:
						cout<<"请输入新的所得税数额"<<endl;
						cin>>tax;
						p1->settax(tax);
						p1->setrealSalary();
						break;
					break; 
					case 0:
						return;
					break;
				}
            }
            else if (p1 == NULL && p2 != NULL)
            {
                cout << endl << endl;
    			cout << "********************************************" << endl;
    			cout << "*     		*输入1 修改名字		   *" << endl;
    			cout << "*     		*输入2 修改基础工资    *" << endl;
    			cout << "*     		*输入3 修改奖金        *" << endl;
    			cout << "*     		*输入0 退出系统		   *" << endl;
    			cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**" << endl;
    			cin>>flag;
				string name;
    			double basewage;
    			double bonus;
				switch(flag){
    				case 1:
    					cout<<"请输入新的名字"<<endl;
						cin>>name;
						p2->setName(name);
						break;
					case 2:
						cout<<"请输入新的基本工资"<<endl;
						cin>>basewage;
						p2->setBasicWage(basewage);
						p2->setrealSalary();
						break;
					case 3:
						cout<<"请输入新的奖金数额"<<endl;
						cin>>bonus;
						p2->setbonus(bonus);
						p2->setrealSalary();
						break;
					break; 
					case 0:
						return;
					break;
				}
            }
            else
            {
                cout << "输出错误！" << endl;
                exit(1);
            }
            return; // 查找成功, 返回
        }
    }

    cout << "查找失败, 该姓名无法修改!" << endl;
}

void clearEmployeeByName(Employee* pEmployee[], int& num)    // 根据姓名来删除员工信息
{
    string Name;
    cout << "\n请输入要删除的员工的姓名: " << endl;
    cin >> Name;

    for (int i = 0; i < num; i++)
    {
        if (pEmployee[i]->getName() == Name)    // 查找成功
        {
			for(int j=i;j<num-1;j++)               // 删除pEmployee[i]元素
			{
				pEmployee[j]=pEmployee[j+1];
			}
            num--;
            cnt--;
            return;                                // 查找成功, 返回
        }
    }

    cout << "查无此人, 无法删除!" << endl;
}

void showEmployeeNum(Employee* pEmployee[], int num)   //显示各种员工人数
{

    int formalEmployeeNum = 0;
    int tempEmployeeNum = 0;
    for (int i = 0; i < num; i++)
    {
        if (pEmployee[i]->flag)
        {
            RegularEmployees* p1 = dynamic_cast<RegularEmployees*>(pEmployee[i]);
            TemporaryEmployee* p2 = dynamic_cast<TemporaryEmployee*>(pEmployee[i]);
            if (p1 != NULL && p2 == NULL)
            {
                formalEmployeeNum++;
            }
            else if (p1 == NULL && p2 != NULL)
            {
                tempEmployeeNum++;
            }
            else
            {
                cout << "输出错误！" << endl;
                exit(1);
            }
        }
    }
    cout << "临时员工工的总人数为: " << tempEmployeeNum << endl;
    cout << "正式员工的总人数为: " << formalEmployeeNum << endl;
}


void showEmployeeSalary(Employee* pEmployee[], int num)  // 显示员工总的实发工资、平均实发工资
{
    int formalEmployeeNum = 0;
    int tempEmployeeNum = 0;
    int formalEmployeeSalary = 0;
    int tempEmployeeSalary = 0;

    for (int i = 0; i < num; i++)
    {
        if (pEmployee[i]->flag)
        {
            RegularEmployees* p1 = dynamic_cast<RegularEmployees*>(pEmployee[i]);
            TemporaryEmployee* p2 = dynamic_cast<TemporaryEmployee*>(pEmployee[i]);
            if (p1 != NULL && p2 == NULL)
            {
                formalEmployeeNum++;
                formalEmployeeSalary += p1->getRealSalary();
            }
            else if (p1 == NULL && p2 != NULL)
            {
                tempEmployeeNum++;
                tempEmployeeSalary += p2->getRealSalary();
            }
            else
            {
                cout << "输出错误！" << endl;
                exit(1);
            }
        }
    }
    cout << "临时员工的总的实际发放的工资:  " << tempEmployeeSalary << endl;
    cout << "临时员工的平均实际发放工资: " << tempEmployeeSalary / tempEmployeeNum << endl;

    cout << "正式员工的总实实际发放工资:  " << formalEmployeeSalary << endl;
    cout << "正式员工的平均实际发放工资: " << formalEmployeeSalary / formalEmployeeNum << endl;
}

void deleteAllEmployee(Employee* pEmployee[], int num) //用循环来删除指针数组

{
    for (int i = 0; i < num; i++)
    {
        delete pEmployee[i];
    }
}
