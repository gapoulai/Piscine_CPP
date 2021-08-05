#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
	_grade = src._grade;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	_grade = src._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	else
		_grade++;
}

void Bureaucrat::decrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	else
		_grade--;
}

void Bureaucrat::executeForm(Form const &form)
{
	if (form.isSigned())
	{
		if (form.getGradeExec() > _grade)
			std::cout << _name << " cannot execute " << form.getName() << " because he's grade too low" << std::endl;
		else
		{
			std::cout << _name << " executes " << form.getName() << std::endl;
			form.execute(*this);
		}
	}
	else
		std::cout << _name << " cannot execute " << form.getName() << " because it's not signed" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src)
{
	out << src.getName() << ", bureaucrat grade " << src.getGrade();
	return out;
}
