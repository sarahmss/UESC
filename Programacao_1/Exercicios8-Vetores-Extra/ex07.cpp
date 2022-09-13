/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex07.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/06 12:34:51 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  (MAT 88) Dada uma seqüência de n números reais, determinar os números que
  compõem a seqüência e o número de vezes que cada um deles ocorre na mesma.
  Exemplo: n = 8
  Seqüência: -1.7, 3.0, 0.0, 1.5, 0.0, -1.7, 2.3, -1,7
  Saída:
  -1.7 ocorre 3 vezes
  3.0 ocorre 1 vez
  0.0 ocorre 2 vezes
  1.5 ocorre 1 vez
  2.3 ocorre 1 vez
*/
#include <iostream>

int already_in(int n, float  lst[][2], float num)
{
  int i;
  
  for (i  = 0; i < n; i++)
    if (lst[i][0] == num)
      return (1);
  return (0);
}

int main(void)
{
  int i, j, n, k = 0;

	std::cout << "Insira o tamanho da sequência: ";
	std::cin >> n;
  float freq[n][2];
	float	sequencia[n];
  for (i = 0; i < n; i++)
  {
    std::cout << "Insira o  termo " << i + 1  << " :";
  	std::cin >> sequencia[i];
    freq[i][1] = 0;
  }
  std::cout << "Sequencia: ";
  for (i = 0; i < n; i++)
  	std::cout << sequencia[i] << " ";
  for (i = 0; i < n; i++)
  {
      if (i == 0)
      {
        freq[k][0] = sequencia[i];
        k++;
        for (j = 0; j < n; j++)
          if (sequencia[i] == sequencia[j])
            freq[i][1]++;
      }
      else if (!already_in(n, freq, sequencia[i]))
      {
        freq[k][0] = sequencia[i];
        k++;
        for (j = 0; j < n; j++)
          if (sequencia[i] == sequencia[j])
            freq[i][1]++;
      }  
  }
  for (i = 0; i < k; i++)
    std::cout << "\n" << freq[i][0] << " Ocorre " << (freq[i][1] > 0 ? freq[i][1] : 1) << (freq[i][1] > 0 ? "vezes" : "vez"); 
}
