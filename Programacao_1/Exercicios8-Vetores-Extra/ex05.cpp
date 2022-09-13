/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:29:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/06 11:07:41 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <math.h>

/*. Faça um programa para resolver o seguinte problema:
São dadas as coordenadas reais x e y de um ponto, um número natural n, e as
coordenadas reais de n pontos (1 < n < 100). Deseja-se calcular e imprimir sem
repetição os raios das circunferências centradas no ponto (x,y) que passam por pelo
menos um dos n pontos dados.
Exemplo : (x,y) = (1.0, 1.0) ; n = 5
pontos : (-1.0, 1.2) , (1.5, 2.0) , (0.0, -2.0) , (0.0, 0.5) , (4.0, 2.0)
Nesse caso há três circunferências de raios: 1.12, 2.01 e 3.162.
Observações:
Distância entre os pontos (a,b) e (c,d) é
Dois pontos estão na mesma circunferência se estão à mesma distância do
centro*/

float dist(float x1, float y1, float x2, float y2)
{
    return(sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)));
}

int main(void)
{
    // cordenadas do centro
    float cx, cy;
    int i = 0, j = 0;
    int n = 0;
    
    while (n < 1 || n > 100)
    {
        if (i > 0)
            std::cout << "n deve ser menor que 100 e maior que 1 : ";
        std::cout << "Insira o valor de n : ";
        std::cin >> n; 
        i++;
    }
    std::cout << "Insira o valor de X: ";
    std::cin >> cx; 
    std::cout << "Insira o valor de Y: ";
    std::cin >> cy;   
    float pontos[n][2];
    std::cout << "Insira as cordenadas dos " << n << " pontos\n";
    for(i = 0; i < n; i++)
    {
        std::cout << "P" << i + 1 << " x: ";
        std::cin >> pontos[i][0];   
        std::cout << "P" << i  + 1 << " y: ";
        std::cin >> pontos[i][1];    
    }
    float raios[n];
    for (i = 0; i < n; i++)
    {
        raios[i] = dist(cx, cy, pontos[i][0], pontos[i][1]);
        for (j = 0; j < i; j++)
            if (raios[i] == raios[j])
                raios[i] = -1;
    }
    std::cout << "Circuferencias de raio: ";
    for (i = 0; i < n; i++)
        if (raios[i] != -1)
            std::cout << raios[i] << " ";
    return (0);
 }