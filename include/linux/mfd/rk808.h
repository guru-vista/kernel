/*
 * rk808.h for Rockchip RK808
 *
 * Copyright (c) 2014, Fuzhou Rockchip Electronics Co., Ltd
 *
 * Author: Chris Zhong <zyw@rock-chips.com>
 * Author: Zhang Qing <zhangqing@rock-chips.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 */

#ifndef __LINUX_REGULATOR_rk808_H
#define __LINUX_REGULATOR_rk808_H

#include <linux/regulator/machine.h>
#include <linux/regmap.h>

/*
 * rk808 Global Register Map.
 */

#define RK808_DCDC1	0 /* (0+RK808_START) */
#define RK808_LDO1	4 /* (4+RK808_START) */
#define RK808_NUM_REGULATORS   14

enum rk808_reg {
	RK808_ID_DCDC1,
	RK808_ID_DCDC2,
	RK808_ID_DCDC3,
	RK808_ID_DCDC4,
	RK808_ID_LDO1,
	RK808_ID_LDO2,
	RK808_ID_LDO3,
	RK808_ID_LDO4,
	RK808_ID_LDO5,
	RK808_ID_LDO6,
	RK808_ID_LDO7,
	RK808_ID_LDO8,
	RK808_ID_SWITCH1,
	RK808_ID_SWITCH2,
};

enum rk816_reg {
	RK816_ID_DCDC1,
	RK816_ID_DCDC2,
	RK816_ID_DCDC3,
	RK816_ID_DCDC4,
	RK816_ID_LDO1,
	RK816_ID_LDO2,
	RK816_ID_LDO3,
	RK816_ID_LDO4,
	RK816_ID_LDO5,
	RK816_ID_LDO6,
};

enum rk818_reg {
	RK818_ID_DCDC1,
	RK818_ID_DCDC2,
	RK818_ID_DCDC3,
	RK818_ID_DCDC4,
	RK818_ID_BOOST,
	RK818_ID_LDO1,
	RK818_ID_LDO2,
	RK818_ID_LDO3,
	RK818_ID_LDO4,
	RK818_ID_LDO5,
	RK818_ID_LDO6,
	RK818_ID_LDO7,
	RK818_ID_LDO8,
	RK818_ID_LDO9,
	RK818_ID_SWITCH,
	RK818_ID_HDMI_SWITCH,
	RK818_ID_OTG_SWITCH,
};

enum rk805_reg {
	RK805_ID_DCDC1,
	RK805_ID_DCDC2,
	RK805_ID_DCDC3,
	RK805_ID_DCDC4,
	RK805_ID_LDO1,
	RK805_ID_LDO2,
	RK805_ID_LDO3,
};

#define RK808_SECONDS_REG	0x00
#define RK808_MINUTES_REG	0x01
#define RK808_HOURS_REG		0x02
#define RK808_DAYS_REG		0x03
#define RK808_MONTHS_REG	0x04
#define RK808_YEARS_REG		0x05
#define RK808_WEEKS_REG		0x06
#define RK808_ALARM_SECONDS_REG	0x08
#define RK808_ALARM_MINUTES_REG	0x09
#define RK808_ALARM_HOURS_REG	0x0a
#define RK808_ALARM_DAYS_REG	0x0b
#define RK808_ALARM_MONTHS_REG	0x0c
#define RK808_ALARM_YEARS_REG	0x0d
#define RK808_RTC_CTRL_REG	0x10
#define RK808_RTC_STATUS_REG	0x11
#define RK808_RTC_INT_REG	0x12
#define RK808_RTC_COMP_LSB_REG	0x13
#define RK808_RTC_COMP_MSB_REG	0x14
#define RK808_ID_MSB		0x17
#define RK808_ID_LSB		0x18
#define RK808_CLK32OUT_REG	0x20
#define RK808_VB_MON_REG	0x21
#define RK808_THERMAL_REG	0x22
#define RK808_DCDC_EN_REG	0x23
#define RK808_LDO_EN_REG	0x24
#define RK808_SLEEP_SET_OFF_REG1	0x25
#define RK808_SLEEP_SET_OFF_REG2	0x26
#define RK808_DCDC_UV_STS_REG	0x27
#define RK808_DCDC_UV_ACT_REG	0x28
#define RK808_LDO_UV_STS_REG	0x29
#define RK808_LDO_UV_ACT_REG	0x2a
#define RK808_DCDC_PG_REG	0x2b
#define RK808_LDO_PG_REG	0x2c
#define RK808_VOUT_MON_TDB_REG	0x2d
#define RK808_BUCK1_CONFIG_REG		0x2e
#define RK808_BUCK1_ON_VSEL_REG		0x2f
#define RK808_BUCK1_SLP_VSEL_REG	0x30
#define RK808_BUCK1_DVS_VSEL_REG	0x31
#define RK808_BUCK2_CONFIG_REG		0x32
#define RK808_BUCK2_ON_VSEL_REG		0x33
#define RK808_BUCK2_SLP_VSEL_REG	0x34
#define RK808_BUCK2_DVS_VSEL_REG	0x35
#define RK808_BUCK3_CONFIG_REG		0x36
#define RK808_BUCK4_CONFIG_REG		0x37
#define RK808_BUCK4_ON_VSEL_REG		0x38
#define RK808_BUCK4_SLP_VSEL_REG	0x39
#define RK808_BOOST_CONFIG_REG		0x3a
#define RK808_LDO1_ON_VSEL_REG		0x3b
#define RK808_LDO1_SLP_VSEL_REG		0x3c
#define RK808_LDO2_ON_VSEL_REG		0x3d
#define RK808_LDO2_SLP_VSEL_REG		0x3e
#define RK808_LDO3_ON_VSEL_REG		0x3f
#define RK808_LDO3_SLP_VSEL_REG		0x40
#define RK808_LDO4_ON_VSEL_REG		0x41
#define RK808_LDO4_SLP_VSEL_REG		0x42
#define RK808_LDO5_ON_VSEL_REG		0x43
#define RK808_LDO5_SLP_VSEL_REG		0x44
#define RK808_LDO6_ON_VSEL_REG		0x45
#define RK808_LDO6_SLP_VSEL_REG		0x46
#define RK808_LDO7_ON_VSEL_REG		0x47
#define RK808_LDO7_SLP_VSEL_REG		0x48
#define RK808_LDO8_ON_VSEL_REG		0x49
#define RK808_LDO8_SLP_VSEL_REG		0x4a
#define RK808_DEVCTRL_REG	0x4b
#define RK808_INT_STS_REG1	0x4c
#define RK808_INT_STS_MSK_REG1	0x4d
#define RK808_INT_STS_REG2	0x4e
#define RK808_INT_STS_MSK_REG2	0x4f
#define RK808_IO_POL_REG	0x50

