/*
 * (C) Copyright 2013-2013
 * Johnson Diao <diaochengdong@gmail.com>
 *
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <asm/arch/s3c2440.h>
#include <asm/arch/gpio.h>
#include <asm/io.h>

#define MINI2440_LED1_ON ~(0x1 << 5)
#define MINI2440_LED2_ON ~(0x1 << 6)
#define MINI2440_LED3_ON ~(0x1 << 7)
#define MINI2440_LED4_ON ~(0x1 << 8)

#define MINI2440_LED1_OFF (0x1 << 5)
#define MINI2440_LED2_OFF (0x1 << 6)
#define MINI2440_LED3_OFF (0x1 << 7)
#define MINI2440_LED4_OFF (0x1 << 8)

void coloured_LED_init(void)
{
	struct s3c24x0_gpio *GPIO_BASE;
	int i;
	GPIO_BASE = s3c24x0_get_base_gpio();
	printf("coloured_LED_init\n");
	// set GPB5.6.7.8 TO OUTPUT AS LED
	writel(0x15400,&GPIO_BASE->gpbcon);
	

	writel((MINI2440_LED1_ON & MINI2440_LED2_ON & MINI2440_LED3_ON & MINI2440_LED4_ON),
		&GPIO_BASE->gpbdat);

	for(i=0;i<1000;i++)
		for(i=0;i<1000;i++);

	//writel((MINI2440_LED1_OFF | MINI2440_LED2_OFF | MINI2440_LED3_OFF | MINI2440_LED4_OFF),
	//	&GPIO_BASE->gpbdat);
	
	
	return ;

}


