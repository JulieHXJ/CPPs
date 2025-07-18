/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strReplace.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:15:18 by xhuang            #+#    #+#             */
/*   Updated: 2025/03/29 14:27:34 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRREPLACE_H
#define STRREPLACE_H

#include <iostream>


class StrReplace
{
private:
    std::string filename;
    std::string s1;
    std::string s2;
public:
    StrReplace(const std::string &filename, const std::string &s1, const std::string &s2);
    bool doReplace();
};


#endif