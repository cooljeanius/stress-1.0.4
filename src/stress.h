/* stress.h: C header for the "stress" program */

#ifndef __STRESS_H__
#define __STRESS_H__

/* Prototypes for utility functions.  */
int usage(int status);
int version(int status);
long long atoll_s(const char *nptr);
long long atoll_b(const char *nptr);

/* Prototypes for worker functions.  */
int hogcpu(void);
int hogio(void);
int hogvm(long long bytes, long long stride, long long hang, int keep);
int hoghdd(long long bytes);

#endif /* !__STRESS_H__ */

/* EOF */
