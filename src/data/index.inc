#if defined _store_included
	#endinput
#endif

#define _store_included

#include "./data/character"

static MySQL:gConnectionHandle;

public DB_Connect(const host[], const user[], const pass[], const db[]) {
  new MySQLOpt:option_id = mysql_init_options();
  mysql_set_option(option_id, AUTO_RECONNECT, true);

  gConnectionHandle = mysql_connect(host, user, pass, db);

  mysql_log();

  printf("Database %s", mysql_errno() == -1 
    ? ("was not connected.") 
    : ("sucessfuly connected."))
  ;
}

public DB_ConnectionClose() {
  return mysql_close(gConnectionHandle);
}

public MySQL:DB_GetHandle() {
  return gConnectionHandle;
}
