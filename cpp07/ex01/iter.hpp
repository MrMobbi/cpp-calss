
#ifndef ITER_HPP
# define ITER_HPP

template<typename t_type, typename t_size>
void	iter(t_type *arr, t_size size, void (fct)(t_type&))
{
	for (int i = 0; i < size; i++)
		fct(arr[i]);
}

template <typename t_type, typename t_size>
void	showArray(const t_type *arr, const t_size size)
{
	for (int i = 0; i < size; i++)
		std::cout << "Array [" << i << "] : " << arr[i] << std::endl;
}

#endif