#define RK818_VB_MON_REG		0x21
#define RK818_THERMAL_REG		0x22
#define RK818_DCDC_EN_REG		0x23
#define RK818_LDO_EN_REG		0x24
#define RK818_SLEEP_SET_OFF_REG1	0x25
#define RK818_SLEEP_SET_OFF_REG2	0x26
#define RK818_DCDC_UV_STS_REG		0x27
#define RK818_DCDC_UV_ACT_REG		0x28
#define RK818_LDO_UV_STS_REG		0x29
#define RK818_LDO_UV_ACT_REG		0x2a
#define RK818_DCDC_PG_REG		0x2b
#define RK818_LDO_PG_REG		0x2c
#define RK818_VOUT_MON_TDB_REG		0x2d
#define RK818_BUCK1_CONFIG_REG		0x2e
#define RK818_BUCK1_ON_VSEL_REG		0x2f
#define RK818_BUCK1_SLP_VSEL_REG	0x30
#define RK818_BUCK2_CONFIG_REG		0x32
#define RK818_BUCK2_ON_VSEL_REG		0x33
#define RK818_BUCK2_SLP_VSEL_REG	0x34
#define RK818_BUCK3_CONFIG_REG		0x36
#define RK818_BUCK4_CONFIG_REG		0x37
#define RK818_BUCK4_ON_VSEL_REG		0x38
#define RK818_BUCK4_SLP_VSEL_REG	0x39
#define RK818_BOOST_CONFIG_REG		0x3a
#define RK818_LDO1_ON_VSEL_REG		0x3b
#define RK818_LDO1_SLP_VSEL_REG		0x3c
#define RK818_LDO2_ON_VSEL_REG		0x3d
#define RK818_LDO2_SLP_VSEL_REG		0x3e
#define RK818_LDO3_ON_VSEL_REG		0x3f
#define RK818_LDO3_SLP_VSEL_REG		0x40
#define RK818_LDO4_ON_VSEL_REG		0x41
#define RK818_LDO4_SLP_VSEL_REG		0x42
#define RK818_LDO5_ON_VSEL_REG		0x43
#define RK818_LDO5_SLP_VSEL_REG		0x44
#define RK818_LDO6_ON_VSEL_REG		0x45
#define RK818_LDO6_SLP_VSEL_REG		0x46
#define RK818_LDO7_ON_VSEL_REG		0x47
#define RK818_LDO7_SLP_VSEL_REG		0x48
#define RK818_LDO8_ON_VSEL_REG		0x49
#define RK818_LDO8_SLP_VSEL_REG		0x4a
#define RK818_DEVCTRL_REG		0x4b
#define RK818_INT_STS_REG1		0X4c
#define RK818_INT_STS_MSK_REG1		0X4d
#define RK818_INT_STS_REG2		0X4e
#define RK818_INT_STS_MSK_REG2		0X4f
#define RK818_IO_POL_REG		0X50
#define RK818_OTP_VDD_EN_REG		0x51
#define RK818_H5V_EN_REG		0x52
#define RK818_SLEEP_SET_OFF_REG3	0x53
#define RK818_BOOST_LDO9_ON_VSEL_REG	0x54
#define RK818_BOOST_LDO9_SLP_VSEL_REG	0x55
#define RK818_BOOST_CTRL_REG		0x56
#define RK818_DCDC_ILMAX_REG		0x90
#define RK818_CHRG_COMP_REG		0x9a
#define RK818_SUP_STS_REG		0xa0
#define RK818_USB_CTRL_REG		0xa1
#define RK818_CHRG_CTRL_REG1		0xa3
#define RK818_CHRG_CTRL_REG2		0xa4
#define RK818_CHRG_CTRL_REG3		0xa5
#define RK818_BAT_CTRL_REG		0xa6
#define RK818_BAT_HTS_TS1_REG		0xa8
#define RK818_BAT_LTS_TS1_REG		0xa9
#define RK818_BAT_HTS_TS2_REG		0xaa
#define RK818_BAT_LTS_TS2_REG		0xab
#define RK818_TS_CTRL_REG		0xac
#define RK818_ADC_CTRL_REG		0xad
#define RK818_ON_SOURCE_REG		0xae
#define RK818_OFF_SOURCE_REG		0xaf
#define RK818_GGCON_REG			0xb0
#define RK818_GGSTS_REG			0xb1
#define RK818_FRAME_SMP_INTERV_REG	0xb2
#define RK818_AUTO_SLP_CUR_THR_REG	0xb3
#define RK818_GASCNT_CAL_REG3		0xb4
#define RK818_GASCNT_CAL_REG2		0xb5
#define RK818_GASCNT_CAL_REG1		0xb6
#define RK818_GASCNT_CAL_REG0		0xb7
#define RK818_GASCNT3_REG		0xb8
#define RK818_GASCNT2_REG		0xb9
#define RK818_GASCNT1_REG		0xba
#define RK818_GASCNT0_REG		0xbb
#define RK818_BAT_CUR_AVG_REGH		0xbc
#define RK818_BAT_CUR_AVG_REGL		0xbd
#define RK818_TS1_ADC_REGH		0xbe
#define RK818_TS1_ADC_REGL		0xbf
#define RK818_TS2_ADC_REGH		0xc0
#define RK818_TS2_ADC_REGL		0xc1
#define RK818_BAT_OCV_REGH		0xc2
#define RK818_BAT_OCV_REGL		0xc3
#define RK818_BAT_VOL_REGH		0xc4
#define RK818_BAT_VOL_REGL		0xc5
#define RK818_RELAX_ENTRY_THRES_REGH	0xc6
#define RK818_RELAX_ENTRY_THRES_REGL	0xc7
#define RK818_RELAX_EXIT_THRES_REGH	0xc8
#define RK818_RELAX_EXIT_THRES_REGL	0xc9
#define RK818_RELAX_VOL1_REGH		0xca
#define RK818_RELAX_VOL1_REGL		0xcb
#define RK818_RELAX_VOL2_REGH		0xcc
#define RK818_RELAX_VOL2_REGL		0xcd
#define RK818_BAT_CUR_R_CALC_REGH	0xce
#define RK818_BAT_CUR_R_CALC_REGL	0xcf
#define RK818_BAT_VOL_R_CALC_REGH	0xd0
#define RK818_BAT_VOL_R_CALC_REGL	0xd1
#define RK818_CAL_OFFSET_REGH		0xd2
#define RK818_CAL_OFFSET_REGL		0xd3
#define RK818_NON_ACT_TIMER_CNT_REG	0xd4
#define RK818_VCALIB0_REGH		0xd5
#define RK818_VCALIB0_REGL		0xd6
#define RK818_VCALIB1_REGH		0xd7
#define RK818_VCALIB1_REGL		0xd8
#define RK818_IOFFSET_REGH		0xdd
#define RK818_IOFFSET_REGL		0xde
#define RK818_SOC_REG			0xe0
#define RK818_REMAIN_CAP_REG3		0xe1
#define RK818_REMAIN_CAP_REG2		0xe2
#define RK818_REMAIN_CAP_REG1		0xe3
#define RK818_REMAIN_CAP_REG0		0xe4
#define RK818_UPDAT_LEVE_REG		0xe5
#define RK818_NEW_FCC_REG3		0xe6
#define RK818_NEW_FCC_REG2		0xe7
#define RK818_NEW_FCC_REG1		0xe8
#define RK818_NEW_FCC_REG0		0xe9
#define RK818_NON_ACT_TIMER_CNT_SAVE_REG 0xea
#define RK818_OCV_VOL_VALID_REG		0xeb
#define RK818_REBOOT_CNT_REG		0xec
#define RK818_POFFSET_REG		0xed
#define RK818_MISC_MARK_REG		0xee
#define RK818_HALT_CNT_REG		0xef
#define RK818_CALC_REST_REGH		0xf0
#define RK818_CALC_REST_REGL		0xf1
#define RK818_SAVE_DATA19		0xf2
#define RK818_NUM_REGULATORS		17

