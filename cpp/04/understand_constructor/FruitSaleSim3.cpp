#include <iostream>
using namespace std;
//생성자와 공생하는... 멤버이니셜라이저
//멤버이니셜라이저는 멤버변수로 선언된 객체의 생성자호출에 활용된다
//또한 객체가 아닌 멤버변수에 대해서도 초기화작업을 진행할수있다.
class FruitSeller
{
	const int APPLE_PRICE;
	int numOfApples;
	int myMoney;
public:
	FruitSeller(int price, int num, int money)
		: APPLE_PRICE(price), numOfApples(num), myMoney(money)//delemeter가 콤마(,)인듯..
	{
	}
	int SaleApples(int money)
	{
		int num=money/APPLE_PRICE;
		numOfApples-=num;
		myMoney+=money;
		return num;
	}
	void ShowSalesResult() const
	{
		cout<<"���� ���: "<<numOfApples<<endl;
		cout<<"�Ǹ� ����: "<<myMoney<<endl<<endl;
	}
};

class FruitBuyer
{
	int myMoney;
	int numOfApples;
public:
	FruitBuyer(int money)
		: myMoney(money), numOfApples(0)
	{
	}
	void BuyApples(FruitSeller &seller, int money)//왜 하필 참조자로 받아오는건지..? 여러가지 이유가 있을거같긴한데.
	{
		numOfApples+=seller.SaleApples(money);
		myMoney-=money;
	}
	void ShowBuyResult() const
	{
		cout<<"���� �ܾ�: "<<myMoney<<endl;
		cout<<"��� ����: "<<numOfApples<<endl<<endl;
	}
};

int main(void)
{
	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(5000);
	buyer.BuyApples(seller, 2000);

	cout<<"���� �Ǹ����� ��Ȳ"<<endl;
	seller.ShowSalesResult();
	cout<<"���� �������� ��Ȳ"<<endl;
	buyer.ShowBuyResult();
	return 0;
}
