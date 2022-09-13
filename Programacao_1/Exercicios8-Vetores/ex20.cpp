/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex20.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:19:04 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/29 09:13:19 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exercicios.h"

void    swap(int *n1, int *n2)
{
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void    bubleSort(int array[], int n)
{
    int i;
    int j;

    for (i = 0; i < (n -1); i++)
        for (j = 0; j < (n-i-1); j++)
            if (array[j] > array[j + 1])
                swap(&array[j], &array[j+1]);
}

int main(void)
{
    int array[20];
    int i;

    for (i = 0; i < 20; i++)
    {
        std::cout << "Lista[" << i  + 1 << "]:";
        std::cin >> array[i];
    }
    bubleSort(array, 20);
    for (i=0; i < 20; i++)
        std::cout << array[i] << " ";
}