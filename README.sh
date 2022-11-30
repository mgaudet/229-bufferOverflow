This contains some buffer overflow demo code. 

It's extremely rough. 

- noaslr_bash disables ASLR on linux
- spawn.c attempts to do same on macos; use resulting spawn executable to spawn another program with ASLR disabled. 