/* IRQ Definitions */
#define RK808_IRQ_VOUT_LO	0
#define RK808_IRQ_VB_LO		1
#define RK808_IRQ_PWRON		2
#define RK808_IRQ_PWRON_LP	3
#define RK808_IRQ_HOTDIE	4
#define RK808_IRQ_RTC_ALARM	5
#define RK808_IRQ_RTC_PERIOD	6
#define RK808_IRQ_PLUG_IN_INT	7
#define RK808_IRQ_PLUG_OUT_INT	8
#define RK808_NUM_IRQ		9

#define RK808_IRQ_VOUT_LO_MSK		BIT(0)
#define RK808_IRQ_VB_LO_MSK		BIT(1)
#define RK808_IRQ_PWRON_MSK		BIT(2)
#define RK808_IRQ_PWRON_LP_MSK		BIT(3)
#define RK808_IRQ_HOTDIE_MSK		BIT(4)
#define RK808_IRQ_RTC_ALARM_MSK		BIT(5)
#define RK808_IRQ_RTC_PERIOD_MSK	BIT(6)
#define RK808_IRQ_PLUG_IN_INT_MSK	BIT(0)
#define RK808_IRQ_PLUG_OUT_INT_MSK	BIT(1)

#define RK808_VBAT_LOW_2V8	0x00
#define RK808_VBAT_LOW_2V9	0x01
#define RK808_VBAT_LOW_3V0	0x02
#define RK808_VBAT_LOW_3V1	0x03
#define RK808_VBAT_LOW_3V2	0x04
#define RK808_VBAT_LOW_3V3	0x05
#define RK808_VBAT_LOW_3V4	0x06
#define RK808_VBAT_LOW_3V5	0x07
#define VBAT_LOW_VOL_MASK	(0x07 << 0)
#define EN_VABT_LOW_SHUT_DOWN	(0x00 << 4)
#define EN_VBAT_LOW_IRQ		(0x1 << 4)
#define VBAT_LOW_ACT_MASK	(0x1 << 4)

#define BUCK_ILMIN_MASK		(7 << 0)
#define BOOST_ILMIN_MASK	(7 << 0)
#define BUCK1_RATE_MASK		(3 << 3)
#define BUCK2_RATE_MASK		(3 << 3)
#define MASK_ALL	0xff

#define BUCK_UV_ACT_MASK	0x0f
#define BUCK_UV_ACT_DISABLE	0

#define SWITCH2_EN	BIT(6)
#define SWITCH1_EN	BIT(5)
#define DEV_OFF_RST	BIT(3)
#define DEV_OFF		BIT(0)
#define RTC_STOP	BIT(0)

#define VB_LO_ACT		BIT(4)
#define VB_LO_SEL_3500MV	(7 << 0)

#define VOUT_LO_INT	BIT(0)
#define CLK32KOUT2_EN	BIT(0)
#define CLK32KOUT2_FUNC		(0 << 1)
#define CLK32KOUT2_FUNC_MASK	BIT(1)
#define H5V_EN_MASK		BIT(0)
#define H5V_EN_ENABLE		BIT(0)
#define REF_RDY_CTRL_MASK	BIT(1)
#define REF_RDY_CTRL_ENABLE	BIT(1)

/*RK818_DCDC_EN_REG*/
#define BUCK1_EN_MASK		BIT(0)
#define BUCK2_EN_MASK		BIT(1)
#define BUCK3_EN_MASK		BIT(2)
#define BUCK4_EN_MASK		BIT(3)
#define BOOST_EN_MASK		BIT(4)
#define LDO9_EN_MASK		BIT(5)
#define SWITCH_EN_MASK		BIT(6)
#define OTG_EN_MASK		BIT(7)

#define BUCK1_EN_ENABLE		BIT(0)
#define BUCK2_EN_ENABLE		BIT(1)
#define BUCK3_EN_ENABLE		BIT(2)
#define BUCK4_EN_ENABLE		BIT(3)
#define BOOST_EN_ENABLE		BIT(4)
#define LDO9_EN_ENABLE		BIT(5)
#define SWITCH_EN_ENABLE	BIT(6)
#define OTG_EN_ENABLE		BIT(7)

