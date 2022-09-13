/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:50:04 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/22 20:42:47 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exercicios.h"

//  Mostrar a média aritmética entre 3 números passados pelo usuário.
int main(void)
{
    int a;
    int b;
    int c;
    int med;
    
    std::cout << ("Selecione os numeros para a média aritmetica.\n");
    std::cout << ("n1: ");
    std::cin >> a;
    std::cout << ("n2: ");
    std::cin >> b;
    std::cout << ("n3: ");
    std::cin >> c;
    med = ((a + b + c) / 3);
    std::cout << med << "\n";
    return (0);
}
