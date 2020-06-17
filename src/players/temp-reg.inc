#if defined _players_tempreg_included
	#endinput
#endif

#define _players_tempreg_included

stock GenerateSalt(buf[], len = sizeof(buf)) {
  static const symbols[] = DEFAULT_ALPHABET;
  new size = sizeof symbols - 1;

  --len;

  for (new i = 0; i < len; i++) {
    buf[i] = symbols[random(size)];
  }

  buf[len] = '\0';

  return len;
}

public CreateAccount(playerid) {

}

public CreateCharacter(playerid) {

}
