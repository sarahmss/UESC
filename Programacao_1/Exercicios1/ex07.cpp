/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex07.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:50:04 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/05 13:45:15 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exercicios.h"

// Leia 4 números e mostre a média ponderada, sabendo-se que os pesos são
// respectivamente: 1, 2, 3 e 4.
int main(void)
{
    int n1;
    int n2;
    int n3;
    int n4;

    std::cout << "n1: \n";
    std::cin >> n1;
    std::cout << "n2: \n";
    std::cin >> n2;
    std::cout << "n3: \n";
    std::cin >> n3;
    std::cout << "n4: \n";
    std::cin >> n4;
    std::cout << "MEDIA PONDERADA = " << (((1 * n1) + (2 * n2) + (3 * n3) + (4 * n4)) / 10) << "\n";
    return (0);
}
