/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex08.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:50:04 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/22 21:07:20 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exercicios.h"
// 8. Lê o saldo de uma aplicação e imprima o novo saldo, considerado o reajuste de 1%.
int main(void)
{
    float saldo;

    std::cout << "SALDO: ";
    std::cin >> saldo;
    saldo += (saldo * 0.01);
    std::cout << "SALDO APÓS REAJUSTE = " << saldo << "R$\n";
    return (0);
}
