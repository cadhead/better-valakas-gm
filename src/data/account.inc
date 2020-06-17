#if defined _data_acc_included
	#endinput
#endif

#define _data_acc_included

#define ACCOUNT_DATA_ERROR_OK        0
#define ACCOUNT_DATA_ERROR_NOT_EXIST 1

enum {
	PLAYER_GROUP_DEFAULT,
	PLAYER_GROUP_PREMIUM,
	PLAYER_GROUP_HELPER,
	PLAYER_GROUP_ADMIN,
	PLAYER_GROUP_OWNER
}

enum e_Account_Info {
  e_ID,
  e_Username[MAX_PLAYER_NAME + 1],
	e_PassHash,
	e_PassSalt,
	e_RegisterDate,
	e_LoginDate,
	e_IP,
	e_PlayerGroup,
	e_ALevel,
	e_PLevel
}

new Account[MAX_PLAYERS][e_Account_Info];

static
  gAccountNULL[e_Account_Info],
  gPlayerLogged[MAX_PLAYERS char]
;

stock bool:IsPlayerLogged(playerid) {
  return !!gPlayerLogged{playerid};
}

stock TogglePlayerLogged(playerid) {
  return IsPlayerLogged(playerid)
    ? gPlayerLogged{playerid} = 1
    : gPlayerLogged{playerid} = 0
  ;
}

stock FetchAccountData(playerid) {
	new
		string[MAX_STRING]
	;

	mysql_format(
		DB_GetHandle(),
		string,
		sizeof string,
		"SELECT * FROM `accounts` WHERE `ID` = '%d' LIMIT 1",
		Character[playerid][e_cUCP]
	);
	mysql_tquery(DB_GetHandle(), string, "SetAccountData", "i", playerid);
}

stock SetAccountData(playerid) {
	
}
