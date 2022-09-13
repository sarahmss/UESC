/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex14.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:50:04 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/28 14:02:34 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exercicios.h"
/*
14. Lê um valor de hora e informa quantos minutos se passaram desde o início do dia.
*/
int main(void)
{
    int hora;
    int minutos;

    std::cout << "INSIRA A\n";
    std::cout << "HORA: ";
    std::cin >> hora;
    std::cout << "MINUTOS: ";
    std::cin >> minutos;
    hora = minutos + (hora * 60);
    std::cout << hora << " min " << "se passaram desde o inicio do dia. ";
    return (0);
}
