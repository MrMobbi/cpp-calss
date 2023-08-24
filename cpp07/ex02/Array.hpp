
#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename t_type = int> 
class Array {

	public :

//	### Constructor
		Array(void) : _size(0)
		{
			this->_element = NULL;
		};
		Array(unsigned int n) : _size(n)
		{
			this->_element = new t_type[n]();
		};
		Array(const Array &t) : _size(t._size)
		{
			this->_element = new t_type[t._size]();
			for (unsigned int i = 0; i < t._size; i++)
				this->_element[i] = t._element[i];
		}

//	### Overload operator'='
		Array &operator = (const Array &t)
		{
			if (this->_element != NULL)
				delete[] (this->_element);
			this->_size = t._size;
			this->_element = new t_type[t._size]();
			for (unsigned int i = 0; i < t._size; i++)
				this->_element[i] = t._element[i];
			return (*this);
		};

//	### Destructor
		~Array(void) 
		{
			delete[] (this->_element);
		};

//	### Exception
		class IndexException : public std::exception
		{
			public :
				virtual const char *what(void) const throw()
				{
					return ("Index is not Valid");
				};
		};

//	### Overload operator '[]'
		t_type &operator [] (const int i) const
		{
			if (i < 0 || i > static_cast<int>(this->_size) - 1)
				throw(IndexException());
			return (this->_element[i]);
		};

//	### Member Function
		unsigned int	size(void) const
		{	
			return (this->_size); 
		};

	private :
		t_type				*_element;
		unsigned int	_size;
};

#endif
