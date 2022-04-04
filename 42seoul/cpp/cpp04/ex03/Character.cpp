#include "Character.hpp"

Character::Character()
{}
Character::Character(const char *name) :name(name), count(0), size(4)
{
    for(int i =0; i < this->size; i++)
        this->slot[i] = NULL;
}

Character::Character(const Character &src):ICharacter()
{
    this->name = src.getName();
    this->count = src.getCount();
    this->size = src.getSize();
    for (int i =0; i < this->size; i++)//이 부분 중요
    {
        if (src.slot[i] == NULL)
            continue;
        if (src.slot[i]->getType() == "Cure")
            this->slot[i] = src.slot[i]->clone();
        else
            this->slot[i] = src.slot[i]->clone();
    }
}

const Character &Character::operator=(const Character &src)
{
    for (int i = 0; i < this->size ; i++)
    {
        if (this->slot[i] != NULL)
            delete this->slot[i];
    }
    this->name = src.getName();
    this->count = src.getCount();
    this->size = src.getSize();
    for (int i =0;i < this->size; i++)//이 부분 중요
    {
        if (src.slot[i] == NULL)
            continue;
        if (src.slot[i]->getType() == "Cure")
            this->slot[i] = src.slot[i]->clone();
        else
            this->slot[i] = src.slot[i]->clone();
    }
    return *this;
}

Character::~Character() 
{
    for (int i = 0; i < this->size ; i++)
    {
        if (this->slot[i] != NULL)
            delete this->slot[i];
    }
}

std::string const & Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria* m)
{ 
    if (this->count < this->size)
    {
        for (int i = 0; i < this->size; i++)
        {
            if (this->slot[i] == NULL)
            {
                this->slot[i] = m;
                count++;
                return;
            }
        }
    }
}

void Character::unequip(int idx)
{
    if (0 <= idx && idx < size && this->slot[idx])
        this->slot[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (0 <= idx && idx < size && this->slot[idx])
        this->slot[idx]->use(target);
}

int Character::getCount() const
{
    return this->count;
}

int Character::getSize() const
{
    return this->size;
}