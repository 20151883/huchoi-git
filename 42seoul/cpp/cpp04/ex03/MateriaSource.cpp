#include "MateriaSource.hpp"

MateriaSource::MateriaSource():amount(0)
{
	for (int i = 0; i < 4; i++)
		this->sources[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &src):amount(0)
{
	for (int i = 0; i < src.amount; i++)
		this->learnMateria(src.sources[i]->clone());
	for (int i = 0; i < 4; i++)
		this->sources[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < this->amount; i++)
		delete this->sources[i];
}

MateriaSource &MateriaSource::operator=(MateriaSource const &src)
{
	for (int i = 0; i < this->amount; i++)
		delete this->sources[i];
	this->amount = 0;
	for (int i = 0; i < src.amount; i++)
		this->learnMateria(src.sources[i]->clone());
	for (int i = 0; i < 4; i++)
		this->sources[i] = NULL;
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (this->amount  == 4 || m == NULL)
		return ;
	for (int i = 0; i < this->amount; i++)
		if (this->sources[i] == m)
			return ;
	this->sources[this->amount++] = m;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < this->amount; i++)
		if (this->sources[i]->getType() == type)
			return (this->sources[i]->clone());
	return (NULL);
}