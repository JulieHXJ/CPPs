/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:08:17 by xhuang            #+#    #+#             */
/*   Updated: 2025/03/29 16:03:19 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "StrReplace.hpp"

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>\n";
        return 1;
    }

    StrReplace coverter(av[1], av[2], av[3]);
    if (!coverter.doReplace())
        return 1;
    
    std::cout << "File processed successfully. Output: " << av[1] << ".replace\n";
    return 0;
}

//tests:
// Hello Universe!
// Universe is big.
// Goodbye Universe!
