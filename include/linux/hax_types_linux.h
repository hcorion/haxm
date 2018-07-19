/*
 * Copyright (c) 2018 Intel Corporation
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *
 *   3. Neither the name of the copyright holder nor the names of its
 *      contributors may be used to endorse or promote products derived from
 *      this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef HAX_LINUX_HAX_TYPES_LINUX_H_
#define HAX_LINUX_HAX_TYPES_LINUX_H_

#include <linux/types.h>
#include <linux/mm_types.h>
#include "../hax_list.h"
#include <assert.h>


typedef unsigned int uint;
#define uint8 u_int8_t
#define uint16 u_int16_t
#define uint32 u_int32_t
#define uint64 u_int64_t
#define int32 int32_t
#define int64 int64_t

typedef ulong mword;
typedef mword HAX_VADDR_T;
typedef uint64_t cpumap_t;
typedef mword preempt_flag;
#define PACKED     __attribute__ ((packed))
#define ALIGNED(x) __attribute__ ((aligned(x)))
#define true 1
#define false 0
#define TRUE true
#define FALSE false
#define __cdecl
#define bool _Bool
//#include <stdint.h>
/*#include <errno.h>
#include <assert.h>
#include <stddef.h>
//#include <stdint.h>

#include "../hax_list.h"



typedef unsigned char       uint8_t;
typedef unsigned short      uint16_t;
typedef unsigned int        uint32_t;
typedef unsigned long long  uint64_t;
typedef unsigned int      *uintptr_t;
// Signed Types
#undef uint64_t
//#undef int64_t
#undef uint64
#undef int64
typedef signed char         int8;
typedef signed short        int16;
typedef signed int          int32;
typedef signed long long    int64;

// Unsigned Types
typedef unsigned char       uint8;
typedef unsigned short      uint16;
typedef unsigned int        uint32;
typedef unsigned int        uint;
typedef unsigned long long  uint64;
typedef unsigned long       ulong;


typedef unsigned char bool;
typedef ulong mword;
typedef mword HAX_VADDR_T;
typedef uint64_t cpumap_t;
typedef mword preempt_flag;
#define PACKED     __attribute__ ((packed))
#define ALIGNED(x) __attribute__ ((aligned(x)))
#define true 1
#define false 0
#define TRUE true
#define FALSE false
#define PAGE_MASK (((mword)0x1 << 12) - 1)
#define PAGE_SHIFT 12
#define page_shift PAGE_SHIFT
#define PAGE_SIZE 4096
#define __cdecl*/

typedef struct {
    // TODO
    //KSPIN_LOCK lock;
    uint32_t flags;
    //KIRQL old_irq;
} hax_spinlock;

// TODO
typedef void *hax_mutex;

// TODO
typedef void hax_rw_lock;

typedef int32 hax_atomic_t;

/* Remove this later */
#define is_leaf(x)  1

struct hax_page {
    void *kva;
    /*PMDL pmdl;*/
    uint64_t pa;
    uint32_t order;
    uint32_t flags;
    struct hax_link_list list;
};

typedef struct hax_memdesc_user {
    /*PMDL pmdl;*/
} hax_memdesc_user;

typedef struct hax_kmap_user {
    /*PMDL pmdl;*/
} hax_kmap_user;

typedef struct hax_memdesc_phys {
    /*PMDL pmdl;*/
} hax_memdesc_phys;

typedef struct hax_kmap_phys {
    /*PVOID kva;*/
    // size == PAGE_SIZE_4K
} hax_kmap_phys;

#endif // HAX_LINUX_HAX_TYPES_LINUX_H_