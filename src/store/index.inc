#if defined _store_included
	#endinput
#endif

#define _store_included

#include "./store/player"

static MySQL:gConnectionHandle;

stock DB_Connect(const host[], const user[], const pass[], const db[]) {
  gConnectionHandle = mysql_connect(host, user, pass, db);

  mysql_log();

  printf("Database %s", mysql_errno() == -1 
    ? ("was not connected.") 
    : ("sucessfuly connected."))
  ;
}

stock DB_ConnectionClose() {
  return mysql_close(gConnectionHandle);
}

stock DB_GetHandle() {
  return gConnectionHandle;
}
