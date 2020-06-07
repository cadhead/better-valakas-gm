#if defined _store_character_included
	#endinput
#endif

#define _store_character_included

enum e_Character_Info {
  ORM:e_ORM,
  e_ID,
  e_UCP,
  e_Name[MAX_PLAYER_NAME + 1],
  e_Cash,
  e_Skin,
  Float:e_HP,
  e_Faction,
  e_Level,
  Float:e_PosX,
  Float:e_PosY,
  Float:e_PosZ,
  Float:e_PosA,
  e_PosWorld,
  e_PosInterior,
  e_SpawnPointType,
  e_Imprisoned,
  e_DeMorgan
}

new gCharacter[MAX_PLAYERS][e_Character_Info];

static gCharacterNULL[e_Character_Info];
static gPlayerLogged[MAX_PLAYERS char];
new gFormatedCharacterName[MAX_PLAYERS][MAX_PLAYER_NAME + 1];

static FormatCharacterName(playerid) {
  new name[MAX_PLAYER_NAME + 1];

  GetPlayerName(playerid, name);

  for (new i = 0; i < MAX_PLAYER_NAME; i++) {
    if (name[i] == '_') name[i] = ' ';
  }

  strcopy(gFormatedCharacterName[playerid], name);
}

stock bool:IsPlayerLogged(playerid) {
  return !!gPlayerLogged{playerid};
}

stock TogglePlayerLogged(playerid) {
  return IsPlayerLogged(playerid)
    ? gPlayerLogged{playerid} = 1
    : gPlayerLogged{playerid} = 0
  ;
}

stock bool:IsCharacterNew(playerid) {
  return !!(
    (gCharacter[playerid][e_PosX] == 0) &
    (gCharacter[playerid][e_PosY] == 0) &
    (gCharacter[playerid][e_PosZ] == 0) &
    (gCharacter[playerid][e_PosA] == 0)
  );
}

stock SetCharacterDefaultSettings(playerid) {
  gCharacter[playerid][e_PosX] = DEFAULT_CHARACTER_POS_X;
  gCharacter[playerid][e_PosY] = DEFAULT_CHARACTER_POS_Y;
  gCharacter[playerid][e_PosZ] = DEFAULT_CHARACTER_POS_Z;
  gCharacter[playerid][e_PosA] = DEFAULT_CHARACTER_POS_A;
  gCharacter[playerid][e_PosWorld] = DEFAULT_CHARACTER_POS_WORLD;
  gCharacter[playerid][e_PosInterior] = DEFAULT_CHARACTER_POS_INT;
  gCharacter[playerid][e_Cash] = DEFAULT_CHARACTER_CASH;
}

stock SetCharacterInfo(playerid) {
  new ORM:ormid = orm_create(
    "characters",
    DB_GetHandle()
  );

  gCharacter[playerid][e_ORM] = ormid;

  GetPlayerName(playerid, gCharacter[playerid][e_Name]);
  FormatCharacterName(playerid);

  orm_addvar_int(ormid, gCharacter[playerid][e_ID], "ID");
  orm_addvar_int(ormid, gCharacter[playerid][e_UCP], "UCP");
  orm_addvar_string(ormid, gCharacter[playerid][e_Name], MAX_PLAYER_NAME + 1, "Name");

  orm_addvar_int(ormid, gCharacter[playerid][e_Faction], "Faction");
  orm_addvar_int(ormid, gCharacter[playerid][e_Cash], "Cash");
  orm_addvar_float(ormid, gCharacter[playerid][e_HP], "HP");
  orm_addvar_int(ormid, gCharacter[playerid][e_Skin], "Skin");
  orm_addvar_int(ormid, gCharacter[playerid][e_Level], "Level");

  orm_addvar_float(ormid, gCharacter[playerid][e_PosX], "PosX");
  orm_addvar_float(ormid, gCharacter[playerid][e_PosY], "PosY");
  orm_addvar_float(ormid, gCharacter[playerid][e_PosZ], "PosZ");
  orm_addvar_float(ormid, gCharacter[playerid][e_PosA], "PosA");
  orm_addvar_int(ormid, gCharacter[playerid][e_PosWorld], "PosWorld");
  orm_addvar_int(ormid, gCharacter[playerid][e_PosInterior], "PosInterior");
  orm_addvar_int(ormid, gCharacter[playerid][e_SpawnPointType], "SpawnPointType");

  orm_addvar_int(ormid, gCharacter[playerid][e_Imprisoned], "Imprisoned");
  orm_addvar_int(ormid, gCharacter[playerid][e_DeMorgan], "DeMorgan");

  orm_setkey(gCharacter[playerid][e_ORM], "Name");
  orm_load(ormid, "OnPlayerDataLoad", "d", playerid);
}

stock ClearCharacterInfo(playerid) {
  gCharacter[playerid] = gCharacterNULL;
  
  orm_save(gCharacter[playerid][e_ORM]);
  orm_destroy(gCharacter[playerid][e_ORM]);

  return 1;
}

stock UpdateCharacterInfo(playerid) {
  orm_update(gCharacter[playerid][e_ORM]);	
}

public OnPlayerDataLoad(playerid) {
  switch(orm_errno(gCharacter[playerid][e_ORM])) {
    case ERROR_OK: {
      if (IsCharacterNew(playerid)) {
        SetCharacterDefaultSettings(playerid);
        UpdateCharacterInfo(playerid);
      }

      OnRegisteredPlayerConnect(playerid);
    }
    case ERROR_NO_DATA: {
      static str[41 + MAX_PLAYER_NAME + 1];

      format(
        str,
        sizeof str,
        "Аккаунт %s не зарегистрирован на сервере!",
        gFormatedCharacterName[playerid]
      );

      SendClientMessage(playerid, COLOR_YELLOW, str);
      SendClientMessage(playerid, COLOR_YELLOW, "Для регистрации перейдите на better-valakas.ru");

      Kick(playerid);
    }
  }

  return 1;
}
