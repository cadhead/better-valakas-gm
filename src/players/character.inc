#if defined _players_character_included
	#endinput
#endif

#define _players_character_included

stock SpawnCharacter(playerid) {
  SetSpawnInfo(playerid,
    NO_TEAM,
    gCharacter[playerid][e_Skin],
    gCharacter[playerid][e_PosX],
    gCharacter[playerid][e_PosY],
    gCharacter[playerid][e_PosZ],
    gCharacter[playerid][e_PosA],
    0, 0, 0, 0, 0, 0
  );

  TogglePlayerSpectating(playerid, false);
  SpawnPlayer(playerid);

  GivePlayerMoney(playerid, gCharacter[playerid][e_Cash]);
  SetPlayerVirtualWorld(playerid, gCharacter[playerid][e_PosWorld]);
  SetPlayerInterior(playerid, gCharacter[playerid][e_PosInterior]);
}

stock SetCharacterHealth(playerid, &Float:health) {
  gCharacter[playerid][e_HP] = health;
  return SetPlayerHealth(playerid, health);
}

stock SetCharacterMoney(playerid, amount) {
  gCharacter[playerid][e_Cash] = amount;
  ResetPlayerMoney(playerid);
  GivePlayerMoney(playerid, amount);
}

stock ChangeCharacterMoney(playerid, amount, bool:flag) {
  gCharacter[playerid][e_Cash] = flag
    ? gCharacter[playerid][e_Cash] + amount
    : gCharacter[playerid][e_Cash] - amount
  ;

  ResetPlayerMoney(playerid);
  GivePlayerMoney(playerid, gCharacter[playerid][e_Cash]);
}
