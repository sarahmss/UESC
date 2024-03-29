 #===============================================================================
# Name   : Prova 1
# Author : Sarah Modesto Sanches
# Date   : 14/10/2021
# Aim    : Ilustrar alguns conceitos b�sicos de introdu��o � estat�stica
# Mail   : <<<smsanches.ege@uesc.br>>>
#===============================================================================

# A fun��o gerar_dados foi programada para gerar uma amostra aleat�ria estraticada de pessoas do munic�pio X. As vari�veis aleat�rias de interesse s�o: Y1 (medido em un), Y2 (medido em un) e Sexo. Adicionalmente, assuma que Y1 e Y2 n�o podem assumir valores reais negativos. Os dados s�o ct�cios e tem nalidades exclusivamente did�ticas para ns de avalia��o pr�tica em an�lise de dados. Realizar a an�lise explorat�ria dos dados com respostas �s seguintes quest�es:A fun��o gerar_dados foi programada para gerar uma amostra aleat�ria estraticada de pessoas do munic�pio X. As vari�veis aleat�rias de interesse s�o: Y1 (medido em un), Y2 (medido em un) e Sexo. Adicionalmente, assuma que Y1 e Y2 n�o podem assumir valores reais negativos. Os dados s�o ct�cios e tem nalidades exclusivamente did�ticas para ns de avalia��o pr�tica em an�lise de dados. Realizar a an�lise explorat�ria dos dados com respostas �s seguintes quest�es:

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

#... 1. (0.5) Antes e ap�s a elimina��o de poss�veis outliers sem distin��o de sexo:
Y1 <- dad[, c("Y1")]
Y2 <- dad[, c("Y2")]
Y1_OUT <- remove_outliers(Y1, na.rm=TRUE)
Y2_OUT <- remove_outliers(Y2, , na.rm=TRUE)
boxplot(main= "Antes ",col=c("darksalmon", "lightgray"), Y1, Y2)
boxplot(main= "Depois ",col=c("darksalmon", "lightgray"), Y1_OUT, Y2_OUT)

#... 2. (0.5) Ap�s a elimina��o de poss�veis outliers para cada sexo:
Y1_M <- remove_outliers(dad[dad$Sexo=='M', c("Y1")], na.rm=TRUE)
Y1_F <- remove_outliers(dad[dad$Sexo=='F', c("Y1")], na.rm=TRUE) 
Y2_M <- remove_outliers(dad[dad$Sexo=='M', c("Y2")], na.rm=TRUE)
Y2_F <- remove_outliers(dad[dad$Sexo=='F', c("Y2")], na.rm=TRUE)
boxplot(main= "Masculino ",col=c("Blue", "lightgray"), Y1_M, Y2_M)
boxplot(main= "Feminino ",col=c("Red", "lightgray"), Y1_F, Y2_F)


#.-------------------------------------------------------------------------------
#. 1.2)  Para Y1 (1.0):

#... 1. (0.5) Uma apresenta��o tabular contendo apenas as freq��ncias: absoluta (Fi), relativa (Fr, %) e acumulada (Fac, %), nessa ordem:
 Y1_tbM <- fdt(Y1_M, na.rm=TRUE)
 Y1_tbF <- fdt(Y1_F, na.rm=TRUE)
#... 2.(0.5) Histograma e o pol�gono de freq��ncia acumulada dos dados:
plot(Y1_tbM , type='cfh' , col="Blue", main="Histograma de frequ�ncia acumulada Masculino", ylab="frequ�ncia", xlab="Y1")
plot(Y1_tbM, type='cfp', col="black", main="pol�gono de frequ�ncia acumulada Masculino ", ylab="frequ�ncia acumulada", xlab="Y1") 
plot(Y1_tbF , type='cfh' , col="Red", main="Histograma de frequ�ncia acumulada Feminino", ylab="frequ�ncia", xlab="Y1")
plot(Y1_tbF, type='cfp', col="black", main="pol�gono de frequ�ncia acumulada Feminino", ylab="frequ�ncia acumulada", xlab="Y1") 
#.-------------------------------------------------------------------------------

#. 2.1)  AED: Medidas determinadas a partir dos vetores (1.5). Para as vari�veis Y1 e Y2 elaborar apresenta��es tabulares contendo as seguintes estimativas:
#... 1. (0.5) Tend�ncia central: m�dia, mediana e moda;

