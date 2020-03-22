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
#include "sampleclient.h"
#include "uasession.h"
#include "samplesubscription.h"
#include "configuration.h"

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





SampleClient::SampleClient()
{
    m_pSession = new UaSession();
    m_pSampleSubscription = new SampleSubscription();
    m_pConfiguration = new Configuration();

    
   

    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
       // return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
    iResult = getaddrinfo(IP_HYM, DEFAULT_PORT, &hints, &result_soc);
    //////////////////////////////////////////////////////////////////////////////////////
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
       // return 1;
    }

    // Attempt to connect to an address until one succeeds
    for (ptr = result_soc; ptr != NULL; ptr = ptr->ai_next) {

        // Create a SOCKET for connecting to server
        ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
            ptr->ai_protocol);
        if (ConnectSocket == INVALID_SOCKET) {
            printf("socket failed with error: %ld\n", WSAGetLastError());
            WSACleanup();
            //return 1;
        }
        /////////////////////////////////////////////////
        int yes = 0;
        setsockopt(ConnectSocket, IPPROTO_TCP, TCP_NODELAY, (char*)&yes, sizeof(yes));
        ///////////////////////////////////////////////////////////////////
        // Connect to server.
        iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            closesocket(ConnectSocket);
            ConnectSocket = INVALID_SOCKET;
            continue;
        }
        break;
    }
    freeaddrinfo(result_soc);

    if (ConnectSocket == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        WSACleanup();
        //return 1;
    }
    ////////////////////////////////////////////2222///////////////////////////////////////////////////////////////////
    
    //*sendbuf = "hello";
    /*iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
    if (iResult == SOCKET_ERROR) {
        printf("send failed with error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        //return 1;
    }*/
    
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData2);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        // return 1;
    }

    ZeroMemory(&hints2, sizeof(hints2));
    hints2.ai_family = AF_UNSPEC;
    hints2.ai_socktype = SOCK_STREAM;
    hints2.ai_protocol = IPPROTO_TCP;

    //////
    iResult = getaddrinfo(IP_2, PORT2, &hints2, &result_soc2);
    //////////////////////////////////////////////////////////////////////////////////////
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        // return 1;
    }

    // Attempt to connect to an address until one succeeds
    for (ptr2 = result_soc; ptr2 != NULL; ptr2 = ptr2->ai_next) {

        // Create a SOCKET for connecting to server
        ConnectSocket2 = socket(ptr2->ai_family, ptr2->ai_socktype,
            ptr2->ai_protocol);
        if (ConnectSocket2 == INVALID_SOCKET) {
            printf("socket failed with error: %ld\n", WSAGetLastError());
            WSACleanup();
            //return 1;
        }
        /////////////////////////////////////////////////
        int yes = 0;
        setsockopt(ConnectSocket2, IPPROTO_TCP, TCP_NODELAY, (char*)&yes, sizeof(yes));
        ///////////////////////////////////////////////////////////////////
        // Connect to server.
        iResult = connect(ConnectSocket2, ptr2->ai_addr, (int)ptr2->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            closesocket(ConnectSocket2);
            ConnectSocket2 = INVALID_SOCKET;
            continue;
        }
        break;
    }
    freeaddrinfo(result_soc2);

    if (ConnectSocket2 == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        WSACleanup();
        //return 1;
    }


}////////////////////////////////////////////////2222222////////////////////////////////////////////////////////////////////

SampleClient::~SampleClient()
{
    if (m_pSampleSubscription)
    {
        // delete local subscription object
        delete m_pSampleSubscription;
        m_pSampleSubscription = NULL;
    }

    if (m_pSession)
    {
        // disconnect if we're still connected
        if (m_pSession->isConnected() != OpcUa_False)
        {
            ServiceSettings serviceSettings;
            m_pSession->disconnect(serviceSettings, OpcUa_True);
        }
        delete m_pSession;
        m_pSession = NULL;
    }

    if (m_pConfiguration)
    {
        delete m_pConfiguration;
        m_pConfiguration = NULL;
    }
}

