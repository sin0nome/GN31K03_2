#pragma comment(lib, "ws2_32.lib")

#include <WinSock2.h>
#include <stdio.h>


struct TestData {
	union {
		unsigned int intData;
		unsigned char charData[4];
	};
};

int main(void) {
	TestData test{};

	test.intData = 0x11223344;

	printf_s("\nlittleendian \n");

	for(int i = 0; i < 4; ++i) {
		printf_s("addr:%p data:%04x\n", &(test.charData[i], test.charData[i]));
	}

	test.intData = htonl(test.intData);

	printf_s("\networlbyte order bigendian\n");

	for(int i = 0; i < 4; ++i) {
		printf_s("addr:%p data:%04x\n", &(test.charData[i], test.charData[i]));
	}


	int s = getchar();
}

