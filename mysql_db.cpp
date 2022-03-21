#include <iostream>
#include "mysql_db.h"

using namespace std;

mysql_db::mysql_db()
{

}

mysql_db::~mysql_db()
{

}

// 连接数据库
int mysql_db::mysql_db_connect(const char *host, const char *user, const char *passwd, const char *db_name, unsigned prot, 
										const char* unix_socket, unsigned long clientflag)
{
	res = mysql_init(&m_mysql_conn);
	if (!res)
	{
		cout << "mysql init error!" << endl;
		return -1;
	}

	res = mysql_real_connect(&m_mysql_conn, host, user, passwd, db_name, prot, unix_socket, clientflag);
	if (res == NULL)
	{
		cout << "connect error!" << endl;
		return -1;
	}

	cout << "connect ok" << endl;

	return 0;
}

// 执行mysql语言，向数据库中写入数据
int mysql_db::exe_mysql_db(char *exe_str)
{
	int ret;

	ret = mysql_query(&m_mysql_conn, exe_str);
	if (ret != 0)
	{
		cout << "write database error!" << endl;
		cout << exe_str << endl;
		return ret;
	}

	return ret;
}

// 从数据库中读取数据
int mysql_db::read_mysql_db_from_table(const char *exe_str)
{
	int num;
	int i;

	mysql_query(&m_mysql_conn, exe_str);

	result_read = mysql_store_result(&m_mysql_conn);
	if (!result_read)
	{
		cout << "read result error!" << endl;
		cout << exe_str << endl;
		return -1;
	}

	num = mysql_num_fields(result_read);
	for (i = 0; i < num; i++)
	{
		field =  mysql_fetch_field_direct(result_read, i);
		cout << field->name << "\t\t";
	}

	cout << endl;

	while ((row = mysql_fetch_row(result_read)) != NULL)
	{
 		for (i = 0; i < num; i++)
 		{
			cout << row[i] << "\t\t";
		}
		cout << endl;
	}	

	return 0;
}

// 断开数据库
int mysql_db::mysql_db_close()
{
	mysql_close(&m_mysql_conn);

	return 0;
}

