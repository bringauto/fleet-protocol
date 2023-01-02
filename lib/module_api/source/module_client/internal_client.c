#include <internal_client/internal_client.h>

#include <stdio.h>

void *init_connection(const char *ipv4_address, unsigned port, char *device_name, unsigned device_type, char *device_role, unsigned device_priority){
    return NULL;
}

int destroy_connection(void **context){
    return -1;
}

int send_status(void *context, void *device_status, unsigned status_size, unsigned timeout){
    return -1;
}

int get_command(void *context, void *device_command, unsigned command_size){
    return -1;
}