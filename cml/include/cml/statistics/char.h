#ifndef CML_STATISTICS_H
#error "Never use <cml/statistics/char.h> directly; include <cml/statistics.h> instead."
#endif

#ifndef CML_STATISTICS_UINT_H
#define CML_STATISTICS_UINT_H

#include <stdlib.h>

__CML_BEGIN_DECLS

double cml_stats_char_mean(const char data[], const size_t stride, const size_t n);
double cml_stats_char_variance(const char data[], const size_t stride, const size_t n);
double cml_stats_char_sd(const char data[], const size_t stride, const size_t n);
double cml_stats_char_variance_with_fixed_mean(const char data[], const size_t stride, const size_t n, const double mean);
double cml_stats_char_sd_with_fixed_mean(const char data[], const size_t stride, const size_t n, const double mean);
double cml_stats_char_tss(const char data[], const size_t stride, const size_t n);
double cml_stats_char_tss_m(const char data[], const size_t stride, const size_t n, const double mean);

double cml_stats_char_covariance(const char data1[], const size_t stride1,const char data2[], const size_t stride2, const size_t n);

double cml_stats_char_variance_m(const char data[], const size_t stride, const size_t n, const double mean);
double cml_stats_char_sd_m(const char data[], const size_t stride, const size_t n, const double mean);

__CML_END_DECLS

#endif /* CML_STATISTICS_UINT_H */
