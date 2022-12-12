/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuji <mtsuji@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:56:40 by msuji             #+#    #+#             */
/*   Updated: 2022/12/11 18:56:41 by msuji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>
#include <stdint.h>

uintptr_t serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}

int main()
{
    Data *ptr = new Data;
    uintptr_t uint;

    std::cout << "\033[034m" << "char ptr value  :" << ptr->getChar() << "\033[0m" << std::endl;
    std::cout << "\033[034m" << "address value   :" << &ptr << "\033[0m" << std::endl;
    uint = serialize(ptr);
    std::cout <<  "\033[01m" << "---serialize---\n(pointeur -> entier non signe)" << "\033[0m" << std::endl;
    std::cout << "\033[032m" << "uintptr_t value :" << uint << "\033[0m" << std::endl;
    ptr = deserialize(uint);
    std::cout <<  "\033[01m" << "--deserialize--\n(entier non signe -> pointeur)" << "\033[0m" << std::endl;
    std::cout << "\033[035m" << "char ptr value  :" << ptr->getChar() << "\033[0m" << std::endl;
    std::cout << "\033[035m" << "address value   :" << &ptr << "\033[0m" << std::endl; 
    delete ptr;
}