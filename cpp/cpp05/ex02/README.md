/usr/bin/ld: /tmp/ccXpPcLZ.o: in function `ShrubberyCreationForm::ShrubberyCreationForm()':
ShrubberyCreationForm.cpp:(.text+0x536): undefined reference to `Form::Form()'
collect2: error: ld returned 1 exit status

g++ -Wall -Werror -Wextra Bureaucrat.cpp Form.cpp main_pre.cpp PresidentialPardonForm.cpp
명령어 입력했을때 위 에러가 나온 이유: derived class 의 생성자에서 base class 의 생성자를 호출하지 않아서.