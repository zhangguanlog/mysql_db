#pragma once
#include <string>
#include "mysql_db.h"

using namespace std;

class test_mysql_db
{
public:
	test_mysql_db();
	~test_mysql_db();

public:
	int start_test_mysql_db();

	int write_mysql_db();

	int read_mysql_db();

public:
	mysql_db mysql_db_test;
	string host;					// 主机ip
	string user;					// 登录用户
	string passwd;					// 登录密码
	string db_name;					// 数据库名称
	unsigned int port;				// 数据库端口号
	string unix_socket;				// 是否使用socket机制登录，NULL ，否
	unsigned long client_flag;		// 连接标指，通常为0;

private:



};
