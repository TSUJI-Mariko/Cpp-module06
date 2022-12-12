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

Convert::Convert(void) : _str(getStr())
{
    std::cout << "\033[35m" << "Convert Default constructor called"  << "\033[0m" << std::endl;
    return ;
}

Convert::Convert(const Convert &convert) : _str(convert.getStr())
{
    std::cout << "\033[35m" << "Convert Copy constructor called"  << "\033[0m" << std::endl;
    *this = convert;
    return ;
}

Convert::Convert(std::string str) :_str(str)
{
    return ;
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

/*
long    const & Convert::getNb(void) const
{
    return (this->_nb);
}*/

void    Convert::impossible(void)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

void    Convert::toChar(void)
{
    char c;
    c = getStr()[0];
    if (c <= -129 || c > 127)
        std::cout << "char impossible" << std::endl;
    if (c <= 7 || (c > 12 && c < 32) || c == 127)
        std::cout << "char: Non displayale" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(c) << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << std::fixed;
    std::cout.precision(1);
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: "<< static_cast<double>(c) << std::endl;        
}

void    Convert::toInt(void)
{
    long int nb;

    nb = std::strtol(getStr().c_str(), NULL, 10);
    if (nb <= -129 || nb > 127)
        std::cout << "char: impossible" << std::endl;
    else if (nb <= 7 || (nb > 12 && nb < 32) || nb == 127)
        std::cout << "char: Non displayale" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(nb) << std::endl;   

    if (nb <= INT_MAX && nb >= INT_MIN)
        std::cout << "int: " << static_cast<int>(nb) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    
    std::cout << std::fixed;
    std::cout.precision(1);
    std::cout << "float: " << static_cast<float>(nb) << "f" << std::endl;
    std::cout << "double: "<< static_cast<double>(nb) << std::endl;
}

void    Convert::toFloat(void)
{
    float f;
    f = static_cast<float>(std::strtol(getStr().c_str(), NULL, 10));
    
    if (f < FLT_MAX && f > FLT_MIN)
    {
        std::cout << std::fixed;
        std::cout.precision(1);
        std::cout << "float: " << f << "f" << std::endl;
        return;
    }
    else
        std::cout << "float: impossible" << std::endl;
}

void    Convert::toDouble(void)
{

}

void    Convert::seachType(void)
{
    if (this->_str.empty())
        return ;
    if (!this->_str.compare("+inf") || !this->_str.compare("-inf") || !this->_str.compare("nan"))
    {
        this->_type = "double";
        return ;
    }
    if (!this->_str.compare("+inff") || !this->_str.compare("-inff") || !this->_str.compare("nanf"))
    {
        this->_type = "float";
        return ;
    }
    int size = this->_str.size();
    if (size == 1)
    {
        if (std::isdigit(this->_str[0]))
            this->_type = "int";
        else
            this->_type = "char";
        return ;
    }
    bool sign = false;
    if (this->_str[0] != '+' && this->_str[0] != '-' && !std::isdigit(this->_str[0]))
        return ;
    if (this->_str[0] == '+' || this->_str[0] == '-')
        sign = true;
    if ((sign == true && size == 2 && (this->_str[1] == 'f' || this->_str[1] == '.')) || this->_str[size - 1] == '.' || (sign == true && this->_str[1] == '.'))
        return ;
    int nb_point;
    if (sign == true)
        nb_point = 1;
    else
        nb_point = 0;
    while (nb_point < size)
    {
        if (!std::isdigit(this->_str[nb_point]))
            break;
        nb_point++;
    }
    if (nb_point == size)
    {
        this->_type = "int";
        return ;
    }
    nb_point = 0;
    int i = 1;
    while (i < size)
    {
        if (!std::isdigit(this->_str[i]))
        {
            if((this->_str[i] != '.' && this->_str[i] != 'f') || (this->_str[i] == 'f' && i != (size -1)))
            {
                this->_type = "impossible";
                return ;
            }
            if ((i == (size - 1)) && this->_str[i] == 'f')
                this->_type = "float";
            else if (this->_str[i] == '.')
            {
                nb_point += 1;
                this->_type = "double";
            }
            if (this->_str[i] == '.' && this->_str[i + 1] == 'f')
            {
                this->_type = "impossible";
                return ;
            }
    }
        if (nb_point > 1)
        {
            this->_type = "impossible";
            return ;
        }
        i++;
    }
}
void    Convert::convertType(void)
{
    if (this->_type == "int")
        toInt();
    if (this->_type == "char")
        toChar();
    if (this->_type == "float")
        toFloat();
}
/*
std::ostream & operator<<(std::ostream & o, const Convert & rhs)
{
    o << "\033[32m" << rhs.getStr() << "\033[0m" << ", Convert grade " << "\033[32m" << rhs.getGrade() << "\033[0m" << std::endl;
    return o;
}
*/