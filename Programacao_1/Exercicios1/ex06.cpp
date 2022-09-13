/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex06.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:50:04 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/22 20:57:03 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exercicios.h"

int main(void)
{
    int dividendo;
    int divisor;
    
    std::cout << "Escolha o dividendo: \n";
    std::cin >> dividendo;
    std::cout << "Escolha o divisor: \n";
    std::cin >> divisor;
    std::cout << "DIVIDENDO = " << dividendo << "\n";
    std::cout << "DIVISOR = " << divisor << "\n";
    std::cout << "QUOCIENTE = " << (dividendo / divisor) << "\n";
    std::cout << "RESTO = " << (dividendo % divisor) << "\n";
    return (0);
}
