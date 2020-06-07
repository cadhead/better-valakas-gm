/*
 *  Events
 */

forward OnPlayerDataLoad(playerid);
forward OnRegisteredPlayerConnect(playerid);

/*
 *  Database
 */

forward MySQL:DB_GetHandle();
forward DB_Connect(const host[], const user[], const pass[], const db[]);
forward DB_ConnectionClose();