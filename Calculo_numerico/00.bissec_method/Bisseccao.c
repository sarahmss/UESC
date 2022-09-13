/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bisseccao.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:33:15 by coder             #+#    #+#             */
/*   Updated: 2022/09/14 01:47:01 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bisseccao.h"

static  double f_x(double x)
{
   return (pow(x, 3) - (9 * x) + 3); // I[0; 1] eps == 0.001
}

static  bool    valor_intermediario(double interv_a, double interv_b)
{
    double  f_a = f_x(interv_a);
    double  f_b = f_x(interv_b);
    
    if ((f_a * f_b) < 0)
        return (true);
    if (f_a == 0 || f_b == 0)
      printf("The %f  values it is a expresion's zero. \n", f_a == 0 ? interv_a : interv_b);
    else
        printf("[%f;%f] Interval does not satisfy Bozanos theorem\n", interv_a, interv_b);
    return (false);
        
}

static  int     get_iter(double interv_a, double interv_b, double eps)
{
    double iter;
    
    iter = log10(interv_b - interv_a);
    iter -= log10(eps);
    iter /= log(2);
    printf ("%f iterations whill be nescessary \n",  ceil(iter));
    return (ceil(iter));
}

static double  bissec(double interv_a, double interv_b, double eps)
{
    double  x_medio;
    double  iter_num;
    double  interv_size = interv_b - interv_a;
    
    if (valor_intermediario(interv_a, interv_b) == false)
        return (0);
    iter_num = get_iter(interv_a, interv_b, eps);
    while (interv_size > eps && iter_num-- != 0)
    {
        interv_size = interv_b - interv_a;
        x_medio = (interv_a + interv_b) / 2;
        if (f_x(x_medio) == 0)
        {
            printf("The %f  values it is a expresion's zero. \n", x_medio);
            return (x_medio);
        }
        if  ((f_x(interv_a)) * (f_x(x_medio)) < 0)
            interv_b = x_medio;
        else 
            interv_a = x_medio;  
   }
    x_medio = (interv_a + interv_b) / 2;
    printf("Final interval: [%f,%f] \n Closest solution: %f\n", interv_a, interv_b, x_medio);
    return (x_medio);
}

int main(int argc, char *argv[])
{    
    if (argc != 4)
        return(printf("invalide usage:  <./bissec intervalo_a intervalo_b eps> \n"));
    bissec(atof(argv[1]), atof(argv[2]), atof(argv[3]));   
}