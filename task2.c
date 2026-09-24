#include <stdio.h>
#include <ctype.h>	// standard C library being used for toupper() to standardize capitolization of user inputed strings

/* Tempurature Unit Conversion Functions
- Only three functions are needed to convert one temp unit into any other
- In the cases of [Celsius -> Kelvin; Fahrenheit -> Celsius; Kelvin -> Fahrenheit], the tempurature can first be converted to non-specified unit, then passed into the function that will then convert the value into the correct unit.
*/

float c_to_f(float c) {
	return((c * (9.0 / 5.0) + 32));
}

float f_to_k(float f) {
	return(((f - 32) * (5.0 / 9.0)) + 273.15);
}

float k_to_c(float k) {
	return(k - 273.15);
}

/* Tempurature Categorization Ranges (In Celsius)
- Freezing: [-inf, 0)
- Cold: [0, 10)
- Comfortable: [10, 25)
- Hot: [25, 35)
- Extreme heat: [35, +inf)
*/

void cat_and_advise(float celsius) {
    printf("Temperature category: ");
    if (celsius < 0.0) {
        printf("Freezing\n");
        printf("Weather advisory: Wear a heavy coat and stay warm!\n");
    } else if (celsius >= 0.0 && celsius < 10.0) {
        printf("Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (celsius >= 10.0 && celsius < 25.0) {
        printf("Comfortable\n");
        printf("Weather advisory: Enjoy the nice weather!\n");
    } else if (celsius >= 25.0 && celsius < 35.0) {
        printf("Hot\n");
        printf("Weather advisory: Drink lots of water!\n");
    } else {
        printf("Extreme Heat\n");
        printf("Weather advisory: Stay indoors and keep cool!\n");
    }
}

/* Main Function

*/

int main(){

	// Initialize local variables
	float input_temp;
	float converted_temp;
	float temp_in_c;
	char og_scale;
	char target_scale;

	// Obtain input tempurature input from user
	printf("Enter the tempurature value: ");

	// Check if user input is a valid floating point value
	if (scanf("%f", &input_temp) != 1) {
		printf("Invalid tempurature value.\n");
		return 1;
	}

	// ***PLACE HOLD***
	printf("Enter the original scale (C, F, or K): ");
	scanf(" %c", &og_scale);
	og_scale = toupper(og_scale);

	// ***PLACE HOLD***
	printf("Enter the scale to convert to (C, F, or K): ");
	scanf(" %c", &target_scale);
	target_scale = toupper(target_scale);

	// ***PLACE HOLD***
	if (og_scale == 'K' && input_temp < 0) {
		printf("Invalid input: Kelvin cannot be less than 0.\n");
		return 1;
	}

	// ***PLACE HOLD***
	if (og_scale == 'C') {
		temp_in_c = input_temp;
	} else if (og_scale == 'F') {
		temp_in_c = f_to_k(input_temp);
		temp_in_c = k_to_c(input_temp);
	} else if (og_scale == 'K') {
		temp_in_c = k_to_c(input_temp);
	} else {
		printf("Invalid original scale.\n");
		return 1;
	}

	// ***PLACE HOLD***
	if (target_scale == 'C') {
		converted_temp = temp_in_c;
	} else if (target_scale == 'F') {
		converted_temp = c_to_f(temp_in_c);
	} else if (target_scale == 'K') {
		converted_temp = c_to_f(temp_in_c);
		converted_temp = f_to_k(temp_in_c);
	} else {
		printf("Invalid target scale.\n");
		return 1;
	}

	// ***PLACE HOLD***
	printf("\nConverted tempurature: %.2f %c\n", converted_temp, target_scale);
	cat_and_advise(temp_in_c);

	return 0;
}



















