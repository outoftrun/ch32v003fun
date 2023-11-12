#include "ch32v003fun.h"

#include <stdio.h>
#define CH32V003_SPI_SPEED_HZ 1000000
#define CH32V003_SPI_DIRECTION_2LINE_TXRX
#define CH32V003_SPI_CLK_MODE_POL0_PHA0			//leading = rising		trailing = falling		sample on leading		default if you're unsure
#define CH32V003_SPI_NSS_SOFTWARE_ANY_MANUAL	// toggle manually!
#define CH32V003_SPI_IMPLEMENTATION
#include "ch32v003_SPI.h"


#define SetBit0 ( 1 << 4 )
#define ClearBit0 ( 1 << ( 16 + 4 ) )
#define BIT( A, B ) ( SetBit0 | ( ( A & ( 1 << B ) ) ? ( 1 << 4 ) : 0 ) )

static const unsigned char header = 0xff;

static inline void doHeader()
{

	static const unsigned int headerBits[] = { ClearBit0, BIT( header, 1 ), ClearBit0, BIT( header, 2 ), ClearBit0,
		BIT( header, 3 ), ClearBit0, BIT( header, 4 ), ClearBit0, BIT( header, 5 ), ClearBit0, BIT( header, 6 ),
		ClearBit0, BIT( header, 7 ), ClearBit0 };


	GPIOD->BSHR = headerBits[0]; // Turn on GPIOs
	GPIOD->BSHR = headerBits[1]; // Turn off GPIOs


	GPIOD->BSHR = headerBits[2]; // Turn on GPIOs
	GPIOD->BSHR = headerBits[3]; // Turn off GPIOs


	GPIOD->BSHR = headerBits[4]; // Turn on GPIOs
	GPIOD->BSHR = headerBits[5]; // Turn off GPIOs

	GPIOD->BSHR = headerBits[6]; // Turn on GPIOs
	GPIOD->BSHR = headerBits[7]; // Turn off GPIOs

	GPIOD->BSHR = headerBits[8]; // Turn on GPIOs
	GPIOD->BSHR = headerBits[9]; // Turn off GPIOs

	GPIOD->BSHR = headerBits[10]; // Turn on GPIOs
	GPIOD->BSHR = headerBits[11]; // Turn off GPIOs

	GPIOD->BSHR = headerBits[12]; // Turn on GPIOs
	GPIOD->BSHR = headerBits[13]; // Turn off GPIOs

	GPIOD->BSHR = headerBits[14]; // Turn on GPIOs
	GPIOD->BSHR = headerBits[15]; // Turn off GPIOs
}


		
void doBitsSolid( const unsigned char red, const unsigned char green, const unsigned char blue )
{
	const unsigned int redBits[] = { BIT( red, 0 ), ClearBit0, BIT( red, 1 ), ClearBit0, BIT( red, 2 ), ClearBit0,
		BIT( red, 3 ), ClearBit0, BIT( red, 4 ), ClearBit0, BIT( red, 5 ), ClearBit0, BIT( red, 6 ), ClearBit0,
		BIT( red, 7 ), ClearBit0 };

	const unsigned int greenBits[] = { BIT( green, 0 ), ClearBit0, BIT( green, 1 ), ClearBit0, BIT( green, 2 ),
		ClearBit0, BIT( green, 3 ), ClearBit0, BIT( green, 4 ), ClearBit0, BIT( green, 5 ), ClearBit0, BIT( green, 6 ),
		ClearBit0, BIT( green, 7 ), ClearBit0 };

	const unsigned int blueBits[] = { BIT( blue, 0 ), ClearBit0, BIT( blue, 1 ), ClearBit0, BIT( blue, 2 ), ClearBit0,
		BIT( blue, 3 ), ClearBit0, BIT( blue, 4 ), ClearBit0, BIT( blue, 5 ), ClearBit0, BIT( blue, 6 ), ClearBit0,
		BIT( blue, 7 ), ClearBit0 };

	doHeader();

	GPIOD->BSHR = redBits[0]; // Turn on GPIOs
	GPIOD->BSHR = redBits[1]; // Turn off GPIOs


	GPIOD->BSHR = redBits[2]; // Turn on GPIOs
	GPIOD->BSHR = redBits[3]; // Turn off GPIOs


	GPIOD->BSHR = redBits[4]; // Turn on GPIOs
	GPIOD->BSHR = redBits[5]; // Turn off GPIOs

	GPIOD->BSHR = redBits[6]; // Turn on GPIOs
	GPIOD->BSHR = redBits[7]; // Turn off GPIOs

	GPIOD->BSHR = redBits[8]; // Turn on GPIOs
	GPIOD->BSHR = redBits[9]; // Turn off GPIOs

	GPIOD->BSHR = redBits[10]; // Turn on GPIOs
	GPIOD->BSHR = redBits[11]; // Turn off GPIOs

	GPIOD->BSHR = redBits[12]; // Turn on GPIOs
	GPIOD->BSHR = redBits[13]; // Turn off GPIOs

	GPIOD->BSHR = redBits[14]; // Turn on GPIOs
	GPIOD->BSHR = redBits[15]; // Turn off GPIOs


	GPIOD->BSHR = greenBits[0]; // Turn on GPIOs
	GPIOD->BSHR = greenBits[1]; // Turn off GPIOs


	GPIOD->BSHR = greenBits[2]; // Turn on GPIOs
	GPIOD->BSHR = greenBits[3]; // Turn off GPIOs


	GPIOD->BSHR = greenBits[4]; // Turn on GPIOs
	GPIOD->BSHR = greenBits[5]; // Turn off GPIOs

	GPIOD->BSHR = greenBits[6]; // Turn on GPIOs
	GPIOD->BSHR = greenBits[7]; // Turn off GPIOs

	GPIOD->BSHR = greenBits[8]; // Turn on GPIOs
	GPIOD->BSHR = greenBits[9]; // Turn off GPIOs

	GPIOD->BSHR = greenBits[10]; // Turn on GPIOs
	GPIOD->BSHR = greenBits[11]; // Turn off GPIOs

	GPIOD->BSHR = greenBits[12]; // Turn on GPIOs
	GPIOD->BSHR = greenBits[13]; // Turn off GPIOs

	GPIOD->BSHR = greenBits[14]; // Turn on GPIOs
	GPIOD->BSHR = greenBits[15]; // Turn off GPIOs

	GPIOD->BSHR = blueBits[0]; // Turn on GPIOs
	GPIOD->BSHR = blueBits[1]; // Turn off GPIOs


	GPIOD->BSHR = blueBits[2]; // Turn on GPIOs
	GPIOD->BSHR = blueBits[3]; // Turn off GPIOs


	GPIOD->BSHR = blueBits[4]; // Turn on GPIOs
	GPIOD->BSHR = blueBits[5]; // Turn off GPIOs

	GPIOD->BSHR = blueBits[6]; // Turn on GPIOs
	GPIOD->BSHR = blueBits[7]; // Turn off GPIOs

	GPIOD->BSHR = blueBits[8]; // Turn on GPIOs
	GPIOD->BSHR = blueBits[9]; // Turn off GPIOs

	GPIOD->BSHR = blueBits[10]; // Turn on GPIOs
	GPIOD->BSHR = blueBits[11]; // Turn off GPIOs

	GPIOD->BSHR = blueBits[12]; // Turn on GPIOs
	GPIOD->BSHR = blueBits[13]; // Turn off GPIOs

	GPIOD->BSHR = blueBits[14]; // Turn on GPIOs
	GPIOD->BSHR = blueBits[15]; // Turn off GPIOs
}


