#if defined _data_included
	#endinput
#endif

#define _data_included

#include "./data/account"
#include "./data/character"

static MySQL:gConnectionHandle;

public DB_Connect(const host[], const user[], const pass[], const db[]) {
  new MySQLOpt:option_id = mysql_init_options();
  mysql_set_option(option_id, AUTO_RECONNECT, true);

  gConnectionHandle = mysql_connect(host, user, pass, db);
  mysql_tquery(gConnectionHandle, !"SET CHARACTER SET 'utf8'", "", "");
  mysql_tquery(gConnectionHandle, !"SET NAMES 'utf8'", "", "");
  mysql_tquery(gConnectionHandle, !"SET character_set_client = 'cp1251'", "", "");
  mysql_tquery(gConnectionHandle, !"SET character_set_connection = 'cp1251'", "", "");
  mysql_tquery(gConnectionHandle, !"SET character_set_results = 'cp1251'", "", "");
  mysql_tquery(gConnectionHandle, !"SET SESSION collation_connection = 'utf8_general_ci'", "", "");

  // mysql_log(ALL);

  switch(mysql_errno()) {
    case 0: print("Successfully connected to database.");
    case 1044: print("Can't connect to database. [Wrong username]");
    case 1045: print("Can't connect to database. [Wrong password]");
    case 1049: print("Can't connect to database. [Not valid DB]");
    case 2003: print("Can't connect to database. [Can't connect to host]");
    case 2005: print("Can't connect to database. [Wrong host]");
    default: printf("Can't connect to database. [Unsigned error, code: %d]", mysql_errno());
  }
}

public DB_ConnectionClose() {
  return mysql_close(gConnectionHandle);
}

public MySQL:DB_GetHandle() {
  return gConnectionHandle;
}
