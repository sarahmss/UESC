/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/26 22:06:02 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"

/* Uma determinada empresa armazena para cada funcionário (10 no total) uma ficha contendo o
código, o número de horas trabalhadas e o seu nº de dependentes.
Considerando que:
a. A empresa paga 12 reais por hora e 40 reais por dependentes.
b. Sobre o salário são feitos descontos de 8,5% para o INSS e 5% para IR.
Faça um programa para ler o código, número de horas trabalhadas e número de dependentes de
cada funcionário. Após a leitura, escreva qual o código, os valores descontados para cada tipo de
imposto e finalmente o salário líquido de cada um dos funcionários */
 
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