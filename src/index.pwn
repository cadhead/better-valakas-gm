#include <a_samp>
#include <a_mysql>
#include <sscanf2>
#include <streamer>
#include <Pawn.CMD>

#include "./config"
#include "./lib/colors"

main() {  }

public OnGameModeInit() {
  SetGameModeText(GAMEMODE_TEXT);

  return 1;
}

public OnPlayerConnect(playerid) {
  SendClientMessage(playerid, COLOR_BLUEGREY_200, "COLOR_BLUEGREY_200");
  SendClientMessage(playerid, COLOR_TEAL_400, "COLOR_TEAL_400");
  SendClientMessage(playerid, COLOR_RED_500, "COLOR_RED_500");
  SendClientMessage(playerid, COLOR_BLUE_500, "COLOR_BLUE_500");

  return 1;
}
