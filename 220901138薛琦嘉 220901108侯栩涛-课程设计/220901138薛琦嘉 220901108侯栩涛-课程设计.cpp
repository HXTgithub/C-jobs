#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int cnt=0;

class Employee   //����Employee��
{
protected:
    string name;         // Ա������
    double BasicWage;  // Ա���Ļ�������
public:
    bool flag;           // 0��ʾ������,�����Է���; 1��ʾ����,���Է���

    Employee();         //�޲����Ĺ��캯��
    Employee(string name, double BasicWage); //���в����Ĺ��캯��
    virtual ~Employee();   //��������

    double getBasicSalary();  //��ʾ�������ʺ���
    string getName();  //��ʾ���ֺ���
    void setName(string name);  //�޸����ֺ���
	void setBasicWage(double wage);
	
    virtual void show();   //�����Ӧְ��������
    virtual void showCount();  //�����Ӧְ��������
    virtual void showSalary();  //�����Ӧְ�����ܹ��ʡ�ƽ������
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


class TemporaryEmployee : public Employee //������ʱԱ����,�̳�Employee��
{
private:
    double bonus;               // ����
    double realSalary;          // ʵ������
    static int tempCount;       // ��̬��������: ��ʱԱ��������
    static double totalSalary;  // ��̬��������: ��ʱԱ���ܹ���
public:
    TemporaryEmployee();
    TemporaryEmployee(string name, double BasicWage, double bonus);
    virtual ~TemporaryEmployee();
	
    double getBonus();
    double getRealSalary();    // �����ʱ����ʵ������

    void show();               // �����ʱ�����������������ʡ�����˰��ʵ������
    void showCount();   // �����ʱԱ��������
    void showSalary();  // �����ʱԱ�����ܹ��ʡ�ƽ������
    
    void setbonus(double bon);
    void setrealSalary();
};

int TemporaryEmployee::tempCount = 0; //������ʱԱ������������ֵΪ0

double TemporaryEmployee::totalSalary = 0;// ������ʱԱ�����ܹ��ʸ���ֵΪ0

TemporaryEmployee::TemporaryEmployee()
{
    this->bonus = 0;
    this->realSalary = getBasicSalary();
    tempCount++;               // ��ʱԱ��������1
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
    tempCount--;               // ��ʱԱ��������1
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
    cout << "��ʱְ����������Ϊ: " << tempCount << endl;
}

void TemporaryEmployee::showSalary()
{
    cout << "��ʱְ�����ܹ���Ϊ: " << totalSalary << endl;
    cout << "��ʱְ����ƽ������Ϊ: " << totalSalary / tempCount << endl << endl;
}


ostream& operator<<(ostream& cout, TemporaryEmployee& t) //������������� (�������һ���������Ϣ)
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
    double tax;                 // ˰��
    double realSalary;          // ʵ������
    static int formalCount;     // ��̬��������: ��ʽְ��������
    static double totalSalary;  // ��̬��������: ��ʽְ���ܹ��ʡ�ƽ������
public:
    RegularEmployees();
    RegularEmployees(string name, double BasicWage, double tax);
    virtual ~RegularEmployees();

    double getTax();
    double getRealSalary();

    void show();                // �����ʽְ�����������������ʡ�����˰��ʵ������
    void showCount();    // �����ʽְ��������
    void showSalary();   // �����ʽְ�����ܹ��ʡ�ƽ������
    
    void settax(double tax);
    void setrealSalary();
};

int RegularEmployees::formalCount = 0;  // ������ʱԱ������������ֵΪ0
double RegularEmployees::totalSalary = 0;  //������ʱԱ�����ܹ��ʸ���ֵΪ0

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
    cout << "��ʽְ����������Ϊ: " << formalCount << endl;
}

void RegularEmployees::showSalary()
{
    cout << "��ʽְ�����ܹ���Ϊ: " << totalSalary << endl;
    cout << "��ʽְ����ƽ������Ϊ: " << totalSalary / formalCount << endl << endl;
}


ostream& operator<<(ostream& cout, RegularEmployees& f)  //������������� (�������һ���������Ϣ)
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

const int MAX = 100;                                     // ְ�����������

