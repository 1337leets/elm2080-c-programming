#include <stdio.h>

// Mesh currents with the 2x2 inverse written out element by element.

int main(void)
{
    int R[2][2] = {
        {6, 4},
        {4, 10}
    };

    float V[2][1] = {
        {16},
        {18}
    };

    float I[2][1] = {
        {0},
        {0}
    };

    float det = (float)R[0][0] * R[1][1] - (float)R[0][1] * R[1][0];

    float R_inv[2][2];
    R_inv[0][0] =  (float)R[1][1] / det;
    R_inv[0][1] = -(float)R[0][1] / det;
    R_inv[1][0] = -(float)R[1][0] / det;
    R_inv[1][1] =  (float)R[0][0] / det;

    I[0][0] = R_inv[0][0] * V[0][0] + R_inv[0][1] * V[1][0];
    I[1][0] = R_inv[1][0] * V[0][0] + R_inv[1][1] * V[1][0];

    printf("Current matrix (2x1):\n");
    printf("I_A = %.2f A\n", I[0][0]);
    printf("I_B = %.2f A\n", I[1][0]);

    return 0;
}
