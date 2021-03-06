#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
{
	ClapTrap::p_name += "_clap_name";
	p_hitPoints = 100;
	p_energyPoints = 50;
	p_attackDamages = 30;
	std::cout << "DiamondTrap " << p_name << " has spawn from default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	p_name = name;
	ClapTrap::p_name = name + "_clap_name";
	p_hitPoints = 100;
	p_energyPoints = 50;
	p_attackDamages = 30;
	std::cout << "ScavTrap " << p_name << " has spawn from named constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
{
	std::cout << "DiamondTrap " << p_name << " has spawn from copy" << std::endl;
	*this = src;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	p_name = src.p_name;
	ClapTrap::p_name = src.p_name + "_clap_name";
	std::cout << "DiamondTrap " << p_name << " has spawn from assignation" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << p_name << " destructed" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap = '" << p_name << "', ClapTrap = '" << ClapTrap::p_name << "'" << std::endl;
}