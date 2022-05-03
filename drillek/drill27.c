#include <stdio.h>



void func(char *p, int x);

int main(){

	printf("Hello, World!\n");

	char hello[] = "Hello";
	char world[] = "World!";

	printf("%s %s\n",hello,world);

	func("foo",7);

	return 0;

}

void func(char *p, int x){
	printf("p is \"%s\" and x is %d\n",p,x);
}