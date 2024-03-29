#===============================================================================
# T�tulo: Covari�ncia e correla��o linear simples
# Curso : Estat�stica b�sica
# Autor : Jos� Cl�udio Faria
# Data  : 30/08/2021 09:09:26
#===============================================================================
# Objetivos
#===============================================================================
# - Exemplificar, atrav�s do R, as medidas estat�sticas: covari�ncia e
#   correla��o linear simples
#===============================================================================

#. PARTE I - Entendimento geom�trico
# Descri��o dos dados
# p   = teor de f�sforo no solo determinado por um m�todo A de an�lise: mg/dm3
# pro = produtividade da cultura: kg/ha

# Observe tratar-se de duas vari�veis aleat�rias (VA), pois ambas as medidas
# estat�sticas medem o grau de associa��o linear entre duas VAs. Ou seja, o
# quanto o diagrama de dispers�o dos dados tende para uma reta.

p  <- c( 9.1, 11.5,  6.4, 16.4, 12.6, 14.1,  8.4,  6.3, 11.2, 12.8,
        11.7, 10.6,  6.4, 10.3,  9.5,  3.2,  2.3, 15.1,  8.2)

pro <- c(4210, 5120, 3030, 6050, 5100, 6120, 4550, 4350, 5820, 8640,
         5220, 4620, 3210, 5230, 4240, 2250, 1550, 8050, 4520)


# Visualiza��o gr�fica das vari�veis aleat�rias em um diagrama de dispers�o
par(mfrow=c(1, 1))
plot(pro ~ p,
     xlim=c(0.9*min(p),
            1.3*max(p)),
     ylim=c(0.9*min(pro),
            1.1*max(pro)),
     col='blue',
     bty='n',
     pch=19)

# Aten��o: setar o dispositivo gr�fico gr�fico para sempre vis�vel!
segments(mean(p),
         min(pro),
         mean(p),
         max(pro),
         col='darkred')

text(x=mean(p),
     y=max(pro),
     lab='mean(p)',
     pos=3)

segments(min(p),
         mean(pro),
         max(p),
         mean(pro),
         col='darkgreen')

text(x=max(p),
     y=mean(pro),
     lab='mean(pro)',
     pos=4)

# Visualizar os dados e observar o gr�fico
dad <- data.frame(p,
                  pro)
dad

# Identifica��o (opcional) dos dados a partir do gr�fico
#identify(p,
#         pro,
#         pos=T)
# Escolha parar (bot�o direito do mouse) ou identifique todos os pontos

# Medidas estat�sticas
mean(p)
mean(pro)

sd(p)
sd(pro)
cov(p, pro)

# Calculando a correla��o usando a formula fundamental: r = cov(a,b) / sd(a) * sd(b)
(cor.p_pro <- cov(p, pro) / (sd(p) * sd(pro)))

# Calculando a correla��o usando fun��o do R
cor(p, pro)

# Verifica��o da influ�ncia da unidade de medida na covari�ncia:
# Passando 'pro' para t/ha
cov(p, pro)

pro2 <- pro/1000

cov(p, pro2)

# Verificando que isto n�o influencia a correla��o linear simples:
cor(p, pro)

cor(p, pro2)

# Verifica��o de que a vari�ncia � um caso particular da covari�ncia, ou seja,
# a covari�ncia de uma vari�vel com ele mesma:
var(p)

cov(p, p)

var(pro)

cov(pro, pro)


#. PARTE II - modelos gr�ficos de diferentes padr�es de associa��o
# Criando os vetores
Y1  <- 1:12

Y2  <- 10 * Y1

Y3  <- -10 * Y1

Y4  <- c(10, 24, 28, 40, 55, 55,
         65, 80, 94, 95, 112, 116)

Y5  <- -1 * Y4

Y6  <- runif(n = 20, 1, 15)

Y7  <- Y6 + rnorm(20, m=2, sd=5)

Y8  <- -1 * Y6 + rnorm(20, m=2, sd=5)

Y9  <- c(0.03, 0.62, 0.07, 0.75, 0.88, 0.59,
         0.93, 0.15, 0.45, 0.61, 0.33, 0.70)

Y10 <- c(0.78, 0.39, 0.40, 0.38, 0.68, 0.63,
         0.66, 0.62, 0.19, 0.98, 0.75, 0.56)

# Definindo par�metros gr�ficos
def.par <- par(no.readonly = TRUE) # save default, for resetting...

par(cex=1,
    bty='n',
    pch=19,
    col='blue')

layout(matrix(c(1, 2,
                3, 4,
                5, 6,
                7, 8),
              ncol=2,
              byrow = TRUE))

# Visualiza��o gr�fica das vari�veis aleat�rias em um diagrama de dispers�o
# Y1 vs. Y2
plot(Y2 ~ Y1,                   
     main='Positiva | Perfeita',
     sub=paste('cor(Y1, Y2)',
               round(cor(Y1, Y2),
                     2),
               sep='='))

# Y1 vs. Y3
plot(Y3 ~ Y1,                   
     main='Negativa | Perfeita',
     sub=paste('cor(Y1, Y3)',
               round(cor(Y1, Y3),
                     2),
               sep='='))

# Y1 vs. Y4
plot(Y4 ~ Y1,
     main='Positiva | Forte',
     sub=paste('cor(Y1, Y4)',
               round(cor(Y1, Y4),
                     2),
               sep='='))

# Y1 vs. Y5
plot(Y5 ~ Y1,
     main='Negativa | Forte',
     sub=paste('cor(Y1, Y5)',
               round(cor(Y1, Y5),
                     2),
               sep='='))

# Y6 vs. Y7
plot(Y7 ~ Y6,
     main='Positiva | Fraca',
     sub=paste('cor(Y6, Y7)',
               round(cor(Y6, Y7),
                     2),
               sep='='))
# Y6 vs. Y8
plot(Y8 ~ Y6,
     main='Negativa | Fraca',
     sub=paste('cor(Y6, Y8)',
               round(cor(Y6, Y8),
                     2),
               sep='='))

# Y10 vs. Y9
plot(Y10 ~ Y9,
     main='Nula',
     sub=paste('cor(Y9, Y10)',
               round(cor(Y9, Y10),
                     2),
               sep='='))

plot(Y9 ~ Y10,
     main='Nula',
     sub=paste('cor(Y10, Y9)',
               round(cor(Y9, Y10),
                     2),
               sep='='))

par(def.par)  # Volta ao padr�o

#. PARTE III - comparando as medidas de associa��o
#.. Covari�ncia
cov(Y1, Y2)   # Perfeita positiva
cov(Y1, Y3)   # Perfeita negativa
cov(Y1, Y4)   # Forte positiva
cov(Y1, Y5)   # Forte negativa
cov(Y6, Y7)   # Fraca e positiva
cov(Y7, Y8)   # Fraca e negativa
cov(Y9, Y10)  # Nula

#.. Correla��o: observar as vantagens em rela��o a covari�ncia!
cor(Y1, Y2)   # Perfeita positiva
cor(Y1, Y3)   # Perfeita negativa
cor(Y1, Y4)   # Forte positiva   
cor(Y1, Y5)   # Forte negativa   
cor(Y6, Y7)   # Fraca e positiva 
cor(Y7, Y8)   # Fraca e negativa 
cor(Y9, Y10)  # Nula             

#.. Verificando a influ�ncia da escala
#... Covari�ncia
cov(Y1, Y4)
cov(100 * Y1, 100 * Y4)

#... Correla��o
cor(Y1, Y4)
cor(100 * Y1, 100 * Y4)
cor(10 * Y1, 1000 * Y4)
