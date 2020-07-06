#include <a_samp>
#include <a_mysql>
#include <sscanf2>
#include <streamer>
#include <Pawn.CMD>
#include <foreach>
#include <formatex>
#include <mdialog>

#define ZMSG_MAX_CHAT_LENGTH 80
#define ZMSG_MAX_PLAYER_CHAT_LENGTH 80
#define ZMSG_SEPARATORS_LIST ' '
#define ZMSG_HYPHEN_END   " ..."
#define ZMSG_HYPHEN_START "... "

#include <zmessage>

#include "./lib/colors"
#include "./lib/vSyncALS"
#include "./lib/dc_kickfix"

#include "./config"
#include "./headers"
#include "./data/index"

#include "./players/index"
#include "./dialogs/index"

#undef format
#define format formatex

main() {
  DB_Connect(DB_HOST, DB_USER, DB_PASS, DB_DBNAME);}

public OnGameModeInit() {
  SetGameModeText(GAMEMODE_TEXT);
  ShowNameTags(1);
  AllowInteriorWeapons(1);
  EnableStuntBonusForAll(0);

  AddPlayerClass(2,1715.7280,-1936.9874,13.5833,2.0400,0,0,0,0,0,0);
  CreateVehicle(522,1715.7280,-1936.9874,13.5833,2.04000,0,0, 0);

  return 1;
}

public OnPlayerConnect(playerid) {
  FetchAccountData(playerid);

  return 1;
}

public OnPlayerDisconnect(playerid, reason) {
  //ClearCharacterData(playerid);

  return 1;
}

public OnPlayerUpdate(playerid) {
  return 1;
}

public OnPlayerRequestClass(playerid, classid) {
  return 0;
}

public OnPlayerRequestSpawn(playerid) {
  return 0;
}

CMD:test(playerid) {
  SetPlayerInterior(playerid, 10);
  SetPlayerPos(playerid, 2269.8772, -1210.3240, 1047.5625);
}
