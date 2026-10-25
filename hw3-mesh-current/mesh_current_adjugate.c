#include <stdio.h>

// Builds the R matrix from the component values and inverts it with the adjugate.
//
// IR1 = IA    IR2 = IB    IR3 = IA + IB
// -16 + IA*R1 + (IA + IB)*R3 = 0    so  IA*(R1 + R3) + IB*R3 = 16
// -18 + IB*R2 + (IA + IB)*R3 = 0    so  IA*R3 + IB*(R2 + R3) = 18
// V = R * I    so    I = inv(R) * V

int main(void)
{
	int i, j, V[2][1], V1, V2, R[2][2], R1, R2, R3, adjR[2][2], detR;
	float I[2][1], invR[2][2];

	V1 = 16; V2 = 18;
	R1 = 2; R2 = 6; R3 = 4;

	V[0][0] = V1;
	V[1][0] = V2;

	R[0][0] = R1 + R3; R[0][1] = R3;
	R[1][0] = R3;      R[1][1] = R2 + R3;

	detR = R[0][0] * R[1][1] - R[0][1] * R[1][0];

	adjR[0][0] = R[1][1];
	adjR[0][1] = -R[0][1];
	adjR[1][0] = -R[1][0];
	adjR[1][1] = R[0][0];

	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			invR[i][j] = (float)adjR[i][j] / detR;

	for (i = 0; i < 2; i++)
	{
		I[i][0] = 0;
		for (j = 0; j < 2; j++)
			I[i][0] += invR[i][j] * V[j][0];
	}

	printf("I_A = %.2f A\n", I[0][0]);
	printf("I_B = %.2f A\n", I[1][0]);

	return 0;
}
