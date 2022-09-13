/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/06 10:32:48 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*	Tentando descobrir se um dado era viciado, um dono de cassino honesto 
	o lançou n vezes. Dados os n resultados dos lançamentos, determinar o número
	de ocorrências de cada face
*/
 
int main(void)
{
	int n;
	int i;
	int	vet[6];
	int	face;
	
	std::cout << "digite a quantidade de vezes que o dado foi lançado: ";
	std::cin >> n;

	for (i = 0; i < 6; i++)
	    vet[i] = 0;
    for (i = 0; i < n; i++)
	{
        std::cout << "digite a face do dado:";
     	std::cin >> face;
     	vet[face - 1]++;
    }
	for (i = 0; i < 6; i++)
	    std::cout << "a face " << i + 1 << " caiu "  << vet[i] << " vezes \n";

}