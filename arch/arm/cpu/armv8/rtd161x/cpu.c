/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 2018 by YH_HSIEH <yh_hsieh@realtek.com>
 *
 * Time initialization.
 */
#include <common.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>


#ifdef CONFIG_RTK_SLAVE_CPU_BOOT
void bootup_slave_cpu(void)
{
	printf("Bring UP slave CPUs\n");
	
	__raw_writel(0x00000000, CPU_RELEASE_ADDR);
	asm volatile ("ISB SY" : : : "memory");
	sync();

     // core 123 jump to FSBL directly
    __raw_writel(0x003E3F3F, 0x9801D538);
    asm volatile ("ISB SY" : : : "memory");
    sync();

    __raw_writel(0x101F3EFF, 0x9801D100);
    asm volatile ("ISB SY" : : : "memory");
    sync();

    __raw_writel(0x0000323F, 0x9801D900);
    asm volatile ("ISB SY" : : : "memory");
    sync();
	
}
#endif //CONFIG_RTK_SLAVE_CPU_BOOT:
