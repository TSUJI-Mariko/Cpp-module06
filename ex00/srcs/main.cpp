/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuji <mtsuji@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:55:09 by msuji             #+#    #+#             */
/*   Updated: 2022/12/05 16:55:12 by msuji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Convert.hpp"
#include <iostream>
#include <string>
#include <cstdlib>



int main(int argc, char **argv)
{

    if (argc != 2)
    {
        std::cout << "Wrong number of argument." << std::endl;
        return -1;
    };
    //std::string str = static_cast<char *>(argv[1]); 
    Convert string = Convert(argv[1]);
    string.seachType();
    string.convertType();
    /*if (check_str(str))
    {
        long    nb;
        nb = std::strtol(argv[1], &argv[1], 10);
        Convert str(nb);
        str.toInt();
    }*/

    return 0;
}