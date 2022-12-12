/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuji <mtsuji@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:53:09 by msuji             #+#    #+#             */
/*   Updated: 2022/12/12 12:53:12 by msuji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base    * generate(void)
{
    std::srand(std::time(NULL));
    int i = std::rand() % 3;
    switch (i)
    {
        case 0:
        {
            std::cout << "generate A" << std::endl;
            return new A;
        }
        case 1:
        {
            std::cout << "generate B" << std::endl;
            return new B;
        }
        default :
        {
            std::cout << "generate C" << std::endl;
            return new C;
        }
    }
}

/*
    std::srand(time(NULL))
    initialisation de rand(), 
    sinon le reslutat sera TOUJOURS la meme chose
*/

void    identify(Base& p)
{
    try
    {
        p = dynamic_cast<A &>(p);
        std::cout << "&A" << std::endl;
        return;
    }
    catch(std::exception &e)
    {}
    try
    {
        p = dynamic_cast<B &>(p);
        std::cout << "&B" << std::endl;
        return ;
    }
    catch(std::exception &e)
    {}
    try
    {   
        p = dynamic_cast<C &>(p);
        std::cout << "&C" << std::endl;
        return ;
    }
    catch(std::exception &e)
    {}
}
/*
    en cas de l'echec de downcast de reference, 
    on renvoie exception(bad_cast) avec typeinfo
    comme lib <typeinfo> est interdit sur le sujet, 
    on doit creer notre propre "try-catch"
*/

void    identify(Base* p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
}

int main(void)
{
    Base *ptr = new Base;
    ptr = generate();
    identify(ptr);
    identify(*ptr);
    delete ptr;
    return 0;
}