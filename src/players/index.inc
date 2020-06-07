#include "./players/account"

public OnRegisteredPlayerConnect(playerid) {
  SetSpawnInfo(playerid,
    NO_TEAM,
    gCharacter[playerid][e_Skin],
    gCharacter[playerid][e_PosX],
    gCharacter[playerid][e_PosY],
    gCharacter[playerid][e_PosZ],
    gCharacter[playerid][e_PosA],
    0, 0, 0, 0, 0, 0
  );

  SpawnPlayer(playerid);

  GivePlayerMoney(playerid, gCharacter[playerid][e_Cash]);
  CreateVehicle(
    522,
    gCharacter[playerid][e_PosX],
    gCharacter[playerid][e_PosY],
    gCharacter[playerid][e_PosZ],
    gCharacter[playerid][e_PosA],
    0,
    0,
    0
  );

  return 1;
}