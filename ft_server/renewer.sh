docker rm test_run
docker rmi test_image
docker build -t "test_image" .
docker run -it -p 80:80 -p 443:443 --name "test_run" test_image
