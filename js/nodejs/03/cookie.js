const http = require("http");
http.createServer((req, res) =>{
	//console.log(req.url, req.headers.cookie);
	console.dir(req.headers);
	res.writeHead(200, {'Set-Cookie': 'my-new-cookie'});
	res.end("hello new client");
}).listen(8080, () =>{
	console.log("8080에서 리스닝중입니다");
})
