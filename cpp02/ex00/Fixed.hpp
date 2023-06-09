
#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed &t);
		Fixed &operator=(const Fixed &t);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	private:
		int					_fixed_point;
		static const int	_fractional_bits = 8;
};

#endif
