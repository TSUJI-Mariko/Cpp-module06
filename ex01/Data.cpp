/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuji <mtsuji@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:59:59 by msuji             #+#    #+#             */
/*   Updated: 2022/12/12 11:00:00 by msuji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void) : _c('C')
{
    return ;
}

Data::Data(const Data &Data)
{
    *this = Data;
    return ;
}

Data::~Data(void)
{
    return ;
}

Data& Data::operator=(const Data&)
{
    this->_c = getChar();
    return *this;
}

char const &Data::getChar(void)
{
    return (this->_c);
}