/* include/dwc3-uboot.h
 *
 * Copyright (c) 2015 Texas Instruments Incorporated - http://www.ti.com
 *
 * Designware SuperSpeed USB uboot init
 *
 * SPDX-License-Identifier:     GPL-2.0
 */

#ifndef __DWC3_UBOOT_H_
#define __DWC3_UBOOT_H_

#include <linux/usb/otg.h>

#ifdef CONFIG_USB_DWC3_RTK
struct usb2_phy;
struct usb3_phy;
#endif

struct dwc3_device {
	int base;
	enum usb_dr_mode dr_mode;
	u32 maximum_speed;
	unsigned tx_fifo_resize:1;
	unsigned has_lpm_erratum;
	u8 lpm_nyet_threshold;
	unsigned is_utmi_l1_suspend;
	u8 hird_threshold;
	unsigned disable_scramble_quirk;
	unsigned u2exit_lfps_quirk;
	unsigned u2ss_inp3_quirk;
	unsigned req_p1p2p3_quirk;
	unsigned del_p1p2p3_quirk;
	unsigned del_phy_power_chg_quirk;
	unsigned lfps_filter_quirk;
	unsigned rx_detect_poll_quirk;
	unsigned dis_u3_susphy_quirk;
	unsigned dis_u2_susphy_quirk;
	unsigned tx_de_emphasis_quirk;
	unsigned tx_de_emphasis;
	int index;

#ifdef CONFIG_USB_DWC3_RTK
	struct usb2_phy *u2phy;
	struct usb3_phy *u3phy;
#endif
};

int dwc3_uboot_init(struct dwc3_device *dev);
void dwc3_uboot_exit(int index);
void dwc3_uboot_handle_interrupt(int index);
#endif /* __DWC3_UBOOT_H_ */
