#if defined _data_acc_included
	#endinput
#endif

#define _data_acc_included

#define ACCOUNT_DATA_ERROR_OK        1
#define ACCOUNT_DATA_ERROR_NOT_EXIST 2

enum {
	PLAYER_GROUP_DEFAULT,
	PLAYER_GROUP_PREMIUM,
	PLAYER_GROUP_HELPER,
	PLAYER_GROUP_ADMIN,
	PLAYER_GROUP_OWNER
}

enum e_Account_Info {
  e_aID,
  e_aUsername[MAX_PLAYER_NAME + 1],
	e_aPassHash,
	e_aPassSalt,
	e_aRegisterDate,
	e_aLoginDate,
	e_aIP,
	e_aPlayerGroup,
	e_aALevel,
	e_aPLevel
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
		"SELECT * FROM `accounts` WHERE `Username` = '%e' LIMIT 1",
		Account[playerid][e_aUsername]
	);
	mysql_tquery(DB_GetHandle(), string, "SetAccountData", "i", playerid);
}

stock SetAccountData(playerid) {
	if (cache_num_rows() == 0) {
		OnPlayerRequestAuth(playerid, ACCOUNT_DATA_ERROR_NOT_EXIST);
	} else if (cache_num_rows() >= 1) {
		OnPlayerRequestAuth(playerid, ACCOUNT_DATA_ERROR_OK);
	} else {
		OnPlayerRequestAuth(playerid, 0);
	}
}
