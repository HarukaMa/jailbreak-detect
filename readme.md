# Jailbreak detection

Just used inline asm to directly do a syscall so you almost can't detour it unless you crack the app itself or go into the kernel to catch it.

The MSB of return value is error bit and remaining bits are `errno`. If the target file does not exist, it should return `0x80000002` which means `ENOENT`. Any other result could mean the device is jailbroken.

The code here is hardcoded to look for file `/var/lib/dpkg/status`, but you can easily modify it and run a loop through a list of files.

Also make sure that your outer logic won't be simply bypassed by Flex.

I did not invent the method.

If you decide to use this method, please bear in mind that people jailbreak their devices for various reasons. I'd recommend to only use this method on critical business logic (like $$$ related parts) or abuse prevention. It's rude if you just close your doors to all jailbroken users.