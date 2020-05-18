# Minimal init

This is an updated, nommu-compatible version of my minimal init,
adapted from the version originally published on ewontfix.com.

All it does it run `/etc/rc` on startup and reap orhaned processes
as they exit. It does not do any process supervision.

The `respawn` utility also included is a minimal process supervisor.
It's not intended for any elaborate supervision, mainly running gettys
for login, started from `/etc/rc` in place of a traditional `inittab`.
The entire command line `argv[1]` to `argv[argc]` is the command that
is executed repeatedly, so `argv[1]` should be an absolute pathname.
Bad Things will happen if it's a program which daemonizes itself.
