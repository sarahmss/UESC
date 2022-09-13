/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex12.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:50:04 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/28 13:47:10 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exercicios.h"

/*12. Calcule o valor de uma prestação em atraso, utilizando a fórmula: PRESTAÇÃO =
VALOR + (VALOR * (TAXA/100) * TEMPO).*/

int main(void)
{
    int valor;
    int prestacao;
    int taxa;
    int tempo;

    std::cout << "Valor: ";
    std::cin >> valor;
    std::cout << "Taxa: ";
    std::cin >> taxa;
    std::cout << "Tempo: ";
    std::cin >> tempo;
    prestacao = valor + (valor * (taxa/100) * tempo);
    std::cout << "A prestação é de " << prestacao  ;
    return (0);
}
