/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 12:56:36 by dbohoyo-          #+#    #+#             */
/*   Updated: 2026/09/09 12:56:39 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <stdexcept>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RESET "\033[0m"

template <typename T> class Array
{
	private:
		T *_array;
		size_t _size;
	public:
		Array() : _array(NULL), _size(0) {}

		Array(unsigned int size) : _array(NULL) , _size(size)
		{
			if (this->_size != 0)
				this->_array = new T[_size]();
		}

		Array(const Array &copy) : _array(NULL), _size(0)
		{
			*this = copy;
		}

		~Array() 
		{
			if (this->_array != NULL)
				delete[] _array;
		}

		Array &operator=(const Array &copy)
		{
			T *new_array = NULL;
			if (copy._size != 0)
			{
				new_array = new T[copy._size]();
				for (size_t i = 0; i < copy._size; i++)
					new_array[i] = copy._array[i];
			}
			delete[] this->_array;
			this->_array = new_array;
			this->_size = copy._size;
			return (*this); 
		}

		T &operator[](size_t i)
		{
			if (i >= this->_size)
				throw std::out_of_range("Index out of range");
			return(this->_array[i]);
		}

		const T &operator[](size_t i) const
		{
			if (i >= this->_size)
				throw std::out_of_range("Index out of range");
			return(this->_array[i]);
		}
		
		size_t size() const
		{
			return (_size);
		}
};