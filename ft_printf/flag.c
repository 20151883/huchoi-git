#include <stdio.h>
#include <string.h>

int main(void)
{
	int num = 42;
	char arr[7];

	strcpy(arr, "string");
	printf("%08.5d\n",num);
//	printf("%05.10s\n", arr);//ssh에서 결과예측 불가능이라고 실행 안시켜줌
    printf("%-3.5s\n",arr);
    printf("%-6.3s\n",arr);
    printf("%-8.6s\n",arr);
    printf("%-8.8s\n",arr);
	return(0);
}//결론 폭에서 남는공간은 항상 스페이스로 채워진다
//결국 마지막부분의 코드는 동일할 것이라는 예상이 맞았다.

