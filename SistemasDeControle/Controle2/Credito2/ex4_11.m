s = tf('s');
si = s * eye(3); % usa 'eye' para matriz identidade
A = [0 1 0;
     0 0 1;
    -24 -26 -9];

B = [   0;
        0;
        1];

u = 1/(s+1);

x_0 =  [    1;
            0;
            2];

si_A = (si - A);
X_s = si_A / (x_0 + B * u);