void SampleClient::connectionStatusChanged(
    OpcUa_UInt32             clientConnectionId,
    UaClient::ServerStatus   serverStatus)
{
    OpcUa_ReferenceParameter(clientConnectionId);

    printf("-------------------------------------------------------------\n");
    switch (serverStatus)
    {
    case UaClient::Disconnected:
        printf("Connection status changed to Disconnected\n");
        break;
    case UaClient::Connected:
        printf("Connection status changed to Connected\n");
        if (m_serverStatus != UaClient::NewSessionCreated)
        {
            m_pConfiguration->updateNamespaceIndexes(m_pSession->getNamespaceTable());
        }
        break;
    case UaClient::ConnectionWarningWatchdogTimeout:
        printf("Connection status changed to ConnectionWarningWatchdogTimeout\n");
        break;
    case UaClient::ConnectionErrorApiReconnect:
        printf("Connection status changed to ConnectionErrorApiReconnect\n");
        break;
    case UaClient::ServerShutdown:
        printf("Connection status changed to ServerShutdown\n");
        break;
    case UaClient::NewSessionCreated:
        printf("Connection status changed to NewSessionCreated\n");
        m_pConfiguration->updateNamespaceIndexes(m_pSession->getNamespaceTable());
        break;
    }
    printf("-------------------------------------------------------------\n");

    m_serverStatus = serverStatus;
}

void SampleClient::setConfiguration(Configuration* pConfiguration)
{
    if (m_pConfiguration)
    {
        delete m_pConfiguration;
    }
    m_pConfiguration = pConfiguration;
}

UaStatus SampleClient::connect1()
{
    UaStatus result;

    // Provide information about the client
    SessionConnectInfo sessionConnectInfo;
    UaString sNodeName("unknown_host");
    char szHostName[256];
    if (0 == UA_GetHostname(szHostName, 256))
    {
        sNodeName = szHostName;
    }

    // Fill session connect info with data from configuration
    sessionConnectInfo.sApplicationName = m_pConfiguration->getApplicationName();
    // Use the host name to generate a unique application URI
    sessionConnectInfo.sApplicationUri = UaString("urn:%1:%2:%3").arg(sNodeName).arg(COMPANY_NAME).arg(PRODUCT_NAME);
    sessionConnectInfo.sProductUri = UaString("urn:%1:%2").arg(COMPANY_NAME).arg(PRODUCT_NAME);
    sessionConnectInfo.sSessionName = sessionConnectInfo.sApplicationUri;
    sessionConnectInfo.bAutomaticReconnect = m_pConfiguration->getAutomaticReconnect();
    sessionConnectInfo.bRetryInitialConnect = m_pConfiguration->getRetryInitialConnect();

    // Security settings are not initialized - we connect without security for now
    SessionSecurityInfo sessionSecurityInfo;

    printf("\nConnecting to %s\n", m_pConfiguration->getServerUrl().toUtf8());
    result = m_pSession->connect(
        m_pConfiguration->getServerUrl(),
        sessionConnectInfo,
        sessionSecurityInfo,
        this);

    if (result.isGood())
    {
        printf("Connect succeeded\n");
    }
    else
    {
        printf("Connect failed with status %s\n", result.toString().toUtf8());
    }

    return result;
}

UaStatus SampleClient::disconnect()
{
    UaStatus result;

    // Default settings like timeout
    ServiceSettings serviceSettings;

    printf("\nDisconnecting ...\n");
    result = m_pSession->disconnect(
        serviceSettings,
        OpcUa_True);

    if (result.isGood())
    {
        printf("Disconnect succeeded\n");
    }
    else
    {
        printf("Disconnect failed with status %s\n", result.toString().toUtf8());
    }

    return result;
}

UaStatus SampleClient::browseSimple()
{
    UaStatus result;
    UaNodeId nodeToBrowse;

    // browse from root folder with no limitation of references to return
    nodeToBrowse = UaNodeId("aaa",3);
    result = browseInternal(nodeToBrowse, 0);
   

    return result;
}

UaStatus SampleClient::browseContinuationPoint()
{
    UaStatus result;
    UaNodeId nodeToBrowse;

    // browse from Massfolder with max references to return set to 5
    nodeToBrowse = UaNodeId("aaa", 3);
    result = browseInternal(nodeToBrowse, 1);

    return result;
}


