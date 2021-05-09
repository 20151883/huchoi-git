#include <iostream>

class ZombieHorde{
    private:
        Zombie *p_zombies;
        int     num_of_zombies;
    public:
        ZombieHorde(int N) :num_of_zombies(N)
        {
            p_zombies = new Zombie[N];//아마도 좀비생성자에 void생성자를 하나 만들어서 거기서 이름과타입을 저장하게끔해야할거같음.
            int idx = 0;
            while (idx < N)
            {
                define_type_name(p_zombies[idx])
            }
        }
        ~ZombieHorde()
        {
            delete []p_zombies;
        }
        void    announce()//all of zombies announec....
        {
            int idx = 0;
            while (idx < num_of_zombies)
                p_zombies[idx++]->announce();
        }
}