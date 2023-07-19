
#include "ShrubberyCreationForm.hpp"

//	### Constructor ###

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &t) : AForm(t) {}

//	### Overload Operator ###

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &t)
{
	(void) t;
	std::cout << "Copy assignement operator of ShrubberyCreationForm called" << std::endl;
	return (*this);
}

//	### Destructor ###

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{ std::cout << "Destructor of ShrubberyCreationForm called" << std::endl; }

//	### Member Function ###

std::string	ShrubberyCreationForm::nameFile(void) const
{
	std::string	file_name;

	file_name = this->getName();
	file_name += "_shrubbery";
	return (file_name);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (this->getSigned() == false)
		throw (AForm::FormNotSignedException());
	else if (executor.getGrade() > this->getGradeToExec())
		throw (AForm::GradeTooHighException());
	else
	{
		std::ofstream file(this->nameFile());
		file << "         # #### ####" << std::endl;
		file << "       ### ./#|### |/####" << std::endl;
		file << "      ##./#/ .||/##/_/##/_#" << std::endl;
        file << "    ###  ./###|/ ./ # ###" << std::endl;
        file << "  ##_._#._.## | #/###_/_####" << std::endl;
        file << " ## #### # . #| /  #### ##/##" << std::endl;
        file << "  __#_--###`  |{,###---###-~" << std::endl;
        file << "             [}{" << std::endl;
        file << "             }}{" << std::endl;
        file << "             }}{" << std::endl;
        file << "             {{}" << std::endl;
        file << "       , -=-~{ .-^- _" << std::endl;
		file.close();
	}
}
