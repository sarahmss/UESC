/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex08.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:05:33 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/01 22:41:30 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exercicios.h"

/* 8) O custo ao consumidor de um carro novo é a soma do custo de fábrica com a
percentagem do distribuidor e dos impostos (aplicados ao custo de fábrica).
Supondo que a percentagem do distribuidor seja de 28% e os impostos de 45%,
escrever um programa em C que leia o custo de fábrica de um carro e escreva o
custo ao consumidor.*/

int main(void)
{
    int custo_fab;
    int custo_cons;
    
    std::cout << "INSIRA O CUSTO DE FÁBRICA: \n";
    std::cin >> custo_fab;
    custo_cons = custo_fab + (custo_fab * 0.28) + (custo_fab * 0.45);
    std::cout << "O CUSTO AO CONSUMIDOR É " << custo_cons << "\n";
}