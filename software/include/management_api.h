/*
 * management_api.h
 *
 *  Created on: 28/09/2016
 *      Author: mruaro
 */

#ifndef _SERVICE_API_H_
#define _SERVICE_API_H_

//These macros must be a continuation of macros present into api.h
#define	REQSERVICEMODE	9
#define WRITESERVICE   	10
#define READSERVICE     11
#define	PUTS			12
#define NOCSENDFREE		13
#define INCOMINGPACKET	14
#define	GETNETADDRESS	15
#define	ADDTASKLOCATION	16
#define	GETTASKLOCATION	17
#define SETTASKRELEASE	18


//A flag TO_KERNEL faz com que o endereço seja enviado diretamente pro kernel
#define	TO_KERNEL					0x10000

extern int SystemCall();

#define RequestServiceMode()				SystemCall(REQSERVICEMODE, 0, 0, 0)
//Send used only by management task to send messages to another management tasks
#define SendService(target, msg, uint_size) while(!SystemCall(WRITESERVICE, target, (unsigned int *)msg, uint_size))
#define ReceiveService(msg)					while(!SystemCall(READSERVICE, 	(unsigned int *)msg, 0, 0))
#define Puts(str) 							while(!SystemCall(PUTS, 		(char*)str,			0, 0))
#define	NoCSendFree()						SystemCall(NOCSENDFREE, 	0, 0, 0)
#define IncomingPacket()					SystemCall(INCOMINGPACKET, 	0, 0, 0)
#define GetNetAddress()						SystemCall(GETNETADDRESS, 	0, 0, 0)
#define AddTaskLocation(task_id, location)	SystemCall(ADDTASKLOCATION, task_id, location, 0)
#define GetTaskLocation(task_id)			SystemCall(GETTASKLOCATION, task_id, 0, 0)
#define SetTaskRelease(message, size)		SystemCall(SETTASKRELEASE, message, size, 0)


#endif /* _SERVICE_API_H_ */
