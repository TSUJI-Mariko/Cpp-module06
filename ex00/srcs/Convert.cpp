/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:06:24 by mtsuji            #+#    #+#             */
/*   Updated: 2022/12/01 18:06:27 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Convert.hpp"

Convert::Convert(void)
{
    std::cout << "\033[35m" << "Convert Default constructor called"  << "\033[0m" << std::endl;
    return ;
}

Convert::Convert(const Convert &convert)
{
    std::cout << "\033[35m" << "Convert Copy constructor called"  << "\033[0m" << std::endl;
    *this = convert;
    return ;
}

Convert::Convert(std::string value)
{
    return;
}

Convert::~Convert(void)
{
    std::cout << "\033[35m" << "Convert Destructor called"  << "\033[0m" << std::endl;
    return ;
}

Convert & Convert::operator =(Convert const &Convert)
{
    std::cout << "\033[35m" << "Convert copy assignment operator called"  << "\033[0m" << std::endl;
    this-> _str = Convert._str;
    return *this;
}

std::string    const & Convert::getStr(void) const
{
    return (this->_str);
}

void    Convert::impossible(void)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}
void    Convert::toChar(void)
{
    char c = getStr()[0];
    if (c < 8 || c > 12 && c < 32 || c != 127)
        std::cout << "Non displayale" << std::endl;
    else
        std::cout << "char: " << c << std::endl;
    std::cout << "int: " << static_cast<int>(c) <<std::endl;
    std::cout << std::fixed << std::setprecision(1) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void    Convert::toInt(void)
{

}

void    Convert::toFloat(void)
{

}
void    Convert::toDouble(void)
{

}
std::ostream & operator<<(std::ostream & o, const Convert & rhs)
{
    o << "\033[32m" << rhs.getStr() << "\033[0m" << ", Convert grade " << "\033[32m" << rhs.getGrade() << "\033[0m" << std::endl;
    return o;
}