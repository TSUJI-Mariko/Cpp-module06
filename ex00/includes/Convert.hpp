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

class Convert
{
    
    public:
        Convert(void);
        Convert(std::string value);
        Convert(const Convert &Convert);
        ~Convert(void);
        Convert &operator =(Convert const &convert);
        std::string    const &getStr(void) const;
        int getGrade(void) const;

        void    impossible(void);
        void    toChar(void);
        void    toInt(void);
        void    toFloat(void);
        void    toDouble(void);

    private:
        std::string  _str;
};

std::ostream & operator<<(std::ostream & o, const Convert & rhs);
#endif