/* IRQ Definitions */
#define RK818_IRQ_VOUT_LO	0
#define RK818_IRQ_VB_LO		1
#define RK818_IRQ_PWRON		2
#define RK818_IRQ_PWRON_LP	3
#define RK818_IRQ_HOTDIE	4
#define RK818_IRQ_RTC_ALARM	5
#define RK818_IRQ_RTC_PERIOD	6
#define RK818_IRQ_USB_OV	7
#define RK818_IRQ_PLUG_IN	8
#define RK818_IRQ_PLUG_OUT	9
#define RK818_IRQ_CHG_OK	10
#define RK818_IRQ_CHG_TE	11
#define RK818_IRQ_CHG_TS1	12
#define RK818_IRQ_TS2		13
#define RK818_IRQ_CHG_CVTLIM	14
#define RK818_IRQ_DISCHG_ILIM	15

#define BUCK1_SLP_SET_MASK	BIT(0)
#define BUCK2_SLP_SET_MASK	BIT(1)
#define BUCK3_SLP_SET_MASK	BIT(2)
#define BUCK4_SLP_SET_MASK	BIT(3)
#define BOOST_SLP_SET_MASK	BIT(4)
#define LDO9_SLP_SET_MASK	BIT(5)
#define SWITCH_SLP_SET_MASK	BIT(6)
#define OTG_SLP_SET_MASK	BIT(7)

#define BUCK1_SLP_SET_OFF	BIT(0)
#define BUCK2_SLP_SET_OFF	BIT(1)
#define BUCK3_SLP_SET_OFF	BIT(2)
#define BUCK4_SLP_SET_OFF	BIT(3)
#define BOOST_SLP_SET_OFF	BIT(4)
#define LDO9_SLP_SET_OFF	BIT(5)
#define SWITCH_SLP_SET_OFF	BIT(6)
#define OTG_SLP_SET_OFF		BIT(7)
#define OTG_BOOST_SLP_OFF	(BOOST_SLP_SET_OFF | OTG_SLP_SET_OFF)

#define BUCK1_SLP_SET_ON	BIT(0)
#define BUCK2_SLP_SET_ON	BIT(1)
#define BUCK3_SLP_SET_ON	BIT(2)
#define BUCK4_SLP_SET_ON	BIT(3)
#define BOOST_SLP_SET_ON	BIT(4)
#define LDO9_SLP_SET_ON		BIT(5)
#define SWITCH_SLP_SET_ON	BIT(6)
#define OTG_SLP_SET_ON		BIT(7)

#define VOUT_LO_MASK		BIT(0)
#define VB_LO_MASK		BIT(1)
#define PWRON_MASK		BIT(2)
#define PWRON_LP_MASK		BIT(3)
#define HOTDIE_MASK		BIT(4)
#define RTC_ALARM_MASK		BIT(5)
#define RTC_PERIOD_MASK		BIT(6)
#define USB_OV_MASK		BIT(7)

#define VOUT_LO_DISABLE		BIT(0)
#define VB_LO_DISABLE		BIT(1)
#define PWRON_DISABLE		BIT(2)
#define PWRON_LP_DISABLE	BIT(3)
#define HOTDIE_DISABLE		BIT(4)
#define RTC_ALARM_DISABLE	BIT(5)
#define RTC_PERIOD_DISABLE	BIT(6)
#define USB_OV_INT_DISABLE	BIT(7)

#define VOUT_LO_ENABLE		(0 << 0)
#define VB_LO_ENABLE		(0 << 1)
#define PWRON_ENABLE		(0 << 2)
#define PWRON_LP_ENABLE		(0 << 3)
#define HOTDIE_ENABLE		(0 << 4)
#define RTC_ALARM_ENABLE	(0 << 5)
#define RTC_PERIOD_ENABLE	(0 << 6)
#define USB_OV_INT_ENABLE	(0 << 7)

#define PLUG_IN_MASK		BIT(0)
#define PLUG_OUT_MASK		BIT(1)
#define CHGOK_MASK		BIT(2)
#define CHGTE_MASK		BIT(3)
#define CHGTS1_MASK		BIT(4)
#define TS2_MASK		BIT(5)
#define CHG_CVTLIM_MASK		BIT(6)
#define DISCHG_ILIM_MASK	BIT(7)

#define PLUG_IN_DISABLE		BIT(0)
#define PLUG_OUT_DISABLE	BIT(1)
#define CHGOK_DISABLE		BIT(2)
#define CHGTE_DISABLE		BIT(3)
#define CHGTS1_DISABLE		BIT(4)
#define TS2_DISABLE		BIT(5)
#define CHG_CVTLIM_DISABLE	BIT(6)
#define DISCHG_ILIM_DISABLE	BIT(7)

#define PLUG_IN_ENABLE		BIT(0)
#define PLUG_OUT_ENABLE		BIT(1)
#define CHGOK_ENABLE		BIT(2)
#define CHGTE_ENABLE		BIT(3)
#define CHGTS1_ENABLE		BIT(4)
#define TS2_ENABLE		BIT(5)
#define CHG_CVTLIM_ENABLE	BIT(6)
#define DISCHG_ILIM_ENABLE	BIT(7)

/* IRQ Definitions */
#define RK805_IRQ_VB_LOW		1
#define RK805_IRQ_PWRON			2
#define RK805_IRQ_PWRON_LP		3
#define RK805_IRQ_HOTDIE		4
#define RK805_IRQ_RTC_ALARM		5
#define RK805_IRQ_RTC_PERIOD		6

/*
 * When PMIC irq occurs, regmap-irq.c will traverse all PMIC child
 * interrupts from low index 0 to high index, we give fall interrupt
 * high priority to be called earlier than rise, so that it can be
 * override by late rise event. This can helps to solve key release
 * glitch which make a wrongly fall event immediately after rise.
 */
#define RK805_IRQ_PWRON_FALL		0
#define RK805_IRQ_PWRON_RISE		7

#define RK805_IRQ_PWRON_RISE_MSK	BIT(0)
#define RK805_IRQ_VB_LOW_MSK		BIT(1)
#define RK805_IRQ_PWRON_MSK		BIT(2)
#define RK805_IRQ_PWRON_LP_MSK		BIT(3)
#define RK805_IRQ_HOTDIE_MSK		BIT(4)
#define RK805_IRQ_RTC_ALARM_MSK		BIT(5)
#define RK805_IRQ_RTC_PERIOD_MSK	BIT(6)
#define RK805_IRQ_PWRON_FALL_MSK	BIT(7)

