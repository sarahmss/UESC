s = tf('s');
si = s * eye(2); % usa 'eye' para matriz identidade
A = [0 2;
    -3 -5];

B = [   0;
        1];

C = [1 3]; 

u = 1/(s+1);

x_0 =  [    2;
            1];

si_A = inv(si - A)
X_s = si_A * (x_0 + B * u);
y =  C  * X_s
% yt = ilaplace(y)