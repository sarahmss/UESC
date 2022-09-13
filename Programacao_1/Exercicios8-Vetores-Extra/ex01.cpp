/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/06 10:05:16 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

/*
    Dada uma sequência de n números, imprimi-la na ordem inversa à da leitura.
*/

int main(void)
{
	int tam;
    int i;
    int j;
	
	std::cout << "digite o tamanho da sequencia: \n";
	std::cin >> tam;
	int vet[tam];
	for (i = 0; i < tam; i++)
    {
		std::cout << "digite uma sequencia de " << tam << " numeros inteiros: \n";
	    std::cin >> vet[i];
    }
    for (j = tam - 1; j >= 0; j--)
        std::cout << vet[j] << " ";

}
