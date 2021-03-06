#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	srand(static_cast<unsigned int>(time(NULL)));
	switch (rand() % 3)
	{
	case 0:
		std::cout << "generate new A" << std::endl;
		return (new A);
	case 1:
		std::cout << "generate new B" << std::endl;
		return (new B);
	case 2:
		std::cout << "generate new C" << std::endl;
		return (new C);
	default:
		return (0);
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		Base &tmp = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return (void)tmp;
	}
	catch (const std::exception &e)
	{
	}
	try
	{
		Base &tmp = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return (void)tmp;
	}
	catch (const std::exception &e)
	{
	}
	try
	{
		Base &tmp = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return (void)tmp;
	}
	catch (const std::exception &e)
	{
	}
}

int main(void)
{
	Base *ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;
	return (0);
}