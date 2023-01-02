#include <stdio.h>

#include <internal_client/internal_client.h>



int main() {
	int return_code;
	void *context = init_connection("192.168.1.4", 54, "green button", 5, "left_side", 1);
	return_code = send_status(context, NULL, 0, 10);
	return_code = get_command(context, NULL, 0);
	return_code = destroy_connection(NULL);
	return 0;
}
