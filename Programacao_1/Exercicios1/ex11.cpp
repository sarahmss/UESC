/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex11.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:50:04 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/28 13:41:41 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exercicios.h"
/*
11. Calcule e mostre a área de um triângulo (área é igual a (base x altura) dividido por 2)
*/
int main(void)
{
    int base;
    int altura;

    std::cout << "INSIRA A\n";
    std::cout << "ALTURA: ";
    std::cin >> altura;
    std::cout << "BASE: ";
    std::cin >> base;
    std::cout << "AREA DO TRIANGULO = " << (base * altura) / 2 << "m²\n";
    return (0);
}
