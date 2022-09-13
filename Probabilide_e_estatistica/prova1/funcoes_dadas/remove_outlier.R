# Coeficiente de variação
cv <- function(x) {
  100 * sd(x) / mean(x)
}

at <- function(x) {
  print(diff(range(x)))
  print(range(x))
}

##===============================================================================
## Título: Remoção de outliers de data.frame com duas variáveis numéricas,
##         com estrutura de covariância e NAs
## Curso : Introdução à estatística
## Autor : José Cláudio Faria/UESC/DCET
## Data  : 20/07/2016 03:13:13
## Versão: v3
## Objetivos:
##===============================================================================
## a) Remoção automática de outliers e NAs de dados com estrutura de covariância
## b) Estender o conceito de programação em R
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

    ## Distâncias interquartílicas - iqr
    iqr.t <- q.t[3] - q.t[1]
    iqr.r <- q.r[3] - q.r[1]

    ## Identificação de outliers
    out <- subset(x,
                  Y1 >= q.t[3] + 1.5 * iqr.t |
                  Y1 <= q.t[1] - 1.5 * iqr.t |
                  Y1 < 0
                  |
                  Y2 >= q.r[3] + 1.5 * iqr.r |
                  Y2 <= q.r[1] - 1.5 * iqr.r |
                  Y2 < 0)

    ## Condição de saída
    if (dim(out)[1] == 0)
      return(x)

    ## Remoção de outliers
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
