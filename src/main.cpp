#include <iostream>
#include "ap_int.h"
#include "utils/x_hls_utils.h"
#include<stdint.h>
#include "hls_stream.h"
#include "ap_axi_sdata.h"

static uint64_t glTimerCnt = 0;

typedef struct
{
	uint64_t inEventsNum;
	uint64_t cornerEventsNum;
	uint64_t durationTime;
} status_t;

void eventRateStat(ap_uint<64> eventNumber, status_t *status, uint64_t *evtNum, uint64_t *time)
{
#pragma HLS INTERFACE s_axilite port=status bundle=config
//#pragma HLS INTERFACE s_axilite port=config bundle=config

	ap_uint<16> x, y;
	ap_uint<16> x0, x1, y0, y1;
	ap_uint<1> pol;
	ap_uint<1> pol0, pol1;
	ap_uint<64> ts;
	ap_uint<64> ts0, ts1;
	ap_uint<1> corner;
	ap_uint<1> cornerIn0;

	status_t statusRet;
	glTimerCnt++;
	statusRet.durationTime = glTimerCnt;
	statusRet.inEventsNum = eventNumber;

	*evtNum = eventNumber;
	*time = glTimerCnt;
	*status = statusRet;
}
