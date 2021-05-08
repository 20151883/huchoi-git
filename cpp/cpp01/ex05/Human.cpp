#include <iostream>
//"with the same life time" 이 말이 뭔 뜻...?
class Human{
    private:
        const Brain brain;
    public:
        Human(void) :brain("test")
        void identify(){
            //just call brains's identify() function
        }
        Brain *getBrain()
        {
            return (brain);
        }
}