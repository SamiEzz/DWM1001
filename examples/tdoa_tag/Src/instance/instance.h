/*
 * @file       instance.h
 *
 * @brief      DecaWave header for application level instance
 *
 * @author     Decawave Software
 *
 * @attention  Copyright 2018 (c) DecaWave Ltd, Dublin, Ireland.
 *             All rights reserved.
 *
 * @modified   2018 PathPartner
 */
 
#ifndef _INSTANCE_H_
#define _INSTANCE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "default_config.h"
#include "deca_types.h"
#include "deca_device_api.h"
#include "pckt_ieee.h"

typedef struct
{
    param_block_t  *pConfig;
    uint32       firststart;
    uint32       blinkenable;
    uint32       current_blink_interval_ms;
}app_cfg_t;


extern app_cfg_t app;


/*******************************************************************************
 ********************** NOTES on DW (MP) features/options **********************
 ******************************************************************************/

#define DWT_PRF_64M_RFDLY   (514.462f)
#define DWT_PRF_16M_RFDLY   (513.907f)

#define MAXIMUM_LED_ON_TIME   (50)

typedef struct
{
    int testAppState ;
    int done ;

    //message structures used for transmitted messages
    // 802.15.4  Minimum IEEE ID blink
    iso_IEEE_EUI64_blink_msg msg ;
    uint16        psduLength ;
    uint8        frame_sn;
    uint8        event[2];
    uint8        eventCnt;
    uint8        timeron;
    uint32        timeout;
    uint16_t chipSleep; // The DW1000 sleep duration
} instance_data_t ;

/* Exported functions prototypes */

/* Set Newchip to 1 to inform instance Tag TDoA that DW1000 has no OTP calibrated
   values */
int instance_init( int sleep_enable) ;

// Call init, then call config, then call run. call colose when finished
void instance_config(param_block_t *config) ;

// returns indication of status report change
int instance_run(void) ;

// Return Device ID reg, enables validation of physical device presence
uint32 instancereaddeviceid(void) ;
int testapprun(instance_data_t *inst, int message);
uint32 ulong2littleEndian(uint32);
void instancesettagaddress(instance_data_t *inst);
void instance_txcallback(const dwt_cb_data_t *txd);
void instance_rxgood(const dwt_cb_data_t *rxd);
void instance_rxtimeout(const dwt_cb_data_t *rxd);
void instance_rxerror(const dwt_cb_data_t *rxd);

extern int dw_ieee_payload(uint8 dwh, uint8 dwp, uint8 * buf);
void process_uartmsg(void);

#ifdef __cplusplus
}
#endif

#endif
