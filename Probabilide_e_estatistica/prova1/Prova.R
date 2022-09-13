 #===============================================================================
# Name   : Prova 1
# Author : Sarah Modesto Sanches
# Date   : 14/10/2021
# Aim    : Ilustrar alguns conceitos básicos de introdução à estatística
# Mail   : <<<smsanches.ege@uesc.br>>>
#===============================================================================

# A função gerar_dados foi programada para gerar uma amostra aleatória estraticada de pessoas do município X. As variáveis aleatórias de interesse são: Y1 (medido em un), Y2 (medido em un) e Sexo. Adicionalmente, assuma que Y1 e Y2 não podem assumir valores reais negativos. Os dados são ctícios e tem nalidades exclusivamente didáticas para ns de avaliação prática em análise de dados. Realizar a análise exploratória dos dados com respostas às seguintes questões:A função gerar_dados foi programada para gerar uma amostra aleatória estraticada de pessoas do município X. As variáveis aleatórias de interesse são: Y1 (medido em un), Y2 (medido em un) e Sexo. Adicionalmente, assuma que Y1 e Y2 não podem assumir valores reais negativos. Os dados são ctícios e tem nalidades exclusivamente didáticas para ns de avaliação prática em análise de dados. Realizar a análise exploratória dos dados com respostas às seguintes questões:

install.packages("Matrix")
install.packages("mvtnorm")
library("Matrix")
library("mvtnorm")
install.packages("fdth")
library("fdth")
dad <- gerar_dados(m1=202012319, m2=202012319, m3=202012319)
str(dad)
dad_rl <- gerar_dados_rl(m1=202012319, m2=202012319, m3=202012319)
str(dad_rl)
plot(dad_rl, pch=20)
tb <- gerar_tdf(m1=202012319, m2=202012319, m3=202012319)
str(tb)

      
#. 1.1) Diagrama de caixa (boxplot) para Y1 e Y2 (1.0):

#... 1. (0.5) Antes e após a eliminação de possíveis outliers sem distinção de sexo:
Y1 <- dad[, c("Y1")]
Y2 <- dad[, c("Y2")]
Y1_OUT <- remove_outliers(Y1, na.rm=TRUE)
Y2_OUT <- remove_outliers(Y2, , na.rm=TRUE)
boxplot(main= "Antes ",col=c("darksalmon", "lightgray"), Y1, Y2)
boxplot(main= "Depois ",col=c("darksalmon", "lightgray"), Y1_OUT, Y2_OUT)

#... 2. (0.5) Após a eliminação de possíveis outliers para cada sexo:
Y1_M <- remove_outliers(dad[dad$Sexo=='M', c("Y1")], na.rm=TRUE)
Y1_F <- remove_outliers(dad[dad$Sexo=='F', c("Y1")], na.rm=TRUE) 
Y2_M <- remove_outliers(dad[dad$Sexo=='M', c("Y2")], na.rm=TRUE)
Y2_F <- remove_outliers(dad[dad$Sexo=='F', c("Y2")], na.rm=TRUE)
boxplot(main= "Masculino ",col=c("Blue", "lightgray"), Y1_M, Y2_M)
boxplot(main= "Feminino ",col=c("Red", "lightgray"), Y1_F, Y2_F)


#.-------------------------------------------------------------------------------
#. 1.2)  Para Y1 (1.0):

#... 1. (0.5) Uma apresentação tabular contendo apenas as freqüências: absoluta (Fi), relativa (Fr, %) e acumulada (Fac, %), nessa ordem:
 Y1_tbM <- fdt(Y1_M, na.rm=TRUE)
 Y1_tbF <- fdt(Y1_F, na.rm=TRUE)
#... 2.(0.5) Histograma e o polígono de freqüência acumulada dos dados:
plot(Y1_tbM , type='cfh' , col="Blue", main="Histograma de frequência acumulada Masculino", ylab="frequência", xlab="Y1")
plot(Y1_tbM, type='cfp', col="black", main="polígono de frequência acumulada Masculino ", ylab="frequência acumulada", xlab="Y1") 
plot(Y1_tbF , type='cfh' , col="Red", main="Histograma de frequência acumulada Feminino", ylab="frequência", xlab="Y1")
plot(Y1_tbF, type='cfp', col="black", main="polígono de frequência acumulada Feminino", ylab="frequência acumulada", xlab="Y1") 
#.-------------------------------------------------------------------------------

#. 2.1)  AED: Medidas determinadas a partir dos vetores (1.5). Para as variáveis Y1 e Y2 elaborar apresentações tabulares contendo as seguintes estimativas:
#... 1. (0.5) Tendência central: média, mediana e moda;

n_M <-  c(mean(Y1_M, na.rm=TRUE), mean(Y2_M, na.rm=TRUE))
n_F <-  c(mean(Y1_F, na.rm=TRUE), mean(Y2_F, na.rm=TRUE))
m_M <-  c(mfv(Y1_M, na.rm=TRUE), mfv(Y2_M, na.rm=TRUE))
m_F <-  c(mfv(Y1_F, na.rm=TRUE), mfv(Y2_F, na.rm=TRUE))
md_M <- c(median(Y1_M, na.rm=TRUE), median(Y2_M, na.rm=TRUE))
md_F <- c(median(Y1_F, na.rm=TRUE), median(Y2_F, na.rm=TRUE))
TC_M <- data.frame(var=c("Y1", "Y2"), n=n_M, m=m_M, md=md_M)
TC_F <- data.frame(var=c("Y1", "Y2"), n=n_F, m=m_F, md=md_F)

