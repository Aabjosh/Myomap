#ifndef ADC_READ_H_
#define ADC_READ_H_

#include <stdint.h>

struct adc_result
{
    int16_t raw;
    int32_t mv;
};

int app_adc_init(void);
int app_adc_read(struct adc_result *result);

#endif