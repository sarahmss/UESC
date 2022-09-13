/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex11.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/06 13:11:34 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*
    Dados dois polinômios reais p(x)=a0+a1x+...+anxne q(x)=b0+b1x+...+bmxm
    determinar o produto desses polinômios.
 */

int main(void)
{
    int n, m;
    int i, j, k;
	std::cout << "Grau n de P(x): ";
	std::cin >> n;
    std::cout << "Grau m de Q(x): ";
	std::cin >> m;
    int Px[n][2];
    int Qx[m][2];
    for (i = 0; i < n; i++)
    {
        std::cout << "Coeficiente a" << i <<" de P(x): ";
	    std::cin >> Px[i][0];
        std::cout << "grau de x" << i << ": ";
	    std::cin >> Px[i][1];
    }
    for (i = 0; i < m; i++)
    {
        std::cout << "Coeficiente a" << i <<" de Q(x): ";
	    std::cin >> Px[i][0];
        std::cout << "grau de x" << i << ": ";
	    std::cin >> Qx[i][1];
    }
    int produto[n * m][2];
    k = 0;
    for (i = 0; i < n ; i++)
    {
        for (j = 0; j < m; j++)
        {
            produto[k][0] = Px[i][0] * Qx[j][0];
            produto[k][1] = Px[i][1] + Qx[j][1];
            k++;
        }
    }
    std::cout << "P(x).Q(x) = ";
    for (i = 0; i < k ; i++)
        std::cout << produto[i][0] << "x^(" << produto[i][1] << ")" << (produto[i + 1][0] > 0 ? " + " : " ");
    return (0);
}