#define RK805_PWR_RISE_INT_STATUS	BIT(0)
#define RK805_VB_LOW_INT_STATUS		BIT(1)
#define RK805_PWRON_INT_STATUS		BIT(2)
#define RK805_PWRON_LP_INT_STATUS	BIT(3)
#define RK805_HOTDIE_INT_STATUS		BIT(4)
#define RK805_ALARM_INT_STATUS		BIT(5)
#define RK805_PERIOD_INT_STATUS		BIT(6)
#define RK805_PWR_FALL_INT_STATUS	BIT(7)

/*INTERRUPT REGISTER*/
#define RK805_INT_STS_REG		0x4C
#define RK805_INT_STS_MSK_REG		0x4D
#define RK805_GPIO_IO_POL_REG		0x50
#define RK805_OUT_REG			0x52
#define RK805_ON_SOURCE_REG		0xAE
#define RK805_OFF_SOURCE_REG		0xAF

/*POWER CHANNELS ENABLE REGISTER*/
#define RK805_DCDC_EN_REG		0x23
#define RK805_SLP_DCDC_EN_REG		0x25
#define RK805_SLP_LDO_EN_REG		0x26
#define RK805_LDO_EN_REG		0x27

/*CONFIG REGISTER*/
#define RK805_THERMAL_REG		0x22

/*BUCK AND LDO CONFIG REGISTER*/
#define RK805_BUCK_LDO_SLP_LP_EN_REG	0x2A
#define RK805_BUCK1_CONFIG_REG		0x2E
#define RK805_BUCK1_ON_VSEL_REG		0x2F
#define RK805_BUCK1_SLP_VSEL_REG	0x30
#define RK805_BUCK2_CONFIG_REG		0x32
#define RK805_BUCK2_ON_VSEL_REG		0x33
#define RK805_BUCK2_SLP_VSEL_REG	0x34
#define RK805_BUCK3_CONFIG_REG		0x36
#define RK805_BUCK4_CONFIG_REG		0x37
#define RK805_BUCK4_ON_VSEL_REG		0x38
#define RK805_BUCK4_SLP_VSEL_REG	0x39
#define RK805_LDO1_ON_VSEL_REG		0x3B
#define RK805_LDO1_SLP_VSEL_REG		0x3C
#define RK805_LDO2_ON_VSEL_REG		0x3D
#define RK805_LDO2_SLP_VSEL_REG		0x3E
#define RK805_LDO3_ON_VSEL_REG		0x3F
#define RK805_LDO3_SLP_VSEL_REG		0x40
#define RK805_OUT_REG			0x52
#define RK805_ON_SOURCE_REG		0xAE
#define RK805_OFF_SOURCE_REG		0xAF
#define RK805_DCDC_VRP_REG		0x92

#define RK805_NUM_REGULATORS		7

#define RK805_PWRON_FALL_RISE_INT_EN	0x0
#define RK805_PWRON_FALL_RISE_INT_MSK	0x81

/*VERSION REGISTER*/
#define RK816_CHIP_NAME_REG			0x17
#define RK816_CHIP_VER_REG			0x18
#define RK816_OTP_VER_REG			0x19
#define RK816_NUM_REGULATORS			10

/*POWER ON/OFF REGISTER*/
#define RK816_VB_MON_REG			0x21
#define RK816_THERMAL_REG			0x22
#define RK816_PWRON_LP_INT_TIME_REG		0x47
#define RK816_PWRON_DB_REG			0x48
#define RK816_DEV_CTRL_REG			0x4B
#define RK816_ON_SOURCE_REG			0xAE
#define RK816_OFF_SOURCE_REG			0xAF

/*POWER CHANNELS ENABLE REGISTER*/
#define RK816_DCDC_EN_REG1			0x23
#define RK816_DCDC_EN_REG2			0x24
#define RK816_SLP_DCDC_EN_REG			0x25
#define RK816_SLP_LDO_EN_REG			0x26
#define RK816_LDO_EN_REG1			0x27
#define RK816_LDO_EN_REG2			0x28

/*BUCK AND LDO CONFIG REGISTER*/
#define RK816_BUCK1_CONFIG_REG			0x2E
#define RK816_BUCK1_ON_VSEL_REG			0x2F
#define RK816_BUCK1_SLP_VSEL_REG		0x30
#define RK816_BUCK2_CONFIG_REG			0x32
#define RK816_BUCK2_ON_VSEL_REG			0x33
#define RK816_BUCK2_SLP_VSEL_REG		0x34
#define RK816_BUCK3_CONFIG_REG			0x36
#define RK816_BUCK4_CONFIG_REG			0x37
#define RK816_BUCK4_ON_VSEL_REG			0x38
#define RK816_BUCK4_SLP_VSEL_REG		0x39
#define RK816_LDO1_ON_VSEL_REG			0x3B
#define RK816_LDO1_SLP_VSEL_REG			0x3C
#define RK816_LDO2_ON_VSEL_REG			0x3D
#define RK816_LDO2_SLP_VSEL_REG			0x3E
#define RK816_LDO3_ON_VSEL_REG			0x3F
#define RK816_LDO3_SLP_VSEL_REG			0x40
#define RK816_LDO4_ON_VSEL_REG			0x41
#define RK816_LDO4_SLP_VSEL_REG			0x42
#define RK816_LDO5_ON_VSEL_REG			0x43
#define RK816_LDO5_SLP_VSEL_REG			0x44
#define RK816_LDO6_ON_VSEL_REG			0x45
#define RK816_LDO6_SLP_VSEL_REG			0x46

/*CHARGER BOOST AND OTG REGISTER*/
#define RK816_OTG_BUCK_LDO_CONFIG_REG           0x2A
#define RK816_CHRG_CONFIG_REG                   0x2B
#define RK816_BOOST_ON_VESL_REG                 0x54
#define RK816_BOOST_SLP_VSEL_REG                0x55
#define RK816_CHRG_BOOST_CONFIG_REG             0x9A
#define RK816_SUP_STS_REG                       0xA0
#define RK816_USB_CTRL_REG                      0xA1
#define RK816_CHRG_CTRL_REG1                    0xA3
#define RK816_CHRG_CTRL_REG2                    0xA4
#define RK816_CHRG_CTRL_REG3                    0xA5
#define RK816_BAT_CTRL_REG                      0xA6
#define RK816_BAT_HTS_TS_REG                    0xA8
#define RK816_BAT_LTS_TS_REG                    0xA9