n_M <-  c(mean(Y1_M, na.rm=TRUE), mean(Y2_M, na.rm=TRUE))
n_F <-  c(mean(Y1_F, na.rm=TRUE), mean(Y2_F, na.rm=TRUE))
m_M <-  c(mfv(Y1_M, na.rm=TRUE), mfv(Y2_M, na.rm=TRUE))
m_F <-  c(mfv(Y1_F, na.rm=TRUE), mfv(Y2_F, na.rm=TRUE))
md_M <- c(median(Y1_M, na.rm=TRUE), median(Y2_M, na.rm=TRUE))
md_F <- c(median(Y1_F, na.rm=TRUE), median(Y2_F, na.rm=TRUE))
TC_M <- data.frame(var=c("Y1", "Y2"), n=n_M, m=m_M, md=md_M)
TC_F <- data.frame(var=c("Y1", "Y2"), n=n_F, m=m_F, md=md_F)

#... 2 (0.5) Posi��o: quartis e decis;
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

#... 3. (0.5) Dispers�o: amplitude total, vari�ncia, desvio padr�o e coeficiente de varia��o
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
 
#. 2.2) Medidas determinadas a partir de apresenta��es tabulares (1.5):
#. A fun��o gerar_tdf foi programada para gerar uma tabela de distribui��o de frequ�ncias do tipo comum, dessas que se encontra em publica��es. Considere que esta tabela descreve um assunto de seu interesse - publicado - e que � necess�rio determinar as medidas estat�sticas b�sicas com nalidades de entendimento e compara��es. Elabore uma apresenta��o tabular contendo:
tb
tb1 <- fdt(tb)

#... 1. (0.5) Tend�ncia central: m�dia, mediana e moda;
TC <- c(n=mean(tb1), md=median(tb1), m=mfv(tb1))
#... 2. (0.5) Posi��o: quartis e decis;
P <- c(
       Q=quantile.fdt(tb1, probs=seq(0, 1, .25)),
       d=quantile.fdt(tb1, probs=seq(0, 1, .1)))
#... 3. (0.5) Dispers�o: amplitude total, vari�ncia, desvio padr�o e coeciente de varia��o.            # -1.812
Dis <- c(ap = at(tb),
         va = var(tb),
         SD = sd(tb),
         CV = cv(tb))

#.---------------------------------------------------------------------------

#. 3.1 ) Associa��o (1.5).
#... 1. (0.5) Estimativas: covari�ncia e correla��o linear simples;

#... 2. (0.5) Diagramas de dispers�o dos dados;

#... 3. (0.5) Um estudo semelhante foi realizado em um outro munic�pio, por outras pessoas. Contudo, as unidades de medida usadas foram: Y1 (100 * un) e Y2 (100 * un). Para comparar associa��es entre as vari�veis de ambos os estudos, qual seria a medida estat�stica recomendada? Justifique.
#.---------------------------------------------------------------------------

#. 3.2 Regress�o linear (2.5)
#. Considere os dados gerados pela fun��o gerar_dados_rl como uma amostra de um estudo da inu�ncia de uma vari�vel xa X (medido em un) sobre uma vari�vel aleat�ria Y (medido em un.dia-1). Os dados s�o ct�cios e tem nalidades exclusivamente did�ticas para ns de avalia��o pr�tica em an�lise quantitativa de dados.
#... 1. (1.0) Ajuste aos dados dois modelos de regress�o linear: polin�mios de grau I e II (ambos n�o for�ado para a origem);

#... 2. (0.5) Apresente um diagrama de dispers�o dos dados com o melhor modelo.

#... 3. (0.5) Qual modelo melhor explica o fen�meno em estudo? Justique com fundamenta��o estat�stica.

#... 4. (0.5) Pelos crit�rios de ajustamento e escolha de modelos vistos em aula, os coecientes de determina��o (r�) de modelos lineares ajustados (for�ados e n�o for�ados para a origem) s�o compar�veis? Justique com fundamenta��o estat�stica.

#. 4 Contextualiza��o (1.0)
#. Localize um artigo cient�co (peri�dico Qualis A ou B) em �rea de seu interesse no qual a an�lise explorat�ria de dados (AED - possivelmente com medidas de associa��o e uso de regress�o linear como modelo explicativo) teve papel preponderante. Discuta o artigo com �nfase nos recursos da AED usados e tamb�m na adequa��o das normas �sicas das apresenta��es gr�ficas e tabulares adotada pelo peri�dico.
