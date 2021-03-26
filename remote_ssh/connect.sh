#!/bin/sh

sh ~/remote_ssh/remote_code.sh
sleep 2
cat ~/.config/code-server/config.yaml
echo "\n"
chmod 400 ~/remote_ssh/mykey
sleep 1
sh ~/remote_ssh/remote_ssh.sh
sleep 1
echo "\n"
