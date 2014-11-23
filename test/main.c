//#include "messagehandler.h"
#include "messaging/messages.h"
#include <stdio.h>

#define SOURCEID 0xFF

int main(void)
{

	INIT_PINGMSG( pingMsg, SOURCEID );
	INIT_PONGMSG( pongMsg, SOURCEID );

	uint8_t *ptr = (uint8_t*)&pingMsg;
	pingMsg.Count = 2;
	PingMessage* msg_ptr = &pingMsg;
	for(int i = 0; i < sizeof(pingMsg); ++i)
		printf("%d ",ptr[i]);
		printf("%d",msg_ptr->Count);
	printf("\n");

	ptr = (uint8_t*)&pongMsg;
	pongMsg.Count = 1;
	msg_ptr = &pingMsg;
	for(int i = 0; i < sizeof(pongMsg); ++i)
		printf("%d ",ptr[i]);
		printf("%d",msg_ptr->Count);
	printf("\n");

	return 0;
}


