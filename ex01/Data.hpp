/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuji <mtsuji@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:00:07 by msuji             #+#    #+#             */
/*   Updated: 2022/12/12 11:00:09 by msuji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DATA_HPP
# define DATA_HPP

class Data
{
    public:
        Data(void);
        Data(const Data &Data);
        ~Data(void);
        Data &operator=(const Data&);

        char const &getChar(void);
        
    private:
        char _c;
};

#endif