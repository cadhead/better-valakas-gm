#if defined _headers_included
	#endinput
#endif

#define _headers_included

/*
 *  Events
 */

forward OnCharacterDataLoad(playerid);
forward OnAccountDataLoad(playerid);
forward OnPlayerRequestAuth(playerid, error);

/*
 *  Database
 */

forward MySQL:DB_GetHandle();
forward DB_Connect(const host[], const user[], const pass[], const db[]);
forward DB_ConnectionClose();

/*
 *	Registration
 */

forward CreateAccount(playerid);
forward CreateCharacter(playerid);
