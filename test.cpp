#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "test.h"

using namespace std;

test_mysql_db::test_mysql_db()
{
	host = "192.168.88.129";
	user = "root";
	passwd = "123456";
	db_name = "simple";
	port = 3306;
	client_flag = 0;
}

test_mysql_db::~test_mysql_db()
{
	mysql_db_test.mysql_db_close();
}

int test_mysql_db::write_mysql_db()
{
	// int result;
	char ch_sql[2048];

	memset(ch_sql, 0, sizeof(ch_sql));

	snprintf(ch_sql, sizeof(ch_sql), "INSERT INTO student_test (name, school_num, age, grade, weight, height) VALUES ('%s', %d, %d, '%s', %lf, %d)", "LiMing", 11010933, 21, "B", 69.5, 176);

	// mysql_db_test.exe_mysql_db(ch_sql);

	return 0;
}

int test_mysql_db::read_mysql_db()
{
	char ch_sql[2048];
	string str = "SELECT * FROM student_test";

	memset(ch_sql, 0, sizeof(ch_sql));

	memcpy(ch_sql, str.c_str(), str.size());

	mysql_db_test.read_mysql_db_from_table(ch_sql);

	return 0;
}


int test_mysql_db::start_test_mysql_db()
{
	int result;

	result = mysql_db_test.mysql_db_connect(host.c_str(), user.c_str(), passwd.c_str(), db_name.c_str(), port, unix_socket.c_str(), client_flag);
	if (result < 0)
	{
		return -1;
	}
	
	write_mysql_db();

	read_mysql_db();

	return 0;
}

int main(int argc, char *argv[])
{
	int result ;
	test_mysql_db test;

	result = test.start_test_mysql_db();
	if (result < 0)
	{
		return -1;
	}

	return 0;
}

