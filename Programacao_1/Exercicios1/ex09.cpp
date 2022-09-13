/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex09.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:50:04 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/22 21:12:15 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exercicios.h"
/*
9. Entre com a base e a altura de um retângulo e mostre os resultados:
a. Perímetro (Perímetro é igual à soma dos 4 lados)
b. Área (Área é igual à lado vezes lado)
*/
int main(void)
{
    int largura;
    int altura;

    std::cout << "ALTURA: ";
    std::cin >> altura;
    std::cout << "LARGURA: ";
    std::cin >> largura;
    std::cout << "PERIMETRO = " << (2 * largura) + (2 * altura) << "m\n";
    std::cout << "AREA = " << (largura * altura) << "m²\n";
    return (0);
}
