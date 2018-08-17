#define F_CPU 16000000UL

#include "oled.h"
#include <avr/io.h>


int main()
{

	sei();
	OLED oled;
	uint8_t fb[1024] = {0};
	OLED_init(&oled, 128, 64, fb, 200000, 0b0111100);

	/* Try to decrease frequency and see what happens without lock */
	OLED_WITH_SPINLOCK(&oled) {
	  	OLED_put_rectangle(&oled, 0, 0, 127, 63, OLED_FILL | OLED_BLACK);
	}

    /* 8 vertice polygon */
    uint8_t x_axis[] = {20, 30, 90, 80, 80, 70, 10, 20};
    uint8_t y_axis[] = {10, 5, 5, 10, 50, 55, 55, 50};
    /* rectangle */
    uint8_t x_axis2[] = {10, 100, 100, 10};
    uint8_t y_axis2[] = {10, 10, 50, 50};
    /* triangle */
    uint8_t x_axis3[] = {30, 80, 70};
    uint8_t y_axis3[] = {30, 30, 10};

    OLED_put_polygon(&oled, 8, x_axis, y_axis, OLED_FILL | OLED_WHITE);
    OLED_put_polygon(&oled, 4, x_axis2, y_axis2, OLED_NO_FILL | OLED_WHITE);
    OLED_put_polygon(&oled, 3, x_axis3, y_axis3, OLED_FILL | OLED_BLACK);

	while (1) {
		OLED_refresh(&oled);
	}
}
