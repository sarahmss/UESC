/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/15 12:01:48 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"

/*Um Banco concederá um crédito especial aos seus clientes, variável com o saldo médio no último
ano. Faça um algoritmo que leia o saldo médio de um cliente e calcule o valor do crédito de acordo
com a tabela abaixo. Mostre uma mensagem informando o saldo médio e o valor do crédito*/
 
int main(void)
{
    float saldo_medio;
    
    std::cout << "Saldo médio do cliente: ";
    std::cin >> saldo_medio;
    if ((saldo_medio >= 0) && (saldo_medio <= 200))
        std::cout << "Com um saldo de " << saldo_medio << "R$ não há crédito disponivel. \n";
    else if ((saldo_medio >= 201) && (saldo_medio <= 400))
        std::cout << "Com um saldo de " << saldo_medio << "R$ o crédito disponível é de " << 0.2 * saldo_medio << "R$.\n";
    else if ((saldo_medio >= 401) && (saldo_medio <= 600))
        std::cout << "Com um saldo de " << saldo_medio << "R$ o crédito disponível é de " << 0.3 * saldo_medio << "R$.\n";
    else if (saldo_medio > 600)
        std::cout << "Com um saldo de " << saldo_medio << "R$ o crédito disponível é de " << 0.4 * saldo_medio << "R$.\n";
    return (0);
 }