#include <module_client/module_client.h>

#include <stdio.h>

void *init(const char *ipv4_address, unsigned port, char *device_name, unsigned device_type){
    return NULL;
}

int destroy(void **context){
    return -1;
}

int send_status(void *context, void *device_status, unsigned status_size, unsigned timeout){
    return -1;
}

int get_command(void *context, void *device_command, unsigned command_size){
    return -1;
}