#... 2 (0.5) Posição: quartis e decis;
M_Q <- c(Y1=quantile(Y1_M, na.rm=TRUE, probs=seq(0, 1, .25)),
         Y2=quantile(Y2_M, na.rm=TRUE, probs=seq(0, 1, .25)))
         
F_Q <- c(Y1=quantile(Y1_F, na.rm=TRUE, probs=seq(0, 1, .25)),
         Y2=quantile(Y2_F, na.rm=TRUE, probs=seq(0, 1, .25)))

M_D <- c(Y1=quantile(Y1_M, na.rm=TRUE, probs=seq(0, 1, .1)),
         Y2=quantile(Y2_M, na.rm=TRUE, probs=seq(0, 1, .1)))

F_D <- c(Y1=quantile(Y1_F, na.rm=TRUE, probs=seq(0, 1, .1)),
         Y2=quantile(Y2_F, na.rm=TRUE, probs=seq(0, 1, .1)))
         
TQ_M <- data.frame(Y1=M_Q[1:5], Y2=M_Q[6:10])
TQ_F <- data.frame(Y1=F_Q[1:5], Y2=F_Q[6:10])
TD_M <- data.frame(Y1=M_D[1:10], Y2=M_D[11:20])
TD_F <- data.frame(Y1=F_D[1:10], Y2=F_D[11:20])

#... 3. (0.5) Dispersão: amplitude total, variância, desvio padrão e coeficiente de variação
at_M <- c(at(Y1_M), at(Y2_M))
at_F <- c(at(Y1_F), at(Y2_F))
var_M <- c(var(Y1_M), var(Y2_M))
var_F <- c(var(Y1_F), var(Y2_F))
sd_M <- c(sd(Y1_M), sd(Y2_M))
sd_F <- c(sd(Y1_F), sd(Y2_F))
cv_M <- c(cv(Y1_M), cv(Y2_M))
cv_F <- c(cv(Y1_F), cv(Y2_F))

TD_M <- data.frame()
TD_F <- data.frame()

#.---------------------------------------------------------------------------
 
#. 2.2) Medidas determinadas a partir de apresentações tabulares (1.5):
#. A função gerar_tdf foi programada para gerar uma tabela de distribuição de frequências do tipo comum, dessas que se encontra em publicações. Considere que esta tabela descreve um assunto de seu interesse - publicado - e que é necessário determinar as medidas estatísticas básicas com nalidades de entendimento e comparações. Elabore uma apresentação tabular contendo:
tb
tb1 <- fdt(tb)

#... 1. (0.5) Tendência central: média, mediana e moda;
TC <- c(n=mean(tb1), md=median(tb1), m=mfv(tb1))
#... 2. (0.5) Posição: quartis e decis;
P <- c(
       Q=quantile.fdt(tb1, probs=seq(0, 1, .25)),
       d=quantile.fdt(tb1, probs=seq(0, 1, .1)))
#... 3. (0.5) Dispersão: amplitude total, variância, desvio padrão e coeciente de variação.            # -1.812
Dis <- c(ap = at(tb),
         va = var(tb),
         SD = sd(tb),
         CV = cv(tb))

#.---------------------------------------------------------------------------

#. 3.1 ) Associação (1.5).
#... 1. (0.5) Estimativas: covariância e correlação linear simples;

#... 2. (0.5) Diagramas de dispersão dos dados;

#... 3. (0.5) Um estudo semelhante foi realizado em um outro município, por outras pessoas. Contudo, as unidades de medida usadas foram: Y1 (100 * un) e Y2 (100 * un). Para comparar associações entre as variáveis de ambos os estudos, qual seria a medida estatística recomendada? Justifique.
#.---------------------------------------------------------------------------

#. 3.2 Regressão linear (2.5)
#. Considere os dados gerados pela função gerar_dados_rl como uma amostra de um estudo da inuência de uma variável xa X (medido em un) sobre uma variável aleatória Y (medido em un.dia-1). Os dados são ctícios e tem nalidades exclusivamente didáticas para ns de avaliação prática em análise quantitativa de dados.
#... 1. (1.0) Ajuste aos dados dois modelos de regressão linear: polinômios de grau I e II (ambos não forçado para a origem);

#... 2. (0.5) Apresente um diagrama de dispersão dos dados com o melhor modelo.

#... 3. (0.5) Qual modelo melhor explica o fenômeno em estudo? Justique com fundamentação estatística.

#... 4. (0.5) Pelos critérios de ajustamento e escolha de modelos vistos em aula, os coecientes de determinação (r²) de modelos lineares ajustados (forçados e não forçados para a origem) são comparáveis? Justique com fundamentação estatística.

#. 4 Contextualização (1.0)
#. Localize um artigo cientíco (periódico Qualis A ou B) em área de seu interesse no qual a análise exploratória de dados (AED - possivelmente com medidas de associação e uso de regressão linear como modelo explicativo) teve papel preponderante. Discuta o artigo com ênfase nos recursos da AED usados e também na adequação das normas ásicas das apresentações gráficas e tabulares adotada pelo periódico.
