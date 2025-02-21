#include <arm_neon.h>

/* { dg-do compile } */
/* { dg-skip-if "" { *-*-* } { "-fno-fat-lto-objects" } } */
/* { dg-excess-errors "" { xfail arm*-*-* } } */

float16x8x2_t
f_vld2q_lane_f16 (float16_t * p, float16x8x2_t v)
{
  float16x8x2_t res;
  /* { dg-error "lane 8 out of range 0 - 7" "" { xfail arm*-*-* } 0 } */
  res = vld2q_lane_f16 (p, v, 8);
  /* { dg-error "lane -1 out of range 0 - 7" "" { xfail arm*-*-* } 0 } */
  res = vld2q_lane_f16 (p, v, -1);
  return res;
}
