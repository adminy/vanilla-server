// vim:ts=4 sw=4
#include "stdafx.h"
#include "ClientManager.h"

void CClientManager::UpdateHorseName(TPacketUpdateHorseName* data, CPeer* peer)
{
	char szQuery[512];

	snprintf(szQuery, sizeof(szQuery), "REPLACE INTO horse_name VALUES(%u, '%s')", data->dwPlayerID, data->szHorseName);

	CDBManager::instance().AsyncQuery(szQuery);

	ForwardPacket(HEADER_DG_UPDATE_HORSE_NAME, data, sizeof(TPacketUpdateHorseName), 0, peer);
}

void CClientManager::AckHorseName(DWORD dwPID, CPeer* peer)
{
	char szQuery[512];

	snprintf(szQuery, sizeof(szQuery), "SELECT `name` FROM horse_name WHERE `id` = %u", dwPID);

	std::unique_ptr<SQLMsg> pmsg(CDBManager::instance().DirectQuery(szQuery));

	TPacketUpdateHorseName packet;
	packet.dwPlayerID = dwPID;

	if (pmsg->Get()->uiNumRows == 0)
	{
		memset(packet.szHorseName, 0, sizeof (packet.szHorseName));
	}
	else
	{
		MYSQL_ROW row = mysql_fetch_row(pmsg->Get()->pSQLResult);
		strncpy(packet.szHorseName, row[0], sizeof(packet.szHorseName));
	}

	peer->EncodeHeader(HEADER_DG_ACK_HORSE_NAME, 0, sizeof(TPacketUpdateHorseName));
	peer->Encode(&packet, sizeof(TPacketUpdateHorseName));
}

