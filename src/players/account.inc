#if defined _players_acc_included
	#endinput
#endif

#define _players_acc_included


#define AUTH_MESSAGE_NOT_EXIST 0
#define AUTH_MESSAGE_GREETINGS 1
#define AUTH_MESSAGE_WHOKNOWS  2

new gAuthMessages[][][] = {
  {"Персонаж %s не зарегистрирован на сервере!",
  "Для регистрации перейдите на better-valakas.ru"},

  {"Добро пожаловать, %s!", ""},

  {"Произошла неизвестная ошибка!",
  "Попробуйте перезайти в игру и залогинится ещё раз."}
};

stock ShowAuthMessage(playerid, type) {
  if (type >= sizeof gAuthMessages) return 0;

  static auth_message[MAX_STRING + MAX_PLAYER_NAME + 1];

  for (new i = 0; i < 2; i++) {
    if (!!gAuthMessages[type][i][0]) {
      format(
        auth_message,
        sizeof auth_message,
        gAuthMessages[type][i],
        gFormatedCharacterName[playerid]
      );

      SendClientMessage(playerid, COLOR_YELLOW, auth_message);
    }
  }

  return 1;
}
