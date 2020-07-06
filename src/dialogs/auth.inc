#if defined _dialogs_auth_included
	#endinput
#endif

#define _dialogs_auth_included

static const
  gLoginDialogText[] = "\
  \\c{FFFFFF}Добро пожаловать на{F44336} "SERVER_NAME"\n\n\
  \n{FFF666}Имя персонажа: {FFFFFF}%s\n\
  \n{FFF666}Введите ваш пароль:",
  gRegDialogText[] = "\
  \\c{FFFFFF}Добро пожаловать на{F44336} "SERVER_NAME"\n\n\
  \n{FFF666}Имя персонажа: {FFFFFF}%s\n\
  \n{F44336}Персонаж не зарегистрирован\n\
  \n{FFF666}Введите пароль:"
;

DialogCreate:Login(playerid) {
  static
    str[sizeof(gLoginDialogText) + MAX_PLAYER_NAME + 20 + 1]
  ;

  format(str, sizeof str, gLoginDialogText, "gFormatedCharacterName[playerid]");

  Dialog_Open(playerid, Dialog:Login, DIALOG_STYLE_PASSWORD,
    "Авторизация",
    str,
    DIALOG_OK, ""
  );
}

DialogResponse:Login(playerid, response, listitem, inputtext[]) {
  if (!response) 
    return Dialog_Show(playerid, Dialog:Login);

  ShowAuthMessage(playerid, AUTH_MESSAGE_GREETINGS);

  return 1;
}

DialogCreate:Registration(playerid) {
  static
    str[sizeof(gLoginDialogText) + MAX_PLAYER_NAME + 20 + 1]
  ;

  format(str, sizeof str, gLoginDialogText, "gFormatedCharacterName[playerid]");

  Dialog_Open(playerid, Dialog:Login, DIALOG_STYLE_PASSWORD,
    "Авторизация",
    str,
    DIALOG_OK, ""
  );
}
