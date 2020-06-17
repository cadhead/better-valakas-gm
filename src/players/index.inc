#if defined __players_included
	#endinput
#endif

#define __players_included

#include "./players/account"
//#include "./players/character"
#include "./players/temp-reg"

public OnPlayerRequestAuth(playerid, error) {
  switch (error) {
    case ACCOUNT_DATA_ERROR_OK: {
      Dialog_Show(playerid, Dialog:Login);
    }
    case ACCOUNT_DATA_ERROR_NOT_EXIST: {
      #if ALLOW_INGAME_REGISTRATION
        Dialog_Show(playerid, Dialog:Registration);
      #else
        ShowAuthMessage(playerid, AUTH_MESSAGE_NOT_EXIST);
      #endif
    }
    default: {
      ShowAuthMessage(playerid, AUTH_MESSAGE_WHOKNOWS);
      Kick(playerid);
    }
  }

  return 1;
}