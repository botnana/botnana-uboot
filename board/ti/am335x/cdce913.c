/// \file  cdce913.c
///
/// \brief APIs to configure CDCE913 clock generator.
///
///

#include <linux/types.h>
#include <common.h>
#include <i2c.h>
#include <errno.h>
#include "cdce913.h"

/******************************************************************************
**                      INTERNAL MACRO DEFINITIONS
*******************************************************************************/
/*
** Register Address for CDCE913
*/

/******************************************************************************
**                          FUNCTION DEFINITIONS
*******************************************************************************/
//-----------------------------------------------------------------------------
// \brief   Initialize the clock synthesizer for use.
//          Y1 (am335x) = 25MHz
//          Y2 (TLK110 phy 1) = 50MHz
//          Y3 (TLK110 phy 0) =  50MHz
//
// \param   baseAddr     Base Address of the interface connected to the IO expander
//
// \return  None.
//-----------------------------------------------------------------------------
int CDCE913Init(void)
{
	uint8_t buf;
	uint8_t pll_1N, pll_1R, pll_1Q, pll_1P, range_1fvco;
	
	/* Check if cdce913 is available */
	if (i2c_probe(CONFIG_SYS_I2C_CDCE913_ADDR)) {
		puts("Could not probe the CDCE913; something fundamentally "
			"wrong on the I2C bus.\n");
		return -ENODEV;
	}
	
	i2c_read(CONFIG_SYS_I2C_CDCE913_ADDR, CDCE913_GENERIC_CFG_0, 1, &buf, 1);
	if((buf & 0x80) == 0x80 &&		// Device identification number
		(buf & 0x0f) == 0x1) {		// Vendor identification number
		// set XCSEL bit (18pF)	
		buf = (0x12 << GENERIC_CFG5_XCSEL_SHIFT);
		i2c_write(CONFIG_SYS_I2C_CDCE913_ADDR, CDCE913_GENERIC_CFG_5, 1, &buf, 1);
		i2c_read(CONFIG_SYS_I2C_CDCE913_ADDR, CDCE913_GENERIC_CFG_5, 1, &buf, 1);
		
		/* use state 1, fvco = 100MHz, set Y2/Y3 = 50MHz for RMII, Y1 = don't care */
		// set Pdiv2 as 2 (fvco / 2 = 50MHz)
		i2c_read(CONFIG_SYS_I2C_CDCE913_ADDR, CDCE913_PLL_CFG_6, 1, &buf, 1);
		buf &= ~PLL_CFG6_PDIV2_SHIFT_MASK;
		buf |= (0x2 << PLL_CFG6_PDIV2_SHIFT);
		i2c_write(CONFIG_SYS_I2C_CDCE913_ADDR, CDCE913_PLL_CFG_6, 1, &buf, 1);
		i2c_read(CONFIG_SYS_I2C_CDCE913_ADDR, CDCE913_PLL_CFG_6, 1, &buf, 1);

		// set Pdiv3 as 2 (fvco / 2 = 50MHz)
		buf = (0x2 << PLL_CFG7_PDIV3_SHIFT);
		i2c_write(CONFIG_SYS_I2C_CDCE913_ADDR, CDCE913_PLL_CFG_7, 1, &buf, 1);
		i2c_read(CONFIG_SYS_I2C_CDCE913_ADDR, CDCE913_PLL_CFG_7, 1, &buf, 1);
		
		// set fvco as 100MHz (N=4, R=0, Q=16, P=2)
		pll_1N = 4, pll_1R = 0, pll_1Q = 16, pll_1P = 2, range_1fvco = 0;
		
		buf = PLL_CFG12_1N_VAL(pll_1N);
		i2c_write(CONFIG_SYS_I2C_CDCE913_ADDR, CDCE913_PLL_CFG_12, 1, &buf, 1);
		i2c_read(CONFIG_SYS_I2C_CDCE913_ADDR, CDCE913_PLL_CFG_12, 1, &buf, 1);

		buf = PLL_CFG13_1N_VAL(pll_1N) | PLL_CFG13_1R_VAL(pll_1R);
		i2c_write(CONFIG_SYS_I2C_CDCE913_ADDR, CDCE913_PLL_CFG_13, 1, &buf, 1);
		i2c_read(CONFIG_SYS_I2C_CDCE913_ADDR, CDCE913_PLL_CFG_13, 1, &buf, 1);

		buf = PLL_CFG14_1R_VAL(pll_1R) | PLL_CFG14_1Q_VAL(pll_1Q);
		i2c_write(CONFIG_SYS_I2C_CDCE913_ADDR, CDCE913_PLL_CFG_14, 1, &buf, 1);
		i2c_read(CONFIG_SYS_I2C_CDCE913_ADDR, CDCE913_PLL_CFG_14, 1, &buf, 1);
		
		buf = PLL_CFG15_1Q_VAL(pll_1Q) | PLL_CFG15_1P_VAL(pll_1P) | PLL_CFG15_1VCO_VAL(range_1fvco);
		i2c_write(CONFIG_SYS_I2C_CDCE913_ADDR, CDCE913_PLL_CFG_15, 1, &buf, 1);
		i2c_read(CONFIG_SYS_I2C_CDCE913_ADDR, CDCE913_PLL_CFG_15, 1, &buf, 1);
		
		// PLL1 Multiplexer: PLL1
		i2c_read(CONFIG_SYS_I2C_CDCE913_ADDR, CDCE913_PLL_CFG_4, 1, &buf, 1);
		buf &= ~PLL_CFG4_MUX1_SHIFT_MASK;
		i2c_write(CONFIG_SYS_I2C_CDCE913_ADDR, CDCE913_PLL_CFG_4, 1, &buf, 1);
		i2c_read(CONFIG_SYS_I2C_CDCE913_ADDR, CDCE913_PLL_CFG_4, 1, &buf, 1);
		
	}
	else printf ("Could not find the CDCE913\n"); 
		
	return 0;

}