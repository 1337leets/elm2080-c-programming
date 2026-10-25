#include <stdio.h>

int main(void)
{
	// Constants
	double gravity = 9.81;          // m/s^2
	double water_density = 1000.0;  // kg/m^3
	double head_efficiency = 0.85;
	double turbine_efficiency = 0.75;
	double generator_efficiency = 0.95;
	double volume_per_day, net_head, overall_efficiency, average_flow_rate, power, annual_energy_output;

	// Calculating the overall efficiency
	overall_efficiency = head_efficiency * turbine_efficiency * generator_efficiency;

	// Requesting user inputs
	printf("Enter the water volume per day (m^3/day): "); scanf("%lf", &volume_per_day);
	printf("Enter the net head (m): "); scanf("%lf", &net_head);

	// Converting the average flow rate from m^3/day to m^3/s
	average_flow_rate = volume_per_day / 86400;

	// Average electrical power (W)
	power = water_density * gravity * net_head * average_flow_rate * overall_efficiency;

	// Annual energy output, W * 8760 h = Wh, divided by 1000 for kWh
	annual_energy_output = power * 8760 / 1000;

	printf("The annual energy output is: %.2f kWh\n", annual_energy_output);

	return 0;
}
