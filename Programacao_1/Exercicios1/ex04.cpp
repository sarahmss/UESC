/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:50:04 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/22 20:50:35 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exercicios.h"

//Lê dois números e mostra a soma. Ante do resultado, deverá aparecer a mensagem: SOMA.
int main(void)
{
    int a;
    int b;
    
    std::cout << "Escolha dois números\n";
    std::cout << "n1: ";
    std::cin >> a;
    std::cout << "n2: ";
    std::cin >> b;
    std::cout << "SOMA = " << (a + b) << "\n";
    return (0);
}
