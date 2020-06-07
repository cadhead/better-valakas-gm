#include <a_samp>
#include <a_mysql>
#include <sscanf2>
#include <streamer>
#include <Pawn.CMD>
#include <foreach>
#include <formatex>
#include <mdialog>
#include <zmessage>

#include "./lib/colors"
#include "./lib/vSyncALS"
#include "./lib/dc_kickfix"

#include "./config"
#include "./headers"
#include "./data/index"

#include "./players/index"

#undef format
#define format formatex

main() {
  DB_Connect(DB_HOST, DB_USER, DB_PASS, DB_DBNAME);
}

public OnGameModeInit() {
  SetGameModeText(GAMEMODE_TEXT);
  ShowNameTags(1);
  AllowInteriorWeapons(1);
  EnableStuntBonusForAll(0);
  // DisableInteriorEnterExits();

  AddPlayerClass(2,1715.7280,-1936.9874,13.5833,2.0400,0,0,0,0,0,0);

  return 1;
}

public OnPlayerConnect(playerid) {
  SetCharacterInfo(playerid);

  return 1;
}

public OnPlayerDisconnect(playerid, reason) {
  ClearCharacterInfo(playerid);

  return 1;
}
