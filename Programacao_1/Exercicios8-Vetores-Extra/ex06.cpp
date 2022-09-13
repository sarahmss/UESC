/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex06.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/06 11:27:36 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*(COMP 89) Dados dois strings (um contendo uma frase e outro contendo uma
palavra), determine o número de vezes que a palavra ocorre na frase.
Exemplo:
Para a palavra ANA e a frase :
ANA E MARIANA GOSTAM DE BANANA
Temos que a palavra ocorre 4 vezes na frase. */
 
#include <iostream>
#include <string.h>
#include <unistd.h>

int	main (void)
{
	char palavra [20], frase [100];
	int i, j, numOcorrencias=0; 
	
	std::cout << "Digite a palavra: \n";
	read(0, palavra, 20);
	std::cout << "Digite a frase: \n";
	read(0, frase, 50);
	for (i = 0; frase[i] != '\n' ; i++)
	{
		if (frase [i] == palavra[0])
		{
			numOcorrencias++;
			for (j = 0; palavra[j] != '\n' ; j++)
				if (frase[i + j] != palavra[j])
				{
					numOcorrencias--;
					break ;	
				}

		}
	}
	std::cout << "A palavra ocorre " << numOcorrencias << " na frase \n";
	return (0);
}
