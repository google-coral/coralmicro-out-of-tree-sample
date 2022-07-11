#include "libs/base/filesystem.h"
#include "libs/base/ipc_m7.h"
#include "third_party/freertos_kernel/include/FreeRTOS.h"
#include "third_party/freertos_kernel/include/task.h"
#include <cstdio>
#include <cstring>

extern "C" void app_main(void *param) {
    ssize_t source_size = coralmicro::filesystem::Size("/hello_world_cm7.cc");
    ssize_t model_size = coralmicro::filesystem::Size("/models/testconv1-edgetpu.tflite");
    coralmicro::IPCM7::GetSingleton()->StartM4();
    while (true) {
        printf("[M7] Hello. Source file size: %d bytes Model file size: %d\r\n", source_size, model_size);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
