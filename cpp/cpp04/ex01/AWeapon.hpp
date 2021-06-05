#include <iostream>

class AWeapon
{
	protected:
		std::string name;
		int			apcost;
		int			damage;
	public:
	AWeapon(std::string const & name, int apcost, int damage);
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
	~AWeapon();
	AWeapon &operator=(const AWeapon &src)
	{
		this->name = src.name;
		this->apcost = src.apcost;
		this->damage = src.damage;
	}
	std::string [...] getName() const;
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
	PlasmaRifle() :AWeapon( "Plasma Rifle", 21, 5)
	{
		this->sound =  "* piouuu piouuu piouuu *";
	}
	~PlasmaRifle()
	{}
	PlasmaRifle(PlasmaRifle &src)
	{
		this->name =  src.name;
		this->apcost = src.apcost;
		this->damage = src.damage;
		this->sound = src.sound;
	}
	PlasmaRifle &operator=(PlasmaRifle &src)
	{
		this->name =  src.name;
		this->apcost = src.apcost;
		this->damage = src.damage;
		this->sound = src.sound;
	}
};

class PowerFist :public AWeapon
{
	PowerFist() :AWeapon("Power Fist", 50, 8)
	{
		 this->sound = "* pschhh... SBAM! *"
	}
	~PowerFist()
	{}
	PowerFist(PowerFist &src)
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
	}
};
