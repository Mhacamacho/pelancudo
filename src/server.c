#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <signal.h>
#include <fcntl.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <netinet/in.h>
#include <stdio.h>

int main() {
	struct ifaddrs * MyAddr;
	struct ifaddrs * temp;
	char names[INET_ADDRSTRLEN];

	getifaddrs(&MyAddr);
	for(temp = MyAddr; temp != NULL; temp = temp->ifa_next)	{
		inet_ntop(AF_INET, &((struct sockaddr_in *) temp->ifa_addr)->sin_addr, names, INET_ADDRSTRLEN);
		printf("ifa_name: %s\nifa_addr: %s\n",temp->ifa_name, names);
	}
}
	

