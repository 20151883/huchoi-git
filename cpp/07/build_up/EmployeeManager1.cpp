#include <iostream>
#include <cstring>
using namespace std;
//상속이 필요한 이유에 대해 설명하기 위해 먼저 문제가 되는 상황을 먼저 연출.
//기능의 처리를 실제로 담당하는 클래스를 가리켜 '컨트롤 클래스'라고 부른다.
class PermanentWorker
{
private:
	char name[100];	
	int salary;
public:
	PermanentWorker(char* name, int money)
		: salary(money)
	{
		strcpy(this->name, name);
	}
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		cout<<"name: "<<name<<endl;
		cout<<"salary: "<<GetPay()<<endl<<endl;
	}
};

class EmployeeHandler
{
private:
	PermanentWorker* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0) 
	{ }
	void AddEmployee(PermanentWorker* emp)
	{
		empList[empNum++]=emp;
	}
	void ShowAllSalaryInfo() const
	{
		for(int i=0; i<empNum; i++)
			empList[i]->ShowSalaryInfo();
	}
	void ShowTotalSalary() const
	{
		int sum=0;
		for(int i=0; i<empNum; i++)
			sum+=empList[i]->GetPay();
		cout<<"salary sum: "<<sum<<endl;
	}
	~EmployeeHandler()
	{
		for(int i=0; i<empNum; i++)
			delete empList[i];
	}
};

int main(void)
{
	// ���������� �������� ����� ��Ʈ�� Ŭ������ ��ü����
	EmployeeHandler handler;

	// ���� ���
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));

	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowAllSalaryInfo();	

	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowTotalSalary();
	return 0;
}