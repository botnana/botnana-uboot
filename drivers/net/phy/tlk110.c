/*
 * TLK110 PHY drivers
 *
 * SPDX-License-Identifier:	GPL-2.0+
 *
 * Base code from drivers/net/phy/smsc.c
 *
 * Some code copied from linux kernel
 */
#include <miiphy.h>
#include "tlk110.h"

static int am335x_tlk110_phy_fixup(struct phy_device *phydev);

int tlk110_config_aneg(struct phy_device *phydev)
{
	//unsigned short val;
	
	//am335x_tlk110_phy_fixup(phydev);
		
	genphy_config_aneg(phydev);
}

static struct phy_driver tlk110_driver = {
	.name = "TI TLK110",
	.uid = 0x2000A211,
	.mask = 0xffff0,
	.features = PHY_BASIC_FEATURES,
	.config = &tlk110_config_aneg,
	.startup = &genphy_startup,
	.shutdown = &genphy_shutdown,
};

static int am335x_tlk110_phy_fixup(struct phy_device *phydev)
{
	unsigned int val;

	/* This is done as a workaround to support TLK110 rev1.0 phy */
	val = phy_read(phydev, MDIO_DEVAD_NONE, TLK110_COARSEGAIN_REG);
	phy_write(phydev, TLK110_COARSEGAIN_REG, MDIO_DEVAD_NONE, (val | TLK110_COARSEGAIN_VAL));

	val = phy_read(phydev, MDIO_DEVAD_NONE, TLK110_LPFHPF_REG);
	phy_write(phydev, TLK110_LPFHPF_REG, MDIO_DEVAD_NONE, (val | TLK110_LPFHPF_VAL));

	val = phy_read(phydev, MDIO_DEVAD_NONE, TLK110_SPAREANALOG_REG);
	phy_write(phydev, TLK110_SPAREANALOG_REG, MDIO_DEVAD_NONE, (val | TLK110_SPANALOG_VAL));

	val = phy_read(phydev, MDIO_DEVAD_NONE, TLK110_VRCR_REG);
	phy_write(phydev, TLK110_VRCR_REG, MDIO_DEVAD_NONE, (val | TLK110_VRCR_VAL));

	val = phy_read(phydev, MDIO_DEVAD_NONE, TLK110_SETFFE_REG);
	phy_write(phydev, TLK110_SETFFE_REG, MDIO_DEVAD_NONE, (val | TLK110_SETFFE_VAL));

	val = phy_read(phydev, MDIO_DEVAD_NONE, TLK110_FTSP_REG);
	phy_write(phydev, MDIO_DEVAD_NONE, TLK110_FTSP_REG, (val | TLK110_FTSP_VAL));

	val = phy_read(phydev, MDIO_DEVAD_NONE, TLK110_ALFATPIDL_REG);
	phy_write(phydev, MDIO_DEVAD_NONE, TLK110_ALFATPIDL_REG, (val | TLK110_ALFATPIDL_VAL));

	val = phy_read(phydev, MDIO_DEVAD_NONE, TLK110_PSCOEF21_REG);
	phy_write(phydev, MDIO_DEVAD_NONE, TLK110_PSCOEF21_REG, (val | TLK110_PSCOEF21_VAL));

	val = phy_read(phydev, MDIO_DEVAD_NONE, TLK110_PSCOEF3_REG);
	phy_write(phydev, MDIO_DEVAD_NONE, TLK110_PSCOEF3_REG, (val | TLK110_PSCOEF3_VAL));

	val = phy_read(phydev, MDIO_DEVAD_NONE, TLK110_ALFAFACTOR1_REG);
	phy_write(phydev, MDIO_DEVAD_NONE, TLK110_ALFAFACTOR1_REG, (val | TLK110_ALFACTOR1_VAL));

	val = phy_read(phydev, MDIO_DEVAD_NONE, TLK110_ALFAFACTOR2_REG);
	phy_write(phydev, MDIO_DEVAD_NONE, TLK110_ALFAFACTOR2_REG, (val | TLK110_ALFACTOR2_VAL));

	val = phy_read(phydev, MDIO_DEVAD_NONE, TLK110_CFGPS_REG);
	phy_write(phydev, MDIO_DEVAD_NONE, TLK110_CFGPS_REG, (val | TLK110_CFGPS_VAL));

	val = phy_read(phydev, MDIO_DEVAD_NONE, TLK110_FTSPTXGAIN_REG);
	phy_write(phydev, MDIO_DEVAD_NONE, TLK110_FTSPTXGAIN_REG, (val | TLK110_FTSPTXGAIN_VAL));

	val = phy_read(phydev, MDIO_DEVAD_NONE, TLK110_SWSCR3_REG);
	phy_write(phydev, MDIO_DEVAD_NONE, TLK110_SWSCR3_REG, (val | TLK110_SWSCR3_VAL));

	val = phy_read(phydev, MDIO_DEVAD_NONE, TLK110_SCFALLBACK_REG);
	phy_write(phydev, MDIO_DEVAD_NONE, TLK110_SCFALLBACK_REG, (val | TLK110_SCFALLBACK_VAL));

	val = phy_read(phydev, MDIO_DEVAD_NONE, TLK110_PHYRCR_REG);
	phy_write(phydev, MDIO_DEVAD_NONE, TLK110_PHYRCR_REG, (val | TLK110_PHYRCR_VAL));

	return 0;
}

int phy_tlk110_init(void)
{
	phy_register(&tlk110_driver);

	return 0;
}
