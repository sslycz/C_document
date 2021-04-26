/*
 * macro.h
 *
 *  Created on: 2021Äê4ÔÂ26ÈÕ
 *      Author: hyq
 */

#ifndef MACRO_MACRO_H_
#define MACRO_MACRO_H_


#define PAGE_SHIFT	(12)
#define PAGE_SIZE	(1UL << PAGE_SHIFT)
#define PAGE_MASK	(~(PAGE_SIZE-1))

#define __ALIGN_MASK(x,mask)	(((x)+(mask))&~(mask))

#define ALIGN(x,a)		__ALIGN_MASK(x,(typeof(x))(a)-1)

#define PAGE_ALIGN(addr) ALIGN(addr, PAGE_SIZE)


/*
(addr)
(addr, 0x1000)
(addr, (typeof(addr))(0x1000) - 1) -> (addr, (long)(0x1000) - 1) -> (addr, (long)(0x1000) - 1)



 */

#endif /* MACRO_MACRO_H_ */
