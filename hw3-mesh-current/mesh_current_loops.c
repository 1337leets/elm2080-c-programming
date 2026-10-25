#include <stdio.h>

// Mesh currents with the inverse and the matrix product done in loops,
// plus a check for a singular matrix.

int main(void)
{
    int R[2][2] = { {6, 4}, {4, 10} };
    float V[2][1] = { {16}, {18} };
    float I[2][1] = { {0}, {0} };
    float R_inv[2][2];

    float r[2][2] = {
        { (float)R[0][0], (float)R[0][1] },
        { (float)R[1][0], (float)R[1][1] }
    };

    float det = r[0][0] * r[1][1] - r[0][1] * r[1][0];

    if (det == 0) {
        printf("The matrix has no inverse. Determinant = 0.\n");
        return 1;
    }

    // Inverse of a 2x2 matrix
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (i == j)
                R_inv[i][j] = r[1 - i][1 - j] / det;  // swap the diagonal
            else
                R_inv[i][j] = -r[i][j] / det;         // negate the off-diagonal
        }
    }

    // I = R_inv * V
    for (int i = 0; i < 2; i++) {
        I[i][0] = 0;
        for (int j = 0; j < 2; j++) {
            I[i][0] += R_inv[i][j] * V[j][0];
        }
    }

    printf("Current matrix (2x1):\n");
    printf("I_A = %.2f A\n", I[0][0]);
    printf("I_B = %.2f A\n", I[1][0]);

    return 0;
}
