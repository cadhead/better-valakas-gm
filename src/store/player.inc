#if defined _store_player_included
	#endinput
#endif

#define _store_player_included

enum e_Character_Info {
  ORM:e_ORM,
  e_ID,
  e_UCP,
  e_Name[MAX_PLAYER_NAME + 1],
  e_Password[MAX_PLAYER_PASSWORD + 1],
  e_PlayerGroup,
  e_Cash,
  e_CLevel,
  e_Group,
  e_ALevel,
  e_PLevel,
  Float:e_HP,
  e_PosX,
  e_PosY,
  e_PosZ,
  e_PosA
}

new gCharacter[MAX_PLAYERS][e_Character_Info];

static gCharacterNULL[e_Character_Info];
static gPlayerLogged[MAX_PLAYERS char];

// static SetCharacterName(playerid) {
//   new name[MAX_PLAYER_NAME + 1];

//   GetPlayerName(playerid, name);

//   for (new i = 0; i < MAX_PLAYER_NAME; i++) {
//     if (name[i] == '_') name[i] = ' ';
//   }

//   strcopy(gCharacter[playerid][e_Name], name);

//   return name;
// }

stock SetCharacterInfo(playerid) {
  new ORM:ormid = orm_create("players", DB_GetHandle());

	gPlayer[playerid][e_ORM] = ormid;

  orm_addvar_int(ormid, gPlayer[playerid][e_ID], "ID");
	orm_addvar_string(ormid, gPlayer[playerid][e_Name], MAX_PLAYER_NAME + 1, "Name");
	orm_addvar_string(ormid, gPlayer[playerid][e_Password], MAX_PLAYER_PASSWORD + 1, "Password");

  orm_addvar_int(ormid, gPlayer[playerid][e_Group], "Group");
  orm_addvar_int(ormid, gPlayer[playerid][e_CLevel], "CLevel");
  orm_addvar_int(ormid, gPlayer[playerid][e_ALevel], "ALevel");
  orm_addvar_int(ormid, gPlayer[playerid][e_PLevel], "PLevel");

  orm_addvar_int(ormid, gPlayer[playerid][e_Cash], "Cash");
  orm_addvar_float(ormid, gPlayer[playerid][e_HP], "HP");

  orm_addvar_float(ormid, gPlayer[playerid][e_PosX], "PosX");
  orm_addvar_float(ormid, gPlayer[playerid][e_PosY], "PosY");
  orm_addvar_float(ormid, gPlayer[playerid][e_PosZ], "PosZ");
  orm_addvar_float(ormid, gPlayer[playerid][e_PosA], "PosA");
}

stock ClearCharacterInfo(playerid) {
  gCharacter[playerid] = gCharacterNULL;
  
  orm_destroy(gCharacter[playerid][e_ORM]);

  return 1;
}

stock bool:IsPlayerLogged(playerid) {
  return !!gPlayerLogged{playerid};
}

stock TogglePlayerLogged(playerid) {
  return IsPlayerLogged(playerid) ? gPlayerLogged{playerid} = 1 : 0
}