
#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>

class fixed
{
	public:
		fixed(void);
		fixed(fixed &t);
		fixed &operator=(const fixed &t);
		~fixed(void);

		int		get_raw_bits(void) const;
		void	set_raw_bits(int const raw);
	private:
		int					_fixed_point;
		static const int	_fractional_bits = 8;
};

#endif
