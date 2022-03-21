cpp = g++
cxxflas = -g -Wall
target = operating_database
source = $(wildcard ./*.cpp)
head_file = (wildcard ./*.h)

lib_mysql = /usr/lib/i386-linux-gnu/
head_file_mysql = /usr/include/mysql/

object = $(patsubst %.cpp, %.o, $(source))

$(target) : $(object)
	$(cpp) $(cxxflas) $^ -o $@ -L $(lib_mysql) -lmysqlclient

$(object) : %.o : %.cpp
	$(cpp) -c $(cxxflas) -I $(head_file_mysql)  $< -o $@ 

clean:
	rm -rf *.o $(target)

