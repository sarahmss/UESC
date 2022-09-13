/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex13.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:50:04 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/28 13:57:16 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exercicios.h"

/* 13. Leia o numerador e o denominador de uma fração e transforme-o em um número
decimal. */

int main(void)
{
    float numerador;
    float denominador;
    float resultado;

    std::cout << "INSIRA O\n";
    std::cout << "NUMERADOR: ";
    std::cin >> numerador;
    std::cout << "DENOMINADOR: ";
    std::cin >> denominador;
    resultado = (numerador / denominador);
    std::cout << "NUMERO DECIMAL = " << resultado << "\n" ; 
    return (0);
}
