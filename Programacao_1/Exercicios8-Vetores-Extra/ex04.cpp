/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/06 10:35:41 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Dados dois vetores x e y, ambos com n elementos, determinar o produto escalar
desses vetores.*/

#include <iostream>
#include <string.h>

int main (void)
{
	int i, n;
  float prod = 0;

  std::cout << "Informe o tamanho dos vetores: ";
  std::cin >> n;
  float y[n];
  float x[n];
  std::cout << "Informe os componentes do vetor x: ";
  for (i = 0; i < n; i++)
    std::cin >> x[i];
  std::cout << "Informe os componentes do vetor y: ";
  for (i = 0; i < n; i++)
    std::cin >> y[i];
  for (i = 0; i < n; i++)
    prod = prod + x[i] * y[i];
  std::cout << "O produto escalar desses vetores: " << prod << "\n";
  return (0);
}
