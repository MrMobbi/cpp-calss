
#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &t);
		Fixed &operator=(const Fixed &t);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	private:
		int					_fixed_point;
		static const int	_fractional_bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &t);

#endif
