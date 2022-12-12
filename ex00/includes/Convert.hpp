/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuji <mtsuji@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:45:19 by msuji             #+#    #+#             */
/*   Updated: 2022/12/05 16:45:21 by msuji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
#define CONVERT_HPP
#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <iomanip>
#include <string>
#include <cstdlib>


class Convert
{
    
    public:
        Convert(void);
        Convert(long nb);
        Convert(std::string str);
        Convert(const Convert &Convert);
        ~Convert(void);
        Convert &operator =(Convert const &convert);
        std::string    const &getStr(void) const;
        long    const &getNb(void) const;

        void    impossible(void);
        void    toChar(void);
        void    toInt(void);
        void    toFloat(void);
        void    toDouble(void);
        void    seachType(void);
        void    convertType(void);

    private:
        std::string  _str;
        std::string _type;
};

std::ostream & operator<<(std::ostream & o, const Convert & rhs);
#endif