#define RK816_TS_CTRL_REG			0xAC
#define RK816_ADC_CTRL_REG			0xAD
#define RK816_GGCON_REG				0xB0
#define RK816_GGSTS_REG				0xB1
#define RK816_ZERO_CUR_ADC_REGH			0xB2
#define RK816_ZERO_CUR_ADC_REGL			0xB3
#define RK816_GASCNT_CAL_REG3			0xB4
#define RK816_GASCNT_CAL_REG2			0xB5
#define RK816_GASCNT_CAL_REG1			0xB6
#define RK816_GASCNT_CAL_REG0			0xB7
#define RK816_GASCNT_REG3			0xB8
#define RK816_GASCNT_REG2			0xB9
#define RK816_GASCNT_REG1			0xBA
#define RK816_GASCNT_REG0			0xBB
#define RK816_BAT_CUR_AVG_REGH			0xBC
#define RK816_BAT_CUR_AVG_REGL			0xBD
#define RK816_TS_ADC_REGH			0xBE
#define RK816_TS_ADC_REGL			0xBF
#define RK816_USB_ADC_REGH			0xC0
#define RK816_USB_ADC_REGL			0xC1
#define RK816_BAT_OCV_REGH			0xC2
#define RK816_BAT_OCV_REGL			0xC3
#define RK816_BAT_VOL_REGH			0xC4
#define RK816_BAT_VOL_REGL			0xC5
#define RK816_RELAX_ENTRY_THRES_REGH		0xC6
#define RK816_RELAX_ENTRY_THRES_REGL		0xC7
#define RK816_RELAX_EXIT_THRES_REGH		0xC8
#define RK816_RELAX_EXIT_THRES_REGL		0xC9
#define RK816_RELAX_VOL1_REGH			0xCA
#define RK816_RELAX_VOL1_REGL			0xCB
#define RK816_RELAX_VOL2_REGH			0xCC
#define RK816_RELAX_VOL2_REGL			0xCD
#define RK816_RELAX_CUR1_REGH			0xCE
#define RK816_RELAX_CUR1_REGL			0xCF
#define RK816_RELAX_CUR2_REGH			0xD0
#define RK816_RELAX_CUR2_REGL			0xD1
#define RK816_CAL_OFFSET_REGH			0xD2
#define RK816_CAL_OFFSET_REGL			0xD3
#define RK816_NON_ACT_TIMER_CNT_REG		0xD4
#define RK816_VCALIB0_REGH			0xD5
#define RK816_VCALIB0_REGL			0xD6
#define RK816_VCALIB1_REGH			0xD7
#define RK816_VCALIB1_REGL			0xD8
#define RK816_FCC_GASCNT_REG3			0xD9
#define RK816_FCC_GASCNT_REG2			0xDA
#define RK816_FCC_GASCNT_REG1			0xDB
#define RK816_FCC_GASCNT_REG0			0xDC
#define RK816_IOFFSET_REGH			0xDD
#define RK816_IOFFSET_REGL			0xDE
#define RK816_SLEEP_CON_SAMP_CUR_REG		0xDF

/*DATA REGISTER*/
#define RK816_SOC_REG				0xE0
#define	RK816_REMAIN_CAP_REG3			0xE1
#define	RK816_REMAIN_CAP_REG2			0xE2
#define	RK816_REMAIN_CAP_REG1			0xE3
#define	RK816_REMAIN_CAP_REG0			0xE4
#define	RK816_UPDATE_LEVE_REG			0xE5
#define	RK816_NEW_FCC_REG3			0xE6
#define	RK816_NEW_FCC_REG2			0xE7
#define	RK816_NEW_FCC_REG1			0xE8
#define	RK816_NEW_FCC_REG0			0xE9
#define RK816_NON_ACT_TIMER_CNT_REG_SAVE	0xEA
#define RK816_OCV_VOL_VALID_REG			0xEB
#define RK816_REBOOT_CNT_REG			0xEC
#define RK816_PCB_IOFFSET_REG			0xED
#define RK816_MISC_MARK_REG			0xEE
#define RK816_HALT_CNT_REG			0xEF
#define RK816_CALC_REST_REGH			0xF0
#define RK816_CALC_REST_REGL			0xF1
#define DATA18_REG				0xF2

/*INTERRUPT REGISTER*/
#define RK816_INT_STS_REG1			0x49
#define RK816_INT_STS_MSK_REG1			0x4A
#define RK816_INT_STS_REG2			0x4C
#define RK816_INT_STS_MSK_REG2			0x4D
#define RK816_INT_STS_REG3			0x4E
#define RK816_INT_STS_MSK_REG3			0x4F
#define RK816_GPIO_IO_POL_REG			0x50

#define RK816_DATA18_REG			0xF2

/* IRQ Definitions */
#define RK816_IRQ_PWRON_FALL			0
#define RK816_IRQ_PWRON_RISE			1
#define RK816_IRQ_VB_LOW			2
#define RK816_IRQ_PWRON				3
#define RK816_IRQ_PWRON_LP			4
#define RK816_IRQ_HOTDIE			5
#define RK816_IRQ_RTC_ALARM			6
#define RK816_IRQ_RTC_PERIOD			7
#define RK816_IRQ_USB_OV			8
#define RK816_IRQ_PLUG_IN			9
#define RK816_IRQ_PLUG_OUT			10
#define RK816_IRQ_CHG_OK			11
#define RK816_IRQ_CHG_TE			12
#define RK816_IRQ_CHG_TS			13
#define RK816_IRQ_CHG_CVTLIM			14
#define RK816_IRQ_DISCHG_ILIM			15

#define RK816_IRQ_PWRON_FALL_MSK		BIT(5)
#define RK816_IRQ_PWRON_RISE_MSK		BIT(6)
#define RK816_IRQ_VB_LOW_MSK			BIT(1)
#define RK816_IRQ_PWRON_MSK			BIT(2)
#define RK816_IRQ_PWRON_LP_MSK			BIT(3)
#define RK816_IRQ_HOTDIE_MSK			BIT(4)
#define RK816_IRQ_RTC_ALARM_MSK			BIT(5)
#define RK816_IRQ_RTC_PERIOD_MSK		BIT(6)
#define RK816_IRQ_USB_OV_MSK			BIT(7)
#define RK816_IRQ_PLUG_IN_MSK			BIT(0)
#define RK816_IRQ_PLUG_OUT_MSK			BIT(1)
#define RK816_IRQ_CHG_OK_MSK			BIT(2)
#define RK816_IRQ_CHG_TE_MSK			BIT(3)
#define RK816_IRQ_CHG_TS_MSK			BIT(4)
#define RK816_IRQ_CHG_CVTLIM_MSK		BIT(6)
#define RK816_IRQ_DISCHG_ILIM_MSK		BIT(7)

