/************************************/
/*	Author  : Mohamed Essam			*/
/*	Date 	: 1/5/2022  			*/
/*	Version : V01					*/
/************************************/
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

#define GPIOA_BASE_ADRESS	0x40010800
#define GPIOB_BASE_ADRESS	0x40010C00
#define GPIOC_BASE_ADRESS	0x40011000

				/* Register Adresses for PORTA */
#define GPIOA_CRL			*((u32 *)(GPIOA_BASE_ADRESS + 0x00))
#define GPIOA_CRH			*((u32 *)(GPIOA_BASE_ADRESS + 0x04))
#define GPIOA_IDR			*((u32 *)(GPIOA_BASE_ADRESS + 0x08))
#define GPIOA_ODR			*((u32 *)(GPIOA_BASE_ADRESS + 0x0c))
#define GPIOA_BSRR			*((u32 *)(GPIOA_BASE_ADRESS + 0x10))
#define GPIOA_BRR			*((u32 *)(GPIOA_BASE_ADRESS + 0x14))
#define GPIOA_LCKR			*((u32 *)(GPIOA_BASE_ADRESS + 0x18))

				/* Register Adresses for PORTB */
#define GPIOB_CRL			*((u32 *)(GPIOB_BASE_ADRESS + 0x00))
#define GPIOB_CRH			*((u32 *)(GPIOB_BASE_ADRESS + 0x04))
#define GPIOB_IDR			*((u32 *)(GPIOB_BASE_ADRESS + 0x08))
#define GPIOB_ODR			*((u32 *)(GPIOB_BASE_ADRESS + 0x0C))
#define GPIOB_BSRR			*((u32 *)(GPIOB_BASE_ADRESS + 0x10))
#define GPIOB_BRR			*((u32 *)(GPIOB_BASE_ADRESS + 0x14))
#define GPIOB_LCKR			*((u32 *)(GPIOB_BASE_ADRESS + 0x18))

				/* Register Adresses for PORTC */
#define GPIOC_CRL			*((u32 *)(GPIOC_BASE_ADRESS + 0x00))
#define GPIOC_CRH			*((u32 *)(GPIOC_BASE_ADRESS + 0x04))
#define GPIOC_IDR			*((u32 *)(GPIOC_BASE_ADRESS + 0x08))
#define GPIOC_ODR			*((u32 *)(GPIOC_BASE_ADRESS + 0x0C))
#define GPIOC_BSRR			*((u32 *)(GPIOC_BASE_ADRESS + 0x10))
#define GPIOC_BRR			*((u32 *)(GPIOC_BASE_ADRESS + 0x14))
#define GPIOC_LCKR			*((u32 *)(GPIOC_BASE_ADRESS + 0x18))


#endif 
