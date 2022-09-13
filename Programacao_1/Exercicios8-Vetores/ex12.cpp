/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex12.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/24 21:47:37 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"
# include <math.h>

/*Faça um programa que leia o tamanho de uma lista de temperaturas de diferentes dias e em
seguida os valores. Ao final, o programa deverá calcular a média e o desvio padrão das temperaturas
lidas*/
int main(void)
{
    int     size;
    int     i;
    int     media;
    double  desvio;

    media = 0;
    desvio = 0;
    std::cout << "Tamanho da lista: ";
    std::cin >> size;
    int temperaturas[size];
    for (i = 0; i < size; i++)
    {
        std::cout << "Temperatura[" << i  + 1 << "]:";
        std::cin >> temperaturas[i];
        media += temperaturas[i];
    }
    media /= size;
    for (i = 0; i < size; i++)
        desvio += pow((temperaturas[i] - media), 2);
    desvio /= size;
    desvio = sqrt(desvio);
    std::cout << "Média:" << media << "\n";
    std::cout << "Desvio Padrão:" << desvio << "\n";
    return (0);
 }