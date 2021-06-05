#include <iostream>

class AWeapon
{
	protected:
		std::string name;
		int			apcost;
		int			damage;
	public:
	AWeapon(std::string const & name, int apcost, int damage)
	{
		this->name = name;
		this->apcost = apcost;
		this->damage = damage;
	}
	AWeapon(const AWeapon &src)
	{
		this->name = src.name;
		this->apcost = src.apcost;
		this->damage = src.damage;
	}
	~AWeapon()
	{

	}
	AWeapon &operator=(const AWeapon &src)
	{
		this->name = src.name;
		this->apcost = src.apcost;
		this->damage = src.damage;
		return *this;
	}
	std::string getName() const
	{
		return this->name;
	}
	virtual int getAPCost() const
	{
		return this->apcost;
	}
	virtual int getDamage() const
	{
		return this->damage;
	}
	virtual void attack() const = 0;
};

class PlasmaRifle :public AWeapon
{
	private:
		std::string sound;
	public:
	PlasmaRifle() :AWeapon("Plasma Rifle", 5, 21)
	{
		this->sound =  "* piouuu piouuu piouuu *";
	}
	~PlasmaRifle()
	{}
	PlasmaRifle(PlasmaRifle &src) :AWeapon(src.getName(), src.getAPCost(), src.getDamage())
	{
		this->sound = src.sound;
	}
	PlasmaRifle &operator=(PlasmaRifle &src)
	{
		this->name =  src.name;
		this->apcost = src.apcost;
		this->damage = src.damage;
		this->sound = src.sound;
		return *this;
	}
	std::string getSound()
	{
		return this->sound;
	}
	virtual void	attack() const
	{
		std::cout<<this->sound<<std::endl;
	}
};

class PowerFist :public AWeapon
{
	private:
		std::string sound;
	public:
	PowerFist() :AWeapon("Power Fist", 8, 50)
	{
		 this->sound = "* pschhh... SBAM! *";
	}
	~PowerFist()
	{}
	PowerFist(PowerFist &src) :AWeapon(src.getName(), src.getAPCost(), src.getDamage())
	{
		this->name =  src.name;
		this->apcost = src.apcost;
		this->damage = src.damage;
		this->sound = src.sound;
	}
	PowerFist &operator=(PowerFist &src)
	{
		this->name =  src.name;
		this->apcost = src.apcost;
		this->damage = src.damage;
		this->sound = src.sound;
		return *this;
	}
	virtual void	attack() const
	{
		std::cout<<this->sound<<std::endl;
	}
};
