#===============================================================================
# Título: Covariância e correlação linear simples
# Curso : Estatística básica
# Autor : José Cláudio Faria
# Data  : 30/08/2021 09:09:26
#===============================================================================
# Objetivos
#===============================================================================
# - Exemplificar, através do R, as medidas estatísticas: covariância e
#   correlação linear simples
#===============================================================================

#. PARTE I - Entendimento geométrico
# Descrição dos dados
# p   = teor de fósforo no solo determinado por um método A de análise: mg/dm3
# pro = produtividade da cultura: kg/ha

# Observe tratar-se de duas variáveis aleatórias (VA), pois ambas as medidas
# estatísticas medem o grau de associação linear entre duas VAs. Ou seja, o
# quanto o diagrama de dispersão dos dados tende para uma reta.

p  <- c( 9.1, 11.5,  6.4, 16.4, 12.6, 14.1,  8.4,  6.3, 11.2, 12.8,
        11.7, 10.6,  6.4, 10.3,  9.5,  3.2,  2.3, 15.1,  8.2)

pro <- c(4210, 5120, 3030, 6050, 5100, 6120, 4550, 4350, 5820, 8640,
         5220, 4620, 3210, 5230, 4240, 2250, 1550, 8050, 4520)


# Visualização gráfica das variáveis aleatórias em um diagrama de dispersão
par(mfrow=c(1, 1))
plot(pro ~ p,
     xlim=c(0.9*min(p),
            1.3*max(p)),
     ylim=c(0.9*min(pro),
            1.1*max(pro)),
     col='blue',
     bty='n',
     pch=19)

# Atenção: setar o dispositivo gráfico gráfico para sempre visível!
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

# Visualizar os dados e observar o gráfico
dad <- data.frame(p,
                  pro)
dad

# Identificação (opcional) dos dados a partir do gráfico
#identify(p,
#         pro,
#         pos=T)
# Escolha parar (botão direito do mouse) ou identifique todos os pontos

# Medidas estatísticas
mean(p)
mean(pro)

sd(p)
sd(pro)
cov(p, pro)

# Calculando a correlação usando a formula fundamental: r = cov(a,b) / sd(a) * sd(b)
(cor.p_pro <- cov(p, pro) / (sd(p) * sd(pro)))

# Calculando a correlação usando função do R
cor(p, pro)

# Verificação da influência da unidade de medida na covariância:
# Passando 'pro' para t/ha
cov(p, pro)

pro2 <- pro/1000

cov(p, pro2)

# Verificando que isto não influencia a correlação linear simples:
cor(p, pro)

cor(p, pro2)

# Verificação de que a variância é um caso particular da covariância, ou seja,
# a covariância de uma variável com ele mesma:
var(p)

cov(p, p)

var(pro)

cov(pro, pro)


#. PARTE II - modelos gráficos de diferentes padrões de associação
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

# Definindo parâmetros gráficos
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

# Visualização gráfica das variáveis aleatórias em um diagrama de dispersão
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

par(def.par)  # Volta ao padrão

#. PARTE III - comparando as medidas de associação
#.. Covariância
cov(Y1, Y2)   # Perfeita positiva
cov(Y1, Y3)   # Perfeita negativa
cov(Y1, Y4)   # Forte positiva
cov(Y1, Y5)   # Forte negativa
cov(Y6, Y7)   # Fraca e positiva
cov(Y7, Y8)   # Fraca e negativa
cov(Y9, Y10)  # Nula

#.. Correlação: observar as vantagens em relação a covariância!
cor(Y1, Y2)   # Perfeita positiva
cor(Y1, Y3)   # Perfeita negativa
cor(Y1, Y4)   # Forte positiva   
cor(Y1, Y5)   # Forte negativa   
cor(Y6, Y7)   # Fraca e positiva 
cor(Y7, Y8)   # Fraca e negativa 
cor(Y9, Y10)  # Nula             

#.. Verificando a influência da escala
#... Covariância
cov(Y1, Y4)
cov(100 * Y1, 100 * Y4)

#... Correlação
cor(Y1, Y4)
cor(100 * Y1, 100 * Y4)
cor(10 * Y1, 1000 * Y4)
