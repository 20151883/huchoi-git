#! /bin/bash
VALUE="delete" #대입연산자 기준으로 공백이 있으면 안됨
VALUE2=$1
rm -rf ./vector.hpp ./stack.hpp ./map.hpp ./etc.hpp
if [ $# -eq 1 ];then
	echo "ONLY DELETE"
else
	echo "DELTE AND COPY"
	cp ./vector/vector.hpp . && cp vector.hpp ft_containers/ && cp vector.hpp qqqq/
	cp ./stack/stack.hpp . && cp stack.hpp ft_containers/ && cp stack.hpp qqqq/
	cp ./map/map.hpp . && cp map.hpp ft_containers/ && cp map.hpp qqqq/
	cp ./etc/etc.hpp . && cp etc.hpp ft_containers/ && cp etc.hpp qqqq/

fi