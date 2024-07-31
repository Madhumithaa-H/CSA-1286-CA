#include <stdio.h>

#define NUM_DEVICES 4

// Function to simulate the device requesting the bus
void request_bus(int device_id) {
    
}

// Function to simulate the device releasing the bus
void release_bus(int device_id) {
    printf("Device %d is accessing  the bus\n", device_id);
}

// Function to perform round-robin bus arbitration
void round_robin_arbitration() {
    int current_device = 0;

    for (int cycle = 0; cycle < 10; cycle++) { // Simulate 10 arbitration cycles
        request_bus(current_device);
        
        
        
        release_bus(current_device);

        // Move to the next device
        current_device = (current_device + 1) % NUM_DEVICES;
    }
}

int main() {
    round_robin_arbitration();
    return 0;
}
