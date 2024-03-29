# Coeficiente de varia��o
cv <- function(x) {
  100 * sd(x) / mean(x)
}

at <- function(x) {
  print(diff(range(x)))
  print(range(x))
}

##===============================================================================
## T�tulo: Remo��o de outliers de data.frame com duas vari�veis num�ricas,
##         com estrutura de covari�ncia e NAs
## Curso : Introdu��o � estat�stica
## Autor : Jos� Cl�udio Faria/UESC/DCET
## Data  : 20/07/2016 03:13:13
## Vers�o: v3
## Objetivos:
##===============================================================================
## a) Remo��o autom�tica de outliers e NAs de dados com estrutura de covari�ncia
## b) Estender o conceito de programa��o em R
##===============================================================================

remove_outliers <- function(x, type=2)
{
  ## Remover NAs
  x <- na.omit(x)

  while(1) 
  {
    ## Quartis
    q.t <- quantile(x$Y1,
                    type=type)[2:4]
    
    q.r <- quantile(x$Y2,
                    type=type)[2:4]

    ## Dist�ncias interquart�licas - iqr
    iqr.t <- q.t[3] - q.t[1]
    iqr.r <- q.r[3] - q.r[1]

    ## Identifica��o de outliers
    out <- subset(x,
                  Y1 >= q.t[3] + 1.5 * iqr.t |
                  Y1 <= q.t[1] - 1.5 * iqr.t |
                  Y1 < 0
                  |
                  Y2 >= q.r[3] + 1.5 * iqr.r |
                  Y2 <= q.r[1] - 1.5 * iqr.r |
                  Y2 < 0)

    ## Condi��o de sa�da
    if (dim(out)[1] == 0)
      return(x)

    ## Remo��o de outliers
    x <- subset(x,
                Y1 < q.t[3] + 1.5 * iqr.t &
                Y1 > q.t[1] - 1.5 * iqr.t &
                Y1 >= 0
                &
                Y2 < q.r[3] + 1.5 * iqr.r &
                Y2 > q.r[1] - 1.5 * iqr.r &
                Y2 >= 0)
  }
}
