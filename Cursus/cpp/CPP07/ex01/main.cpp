/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 12:55:56 by dbohoyo-          #+#    #+#             */
/*   Updated: 2026/09/09 12:56:00 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};
std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}
template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}
int main() {
  // Test iter with an array of simple int values.
  int tab[] = { 0, 1, 2, 3, 4 };
  // Test iter with an array of complex Awesome objects.
  Awesome tab2[5];
  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );
  return 0;
}