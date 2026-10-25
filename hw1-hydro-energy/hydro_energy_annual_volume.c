#include <stdio.h>

// Variant that asks for the yearly water volume instead of the daily one
// and works in joules before converting to kWh.

int main(void)
{
    double head_nominal;      // nominal head (m)
    double volume_yearly;     // water collected per year (m^3/year)

    const double RHO = 1000.0;          // water density (kg/m^3)
    const double G = 9.81;              // gravitational acceleration (m/s^2)
    const double ETA_HEAD = 0.85;       // head efficiency
    const double ETA_TURBINE = 0.75;    // turbine efficiency
    const double ETA_GENERATOR = 0.95;  // generator efficiency
    const double J_PER_KWH = 3.6e6;     // joules in one kWh

    double head_net;
    double energy_potential_j;
    double energy_electric_j;
    double energy_electric_kwh;

    printf("Enter the nominal head (m): ");
    scanf("%lf", &head_nominal);

    printf("Enter the water volume per year (m^3/year): ");
    scanf("%lf", &volume_yearly);

    // Head losses are applied to the head itself
    head_net = head_nominal * ETA_HEAD;

    // Potential energy of the yearly water volume (J)
    energy_potential_j = volume_yearly * RHO * G * head_net;

    // Electrical energy after the turbine and the generator (J)
    energy_electric_j = energy_potential_j * ETA_TURBINE * ETA_GENERATOR;

    energy_electric_kwh = energy_electric_j / J_PER_KWH;

    printf("\n-----------------------------------------------------\n");
    printf("Results:\n");
    printf("Nominal head: %.2f m\n", head_nominal);
    printf("Net head: %.2f m\n", head_net);
    printf("Yearly water volume: %.2f m^3/year\n", volume_yearly);
    printf("Annual energy output: %.2f kWh/year\n", energy_electric_kwh);
    printf("-----------------------------------------------------\n");

    return 0;
}
