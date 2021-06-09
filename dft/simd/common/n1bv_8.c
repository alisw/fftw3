/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Thu Dec 10 07:04:44 EST 2020 */

#include "dft/codelet-dft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_notw_c.native -fma -simd -compact -variables 4 -pipeline-latency 8 -sign 1 -n 8 -name n1bv_8 -include dft/simd/n1b.h */

/*
 * This function contains 26 FP additions, 10 FP multiplications,
 * (or, 16 additions, 0 multiplications, 10 fused multiply/add),
 * 22 stack variables, 1 constants, and 16 memory accesses
 */
#include "dft/simd/n1b.h"

static void n1bv_8(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP707106781, +0.707106781186547524400844362104849039284835938);
     {
	  INT i;
	  const R *xi;
	  R *xo;
	  xi = ii;
	  xo = io;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(16, is), MAKE_VOLATILE_STRIDE(16, os)) {
	       V T3, Tj, Te, Tk, Ta, Tn, Tf, Tm;
	       {
		    V T1, T2, Tc, Td;
		    T1 = LD(&(xi[0]), ivs, &(xi[0]));
		    T2 = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
		    T3 = VSUB(T1, T2);
		    Tj = VADD(T1, T2);
		    Tc = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
		    Td = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
		    Te = VSUB(Tc, Td);
		    Tk = VADD(Tc, Td);
		    {
			 V T4, T5, T6, T7, T8, T9;
			 T4 = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
			 T5 = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
			 T6 = VSUB(T4, T5);
			 T7 = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
			 T8 = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
			 T9 = VSUB(T7, T8);
			 Ta = VADD(T6, T9);
			 Tn = VADD(T7, T8);
			 Tf = VSUB(T6, T9);
			 Tm = VADD(T4, T5);
		    }
	       }
	       {
		    V Tb, Tg, Tp, Tq;
		    Tb = VFNMS(LDK(KP707106781), Ta, T3);
		    Tg = VFNMS(LDK(KP707106781), Tf, Te);
		    ST(&(xo[WS(os, 3)]), VFNMSI(Tg, Tb), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 5)]), VFMAI(Tg, Tb), ovs, &(xo[WS(os, 1)]));
		    Tp = VADD(Tj, Tk);
		    Tq = VADD(Tm, Tn);
		    ST(&(xo[WS(os, 4)]), VSUB(Tp, Tq), ovs, &(xo[0]));
		    ST(&(xo[0]), VADD(Tp, Tq), ovs, &(xo[0]));
	       }
	       {
		    V Th, Ti, Tl, To;
		    Th = VFMA(LDK(KP707106781), Ta, T3);
		    Ti = VFMA(LDK(KP707106781), Tf, Te);
		    ST(&(xo[WS(os, 1)]), VFMAI(Ti, Th), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 7)]), VFNMSI(Ti, Th), ovs, &(xo[WS(os, 1)]));
		    Tl = VSUB(Tj, Tk);
		    To = VSUB(Tm, Tn);
		    ST(&(xo[WS(os, 6)]), VFNMSI(To, Tl), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 2)]), VFMAI(To, Tl), ovs, &(xo[0]));
	       }
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 8, XSIMD_STRING("n1bv_8"), { 16, 0, 10, 0 }, &GENUS, 0, 0, 0, 0 };

void XSIMD(codelet_n1bv_8) (planner *p) { X(kdft_register) (p, n1bv_8, &desc);
}

#else

/* Generated by: ../../../genfft/gen_notw_c.native -simd -compact -variables 4 -pipeline-latency 8 -sign 1 -n 8 -name n1bv_8 -include dft/simd/n1b.h */

/*
 * This function contains 26 FP additions, 2 FP multiplications,
 * (or, 26 additions, 2 multiplications, 0 fused multiply/add),
 * 22 stack variables, 1 constants, and 16 memory accesses
 */
#include "dft/simd/n1b.h"

static void n1bv_8(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP707106781, +0.707106781186547524400844362104849039284835938);
     {
	  INT i;
	  const R *xi;
	  R *xo;
	  xi = ii;
	  xo = io;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(16, is), MAKE_VOLATILE_STRIDE(16, os)) {
	       V Ta, Tk, Te, Tj, T7, Tn, Tf, Tm;
	       {
		    V T8, T9, Tc, Td;
		    T8 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
		    T9 = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
		    Ta = VSUB(T8, T9);
		    Tk = VADD(T8, T9);
		    Tc = LD(&(xi[0]), ivs, &(xi[0]));
		    Td = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
		    Te = VSUB(Tc, Td);
		    Tj = VADD(Tc, Td);
		    {
			 V T1, T2, T3, T4, T5, T6;
			 T1 = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
			 T2 = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
			 T3 = VSUB(T1, T2);
			 T4 = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
			 T5 = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
			 T6 = VSUB(T4, T5);
			 T7 = VMUL(LDK(KP707106781), VSUB(T3, T6));
			 Tn = VADD(T4, T5);
			 Tf = VMUL(LDK(KP707106781), VADD(T3, T6));
			 Tm = VADD(T1, T2);
		    }
	       }
	       {
		    V Tb, Tg, Tp, Tq;
		    Tb = VBYI(VSUB(T7, Ta));
		    Tg = VSUB(Te, Tf);
		    ST(&(xo[WS(os, 3)]), VADD(Tb, Tg), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 5)]), VSUB(Tg, Tb), ovs, &(xo[WS(os, 1)]));
		    Tp = VADD(Tj, Tk);
		    Tq = VADD(Tm, Tn);
		    ST(&(xo[WS(os, 4)]), VSUB(Tp, Tq), ovs, &(xo[0]));
		    ST(&(xo[0]), VADD(Tp, Tq), ovs, &(xo[0]));
	       }
	       {
		    V Th, Ti, Tl, To;
		    Th = VBYI(VADD(Ta, T7));
		    Ti = VADD(Te, Tf);
		    ST(&(xo[WS(os, 1)]), VADD(Th, Ti), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 7)]), VSUB(Ti, Th), ovs, &(xo[WS(os, 1)]));
		    Tl = VSUB(Tj, Tk);
		    To = VBYI(VSUB(Tm, Tn));
		    ST(&(xo[WS(os, 6)]), VSUB(Tl, To), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 2)]), VADD(Tl, To), ovs, &(xo[0]));
	       }
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 8, XSIMD_STRING("n1bv_8"), { 26, 2, 0, 0 }, &GENUS, 0, 0, 0, 0 };

void XSIMD(codelet_n1bv_8) (planner *p) { X(kdft_register) (p, n1bv_8, &desc);
}

#endif
