
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
		Fixed &operator = (const Fixed &t);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		bool	operator < (const Fixed &t) const;
		bool	operator > (const Fixed &t) const;
		bool	operator <= (const Fixed &t) const;
		bool	operator >= (const Fixed &t) const;
		bool	operator == (const Fixed &t) const;
		bool	operator != (const Fixed &t) const;
	
		Fixed	operator + (const Fixed &t);
		Fixed	operator - (const Fixed &t);
		Fixed	operator / (const Fixed &t);
		Fixed	operator * (const Fixed &t);

		Fixed	&operator ++ (void);	// empty parameter => PREFIX version
		Fixed	&operator -- (void); 
		Fixed	operator ++ (int);		// dummy parameter => POSTFIX version
		Fixed	operator -- (int);

		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);

	private:
		int					_fixed_point;
		static const int	_fractional_bits = 8;
};

std::ostream &operator << (std::ostream &out, const Fixed &t);

#endif
