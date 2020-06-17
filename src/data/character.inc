#if defined _data_character_included
	#endinput
#endif

#define _data_character_included

enum e_Character_Info {
  e_cID,
  e_cUCP,
  e_cName[MAX_PLAYER_NAME + 1],
  e_cCash,
  e_cPhone,
  e_cSkin,
  Float:e_cHP,
  e_cFaction,
  e_cLevel,
  Float:e_cPosX,
  Float:e_cPosY,
  Float:e_cPosZ,
  Float:e_cPosA,
  e_cPosWorld,
  e_cPosInterior,
  e_cSpawnPointType,
  e_cLicenseCar,
  e_cLicenseWater,
  e_cLicensePilot
}

new
  Character[MAX_PLAYERS][e_Character_Info],
  gFormatedCharacterName[MAX_PLAYERS][MAX_PLAYER_NAME + 1]
;

static
  gCharacterNULL[e_Character_Info]
;

static FormatCharacterName(playerid) {
  new name[MAX_PLAYER_NAME + 1];

  GetPlayerName(playerid, name);

  for (new i = 0; i < MAX_PLAYER_NAME; i++) {
    if (name[i] == '_') name[i] = ' ';
  }

  strcopy(gFormatedCharacterName[playerid], name);
}

stock bool:IsCharacterNew(playerid) {
  return !!(
    (Character[playerid][e_cPosX] == 0) &
    (Character[playerid][e_cPosY] == 0) &
    (Character[playerid][e_cPosZ] == 0) &
    (Character[playerid][e_cPosA] == 0)
  );
}

stock GenerateCharacterPhoneNumber(playerid) {
  Character[playerid][e_cPhone] = 10000 + random(89999);
}

stock SetCharacterDefaultSettings(playerid) {
  Character[playerid][e_cPosX] = DEFAULT_CHARACTER_POS_X;
  Character[playerid][e_cPosY] = DEFAULT_CHARACTER_POS_Y;
  Character[playerid][e_cPosZ] = DEFAULT_CHARACTER_POS_Z;
  Character[playerid][e_cPosA] = DEFAULT_CHARACTER_POS_A;
  Character[playerid][e_cPosWorld] = DEFAULT_CHARACTER_POS_WORLD;
  Character[playerid][e_cPosInterior] = DEFAULT_CHARACTER_POS_INT;
  Character[playerid][e_cCash] = DEFAULT_CHARACTER_CASH;
  
  GenerateCharacterPhoneNumber(playerid);

  UpdateCharacterData(playerid);
}

stock FetchCharacterData(playerid) {

}

stock ClearCharacterData(playerid) {

  Character[playerid] = gCharacterNULL;

  return 1;
}

stock UpdateCharacterData(playerid) {
}

public OnCharacterDataLoad(playerid) {
  if (IsCharacterNew(playerid)) {
    SetCharacterDefaultSettings(playerid);
  }

  return 1;
}