void Menu();                                                // �˵�
void output(Employee* pEmployee[], int num);               // ���Ա��������Ϣ
void queryEmployeeByName(Employee* pEmployee[], int num);    // ��������������Ա����Ϣ
void modifyEmployeeByName(Employee* pEmployee[], int num);   // �����������޸�Ա����Ϣ
void clearEmployeeByName(Employee* pEmployee[], int& num);   // ����������ɾ��Ա����Ϣ
void deleteAllEmployee(Employee* pEmployee[], int num);      // ��ѭ����ɾ��ָ������
void showEmployeeNum(Employee* pEmployee[], int num);        // ��ʾ����Ա��������
void showEmployeeSalary(Employee* pEmployee[], int num);     // ��ʾԱ���ܵ�ʵ�����ʡ�ƽ��ʵ������
void input(Employee* pEmployee[], int n);					//������� 
void Init(Employee* pEmployee[]);							//��ȡ�ļ� 
void write(Employee* pEmployee[]);							//д���ļ� 
int main()
{
    int n;
    cout<<"------���ľ���,��ӭ����Ա��������Ϣ����ϵͳ------"<<endl;

    Employee* pEmployee[MAX];
    memset(pEmployee,0,MAX); // ��pEmployee������Ԫ�ظ�������num��, ��ֵΪ0
	Init(pEmployee);
    int ch;
    while (true)
    {

    	Menu();
        cout << "\n\n------------------------------------------------";
        cout << "\n��ѡ������Ҫ�Ĳ������ο����ϲ˵���: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
			cout<<"������Ҫ���Ա��������:"<<endl;
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
           deleteAllEmployee(pEmployee, cnt);  // �˳�����

            cout << "�ɹ��˳�ϵͳ" << endl;
            return 0;
        default:
            cout << "������������, ����������" << endl;
            break;
        }
    }
	
    return 0;
}

void Init(Employee* pEmployee[]){   //����������
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

void write(Employee* pEmployee[]){ //д���ݺ���
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
                cout << "д���ļ�ʧ��" << endl;
                exit(1);
            }
            out<<endl;
        }
	}
}


void Menu()  //��ʾ�˵�
{
    cout << endl << endl;
    cout << "*************���ľ���,������ϵͳ�Ļ�������************************" << endl;
    cout << "*     *����1 ����Ա����Ϣ            	*����2 �޸�Ա����Ϣ        *" << endl;
    cout << "*     *����3 ����Ա����Ϣ            	*����4 ɾ��Ա����Ϣ        *" << endl;
    cout << "*     *����5 ��ʾԱ����¼            	*����6 ��ʾ�˵�            *" << endl;
    cout << "*     *����7 ͳ��Ա������           	*����8 ͳ���ܷ��Ź���      *" << endl;
    cout << "*     *����0 �˳�ϵͳ                                              *" << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**" << endl;
}

void input(Employee* pEmployee[], int n)    //����Ա����Ϣ
{
    string name;        // Ա������
    double BasicWage; // Ա����������
    double tax;         // Ա��˰��
    double bonus;       // Ա������
    char choice;

    cout << "����ȷ����Ա�������� 0��ʾ��ʱԱ����1��ʾ��ʽԱ������: \n" << endl;

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
            cout << "������������!!!" << endl;
            pEmployee[i] = new TemporaryEmployee();
        }
        pEmployee[i]->flag = true;   // ���Է���
    }
    cnt+=n;
}

void output(Employee* pEmployee[], int num)  // ���Ա����Ϣ
{
    cout << endl << endl;
    cout << "����  �������� ˰�ջ򽱽� ʵ�ʹ���" << endl;
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
                cout << "�������" << endl;
                exit(1);
            }
        }
    }
}


void queryEmployeeByName(Employee* pEmployee[], int num) //��������������Ա����Ϣ
{
    string queryName;
    cout << "\n������Ҫ��ѯ��Ա��������: " << endl;
    cin >> queryName;

    for (int i = 0; i < num; i++)
    {
        if (pEmployee[i]->getName() == queryName && pEmployee[i]->flag)
        {
            cout << "Ա������Ϊ: " << queryName << ", Ա������������: " << pEmployee[i]->getBasicSalary() << endl;
            return; // ���ҳɹ�
        }
    }

    cout << "����ʧ�� !!!" << endl;
}


