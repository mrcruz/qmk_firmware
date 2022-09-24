BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover

# optional features
TAP_DANCE_ENABLE = yes
KEY_OVERRIDE_ENABLE = no
AUTO_SHIFT_ENABLE = no
COMBO_ENABLE = no
LEADER_ENABLE = no
KEY_LOCK_ENABLE = no
SWAP_HANDS_ENABLE = no
UNICODE_ENABLE = no

# trackball
# POINTING_DEVICE_ENABLE = yes
# POINTING_DEVICE_DRIVER = pmw3360
# MOUSE_SHARED_EP = no # Unify multiple HID interfaces into a single Endpoint # https://qmk.fm/changes/2018-11-16-use-a-single-endpoint-for-hid-reports

# Disable unsupported hardware
BACKLIGHT_ENABLE = no
RGBLIGHT_ENABLE = no
AUDIO_ENABLE = no
AUDIO_SUPPORTED = no
BACKLIGHT_SUPPORTED = no

# optmization to reduce firmware size
# EXTRAFLAGS += -flto
LTO_ENABLE = yes
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
