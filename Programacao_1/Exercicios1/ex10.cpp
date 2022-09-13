/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex10.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:50:04 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/22 21:28:53 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exercicios.h"
/*
10. Lê o raio de um círculo e mostre como saída o perímetro (2*π*Raio) e a área (π*Raio2).
*/
int main(void)
{
    int r;

    std::cout << "RAIO: ";
    std::cin >> r;
    std::cout << "PERIMETRO = " << (2 *  3.14 * r) << "m\n";
    std::cout << "AREA = " << (3.14 * r * r) << "m²\n";
    return (0);
}