#define RK816_VBAT_LOW_2V8			0x00
#define RK816_VBAT_LOW_2V9			0x01
#define RK816_VBAT_LOW_3V0			0x02
#define RK816_VBAT_LOW_3V1			0x03
#define RK816_VBAT_LOW_3V2			0x04
#define RK816_VBAT_LOW_3V3			0x05
#define RK816_VBAT_LOW_3V4			0x06
#define RK816_VBAT_LOW_3V5			0x07
#define RK816_PWR_FALL_INT_STATUS		(0x1 << 5)
#define RK816_PWR_RISE_INT_STATUS		(0x1 << 6)
#define RK816_ALARM_INT_STATUS			(0x1 << 5)
#define EN_VBAT_LOW_IRQ				(0x1 << 4)
#define VBAT_LOW_ACT_MASK			(0x1 << 4)
#define RTC_TIMER_ALARM_INT_MSK			(0x3 << 2)
#define RTC_TIMER_ALARM_INT_DIS			(0x0 << 2)
#define RTC_PERIOD_ALARM_INT_MSK		(0x3 << 5)
#define RTC_PERIOD_ALARM_INT_ST			(0x3 << 5)
#define RTC_PERIOD_ALARM_INT_DIS		(0x3 << 5)
#define RTC_PERIOD_ALARM_INT_EN			(0x9f)
#define REG_WRITE_MSK				0xff
#define BUCK4_MAX_ILIMIT			0x2c
#define BUCK_RATE_MSK				(0x3 << 3)
#define BUCK_RATE_12_5MV_US			(0x2 << 3)
#define ALL_INT_FLAGS_ST			0xff
#define PLUGIN_OUT_INT_EN			0xfc
#define RK816_PWRON_FALL_RISE_INT_EN		0x9f
#define BUCK1_2_IMAX_MAX			(0x3 << 6)
#define BUCK3_4_IMAX_MAX			(0x3 << 3)
#define BOOST_DISABLE				((0x1 << 5) | (0x0 << 1))
#define BUCK4_VRP_3PERCENT			0xc0
#define RK816_BUCK_DVS_CONFIRM			(0x1 << 7)
#define RK816_TYPE_ES2				0x05
#define RK816_CHIP_VERSION_MASK			0x0f

#define TEMP105C			0x08
#define TEMP115C			0x0c
#define TEMP_HOTDIE_MSK			0x0c
#define SLP_SD_MSK			(0x3 << 2)
#define SHUTDOWN_FUN			(0x2 << 2)
#define SLEEP_FUN			(0x1 << 2)
#define RK8XX_ID_MSK			0xfff0
#define PWM_MODE_MSK			BIT(7)
#define FPWM_MODE			BIT(7)
#define AUTO_PWM_MODE			0
#define REGS_WMSK			0xf0

enum rk817_reg_id {
	RK817_ID_DCDC1 = 0,
	RK817_ID_DCDC2,
	RK817_ID_DCDC3,
	RK817_ID_DCDC4,
	RK817_ID_LDO1,
	RK817_ID_LDO2,
	RK817_ID_LDO3,
	RK817_ID_LDO4,
	RK817_ID_LDO5,
	RK817_ID_LDO6,
	RK817_ID_LDO7,
	RK817_ID_LDO8,
	RK817_ID_LDO9,
	RK817_ID_BOOST,
	RK817_ID_BOOST_OTG_SW,
	RK817_NUM_REGULATORS
};

enum rk809_reg_id {
	RK809_ID_DCDC5 = RK817_ID_BOOST,
	RK809_ID_SW1,
	RK809_ID_SW2,
	RK809_NUM_REGULATORS
};

#define RK817_SECONDS_REG		0x00
#define RK817_MINUTES_REG		0x01
#define RK817_HOURS_REG			0x02
#define RK817_DAYS_REG			0x03
#define RK817_MONTHS_REG		0x04
#define RK817_YEARS_REG			0x05
#define RK817_WEEKS_REG			0x06
#define RK817_ALARM_SECONDS_REG		0x07
#define RK817_ALARM_MINUTES_REG		0x08
#define RK817_ALARM_HOURS_REG		0x09
#define RK817_ALARM_DAYS_REG		0x0a
#define RK817_ALARM_MONTHS_REG		0x0b
#define RK817_ALARM_YEARS_REG		0x0c
#define RK817_RTC_CTRL_REG		0xd
#define RK817_RTC_STATUS_REG		0xe
#define RK817_RTC_INT_REG		0xf
#define RK817_RTC_COMP_LSB_REG		0x10
#define RK817_RTC_COMP_MSB_REG		0x11

#define RK817_POWER_EN_SAVE0		0x99
#define RK817_POWER_EN_SAVE1		0xa4

#define RK817_POWER_EN_REG(i)		(0xb1 + (i))
#define RK817_POWER_SLP_EN_REG(i)	(0xb5 + (i))

#define RK817_POWER_CONFIG		(0xb9)

#define RK817_BUCK_CONFIG_REG(i)	(0xba + (i) * 3)

#define RK817_BUCK1_ON_VSEL_REG		0xBB
#define RK817_BUCK1_SLP_VSEL_REG	0xBC

#define RK817_BUCK2_CONFIG_REG		0xBD
#define RK817_BUCK2_ON_VSEL_REG		0xBE
#define RK817_BUCK2_SLP_VSEL_REG	0xBF

#define RK817_BUCK3_CONFIG_REG		0xC0
#define RK817_BUCK3_ON_VSEL_REG		0xC1
#define RK817_BUCK3_SLP_VSEL_REG	0xC2

#define RK817_BUCK4_CONFIG_REG		0xC3
#define RK817_BUCK4_ON_VSEL_REG		0xC4
#define RK817_BUCK4_SLP_VSEL_REG	0xC5

#define RK817_LDO_ON_VSEL_REG(idx)	(0xcc + (idx) * 2)
#define RK817_BOOST_OTG_CFG		(0xde)

#define RK817_ID_MSB			0xed
#define RK817_ID_LSB			0xee

#define RK817_SYS_STS			0xf0
#define RK817_SYS_CFG(i)		(0xf1 + (i))

#define RK817_ON_SOURCE_REG		0xf5
#define RK817_OFF_SOURCE_REG		0xf6

