// 2023-06-26 recallmenot

#define DEMO_GPIO_blink 0
#define DEMO_GPIO_blink_port 0
#define DEMO_GPIO_out 0
#define DEMO_GPIO_in_btn 1
#define DEMO_ADC_bargraph 0
#define DEMO_PWM_dayrider 0

#if ( ( DEMO_GPIO_blink + DEMO_GPIO_blink_port + DEMO_GPIO_out + DEMO_GPIO_in_btn + DEMO_ADC_bargraph + \
		  DEMO_PWM_dayrider ) > 1 ||                                                                    \
	  ( DEMO_GPIO_blink + DEMO_GPIO_blink_port + DEMO_GPIO_out + DEMO_GPIO_in_btn + DEMO_ADC_bargraph + \
		  DEMO_PWM_dayrider ) < 1 )
#error "please enable ONE of the demos by setting it to 1 and the others to 0"
#endif

#include "ch32v003fun.h"

#include "ch32v003_GPIO_branchless.h"

#include <stdio.h>
static unsigned int cnt = 0;
static int state = 1;
static int port =GPIOv_from_PORT_PIN( GPIO_port_D, 3 );

void   ( * volatile fun_prt )();
void mat();
void cat();


void cat()
{
	uint8_t bpin_d3_gnd = !GPIO_digitalRead( port );


	if ( bpin_d3_gnd && ( state == 0 ) )
	{
		printf( "state %d %d\n", state, cnt );
		cnt++;
		state = 1;
	}
	else if ( !bpin_d3_gnd && ( state == 1 ) )
	{
		printf( "state %d %d\n", state, cnt );
		cnt++;
		state = 0;
		fun_prt = &mat;
	}
}


void mat()
{
	uint8_t bpin_d3_gnd = !GPIO_digitalRead( port );


	if ( bpin_d3_gnd && ( state == 0 ) )
	{
		printf( "mat 1 state %d %d\n", state, cnt );
		cnt++;
		state = 1;
	}
	else if ( !bpin_d3_gnd && ( state == 1 ) )
	{
		printf( "mat 2 state %d %d\n", state, cnt );
		cnt++;
		state = 0;
		fun_prt = &cat;

	}
}

int main()
{
	SystemInit();


	Delay_Ms( 2000 );
	printf( "DEMO_GPIO_in_btn \n" );
	GPIO_port_enable( GPIO_port_C );
	GPIO_port_enable( GPIO_port_D );
	// GPIO D3 Push-Pull
	GPIO_pinMode( GPIOv_from_PORT_PIN( GPIO_port_D, 3 ), GPIO_pinMode_I_pullUp, GPIO_Speed_In );
	fun_prt = &cat;
	while ( 1 )
	{
		( *fun_prt )();
	}
}
