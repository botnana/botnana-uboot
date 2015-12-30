///
/// \file  cdce913.h
///
/// \brief Interface APIs.
///
//

#ifndef _CDCE913_H_
#define _CDCE913_H_

/**************************************************************************
 * CDCE913 registers 
 **************************************************************************/
#define CDCE913_GENERIC_CFG_0	0x80
#define CDCE913_GENERIC_CFG_1	0x81
#define CDCE913_GENERIC_CFG_2	0x82
#define CDCE913_GENERIC_CFG_3	0x83
#define CDCE913_GENERIC_CFG_4	0x84
#define CDCE913_GENERIC_CFG_5	0x85
#define CDCE913_GENERIC_CFG_6	0x86

#define CDCE913_PLL_CFG_0	0x90
#define CDCE913_PLL_CFG_1	0x91
#define CDCE913_PLL_CFG_2	0x92
#define CDCE913_PLL_CFG_3	0x93
#define CDCE913_PLL_CFG_4	0x94
#define CDCE913_PLL_CFG_5	0x95
#define CDCE913_PLL_CFG_6	0x96
#define CDCE913_PLL_CFG_7	0x97
#define CDCE913_PLL_CFG_8	0x98
#define CDCE913_PLL_CFG_9	0x99
#define CDCE913_PLL_CFG_10	0x9a
#define CDCE913_PLL_CFG_11	0x9b
#define CDCE913_PLL_CFG_12	0x9c
#define CDCE913_PLL_CFG_13	0x9d
#define CDCE913_PLL_CFG_14	0x9e
#define CDCE913_PLL_CFG_15	0x9f

/* bitfields */
#define PLL_CFG4_MUX1_SHIFT	7
#define PLL_CFG4_MUX1_SHIFT_MASK			(0x1 << PLL_CFG4_MUX1_SHIFT)

#define GENERIC_CFG5_XCSEL_SHIFT	3
#define GENERIC_CFG5_XCSEL_SHIFT_MASK		(0x1F << GENERIC_CFG5_XCSEL_SHIFT)

#define PLL_CFG6_PDIV2_SHIFT	0
#define PLL_CFG6_PDIV2_SHIFT_MASK		(0x7F << PLL_CFG6_PDIV2_SHIFT)

#define PLL_CFG7_PDIV3_SHIFT	0
#define PLL_CFG7_PDIV2_SHIFT_MASK		(0x7F << PLL_CFG7_PDIV2_SHIFT)

#define PLL_CFG12_1N_VAL(x)			(x >> 4)

#define PLL_CFG13_1N_VAL(x)			((x & 0xF) << 4)
#define PLL_CFG13_1R_VAL(x)			(x >> 5)

#define PLL_CFG14_1R_VAL(x)			((x & 0x1F) << 3)
#define PLL_CFG14_1Q_VAL(x)			(x >> 3)

#define PLL_CFG15_1Q_VAL(x)			((x & 0x7) << 5)
#define PLL_CFG15_1P_VAL(x)			(x << 2)
#define PLL_CFG15_1VCO_VAL(x)		(x << 0)

#define CONFIG_SYS_I2C_CDCE913_ADDR	0x65	/* CDCE913 PHY */	/* added by chris(mapacode) */

/**************************************************************************
**                       Macro Definitions
**************************************************************************/
/*
** Macros for configuring the interface Type
*/


//-----------------------------------------------------------------------------
// Public Function Prototypes
//-----------------------------------------------------------------------------
extern int CDCE913Init(void);

#endif