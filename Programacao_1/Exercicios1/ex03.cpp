/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:50:04 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/22 20:47:24 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exercicios.h"

// Lê um número e mostra seu sucessor e seu antecessor na tela.
int main(void)
{
    int a;
    
    std::cout << "Selecione um numero: ";
    std::cin >> a;
    std::cout << "seu antecessor é: " << (a - 1) << "\n";
    std::cout << "e seu sucessor é: " << (a + 1) << "\n";
    return (0);
}
