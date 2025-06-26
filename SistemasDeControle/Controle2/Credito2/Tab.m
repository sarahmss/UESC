% Parâmetros do sistema
a = 14.97;
s = tf('s');
K = 750;
Gp = a * K /(s+a);
[num, den] = tfdata(Gp, 'v'); 
[A, B, C, D] = tf2ss(num, den);

% Estado inicial
x0 = 3;

% Vetor de tempos desejados
t_vals = 0:0.2:0.8;

% Solução exata
y_exato = zeros(size(t_vals));
for i = 1:length(t_vals)
    t = t_vals(i);
    y_exato(i) = exp(A*t)*x0 + (1 - exp(A*t))/(-A)*B;  % u(t) = 1 constante
end

% ---------- Simulação com T = 0.2 ----------
T = 0.2;
A_d = 1 + A*T;
B_d = B*T;
x = x0;
y_T02 = zeros(size(t_vals));
y_T02(1) = C*x;
for i = 2:length(t_vals)
    x = A_d * x + B_d * 1;
    y_T02(i) = C * x;
end

% ---------- Simulação com T = 0.1 ----------
T = 0.1;
A_d = 1 + A*T;
B_d = B*T;
x = x0;
y_T01 = zeros(size(t_vals));
y_T01(1) = C*x;
for i = 2:length(t_vals)
    for j = 1:(0.2/T)
        x = A_d * x + B_d * 1;
    end
    y_T01(i) = C * x;
end

% ---------- Simulação com T = 0.05 ----------
T = 0.05;
A_d = 1 + A*T;
B_d = B*T;
x = x0;
y_T005 = zeros(size(t_vals));
y_T005(1) = C*x;
for i = 2:length(t_vals)
    for j = 1:(0.2/T)
        x = A_d * x + B_d * 1;
    end
    y_T005(i) = C * x;
end

% ---------- Imprimir a tabela ----------
fprintf('Tempo (s)\tExato\t\tT=0.2\t\tT=0.1\t\tT=0.05\n');
for i = 1:length(t_vals)
    fprintf('%.1f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n', ...
        t_vals(i), y_exato(i), y_T02(i), y_T01(i), y_T005(i));
end
