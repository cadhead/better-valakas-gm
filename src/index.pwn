#include <a_samp>
#include <a_mysql>
#include <sscanf2>
#include <streamer>
#include <Pawn.CMD>
#include <foreach>
#include <formatex>
#include <mdialog>
#include <zmessage>

#include "./config"
#include "./store/index"

#include "./lib/colors"

main() {
  DB_Connect(DB_HOST, DB_USER, DB_PASS, DB_DBNAME);
}

public OnGameModeInit() {
  SetGameModeText(GAMEMODE_TEXT);
  ShowNameTags(1);
  AllowInteriorWeapons(1);
  EnableStuntBonusForAll(0);
  // DisableInteriorEnterExits();

  AddPlayerClass(2, 1958.3783, 1343.1572, 15.3746, 269.1425, 0, 0, 0, 0, 0, 0);

  return 1;
}

public OnPlayerConnect(playerid) {
  return 1;
}
