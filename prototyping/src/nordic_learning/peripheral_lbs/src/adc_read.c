#include <zephyr/drivers/adc.h>
#include <errno.h>
#include <zephyr/devicetree.h>
#include <zephyr/logging/log.h>

#include "adc_read.h"

LOG_MODULE_REGISTER(app_adc, LOG_LEVEL_INF);

static const struct adc_dt_spec adc_channel = ADC_DT_SPEC_GET(DT_PATH(zephyr_user));
int16_t buf;

// Blueprint of how to save the data from the adc
struct adc_sequence sequence = 
{
    .buffer = &buf,
    /* buffer size in bytes, not number of samples */
    .buffer_size = sizeof(buf),
    //Optional
    //.calibrate = true,
};

int app_adc_init()
{
    int err = 0;

    if (!adc_is_ready_dt(&adc_channel)) 
    {
        LOG_ERR("ADC controller devivce %s not ready", adc_channel.dev->name);
        return -ENODEV;
    }

    err = adc_channel_setup_dt(&adc_channel);
    if (err < 0) 
    {
        LOG_ERR("Could not setup channel #%d (%d)", 0, err);
        return err;
    }

    err = adc_sequence_init_dt(&adc_channel, &sequence);
    if (err < 0) 
    {
        LOG_ERR("Could not initalize sequnce");
        return err;
    }

    return 0;
}

int app_adc_read( struct adc_result *result )
{
    int err = adc_read(adc_channel.dev, &sequence);
    if (err < 0) 
    {
        LOG_ERR("Could not read (%d)", err);
        return err;
    }

    result->raw = buf;
    result->mv = buf;

    return adc_raw_to_millivolts_dt(&adc_channel, &result->mv);
}