void doBits( const unsigned char red, const unsigned char green, const unsigned char blue )
{

	// these can be rpleaced with inline code
	const unsigned int redBits[] = { BIT( red, 0 ), ClearBit0, BIT( red, 1 ), ClearBit0, BIT( red, 2 ), ClearBit0,
		BIT( red, 3 ), ClearBit0, BIT( red, 4 ), ClearBit0, BIT( red, 5 ), ClearBit0, BIT( red, 6 ), ClearBit0,
		BIT( red, 7 ), ClearBit0 };

	const unsigned int greenBits[] = { BIT( green, 0 ), ClearBit0, BIT( green, 1 ), ClearBit0, BIT( green, 2 ),
		ClearBit0, BIT( green, 3 ), ClearBit0, BIT( green, 4 ), ClearBit0, BIT( green, 5 ), ClearBit0, BIT( green, 6 ),
		ClearBit0, BIT( green, 7 ), ClearBit0 };

	const unsigned int blueBits[] = { BIT( blue, 0 ), ClearBit0, BIT( blue, 1 ), ClearBit0, BIT( blue, 2 ), ClearBit0,
		BIT( blue, 3 ), ClearBit0, BIT( blue, 4 ), ClearBit0, BIT( blue, 5 ), ClearBit0, BIT( blue, 6 ), ClearBit0,
		BIT( blue, 7 ), ClearBit0 };


	doHeader();

	GPIOD->BSHR = redBits[0]; // Turn on GPIOs
	GPIOD->BSHR = redBits[1]; // Turn off GPIOs


	GPIOD->BSHR = redBits[2]; // Turn on GPIOs
	GPIOD->BSHR = redBits[3]; // Turn off GPIOs


	GPIOD->BSHR = redBits[4]; // Turn on GPIOs
	GPIOD->BSHR = redBits[5]; // Turn off GPIOs

	GPIOD->BSHR = redBits[6]; // Turn on GPIOs
	GPIOD->BSHR = redBits[7]; // Turn off GPIOs

	GPIOD->BSHR = redBits[8]; // Turn on GPIOs
	GPIOD->BSHR = redBits[9]; // Turn off GPIOs

	GPIOD->BSHR = redBits[10]; // Turn on GPIOs
	GPIOD->BSHR = redBits[11]; // Turn off GPIOs

	GPIOD->BSHR = redBits[12]; // Turn on GPIOs
	GPIOD->BSHR = redBits[13]; // Turn off GPIOs

	GPIOD->BSHR = redBits[14]; // Turn on GPIOs
	GPIOD->BSHR = redBits[15]; // Turn off GPIOs


	GPIOD->BSHR = greenBits[0]; // Turn on GPIOs
	GPIOD->BSHR = greenBits[1]; // Turn off GPIOs


	GPIOD->BSHR = greenBits[2]; // Turn on GPIOs
	GPIOD->BSHR = greenBits[3]; // Turn off GPIOs


	GPIOD->BSHR = greenBits[4]; // Turn on GPIOs
	GPIOD->BSHR = greenBits[5]; // Turn off GPIOs

	GPIOD->BSHR = greenBits[6]; // Turn on GPIOs
	GPIOD->BSHR = greenBits[7]; // Turn off GPIOs

	GPIOD->BSHR = greenBits[8]; // Turn on GPIOs
	GPIOD->BSHR = greenBits[9]; // Turn off GPIOs

	GPIOD->BSHR = greenBits[10]; // Turn on GPIOs
	GPIOD->BSHR = greenBits[11]; // Turn off GPIOs

	GPIOD->BSHR = greenBits[12]; // Turn on GPIOs
	GPIOD->BSHR = greenBits[13]; // Turn off GPIOs

	GPIOD->BSHR = greenBits[14]; // Turn on GPIOs
	GPIOD->BSHR = greenBits[15]; // Turn off GPIOs

	GPIOD->BSHR = blueBits[0]; // Turn on GPIOs
	GPIOD->BSHR = blueBits[1]; // Turn off GPIOs


	GPIOD->BSHR = blueBits[2]; // Turn on GPIOs
	GPIOD->BSHR = blueBits[3]; // Turn off GPIOs


	GPIOD->BSHR = blueBits[4]; // Turn on GPIOs
	GPIOD->BSHR = blueBits[5]; // Turn off GPIOs

	GPIOD->BSHR = blueBits[6]; // Turn on GPIOs
	GPIOD->BSHR = blueBits[7]; // Turn off GPIOs

	GPIOD->BSHR = blueBits[8]; // Turn on GPIOs
	GPIOD->BSHR = blueBits[9]; // Turn off GPIOs

	GPIOD->BSHR = blueBits[10]; // Turn on GPIOs
	GPIOD->BSHR = blueBits[11]; // Turn off GPIOs

	GPIOD->BSHR = blueBits[12]; // Turn on GPIOs
	GPIOD->BSHR = blueBits[13]; // Turn off GPIOs

	GPIOD->BSHR = blueBits[14]; // Turn on GPIOs
	GPIOD->BSHR = blueBits[15]; // Turn off GPIOs
}
/*contains all SPI configuations, such as pins and control registers*/
/*SPI control: master, interrupts disabled, clock polarity low when idle, clock phase falling edge, clock up tp 1 MHz*/
void SPI_Initializer()
{
	SPI_init();
	SPI_begin_8();
}

