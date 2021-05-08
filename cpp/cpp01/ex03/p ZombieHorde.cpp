#include <iostream>

class ZombieHorde{
    private:
        Zombie *p_zombie;
    public:
        ZombieHorde(int N)
        {
            p_zombie = new Zombie[N];//아마도 좀비생성자에 void생성자를 하나 만들어서 거기서 이름과타입을 저장하게끔해야할거같음.
        }
        ~ZombieHorde()
        {
            delete []p_zombie;
        }
        void    announce()//all of zombies announec....
        {

        }
}