#include <stdio.h>

// Variant with input validation. Rejects non-numeric and non-positive input.

int main(void)
{
    double daily_volume; // water volume per day (m^3/day)
    double head;         // head (m)

    double g = 9.81;                 // gravitational acceleration (m/s^2)
    double rho = 1000.0;             // water density (kg/m^3)
    double head_efficiency = 0.85;
    double turbine_efficiency = 0.75;
    double generator_efficiency = 0.95;

    printf("Enter the water volume per day (m^3/day): ");
    if (scanf("%lf", &daily_volume) != 1 || daily_volume <= 0) {
        printf("Please enter a valid value!\n");
        return 1;
    }

    printf("Enter the head (m): ");
    if (scanf("%lf", &head) != 1 || head <= 0) {
        printf("Please enter a valid value!\n");
        return 1;
    }

    double yearly_volume = daily_volume * 365; // m^3/year
    double total_efficiency = head_efficiency * turbine_efficiency * generator_efficiency;

    // E = rho * g * h * V * eta
    double energy_joule = rho * g * head * yearly_volume * total_efficiency;
    double energy_kwh = energy_joule / 3600000.0;

    printf("\nAnnual energy output: %.2f J (about %.2f kWh)\n", energy_joule, energy_kwh);

    return 0;
}
