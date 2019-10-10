#define _GNU_SOURCE
#include <dlfcn.h>
#include <libinput.h>

typedef const char *(*orig_get_name_t)(struct libinput_device *device);

const char *libinput_device_get_name(struct libinput_device *device)
{
    // Setting the scroll button to 0 effectively disables this feature
    libinput_device_config_scroll_set_button(device, 0);
    orig_get_name_t orig_get_name;
    orig_get_name = (orig_get_name_t) dlsym(RTLD_NEXT, "libinput_device_get_name");
    return orig_get_name(device);
}