UaStatus SampleClient::read()
{
    UaStatus          result;
    ServiceSettings   serviceSettings;
    UaReadValueIds    nodesToRead;
    UaDataValues      values;
    UaDiagnosticInfos diagnosticInfos;

    // read all nodes from the configuration
    UaNodeIdArray nodes = m_pConfiguration->getNodesToRead();
  
    
    nodesToRead.create(nodes.length());

    for (OpcUa_UInt32 i = 0; i < nodes.length(); i++)
    {
        nodesToRead[i].AttributeId = OpcUa_Attributes_Value;
        OpcUa_NodeId_CopyTo(&nodes[i], &nodesToRead[i].NodeId);
    }
    
   
    printf("\nReading ...\n");
    result = m_pSession->read(
        serviceSettings,
        0,
        OpcUa_TimestampsToReturn_Both,
        nodesToRead,
        values,
        diagnosticInfos);
    ////////////////////////////////////////////////////////////////////////////////
    if (result.isGood())
    {
        
        for (OpcUa_UInt32 i = 0; i < nodes.length(); i++)
        {
            
            if (OpcUa_IsGood(values[i].StatusCode))
            {

                ///////////////////////////////////////////////////////////////////////////////////////////////////////
                printf("Value[%d]: %s\n", i, UaVariant(values[i].Value).toString().toUtf8());

                /////////////////////////////////////////////send/////////////////////////////////////////////////////////

                UaByteArray am;
                double d;
                if (i > 11 && i < 24)
                {
                    send(ConnectSocket2, "/", 1, 0);
                    iResult = send(ConnectSocket2, UaVariant(values[i].Value).toString().toUtf8(), (int)strlen(UaVariant(values[i].Value).toString().toUtf8()), 0);
                    if (iResult == SOCKET_ERROR) {
                        printf("send failed with error: %d\n", WSAGetLastError());
                        closesocket(ConnectSocket2);
                        WSACleanup();
                        //return 1;
                    }

                    printf("Bytes Sent: %ld\n", iResult);
                }
                else
                {
                send(ConnectSocket, "/", 1, 0);
                iResult = send(ConnectSocket, UaVariant(values[i].Value).toString().toUtf8(), (int)strlen(UaVariant(values[i].Value).toString().toUtf8()), 0);
                if (iResult == SOCKET_ERROR) {
                    printf("send failed with error: %d\n", WSAGetLastError());
                    closesocket(ConnectSocket);
                    WSACleanup();
                    //return 1;
                }

                printf("Bytes Sent: %ld\n", iResult);
                 }
                /////////////////////////////////////////////////////////////////////////////////////////////////////////
            }
            else
            {
                printf("Read failed for item[%d] with status %s\n", i, UaStatus(values[i].StatusCode).toString().toUtf8());
            }
        }
        //send(ConnectSocket, "dsd", 3, 0);
    }
    else
    {
        // Service call failed
        printf("Read failed with status %s\n", result.toString().toUtf8());
    }

    return result;
}



UaStatus SampleClient::write()
{
    UaStatus            result;
    ServiceSettings     serviceSettings;
    UaWriteValues       nodesToWrite;
    UaStatusCodeArray   results;
    UaDiagnosticInfos   diagnosticInfos;

    // write all nodes from the configuration
    UaNodeIdArray nodes = m_pConfiguration->getNodesToWrite();
    UaVariantArray values = m_pConfiguration->getWriteValues();
    nodesToWrite.create(nodes.length());

    for (OpcUa_UInt32 i = 0; i < nodes.length(); i++)
    {
        nodesToWrite[i].AttributeId = OpcUa_Attributes_Value;
        OpcUa_NodeId_CopyTo(&nodes[i], &nodesToWrite[i].NodeId);
        // set value to write
        OpcUa_Variant_CopyTo(&values[i], &nodesToWrite[i].Value.Value);
    }

    printf("\nWriting...\n");
    result = m_pSession->write(
        serviceSettings,
        nodesToWrite,
        results,
        diagnosticInfos);

    if (result.isGood())
    {
        // Write service succeded - check individual status codes
        for (OpcUa_UInt32 i = 0; i < results.length(); i++)
        {
            if (OpcUa_IsGood(results[i]))
            {
                printf("Write succeeded for item[%d]\n", i);
            }
            else
            {
                printf("Write failed for item[%d] with status %s\n", i, UaStatus(results[i]).toString().toUtf8());
            }
        }
    }
    else
    {
        // Service call failed
        printf("Write failed with status %s\n", result.toString().toUtf8());
    }

    return result;
}

