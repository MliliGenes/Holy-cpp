/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fZ!r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:46:29 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/07/17 19:32:26 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define DEFAULT "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

std::string toUpperCase(const std::string& str) {
    std::string upperCase = str;
    for (std::string::iterator it = upperCase.begin(); it != upperCase.end(); it++)
        *it = std::toupper(*it);
    return (upperCase);
}

int main(int ac, char **av) {

    if (ac == 1)
        std::cout << DEFAULT << std::endl;
    else {
        for (int i = 1; i < ac; i++)
            std::cout << toUpperCase(av[i]);
        std::cout << std::endl;
    }
    return 0;
}