/*
 * The MIT License (MIT)
 *
 * File: messages.h
 *
 * Description: Message library for use with RF24l01.
 *
 * Copyright (c) 2014 Ed Crampton
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _MESSAGES_H_
#define _MESSAGES_H_

#include <stdint.h>


#define BASEMESSAGE Rf24MessageBase MessageBase

///@brief enums for service message ids
typedef enum  {
	BROADCAST_MSG_ID,
	BEACON_MSG_ID
} MessageServiceId_e;

///@brief enums for data message ids
typedef enum  {
	PING_MSG_ID,	///Ping message
	PONG_MSG_ID,	///Pong message
	TEMPERATURE_MSG_ID	///Temperature message
} MessageDataId_e;


///@brief Header for all messages sent of rf24l01
typedef struct {
	uint8_t SrcAddr;
	uint8_t DstAddr;
	uint8_t MessageFlags;  ///BIT0 - Service BIT1 - Data
	uint8_t MessageId;
} Rf24MessageBase;


typedef struct  {
	BASEMESSAGE;
	uint8_t Count;
} PingMessage;

typedef struct  {
	BASEMESSAGE;
	uint8_t Temperature;
} TemperatureMessage;

#define INIT_HEADER(src,dst,flag,e) { src,dst,flag,e }
//#define INIT_PINGMSG(X) PingMessage X = { {0,0,0,PING_MSG_ID}, 0}
#define INIT_PINGMSG(X,SOURCE) PingMessage X = { INIT_HEADER(SOURCE,0,0,PING_MSG_ID), 0}
#define INIT_PONGMSG(X,SOURCE) PingMessage X = { INIT_HEADER(SOURCE,0,0,PONG_MSG_ID), 0}
#define INIT_TEMPERATUREMSG(X,SOURCE) TemperatureMessage X = { INIT_HEADER(SOURCE,0,0,TEMPERATURE_MSG_ID), 0}


//Message Size
#define MESSAGE_SIZE(msg) sizeof(msg)



#define FOR_ALL_MESSAGES(OPERATION, ...) \
	OPERATION(TemperatureMessage) __VA_ARGS__ \
	OPERATION(PingMessage) __VA_ARGS__ \
	OPERATION(Rf24MessageBase) __VA_ARGS__

#ifdef __cplusplus
}
#endif
#endif