/* INTERRUPT REGISTER */
#define RK817_INT_STS_REG0		0xf8
#define RK817_INT_STS_MSK_REG0		0xf9
#define RK817_INT_STS_REG1		0xfa
#define RK817_INT_STS_MSK_REG1		0xfb
#define RK817_INT_STS_REG2		0xfc
#define RK817_INT_STS_MSK_REG2		0xfd
#define RK817_GPIO_INT_CFG		0xfe

/* IRQ Definitions */
#define RK817_IRQ_PWRON_FALL		0
#define RK817_IRQ_PWRON_RISE		1
#define RK817_IRQ_PWRON			2
#define RK817_IRQ_PWMON_LP		3
#define RK817_IRQ_HOTDIE		4
#define RK817_IRQ_RTC_ALARM		5
#define RK817_IRQ_RTC_PERIOD		6
#define RK817_IRQ_VB_LO			7
#define RK817_IRQ_PLUG_IN		(8 + 0)
#define RK817_IRQ_PLUG_OUT		(8 + 1)
#define RK817_IRQ_CHRG_TERM		(8 + 2)
#define RK817_IRQ_CHRG_TIME		(8 + 3)
#define RK817_IRQ_CHRG_TS		(8 + 4)
#define RK817_IRQ_USB_OV		(8 + 5)
#define RK817_IRQ_CHRG_IN_CLMP		(8 + 6)
#define RK817_IRQ_BAT_DIS_ILIM		(8 + 7)
#define RK817_IRQ_GATE_GPIO		(16 + 0)
#define RK817_IRQ_TS_GPIO		(16 + 1)
#define RK817_IRQ_CODEC_PD		(16 + 2)
#define RK817_IRQ_CODEC_PO		(16 + 3)
#define RK817_IRQ_CLASSD_MUTE_DONE	(16 + 4)
#define RK817_IRQ_CLASSD_OCP		(16 + 5)
#define RK817_IRQ_BAT_OVP		(16 + 6)
#define RK817_IRQ_CHRG_BAT_HI		(16 + 7)
#define RK817_IRQ_END			(RK817_IRQ_CHRG_BAT_HI + 1)

/*
 * rtc_ctrl 0xd
 * same as 808, except bit4
 */
#define RK817_RTC_CTRL_RSV4		BIT(4)

/* power config 0xb9 */
#define RK817_BUCK3_FB_RES_MSK		BIT(6)
#define RK817_BUCK3_FB_RES_INTER	BIT(6)
#define RK817_BUCK3_FB_RES_EXT		0

/* buck config 0xba */
#define RK817_RAMP_RATE_OFFSET		6
#define RK817_RAMP_RATE_MASK		(0x3 << RK817_RAMP_RATE_OFFSET)
#define RK817_RAMP_RATE_3MV_PER_US	(0x0 << RK817_RAMP_RATE_OFFSET)
#define RK817_RAMP_RATE_6_3MV_PER_US	(0x1 << RK817_RAMP_RATE_OFFSET)
#define RK817_RAMP_RATE_12_5MV_PER_US	(0x2 << RK817_RAMP_RATE_OFFSET)
#define RK817_RAMP_RATE_25MV_PER_US	(0x3 << RK817_RAMP_RATE_OFFSET)

/* sys_cfg1 0xf2 */
#define RK817_HOTDIE_TEMP_MSK		(0x3 << 4)
#define RK817_HOTDIE_85			(0x0 << 4)
#define RK817_HOTDIE_95			(0x1 << 4)
#define RK817_HOTDIE_105		(0x2 << 4)
#define RK817_HOTDIE_115		(0x3 << 4)

#define RK817_TSD_TEMP_MSK		BIT(6)
#define RK817_TSD_140			0
#define RK817_TSD_160			BIT(6)

#define RK817_CLK32KOUT2_EN		BIT(7)

/* sys_cfg3 0xf4 */
#define RK817_SLPPIN_FUNC_MSK		(0x3 << 3)
#define SLPPIN_NULL_FUN			(0x0 << 3)
#define SLPPIN_SLP_FUN			(0x1 << 3)
#define SLPPIN_DN_FUN			(0x2 << 3)
#define SLPPIN_RST_FUN			(0x3 << 3)

#define RK817_RST_FUNC_MSK		(0x3 << 6)
#define RK817_RST_FUNC_SFT		(6)
#define RK817_RST_FUNC_CNT		(3)
#define RK817_RST_FUNC_DEV		(0) /* reset the dev */
#define RK817_RST_FUNC_REG		(0x1 << 6) /* reset the reg only */

#define RK817_SLPPOL_MSK		BIT(5)
#define RK817_SLPPOL_H			BIT(5)
#define RK817_SLPPOL_L			(0)

/* gpio&int 0xfe */
#define RK817_INT_POL_MSK		BIT(1)
#define RK817_INT_POL_H			BIT(1)
#define RK817_INT_POL_L			0
#define RK809_BUCK5_CONFIG(i)		(RK817_BOOST_OTG_CFG + (i) * 1)

enum {
	BUCK_ILMIN_50MA,
	BUCK_ILMIN_100MA,
	BUCK_ILMIN_150MA,
	BUCK_ILMIN_200MA,
	BUCK_ILMIN_250MA,
	BUCK_ILMIN_300MA,
	BUCK_ILMIN_350MA,
	BUCK_ILMIN_400MA,
};

enum {
	BOOST_ILMIN_75MA,
	BOOST_ILMIN_100MA,
	BOOST_ILMIN_125MA,
	BOOST_ILMIN_150MA,
	BOOST_ILMIN_175MA,
	BOOST_ILMIN_200MA,
	BOOST_ILMIN_225MA,
	BOOST_ILMIN_250MA,
};

struct rk808_pin_info {
	struct pinctrl *p;
	struct pinctrl_state *reset;
	struct pinctrl_state *power_off;
	struct pinctrl_state *sleep;
};

struct rk808 {
	struct i2c_client *i2c;
	struct regmap_irq_chip_data *irq_data;
	struct regmap_irq_chip_data *battery_irq_data;
	struct regmap *regmap;
	long variant;
	struct rk808_pin_info *pins;
	int hold_gpio;
	int stby_gpio;
};

enum {
	RK805_ID = 0x8050,
	RK808_ID = 0x0000,
	RK809_ID = 0x8090,
	RK816_ID = 0x8160,
	RK817_ID = 0x8170,
	RK818_ID = 0x8180,
};

#endif /* __LINUX_REGULATOR_rk808_H */
