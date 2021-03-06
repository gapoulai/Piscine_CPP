#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	{
		ClapTrap roger("roger");
		ClapTrap christian("christiant");

		roger.print_status();
		christian.print_status();
		roger.attack("skag");
		roger.takeDamage(2);
		roger.attack("skag");
		roger.takeDamage(3);
		roger.attack("skag");
		roger.takeDamage(5);
		christian.attack("skag");
		christian.takeDamage(2);
		christian.beRepaired(2);
		roger.print_status();
		christian.print_status();
	}
	{
		ScavTrap henry("henry");
		henry.guardGate();
		henry.print_status();
	}
	return 0;
}

