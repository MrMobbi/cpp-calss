
#ifndef TEMPLATE_H
# define TEMPLATE_H

template<typename t_type>
const t_type	&max(const t_type &a, const t_type &b)
{
	return (a >= b ? a : b);
}

template<typename t_type>
const t_type	&min(const t_type &a, const t_type &b)
{
	return (a <= b ? a : b);
}

template<typename t_type>
void	swap(t_type &a, t_type &b)
{
	t_type	tmp(a);

	a = b;
	b = tmp;
}

#endif
