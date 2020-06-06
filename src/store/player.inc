#if defined _store_player_included
	#endinput
#endif

#define _store_player_included

enum e_Player_Info {
  ORM:e_ORM,
  e_ID,
  e_UCP,
  e_Name[MAX_PLAYER_NAME + 1],
  e_Password[MAX_PLAYER_PASSWORD + 1],
  e_Cash,
  e_X,
  e_Y,
  e_Z,
  e_A,
  bool:e_Logged,
}

static
  gPlayer[MAX_PLAYERS][e_Player_Info],
  gPlayerNULL[e_Player_Info]
;
