#pragma once

#include "mysql.h"

class mysql_db
{
public:
	mysql_db();
	~mysql_db();

public:
	int mysql_db_connect(const char *host, const char *user, const char *passwd, const char *db_name, unsigned prot, 
										const char* unix_socket, unsigned long clientflag);

	int mysql_db_close();

	int exe_mysql_db(char *exe_str);

	int read_mysql_db_from_table(const char *exe_str);

private:
	MYSQL m_mysql_conn;
	MYSQL *res;
	MYSQL_RES *result_read;
	MYSQL_FIELD *field;
	MYSQL_ROW row;

};



