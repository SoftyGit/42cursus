#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
	private:
		const std::string	_target;
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(const std::string _target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& srcs);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& srcs);

		void	execute(const Bureaucrat& executor) const;
};

#endif