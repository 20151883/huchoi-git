#ifndef __ENEMY__
#define __ENEMY__

#include <iostream>

class Enemy
{
	protected://웬만한 멤버변수는 최상위 부모쪽에서 선언 해주는게 좋다... (x) 모든 멤버함수는 최상위 부모에서 정의해야한다. 하지만 멤버변수는 그럴필요가 전혀없다. 멤버변수에 직접 접근할게 아니기때문
		int hp;
		std::string type;
		Enemy();

		int flag;

	public:
		Enemy(int hp, std::string const & type);//생성자를 통한 protected 멤버변수 초기화는 제일 마지막 상속클래스가 하는걸로 결론 지었는데... 부모쪽에서 해도 괜찮다. 어짜피 자식클래스에서 다른 값으로 덮어씌울수있기때문에.. 그런데 직관적으로 만들기 위해서는 웬만하면 마지막 자식클래스의 생성자에서 초기화하는게 좋겠다.
		virtual ~Enemy();
		Enemy(const Enemy &src);
		Enemy &operator=(const Enemy &src);
		const std::string getType() const;
		int getHp() const;
		virtual void takeDamage(int);//이 부분 순수 가상함수로 안주었다는건 분명 정의가 되어야된다는 뜻. Enemy::take_damage(100) 이렇게 호출 가능하다는것.

		void setFlag(int num);
		int getFlag() const;

};
#endif
