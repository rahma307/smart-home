/*
 * std.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: hp
 */

#ifndef _STD_TYPES_H
#define _STD_TYPES_H

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;

/** Check if the function correct or not    ****/

#define  STD_TYPES_NOK  0
#define  STD_TYPES_OK   1

#define  NULL      ((void *)0)  // we don't include <stdio.h> so we don't have NULL

#endif