UaStatus SampleClient::subscribe()
{
    UaStatus result;

    result = m_pSampleSubscription->createSubscription(m_pSession);
    if ( result.isGood() )
    {
        result = m_pSampleSubscription->createMonitoredItems();
    }
    return result;
}

UaStatus SampleClient::unsubscribe()
{
    return m_pSampleSubscription->deleteSubscription();
}

UaStatus SampleClient::browseInternal(const UaNodeId& nodeToBrowse, OpcUa_UInt32 maxReferencesToReturn)
{
    UaStatus result;

    ServiceSettings serviceSettings;
    BrowseContext browseContext;
    UaByteString continuationPoint;
    UaReferenceDescriptions referenceDescriptions;

    // configure browseContext
    browseContext.browseDirection = OpcUa_BrowseDirection_Forward;
    browseContext.referenceTypeId = OpcUaId_HierarchicalReferences;
    browseContext.includeSubtype = OpcUa_True;
    browseContext.maxReferencesToReturn = maxReferencesToReturn;

    printf("\nBrowsing from Node %s...\n", nodeToBrowse.toXmlString().toUtf8());
    result = m_pSession->browse(
        serviceSettings,
        nodeToBrowse,
        browseContext,
        continuationPoint,
        referenceDescriptions);

    if (result.isGood())
    {
        // print results
        printBrowseResults(referenceDescriptions);

        // continue browsing
        while (continuationPoint.length() > 0)
        {
            printf("\nContinuationPoint is set. BrowseNext...\n");
            // browse next
            result = m_pSession->browseNext(
                serviceSettings,
                OpcUa_False,
                continuationPoint,
                referenceDescriptions);

            if (result.isGood())
            {
                // print results
                printBrowseResults(referenceDescriptions);
            }
            else
            {
                // Service call failed
                printf("BrowseNext failed with status %s\n", result.toString().toUtf8());
            }
        }
    }
    else
    {
        // Service call failed
        printf("Browse failed with status %s\n", result.toString().toUtf8());
    }

    return result;
}

void SampleClient::printBrowseResults(const UaReferenceDescriptions& referenceDescriptions)
{
    OpcUa_UInt32 i;
    for (i=0; i<referenceDescriptions.length(); i++)
    {
        printf("node: ");
        UaNodeId referenceTypeId(referenceDescriptions[i].ReferenceTypeId);
        printf("[Ref=%s] ", referenceTypeId.toString().toUtf8() );
        UaQualifiedName browseName(referenceDescriptions[i].BrowseName);
        printf("%s ( ", browseName.toString().toUtf8() );
        if (referenceDescriptions[i].NodeClass & OpcUa_NodeClass_Object) printf("Object ");
        if (referenceDescriptions[i].NodeClass & OpcUa_NodeClass_Variable) printf("Variable ");
        if (referenceDescriptions[i].NodeClass & OpcUa_NodeClass_Method) printf("Method ");
        if (referenceDescriptions[i].NodeClass & OpcUa_NodeClass_ObjectType) printf("ObjectType ");
        if (referenceDescriptions[i].NodeClass & OpcUa_NodeClass_VariableType) printf("VariableType ");
        if (referenceDescriptions[i].NodeClass & OpcUa_NodeClass_ReferenceType) printf("ReferenceType ");
        if (referenceDescriptions[i].NodeClass & OpcUa_NodeClass_DataType) printf("DataType ");
        if (referenceDescriptions[i].NodeClass & OpcUa_NodeClass_View) printf("View ");
        UaNodeId nodeId(referenceDescriptions[i].NodeId.NodeId);
        printf("[NodeId=%s] ", nodeId.toFullString().toUtf8() );
        printf(")\n");
    }
}