void modifyEmployeeByName(Employee* pEmployee[], int num)     // �����������޸�Ա����Ϣ
{
    string queryName, newName;
    cout << "\n������Ҫ�޸ĵ�Ա��������: " << endl;
    cin >> queryName;
	int flag;
    for (int i = 0; i < num; i++)
    {
        if (pEmployee[i]->getName() == queryName && pEmployee[i]->flag)              // ���ҳɹ�
        {
            RegularEmployees* p1 = dynamic_cast<RegularEmployees*>(pEmployee[i]);
            TemporaryEmployee* p2 = dynamic_cast<TemporaryEmployee*>(pEmployee[i]);
            if (p1 != NULL && p2 == NULL)
            {
                cout << endl << endl;
    			cout << "********************************************" << endl;
    			cout << "*     		*����1 �޸�����		   *" << endl;
    			cout << "*     		*����2 �޸Ļ�������	   *" << endl;
    			cout << "*     		*����3 �޸�����˰	   *" << endl;
    			cout << "*     		*����0 �˳�ϵͳ		   *" << endl;
    			cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**" << endl;
    			cin>>flag;
    			string name;
    			double basewage;
    			double tax;
    			switch(flag){
    				case 1:
    					cout<<"�������µ�����"<<endl;
						cin>>name;
						p1->setName(name);
						break;
					case 2:
						cout<<"�������µĻ�������"<<endl;
						cin>>basewage;
						p1->setBasicWage(basewage);
						p1->setrealSalary();
						break;
					case 3:
						cout<<"�������µ�����˰����"<<endl;
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
    			cout << "*     		*����1 �޸�����		   *" << endl;
    			cout << "*     		*����2 �޸Ļ�������    *" << endl;
    			cout << "*     		*����3 �޸Ľ���        *" << endl;
    			cout << "*     		*����0 �˳�ϵͳ		   *" << endl;
    			cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**" << endl;
    			cin>>flag;
				string name;
    			double basewage;
    			double bonus;
				switch(flag){
    				case 1:
    					cout<<"�������µ�����"<<endl;
						cin>>name;
						p2->setName(name);
						break;
					case 2:
						cout<<"�������µĻ�������"<<endl;
						cin>>basewage;
						p2->setBasicWage(basewage);
						p2->setrealSalary();
						break;
					case 3:
						cout<<"�������µĽ�������"<<endl;
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
                cout << "�������" << endl;
                exit(1);
            }
            return; // ���ҳɹ�, ����
        }
    }

    cout << "����ʧ��, �������޷��޸�!" << endl;
}

void clearEmployeeByName(Employee* pEmployee[], int& num)    // ����������ɾ��Ա����Ϣ
{
    string Name;
    cout << "\n������Ҫɾ����Ա��������: " << endl;
    cin >> Name;

    for (int i = 0; i < num; i++)
    {
        if (pEmployee[i]->getName() == Name)    // ���ҳɹ�
        {
			for(int j=i;j<num-1;j++)               // ɾ��pEmployee[i]Ԫ��
			{
				pEmployee[j]=pEmployee[j+1];
			}
            num--;
            cnt--;
            return;                                // ���ҳɹ�, ����
        }
    }

    cout << "���޴���, �޷�ɾ��!" << endl;
}

void showEmployeeNum(Employee* pEmployee[], int num)   //��ʾ����Ա������
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
                cout << "�������" << endl;
                exit(1);
            }
        }
    }
    cout << "��ʱԱ������������Ϊ: " << tempEmployeeNum << endl;
    cout << "��ʽԱ����������Ϊ: " << formalEmployeeNum << endl;
}


void showEmployeeSalary(Employee* pEmployee[], int num)  // ��ʾԱ���ܵ�ʵ�����ʡ�ƽ��ʵ������
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
                cout << "�������" << endl;
                exit(1);
            }
        }
    }
    cout << "��ʱԱ�����ܵ�ʵ�ʷ��ŵĹ���:  " << tempEmployeeSalary << endl;
    cout << "��ʱԱ����ƽ��ʵ�ʷ��Ź���: " << tempEmployeeSalary / tempEmployeeNum << endl;

    cout << "��ʽԱ������ʵʵ�ʷ��Ź���:  " << formalEmployeeSalary << endl;
    cout << "��ʽԱ����ƽ��ʵ�ʷ��Ź���: " << formalEmployeeSalary / formalEmployeeNum << endl;
}

void deleteAllEmployee(Employee* pEmployee[], int num) //��ѭ����ɾ��ָ������

{
    for (int i = 0; i < num; i++)
    {
        delete pEmployee[i];
    }
}
