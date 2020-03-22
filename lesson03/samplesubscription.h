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
#ifndef SAMPLESUBSCRIPTION_H
#define SAMPLESUBSCRIPTION_H

#include "uabase.h"
#include "uaclientsdk.h"

using namespace UaClientSdk;

class SampleSubscription :
    public UaSubscriptionCallback
{
    UA_DISABLE_COPY(SampleSubscription);
public:
    SampleSubscription();
    virtual ~SampleSubscription();

    // UaSubscriptionCallback implementation ----------------------------------------------------
    virtual void subscriptionStatusChanged(
        OpcUa_UInt32      clientSubscriptionHandle,
        const UaStatus&   status);
    virtual void dataChange(
        OpcUa_UInt32               clientSubscriptionHandle,
        const UaDataNotifications& dataNotifications,
        const UaDiagnosticInfos&   diagnosticInfos);
    virtual void newEvents(
        OpcUa_UInt32                clientSubscriptionHandle,
        UaEventFieldLists&          eventFieldList);
    // UaSubscriptionCallback implementation ------------------------------------------------------

    // Create / delete a subscription on the server
    UaStatus createSubscription(UaSession* pSession);
    UaStatus deleteSubscription();

    // Create monitored items in the subscription
    UaStatus createMonitoredItems();

private:
    UaSession*                  m_pSession;
    UaSubscription*             m_pSubscription;
};

#endif // SAMPLESUBSCRIPTION_H
