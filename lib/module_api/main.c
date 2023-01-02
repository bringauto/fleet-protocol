#include <stdio.h>

#include <module_client/module_client.h>

int main() {
    int return_code;
    void *context = init("192.168.1.4",54,"green button", 1);
    return_code = send_status(context, NULL, 0, 10);
    return_code = get_command(context, NULL, 0);
    return_code = destroy(NULL);
    return 0;
}
