#ifndef ASM_RTSP_R8_MSG_PROCESS_H_INCLUDE
#define ASM_RTSP_R8_MSG_PROCESS_H_INCLUDE

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <sys/socket.h>
#include <linux/if.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include "public_def.h"

//asm发给as的as的信息
typedef struct _AS_INFO
{
    char ip[40];
    int downPort;
}AS_INFO;
//as发给asm的setup中ss的相关信息
typedef struct _S8_SS
{
    char client[128];
    char destination[40];
    int client_port;
}R8_SS;
//asm发给as的setup消息
typedef struct _R8_SETUP_MSG
{
	char as_ip[40];
	int as_port;
	int cseq;
	char require[256];
	char session_group[256];
	char ondemandsessionid[256];
	char policy[128];
	char app_id[256];
	int app_type;
	R8_SS ss;
}R8_SETUP_MSG;
//as发给asm的setup response
typedef struct _R8_SETUP_RES
{
	int err_code;
	int cseq;
	INT64 session;
	char ondemand_session_id[128];
	S7_SS ss;
	AS_INFO as;
}R8_SETUP_RES;

//创建asm向as发送的setup消息
int rtsp_r8_setup_msg_encode(R8_SETUP_MSG msg, char *setup_msg);
//解析as向asm发送的setup response消息
int rtsp_r8_setup_res_parse(char *setup_res_msg, R8_SETUP_RES *res);
