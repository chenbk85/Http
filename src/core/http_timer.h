#ifndef _HTTP_HTTP_TIMER_H_INCLUDED_
#define _HTTP_HTTP_TIMER_H_INCLUDED_

#include <sys/time.h>

extern struct timeval time_now;
int Gettimeofday(struct timeval *tv, struct timezone *tz);
int Settimeofday(const struct timeval *tv, const struct timezone *tz);
struct timeval timer_now();
int timer_cmp(struct timeval time_a, struct timeval time_b);
struct timeval timer_dup(struct timeval time_b);
struct timeval set_time_now(void);
void timer_reset(struct timeval *tv);

int timer_isnull(struct timeval tv);
struct timeval timer_sub(struct timeval time_a, struct timeval time_b);
struct timeval timer_add_long(struct timeval time_a, long b);
#endif

