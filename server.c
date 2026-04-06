#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, client_fd;
    struct sockaddr_in addr;
    char buffer[BUFFER_SIZE], response[BUFFER_SIZE];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr*)&addr, sizeof(addr));
    listen(server_fd, 5);

    printf("Server running on port %d\n", PORT);

    while (1) {
        client_fd = accept(server_fd, NULL, NULL);

        int bytes = recv(client_fd, buffer, BUFFER_SIZE, 0);
        buffer[bytes] = '\0';

        char op[10];
        int a, b;
        if (sscanf(buffer, "%s %d %d", op, &a, &b) != 3) {
            sprintf (response, "ERR invalid_input");
        } else if (strcmp(op, "add") == 0){
            sprintf(response, "OK %d", a + b);
        }else if (strcmp(op, "sub") == 0){
            sprintf(response, "OK %d", a - b);
        }else if (strcmp (op, "mul") == 0){
            sprintf(response, "OK %d", a * b);
        }else if (strcmp(op, "div") == 0){
            if (b==0) {
                sprintf(response, "ERR division_by_zero");
            }else {
                sprintf(response, "OK %d", a/b);
            }
        
        }else{
            sprintf(response, "ERR unsupported_operation");
        }

        send(client_fd, response, strlen(response), 0);
        close(client_fd);
    }
}