int main1()
{
	SystemInit();
SPI_Initializer();
printf("started\n");
	// // Enable GPIOs
	// RCC->APB2PCENR |= RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOC;

	// // GPIO D0 Push-Pull
	// GPIOD->CFGLR &= ~( 0xf << ( 4 * 0 ) );
	// GPIOD->CFGLR |= ( GPIO_Speed_50MHz | GPIO_CNF_OUT_PP ) << ( 4 * 0 );

	// // GPIO D4 Push-Pull
	// GPIOD->CFGLR &= ~( 0xf << ( 4 * 4 ) );
	// GPIOD->CFGLR |= ( GPIO_Speed_50MHz | GPIO_CNF_OUT_PP ) << ( 4 * 4 );

	// // GPIO D6 Push-Pull
	// GPIOD->CFGLR &= ~( 0xf << ( 4 * 6 ) );
	// GPIOD->CFGLR |= ( GPIO_Speed_50MHz | GPIO_CNF_OUT_PP ) << ( 4 * 6 );

	// // GPIO C0 Push-Pull
	// GPIOC->CFGLR &= ~( 0xf << ( 4 * 0 ) );
	while ( 1 )
	{
		printf("cats\n");
	// 	doBitsSolid( 0xff, 0xff, 0xff );
	}
}
