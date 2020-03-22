/******************************************************************************
** Copyright (c) 2006-2019 Unified Automation GmbH. All rights reserved.
**
** Software License Agreement ("SLA") Version 2.7
**
** Unless explicitly acquired and licensed from Licensor under another
** license, the contents of this file are subject to the Software License
** Agreement ("SLA") Version 2.7, or subsequent versions
** as allowed by the SLA, and You may not copy or use this file in either
** source code or executable form, except in compliance with the terms and
** conditions of the SLA.
**
** All software distributed under the SLA is provided strictly on an
** "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,
** AND LICENSOR HEREBY DISCLAIMS ALL SUCH WARRANTIES, INCLUDING WITHOUT
** LIMITATION, ANY WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
** PURPOSE, QUIET ENJOYMENT, OR NON-INFRINGEMENT. See the SLA for specific
** language governing rights and limitations under the SLA.
**
** The complete license agreement can be found here:
** http://unifiedautomation.com/License/SLA/2.7/
**
** Project: C++ OPC Client SDK sample code
**
******************************************************************************/
#ifndef SAMPLECLIENT_H
#define SAMPLECLIENT_H

#include "uabase.h"
#include "uaclientsdk.h"

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>


// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")


#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "5545"

#define IP_HYM "172.20.10.2"
#define IP_2 "172.20.10.2"
#define PORT2 "7139"
#define IP_3 ""
#define PORT3 ""
#define IP_4 ""
#define PORT4 ""
#define IP_5 ""
#define PORT5 ""
#define IP_6 ""
#define PORT6 ""
#define IP_7 ""
#define PORT7 ""
#define IP_8 ""
#define PORT8 ""

class SampleSubscription;
class Configuration;

using namespace UaClientSdk;

class SampleClient : public UaSessionCallback
{
    UA_DISABLE_COPY(SampleClient);
public:
    SampleClient();
    virtual ~SampleClient();

    // UaSessionCallback implementation ----------------------------------------------------
    virtual void connectionStatusChanged(OpcUa_UInt32 clientConnectionId, UaClient::ServerStatus serverStatus);
    // UaSessionCallback implementation ------------------------------------------------------

    // set a configuration object we use to get connection parameters and NodeIds
    void setConfiguration(Configuration* pConfiguration);

    // OPC UA service calls
    UaStatus connect1();
    UaStatus disconnect();
    UaStatus browseSimple();
    UaStatus browseContinuationPoint();
    UaStatus read();
    UaStatus write();
    UaStatus subscribe();
    UaStatus unsubscribe();

private:
    // helper methods
    UaStatus browseInternal(const UaNodeId& nodeToBrowse, OpcUa_UInt32 maxReferencesToReturn);
    void printBrowseResults(const UaReferenceDescriptions& referenceDescriptions);

    WSADATA wsaData;
    SOCKET ConnectSocket = INVALID_SOCKET;
    struct addrinfo* result_soc = NULL,
        * ptr = NULL,
        hints;
    WSADATA wsaData2;


    SOCKET ConnectSocket2 = INVALID_SOCKET;
    struct addrinfo* result_soc2 = NULL,
        * ptr2 = NULL,
        hints2;



    //std::string sendbuf ;
    const char* sendbuf;
    char recvbuf[DEFAULT_BUFLEN];
    int iResult;
    int recvbuflen = DEFAULT_BUFLEN;

private:
    UaSession*              m_pSession;
    SampleSubscription*     m_pSampleSubscription;
    Configuration*          m_pConfiguration;
    UaClient::ServerStatus  m_serverStatus;
};


#endif // SAMPLECLIENT_H

