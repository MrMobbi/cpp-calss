
#include <iostream>
#include <string>

class Base {
	public :
		virtual ~Base(void) {};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base	*generate(void)
{
	std::time_t result = std::time(NULL);
	int	rand = result % 3;

	switch (rand)
	{
		case 0:
			std::cout << "A" << std::endl;
			return (new A());
		case 1:
			std::cout << "B" << std::endl;
			return (new B());
		case 2:
			std::cout << "C" << std::endl;
			return (new C());
	}
	return (new A);
}

void	identify(Base *p)
{
	std::string	type;

	if (dynamic_cast<A *>(p))
		type = "A";
	else if (dynamic_cast<B *>(p))
		type = "B";
	else if (dynamic_cast<C *>(p))
		type = "C";

	std::cout << "Identify on a pointer :" << std::endl;
	std::cout << "Type of the class is : [" << type << "]" << std::endl;
}

void	identify(Base &p)
{
	std::string type;

	try
	{
		A	&a = dynamic_cast<A &> (p);
		(void) a;
		type = "A";
	}
	catch (std::exception &e) {}

	try
	{
		B	&b = dynamic_cast<B &> (p);
		(void) b;
		type = "B";
	}
	catch (std::exception &e) {}

	try
	{
		C	&c = dynamic_cast<C &> (p);
		(void) c;
		type = "C";
	}
	catch (std::exception &e) {}

	std::cout << "Identify on a reference :" << std::endl;
	std::cout << "Type of the class is : [" << type << "]" << std::endl;

}

int	main(void)
{
	Base *test = generate();
	std::cout << test << std::endl;
	identify(test);
	identify(*test);
	delete (test);
	return (0);
}
