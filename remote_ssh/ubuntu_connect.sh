chmod 400 ~/remote_ssh/mykey
ssh -o StrictHostKeyChecking=no -i ~/remote_ssh/mykey ubuntu@193.123.236.169
