#include <stdio.h>

int main(void)
{
	// Defining variables and values
	float voltage, resistance_1, resistance_2, current, voltage_2;
	voltage = 20;
	resistance_1 = 1;

	printf("Voltage across R2\n");

	// Stepping R2 from 1 to 20 ohm
	for (resistance_2 = 1; resistance_2 <= 20; resistance_2++)
	{
		// Calculating the current and the voltage across R2
		current = voltage / (resistance_1 + resistance_2);
		voltage_2 = current * resistance_2;

		printf("R2 = %2.0f ohm: %.2f V\n", resistance_2, voltage_2);
	}

	return 0;
}
