/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/19 13:37:17 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*Escrever um algoritmo para ler dois valores numéricos e apresentar a diferença do maior
pelo menor*/
 
int main(void)
{
    int n1;
    int n2;
    
    std::cout << "n1: ";
    std::cin >> n1;
    std::cout << "n2: ";
    std::cin >> n2;
    if  (n1 > n2)
        std::cout << (n1 - n2) << "\n";
    else if  (n2 > n1)
        std::cout << (n2 - n1) << "\n";
    return (0);
 }