/* { dg-skip-if "test SSE2 vector" { ! { i?86-*-* x86_64-*-* } } } */

/* Test compatibility of vector types: layout between separately-compiled
   modules, parameter passing, and function return.  This test uses
   vectors of integer values.  */

#include "cpuid.h"

extern void vector_1_x (void);
extern void exit (int);
int fails;

int
main ()
{
  unsigned int eax, ebx, ecx, edx;

  if (!__get_cpuid (1, &eax, &ebx, &ecx, &edx))
    return 0;

  /* Run SSE vector test only if host has SSE2 support.  */
  if (edx & bit_SSE2)
    vector_1_x ();

  exit (0);
}
