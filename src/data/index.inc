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

  mysql_log(ALL);

  printf("%s to database.", mysql_errno() == -1 
    ? ("Can't connect to") 
    : ("Successfully connected"))
  ;
}

public DB_ConnectionClose() {
  return mysql_close(gConnectionHandle);
}

public MySQL:DB_GetHandle() {
  return gConnectionHandle;
}
