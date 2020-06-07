#if defined _config_included
	#endinput
#endif

#define _config_included

#define DB_HOST    "remotemysql.com"
#define DB_PORT    "3306"
#define DB_USER    "j91PWkM3Xp"
#define DB_PASS    "nrDGCaFZZd"
#define DB_DBNAME  "j91PWkM3Xp"

#if defined MAX_PLAYERS
	#undef MAX_PLAYERS
	#define MAX_PLAYERS 150
#endif

#define MAX_STRING   128
#define MAX_UCP_NAME 30
#define MAX_IP       16

#define ONE_MINUTE (1000 * 60)
#define ONE_HOUR   (ONE_MINUTE * 60)

#define MODE_NAME     "better-valakas"
#define VERSION_MAJOR 0
#define VERSION_MINOR 0
#define VERSION_BUILD 0
#define VERSION_EXTRA ""

#define VERSION_STRING "v" #VERSION_MAJOR "." #VERSION_MINOR "." #VERSION_BUILD VERSION_EXTRA
#define GAMEMODE_TEXT  MODE_NAME " " VERSION_STRING

#define WORLD_SAVE_TIME ONE_MINUTE * 5

#define KEY_USING  KEY_YES
#define KEY_CANCEL KEY_NO

#define ALLOWED_STRING_SYMBOLS     'a'..'z','A'..'Z','0'..'9','_','[',']','=','(',')',' '
#define ALLOWED_STRING_SYMBOLS_STR "'a'..'z','A'..'Z','0'..'9','_','[',']','=','(',')',' '"
#define ALLOWED_NICK_SYMBOLS       'a'..'z','A'..'Z','0'..'9','_','[',']','.','=','(',')'
#define ALLOWED_NICK_SYMBOLS_STR   "'a'..'z','A'..'Z','0'..'9','_','[',']','.','=','(',')'"

#define MAX_PLAYER_PASSWORD      30
#define MAX_PLAYER_LOGIN_ATTEMPT 3
#define MAX_LOGIN_TIME           120

#define PASSWORD_SALT_LENGTH  12
#define PASSWORD_HASH_LENGTH  64

#define DEFAULT_ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"

#define MAX_MONEY_CASH    1000000000
#define MAX_MONEY_BANK    1000000000
#define MAX_BANK_ACCOUNTS 3

#define SYS_WEATHER_UPDATE ONE_HOUR

#define INTERIOR_FREEZE_DELAY 1000

#define SKINS_COST   0
#define SKINS_IGNORE 0, 74
#define SKINS_MAX    310

#define HOUSE_UNLOGIN_SELL_DAYS    21
#define VEHICLE_UNLOGIN_SELL_DAYS  21
#define BUSINESS_UNLOGIN_SELL_DAYS 14

#define FACTION_MAX_NAME    40
#define FACTION_MAX_MEMBERS 20
#define FACTION_MAX_RANKS   20
#define FACTION_MAX_BANK    1000000000
#define FACTION_MAX_MOTD    64

#define DEFAULT_CHARACTER_POS_X     1715.7280
#define DEFAULT_CHARACTER_POS_Y     -1936.9874
#define DEFAULT_CHARACTER_POS_Z     13.5833
#define DEFAULT_CHARACTER_POS_A     2.0400
#define DEFAULT_CHARACTER_POS_WORLD 0
#define DEFAULT_CHARACTER_POS_INT   0
#define DEFAULT_CHARACTER_CASH      500

enum CoordInfo {
	Float:Coord_X,
	Float:Coord_Y,
	Float:Coord_Z
}
