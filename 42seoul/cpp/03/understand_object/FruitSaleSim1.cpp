#include <iostream>
using namespace std;
//단순히 구조체를 확장한것이 클래스라고 말할수도 있으나, 그것이 전부라고 인식하지 않아야 한다.
//이 예제에서 객체에 대해 배우는건, 실행활에서의 객체를 환기하고, 실생활의 객체, 객체간의 자연스러운 현상을 컴퓨터의언어로 정의할수있다는거.
class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	void InitMembers(int price, int num, int money)
	{
		APPLE_PRICE=price;
		numOfApples=num;
		myMoney=money;
	}
	int SaleApples(int money)
	{
		int num=money/APPLE_PRICE;
		numOfApples-=num;
		myMoney+=money;
		return num;
	}
	void ShowSalesResult()
	{
		cout<<"���� ���: "<<numOfApples<<endl;
		cout<<"�Ǹ� ����: "<<myMoney<<endl<<endl;
	}
};

class FruitBuyer
{//키워드 설정 안하면 디폴트로 private이 됨.
	int myMoney;		// private:
	int numOfApples;	// private:

public:
	void InitMembers(int money)
	{
		myMoney=money;
		numOfApples=0;
	}
	void BuyApples(FruitSeller &seller, int money)
	{
		numOfApples+=seller.SaleApples(money);//중요한 지점
		myMoney-=money;
	}
	void ShowBuyResult()
	{
		cout<<"���� �ܾ�: "<<myMoney<<endl;
		cout<<"��� ����: "<<numOfApples<<endl<<endl;
	}
};

int main(void)
{
	FruitSeller seller;
	//FruitSeller *p_seller = new FruitSeller;////new 우측에 와야하는것: 자료형과 (필요하다면)필요한 개수(...?)
	seller.InitMembers(1000, 20, 0);
	//FruitBuyer *p_buyer = new FruitBuyer;
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);//중요한 지점

	cout<<"���� �Ǹ����� ��Ȳ"<<endl;
	seller.ShowSalesResult();
	cout<<"���� �������� ��Ȳ"<<endl;
	buyer.ShowBuyResult();
	return 0;
}
